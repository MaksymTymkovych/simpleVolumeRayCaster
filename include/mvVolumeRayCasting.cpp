#include "mv.h"

mvStatus_t mvRayCasterCreate(mvRayCastState_t **pState, mvImage3_t *volume, const mvSize2_t size, const mvRayCasterOptions options) {
    (*pState) = (mvRayCastState_t *) malloc( sizeof(mvRayCastState_t) );
    (*pState)->colorBuffer = mvImage( size, 3, MV_TYPE_UINT8 );
    (*pState)->clearColor = mvColor(0,0,0);

    (*pState)->volume = volume;


    (*pState)->box = mvBoxAABB(mvVec3f(-1.0f,-1.0f,-1.0f),mvVec3f(1.0f,1.0f,1.0f));

    mvIdentity(&(*pState)->modelMatrix);
    mvRotate((*pState)->modelMatrix,90,1.0,0.0,0.0);
    (*pState)->viewMatrix = mvLookAt(0.0f, 0.0f, 2.0f,0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    (*pState)->projectionMatrix = mvPerspectiveProjection(45.0f, (*pState)->colorBuffer.size.width/(*pState)->colorBuffer.size.height, 1.0f, 15.0f);

    (*pState)->lookUpTable = NULL;

    if (options==MV_RAY_CASTER_OPTIONS_USE_SHADING) {
        mvSize3_t size3 = volume->size;

        mvSize_t gradient_size = (*pState)->volume->size.depth * (*pState)->volume->size.height * (*pState)->volume->size.width;
        (*pState)->gradient = new mvVec3f_t[gradient_size];
        const mvSize_t n = 1;
        mvVec3f_t *pVec = (*pState)->gradient;
        for (mvSize_t z(0); z<volume->size.depth; z++) {
            for (mvSize_t y(0); y<volume->size.height; y++) {
                for (mvSize_t x(0); x<volume->size.width; x++) {
                    mvVec3f_t vec1, vec2;
                    //std::cout<<x<<" "<<y<<" "<<z<<"; ";
                    mvSInt32_t pos = x-n;
                    if (pos >= 0) {
                        vec1.x = *mvImagePixel1u8(*(*pState)->volume,mvSize3(pos, y, z));

                    }
                    pos = x + n;
                    if (pos < volume->size.width) {
                        vec2.x = *mvImagePixel1u8(*(*pState)->volume,mvSize3(pos, y, z));
                    }
                    pos = y - n;
                    if (pos >= 0) {
                        vec1.y = *mvImagePixel1u8(*(*pState)->volume,mvSize3(x, pos, z));
                    }
                    pos = y + n;
                    if (pos < volume->size.height) {
                        vec2.y = *mvImagePixel1u8(*(*pState)->volume,mvSize3(x, pos, z));
                    }
                    pos = z - n;
                    if (pos >= 0) {
                        vec1.z = *mvImagePixel1u8(*(*pState)->volume,mvSize3(x, y, pos));
                    }
                    pos = z + n;
                    if (pos < volume->size.depth) {
                        vec2.z = *mvImagePixel1u8(*(*pState)->volume,mvSize3(x, y, pos));
                    }
                    mvVec3f_t vec = mvNormalize(vec2-vec1);
                    *pVec = vec;
                    if (std::isnan(pVec->x)) {
                        *pVec = mvVec3f(0.0f,0.0f,0.0f);
                    }
                    ++pVec;
                }
            }
        }
    }

    return MV_STATUS_NO_ERROR;
}


mvStatus_t mvRayCasterRender(mvRayCastState_t **pState) {
    if (pState != NULL) {
        mvFloat_t fx,
                  fy,
                  dx(2.0f/((*pState)->colorBuffer.size.width)),
                  dy(2.0f/((*pState)->colorBuffer.size.height));
        mvColor_t *pPixel(reinterpret_cast<mvColor_t *> ((*pState)->colorBuffer.data));

        fy = -1.0f;
        for (mvSize_t y(0); y<(*pState)->colorBuffer.size.height;++y,fy+=dy) {
            fx = -1.0f;
            for (mvSize_t x(0); x<(*pState)->colorBuffer.size.width;++x,fx+=dx,++pPixel) {
                mvRay_t ray =  mvGenerateRay(pState,fx,fy);
                mvVec3f_t start, finish;
                if (mvRayIntersectVolume(pState,ray,start,finish)) {
                    (*pPixel) = mvRayCasterGetColor(pState,start,finish);
                } else {
                    (*pPixel) = (*pState)->clearColor;
                }
            }
        }

    }
    return MV_STATUS_NO_ERROR;
}

mvStatus_t mvRayCasterDelete(mvRayCastState_t **pState ) {
    if (pState != NULL) {
        mvDelete((*pState)->colorBuffer);

        if ((*pState)->gradient != NULL) {
            delete [] (*pState)->gradient;
            (*pState)->gradient = NULL;
        }

        free(*pState);
        (*pState) = NULL;
    }
    return MV_STATUS_NO_ERROR;
}

void mvRayCasterSetLookUpTable(mvRayCastState_t **pState, mvImage1_t *lookUpTable) {
    if (pState != NULL) {
        (*pState)->lookUpTable = lookUpTable;
    }
}

