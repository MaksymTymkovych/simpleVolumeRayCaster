#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <string>
#include "../include/ImageBuffer.h"

ImageBuffer::ImageBuffer()
{
    this->h = 0;
    this->w = 0;
    this->data = NULL;
    getMemory(w,h);
}

ImageBuffer::ImageBuffer(const size_t w, const size_t h)
{
    this->h = h;
    this->w = w;
    this->data = NULL;
    getMemory(w,h);
}

void ImageBuffer::getMemory(const size_t w, const size_t h)
{
    if (data==NULL)
    {
        data = static_cast<unsigned char *>(malloc(w*h*3));
    } else {
        realloc(data,w*h*3);
    }
}

void ImageBuffer::fill(const unsigned char value)
{
    memset(data,value,w*h*3);
    return;
}

void ImageBuffer::setValue(const size_t x, const size_t y, const unsigned char value)
{
    if (!(x<w && y<h))
    {
        //throw
        return;
    }
    else
    {
        data[(x+y*w)*3  ] = value;
        data[(x+y*w)*3+1] = value;
        data[(x+y*w)*3+2] = value;
    }
}

size_t ImageBuffer::getWidth()
{
    return w;
}
size_t ImageBuffer::getHeight()
{
    return h;
}

void ImageBuffer::saveToBitmap(const std::string fileName)
{

}

ImageBuffer::~ImageBuffer()
{
    free(data);
    data = NULL;
}
