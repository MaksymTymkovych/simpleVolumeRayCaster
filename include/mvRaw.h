#ifndef _MV_RAW_H_
#define _MV_RAW_H_
#include <iostream>
#include <fstream>

MV_INLINE mvStatus_t mvImageLoadFromRaw(mvImage1_t &image, const std::string fileName, const mvSize_t size, const mvSize_t planes = 1) {
    image = mvImage(size,planes);
    std::ifstream fraw(fileName.c_str(), std::ios::in | std::ios::binary);
    fraw.read(reinterpret_cast<char *>(image.data),size*planes);
    fraw.close();
    return MV_STATUS_NO_ERROR;
}

MV_INLINE mvStatus_t mvImageSaveToRaw(mvImage1_t &image, const std::string fileName) {
    std::ofstream fraw(fileName.c_str(), std::ios::out | std::ios::binary);
    fraw.write(reinterpret_cast<char *>(image.data),image.size*image.planes);
    fraw.close();
    return MV_STATUS_NO_ERROR;
}

MV_INLINE mvStatus_t mvImageLoadFromRaw(mvImage2_t &image, const std::string fileName, const mvSize2_t size, const mvSize_t planes = 1) {
    image = mvImage(size,planes);
    std::ifstream fraw(fileName.c_str(), std::ios::in | std::ios::binary);
    fraw.read(reinterpret_cast<char *>(image.data),size.width*size.height*planes);
    fraw.close();
    return MV_STATUS_NO_ERROR;
}

MV_INLINE mvStatus_t mvImageSaveToRaw(mvImage2_t &image, const std::string fileName, const mvSize_t planes = 1) {
    std::ofstream fraw(fileName.c_str(), std::ios::out | std::ios::binary);
    fraw.write(reinterpret_cast<char *>(image.data),image.size.width*image.size.height*planes);
    fraw.close();
    return MV_STATUS_NO_ERROR;
}

MV_INLINE mvStatus_t mvImageLoadFromRaw(mvImage3_t &image, const std::string fileName, const mvSize3_t size, const mvSize_t planes = 1) {
    image = mvImage(size,planes);
    std::ifstream fraw(fileName.c_str(), std::ios::in | std::ios::binary);
    fraw.read(reinterpret_cast<char *>(image.data),size.width*size.height*size.depth*planes);
    fraw.close();
    return MV_STATUS_NO_ERROR;
}

MV_INLINE mvStatus_t mvImageSaveToRaw(mvImage3_t &image, const std::string fileName) {
    std::ofstream fraw(fileName.c_str(), std::ios::out | std::ios::binary);
    fraw.write(reinterpret_cast<char *>(image.data),image.size.width*image.size.height*image.size.depth);
    fraw.close();
    return MV_STATUS_NO_ERROR;
}

#endif // _MV_RAW_H_
