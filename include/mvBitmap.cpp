#include "mv.h"
#include <iostream>
#include <fstream>

#pragma pack(push, 1)
typedef struct mvBitmapFileHeader_t {
    mvUInt16_t type;
    mvUInt32_t size;
    mvUInt16_t reserved1, reserved2;
    mvUInt32_t offset;
} mvBitmapFileHeader_t;

typedef struct mvBitmapInfoHeader_t {
    mvUInt32_t size;
    mvSInt32_t width;
    mvSInt32_t height;
    mvUInt16_t planes;
    mvUInt16_t bitCount;
    mvUInt32_t compression;
    mvUInt32_t sizeImage;
    mvSInt32_t xPelsPerMeter;
    mvSInt32_t yPelsPerMeter;
    mvUInt32_t clrUsed;
    mvUInt32_t clrImportant;
} mvBitmapInfoHeader_t;
#pragma pack(pop)

mvStatus_t mvImageLoadFromBitmap(mvImage2_t &image, const std::string fileName) {
    return MV_STATUS_NO_ERROR;
}

mvStatus_t mvImageSaveToBitmap(mvImage2_t &image, const std::string fileName) {
    if (image.type==MV_TYPE_UINT8 && image.planes==3) {
        std::ofstream file(fileName.c_str(), std::ios::out | std::ios::binary);

        mvBitmapFileHeader_t fileHeader;
        mvBitmapInfoHeader_t infoHeader;
        memset(&fileHeader,0,sizeof(fileHeader));

        mvSize_t linewidth = mvCeil4(image.size.width * 3);
        mvSize_t lineoff = image.size.width * 3 - linewidth;
        fileHeader.type = 0x4d42;
        fileHeader.size = sizeof(fileHeader) + sizeof(infoHeader) + linewidth * image.size.height;
        fileHeader.offset = sizeof(infoHeader);

        infoHeader.size = sizeof(infoHeader);
        infoHeader.width = image.size.width;
        infoHeader.height = - image.size.height;
        infoHeader.planes = 1;
        infoHeader.bitCount = 24;
        infoHeader.compression = 0; //no compression
        infoHeader.sizeImage = linewidth * image.size.height;
        infoHeader.xPelsPerMeter = 3780;
        infoHeader.yPelsPerMeter = 3780;
        infoHeader.clrUsed = 0;
        infoHeader.clrImportant = 0;

        file.write(reinterpret_cast<char*>(&fileHeader),sizeof(fileHeader));
        file.write(reinterpret_cast<char*>(&infoHeader),sizeof(infoHeader));

        mvUInt8_t *pixel = reinterpret_cast<mvUInt8_t *>(image.data);
        for (mvSize_t y(0); y<image.size.height; ++y) {
            for (mvSize_t x(0); x<image.size.width; ++x) {
                mvColor_t color;
                color.red = *pixel; ++pixel;
                color.green = *pixel; ++pixel;
                color.blue = *pixel; ++pixel;
                file.write(reinterpret_cast<char*>(&color.blue),sizeof(mvUInt8_t));
                file.write(reinterpret_cast<char*>(&color.green),sizeof(mvUInt8_t));
                file.write(reinterpret_cast<char*>(&color.red),sizeof(mvUInt8_t));
            }
            for (mvSize_t x(0); x<lineoff; ++x) {
                file.write(reinterpret_cast<char*>(pixel),sizeof(mvUInt8_t));
            }
        }


        file.close();
    } else {
        return MV_STATUS_UNSUPPORTED_IMAGE;
    }
    return MV_STATUS_NO_ERROR;
}
