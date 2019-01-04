#ifndef _MV_IMAGES_H_
#define _MV_IMAGES_H_
#include "mvTypes.h"
#include <iostream>
#include <fstream>

MV_INLINE mvImage1_t mvImage(const mvSize_t size, const mvSize_t planes = 1, const mvType_t type = MV_TYPE_UINT8) {
    mvImage1_t result;
    switch(type) {
    case MV_TYPE_UINT8:
    case MV_TYPE_SINT8:
        result.bytes = size*planes*sizeof(mvUInt8_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_UINT16:
    case MV_TYPE_SINT16:
        result.bytes = size*planes*sizeof(mvUInt16_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_UINT32:
    case MV_TYPE_SINT32:
        result.bytes = size*planes*sizeof(mvUInt32_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_FLOAT:
        result.bytes = size*planes*sizeof(mvFloat_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_DOUBLE:
        result.bytes = size*planes*sizeof(mvDouble_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_NONE:
    case MV_TYPE_BOOL:
    default:
        result.bytes = 0;
        result.planes = 0;
        result.size = 0;
        result.type = MV_TYPE_NONE;
        result.data = NULL;
        break;
    }
    return result;
}

MV_INLINE mvImage2_t mvImage(const mvSize2_t size, const mvSize_t planes = 1, const mvType_t type = MV_TYPE_UINT8) {
    mvImage2_t result;
    switch(type) {
    case MV_TYPE_UINT8:
    case MV_TYPE_SINT8:
        result.bytes = size.height*size.width*planes*sizeof(mvUInt8_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_UINT16:
    case MV_TYPE_SINT16:
        result.bytes = size.height*size.width*planes*sizeof(mvUInt16_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_UINT32:
    case MV_TYPE_SINT32:
        result.bytes = size.height*size.width*planes*sizeof(mvUInt32_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_FLOAT:
        result.bytes = size.height*size.width*planes*sizeof(mvFloat_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_DOUBLE:
        result.bytes = size.height*size.width*planes*sizeof(mvDouble_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_NONE:
    case MV_TYPE_BOOL:
    default:
        result.bytes = 0;
        result.planes = 0;
        result.size.height = 0;
        result.size.width = 0;
        result.type = MV_TYPE_NONE;
        result.data = NULL;
        break;
    }
    return result;
}

MV_INLINE mvImage3_t mvImage(const mvSize3_t size, const mvSize_t planes = 1, const mvType_t type = MV_TYPE_UINT8) {
    mvImage3_t result;
    switch(type) {
    case MV_TYPE_UINT8:
    case MV_TYPE_SINT8:
        result.bytes = size.height*size.width*size.depth*planes*sizeof(mvUInt8_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_UINT16:
    case MV_TYPE_SINT16:
        result.bytes = size.height*size.width*size.depth*sizeof(mvUInt16_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_UINT32:
    case MV_TYPE_SINT32:
        result.bytes = size.height*size.width*size.depth*sizeof(mvUInt32_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_FLOAT:
        result.bytes = size.height*size.width*size.depth*sizeof(mvFloat_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_DOUBLE:
        result.bytes = size.height*size.width*size.depth*sizeof(mvDouble_t);
        result.planes = planes;
        result.size = size;
        result.type = type;
        result.data = malloc(result.bytes);
        break;
    case MV_TYPE_NONE:
    case MV_TYPE_BOOL:
    default:
        result.bytes = 0;
        result.planes = 0;
        result.size.height = 0;
        result.size.width = 0;
        result.size.depth = 0;
        result.type = MV_TYPE_NONE;
        result.data = NULL;
        break;
    }
    return result;
}

MV_INLINE void mvDelete(mvImage1_t &image) {
    if (image.data!=NULL) {
        free(image.data);
    }
    image.bytes = 0;
    image.planes = 0;
    image.size = 0;
    image.type = MV_TYPE_NONE;
}

MV_INLINE void mvDelete(mvImage2_t &image) {
    if (image.data!=NULL) {
        free(image.data);
    }
    image.bytes = 0;
    image.planes = 0;
    image.size = mvSize2(0,0);
    image.type = MV_TYPE_NONE;
}

MV_INLINE void mvDelete(mvImage3_t &image) {
    if (image.data!=NULL) {
        free(image.data);
    }
    image.bytes = 0;
    image.planes = 0;
    image.size = mvSize3(0,0,0);
    image.type = MV_TYPE_NONE;
}

MV_INLINE void mvZero(mvImage1_t &image) {
    memset(image.data,0,image.bytes);
}

MV_INLINE void mvZero(mvImage2_t &image) {
    memset(image.data,0,image.bytes);
}

MV_INLINE void mvZero(mvImage3_t &image) {
    memset(image.data,0,image.bytes);
}


MV_INLINE mvUInt8_t* mvImagePixel1u8(const mvImage1_t &image, const mvSize_t &pos) {
    return reinterpret_cast<mvUInt8_t*>(image.data) + pos;
}

MV_INLINE mvUInt8_t* mvImagePixel1u8(const mvImage2_t &image, const mvSize2_t &pos) {
    return reinterpret_cast<mvUInt8_t*>(image.data) + pos.width + pos.height * image.size.width;
}

MV_INLINE mvUInt8_t* mvImagePixel1u8(const mvImage3_t &image, const mvSize3_t &pos) {
    return reinterpret_cast<mvUInt8_t*>(image.data) + pos.width + (pos.height  + pos.depth * image.size.height) * image.size.width;
}


MV_INLINE mvUInt8_t mvImagePixel1u8(const mvImage3_t &image, const mvVec3f_t &pos) {
    const mvSize_t xmin(floorf(pos.x)), xmax(xmin+1), ymin(floorf(pos.y)), ymax(ymin+1), zmin(floorf(pos.z)), zmax(zmin+1);


    if (!(xmax<image.size.width && ymax<image.size.height && zmax<image.size.depth && xmin>=0 && ymin>=0 && zmin>=0))
    {
        //throw
        return 0;
    }

    const unsigned char V000(*mvImagePixel1u8(image,mvSize3(xmin,ymin,zmin))), V001(*mvImagePixel1u8(image,mvSize3(xmax,ymin,zmin))),
                        V010(*mvImagePixel1u8(image,mvSize3(xmin,ymax,zmin))), V011(*mvImagePixel1u8(image,mvSize3(xmax,ymax,zmin))),
                        V100(*mvImagePixel1u8(image,mvSize3(xmin,ymin,zmax))), V101(*mvImagePixel1u8(image,mvSize3(xmax,ymin,zmax))),
                        V110(*mvImagePixel1u8(image,mvSize3(xmin,ymax,zmax))), V111(*mvImagePixel1u8(image,mvSize3(xmax,ymax,zmax)));

    const float xd(pos.x-xmin);
    const float yd(pos.y-ymin);
    const float zd(pos.z-zmin);
    const float ixd(1.0f-xd);
    const float iyd(1.0f-yd);
    const float izd(1.0f-zd);

    const unsigned char V00(V000*ixd+V001*xd), V01(V010*ixd+V011*xd),
                        V10(V100*ixd+V101*xd), V11(V110*ixd+V111*xd);

    const unsigned char V0(V00*iyd+V01*yd), V1(V10*iyd+V11*yd);

    return (V0*izd+V1*zd);
}

MV_INLINE mvStatus_t mvSaveToTextFile(const mvImage1_t &image, const std::string fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        if (image.type == MV_TYPE_UINT8) {
            mvUInt8_t* pData = reinterpret_cast<mvUInt8_t*>(image.data);
            for(mvSize_t i(0); i<image.size; ++i) {
                for(mvSize_t p(0); p<image.planes; ++p, ++pData) {
                    file<<(int) *pData<<";";
                }
                file<<std::endl;
            }
            file.close();
            return MV_STATUS_NO_ERROR;
        } else {
            return MV_STATUS_UNSUPPORTED_IMAGE;
        }

    } else {
        return MV_STATUS_FILE_OPENING_ERROR;
    }
}


#endif // _MV_IMAGES_H_
