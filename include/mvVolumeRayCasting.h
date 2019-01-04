#ifndef _MV_VOLUME_RAY_CASTING_H_
#define _MV_VOLUME_RAY_CASTING_H_
#include "mvTypes.h"
#include "mvMath.h"
#include "mvImages.h"

typedef struct mvRayCastState_t {
    mvImage2_t colorBuffer;
    mvColor_t clearColor;

    mvImage3_t *volume;
    mvVec3f_t *gradient;

    mvImage1_t *lookUpTable;

    mvBoxAABB_t box;

    mvMat4f_t modelMatrix;
    mvMat4f_t viewMatrix;
    mvMat4f_t projectionMatrix;

} mvRayCastState_t;

typedef enum mvRayCasterOptions {
    MV_RAY_CASTER_OPTIONS_NONE = 0,
    MV_RAY_CASTER_OPTIONS_USE_SHADING = 0x10
} mvRayCasterOptions;

mvStatus_t mvRayCasterCreate(mvRayCastState_t **pState, mvImage3_t *volume, const mvSize2_t size, const mvRayCasterOptions options = MV_RAY_CASTER_OPTIONS_NONE);
mvStatus_t mvRayCasterRender(mvRayCastState_t **pState);
mvStatus_t mvRayCasterDelete(mvRayCastState_t **pState);
void mvRayCasterSetLookUpTable(mvRayCastState_t **pState, mvImage1_t *lookUpTable);

MV_INLINE mvRay_t mvGenerateRay(mvRayCastState_t **pState, const mvFloat_t &x, const mvFloat_t &y) {

    mvVec3f_t position(mvVec3f((*pState)->viewMatrix.a03,
                               (*pState)->viewMatrix.a13,
                               (*pState)->viewMatrix.a23));
    mvMat4f_t inverse;

    mvInverse((*pState)->modelMatrix*(*pState)->viewMatrix,&inverse);

    position.x = inverse.a03;
    position.y = inverse.a13;
    position.z = inverse.a23;
    mvVec3f_t direction(mvVec3f(x,y,1.0f)-position);
    return mvRay(position,direction);
}

MV_INLINE mvBool_t mvRayIntersectVolume(mvRayCastState_t **pState, const mvRay_t &ray, mvVec3f_t &start, mvVec3f_t &finish) {


    mvFloat_t t0,t1;

    mvMat3f_t modelMatrix;
    mvIdentity( &modelMatrix );
    //mvRotate(modelMatrix,0,1.0,0.0,0.0);
    //mvRotate(modelMatrix,2,0.0,1.0,0.0);
   // mvRotate(modelMatrix,2,0.0,0.0,1.0);

    mvMat3f_t iModelMatrix;
    mvInverse(modelMatrix,&iModelMatrix);

    mvFloat_t dx = 1.0/((*pState)->box.max.x - (*pState)->box.min.x);
    mvFloat_t dy = 1.0/((*pState)->box.max.y - (*pState)->box.min.y);
    mvFloat_t dz = 1.0/((*pState)->box.max.z - (*pState)->box.min.z);

    if (mvIntersection(ray,(*pState)->box,iModelMatrix, t0,t1)) {
        if (t0<0.0) t0 = 0.0f;
        if (t1<0.0) t1 = 0.0f;
        mvVec3f_t p0((ray.position+t0*ray.direction));
        mvVec3f_t p1((ray.position+t1*ray.direction));

        mvVec3f_t ip0 = iModelMatrix*p0 - (*pState)->box.min;
        ip0.x = ip0.x * dx; ip0.y = ip0.y * dy; ip0.z = ip0.z * dz;

        mvVec3f_t ip1 = iModelMatrix*p1 - (*pState)->box.min;
        ip1.x = ip1.x * dx; ip1.y = ip1.y * dy; ip1.z = ip1.z * dz;

        start.x = (ip0.x) * ((*pState)->volume->size.width-1);
        start.y = (ip0.y) * ((*pState)->volume->size.height-1);
        start.z = (ip0.z) * ((*pState)->volume->size.depth-1);

        finish.x = (ip1.x) * ((*pState)->volume->size.width-1);
        finish.y = (ip1.y) * ((*pState)->volume->size.height-1);
        finish.z = (ip1.z) * ((*pState)->volume->size.depth-1);

        return MV_TRUE;
    }
    return MV_FALSE;
}

MV_INLINE mvColor_t mvRayCasterGetColor(mvRayCastState_t **pState, mvVec3f_t &start, const mvVec3f_t &finish) {
    mvUInt8_t max(0);

    mvVec3f_t dir(finish-start);
    dir = mvNormalize(dir);
    mvUInt8_t curr;
    mvSize3_t size = (*pState)->volume->size;
    mvSize3_t pos;

    mvSize_t count = 0;
    mvUInt32_t v(0);

    mvColor4_t src = mvColor4(0,0,0,0), dst = mvColor4(0,0,0,0);
    float srca(0.0f),srcr(0.0f),srcg(0.0f),srcb(0.0f),
            dsta(0.0f),dstr(0.0f),dstg(0.0f),dstb(0.0f);

    while (mvDistance(start-finish)>=1.0) {
        pos.width  = (mvSize_t)floorf(start.x);
        pos.height = (mvSize_t)floorf(start.y);
        pos.depth  = (mvSize_t)floorf(start.z);


        if (pos.width<0) pos.width = 0;
        if (pos.width>size.width) pos.width = size.width - 1;
        if (pos.height<0) pos.height = 0;
        if (pos.height>size.width) pos.height = size.height - 1;
        if (pos.depth<0) pos.depth = 0;
        if (pos.depth>size.depth) pos.depth = size.depth - 1;
        //curr = *mvImagePixel1u8((*pState)->volume,pos);


        //curr = mvImagePixels1u8((*(*pState)->volume),pos);
        //curr = *mvImagePixel1u8(*(*pState)->volume,pos);//fastes
        curr = mvImagePixel1u8(*(*pState)->volume,start); //slowest


        //mvVec3f_t vec = *(reinterpret_cast<mvVec3f_t*>((*pState)->gradient) + pos.width + (pos.height  + pos.depth * size.height) * size.width);
        //curr = std::abs((long)std::ceil(mvDistance(vec)));

        src = *((reinterpret_cast<mvColor4_t *> ((*pState)->lookUpTable->data))+curr);
        srca = (float)(src.alpha)/255.0f;
        srcr = (float)(src.red)/255.0f;
        srcg = (float)(src.green)/255.0f;
        srcb = (float)(src.blue)/255.0f;

        /*
        //std::cout<<pos.width<<" "<<pos.height<<" "<<pos.depth<<std::endl;
        mvVec3f_t vec = *(reinterpret_cast<mvVec3f_t*>((*pState)->gradient) + pos.width + (pos.height  + pos.depth * size.height) * size.width);
        //std::cout<<pos.width<<" "<<pos.height<<" "<<pos.depth<<std::endl;
        if (mvDistance(vec)>0.5) {
            srca = srca/2;
        }
        */


        /*
        src.alpha = src.alpha * 0.5f;
        src.red *=  src.alpha;
        src.green *=  src.alpha;
        src.blue *=  src.alpha;
        */
        srca = srca * 0.5f;
        srcr = srcr * srca;
        srcg = srcg * srca;
        srcb = srcb * srca;

        /*
        dst.red = ((255.0f - dst.alpha)*src.red)/255.0f + dst.red;
        dst.green = ((255.0f - dst.alpha)*src.green)/255.0f + dst.green;
        dst.blue = ((255.0f - dst.alpha)*src.blue)/255.0f + dst.blue;
        dst.alpha = ((255.0f - dst.alpha)*src.alpha)/255.0f + dst.alpha;
        */
        dstr = (1.0f - dsta)*srcr + dstr;
        dstg = (1.0f - dsta)*srcg + dstg;
        dstb = (1.0f - dsta)*srcb + dstb;
        dsta = (1.0f - dsta)*srca + dsta;
        //if (dst.alpha/255.0f>=0.95f) break;
        if (dsta>=0.95f) break;
        /*
        v+=curr;
        if (curr>max) {
            max = curr;
            if (max>50) return mvColor(max,max,max);
        }
        ++count;
        */
        start = start + dir;


    }
    /*
    //return mvColor(0,0,0);
    if (count!=0)max = v/count;
    else max = 0;
    //std::cout<<(float) max<<"; ";
    return mvColor(max,max,max);
    */
    //return mvColor(dst.red,dst.green,dst.blue);
    if (dstr>1.0f) dstr = 1.0f;
    if (dstg>1.0f) dstg = 1.0f;
    if (dstb>1.0f) dstb = 1.0f;
    return mvColor((mvUInt8_t)(dstr*255.0f),(mvUInt8_t)(dstg*255.0f),(mvUInt8_t)(dstb*255.0f));

}


#endif // _MV_VOLUME_RAY_CASTING_H_
