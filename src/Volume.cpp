#include <cstdlib>
#include <string>
#include <cstring>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <cmath>
#include "../include/Volume.h"


Volume::Volume(): data(NULL)
{
    this->w = 0;
    this->h = 0;
    this->d = 0;
    this->data = NULL;
    getMemory(w,h,d);
}

Volume::Volume(const size_t w, const size_t h, const size_t d): data(NULL)
{
    this->w = w;
    this->h = h;
    this->d = d;
    this->data = NULL;
    getMemory(w,h,d);
}

void Volume::getMemory(const size_t w, const size_t h, const size_t d)
{
    if (data==NULL)
    {
        data = static_cast<unsigned char *>(malloc(w*h*d));
    } else {
        realloc(data,w*h*d);
    }
}

void Volume::fill(const unsigned char value)
{
    memset(data,value,w*h*d);
    return;
}

void Volume::setValue(const size_t x, const size_t y, const size_t z, const unsigned char value)
{
    if (!(x<w && y<h && z<d))
    {
        //throw
        return;
    }
    else
    {
        data[(x*w+y)*h+z] = value;
    }
}

const unsigned char Volume::getValue(const size_t x, const size_t y, const size_t z)
{
    if ((x<w && y<h && z<d))
    {
        return data[(x*w+y)*h+z];
    }
    else
    {
        //throw;
        return 0;
    }
}

//trilinear interpolation
const unsigned char Volume::getValue(const float x, const float y, const float z)
{
    const size_t xmin(floorf(x)), xmax(xmin+1), ymin(floorf(y)), ymax(ymin+1), zmin(floorf(z)), zmax(zmin+1);

    if (!(xmax<w && ymax<h && zmax<d && xmin>=0 && ymin>=0 && zmin>=0))
    {
        //throw
        return 0;
    }

    const unsigned char V000(data[(xmin*w+ymin)*h+zmin]), V001(data[(xmax*w+ymin)*h+zmin]),
                        V010(data[(xmin*w+ymax)*h+zmin]), V011(data[(xmax*w+ymax)*h+zmin]),
                        V100(data[(xmin*w+ymin)*h+zmax]), V101(data[(xmax*w+ymin)*h+zmax]),
                        V110(data[(xmin*w+ymax)*h+zmax]), V111(data[(xmax*w+ymax)*h+zmax]);

    const float xd(x-xmin)/*/(xmax-xmin)*/;
    const float yd(y-ymin)/*/(ymax-ymin)*/;
    const float zd(z-zmin)/*/(zmax-zmin)*/;
    const float ixd(1.0f-xd);
    const float iyd(1.0f-yd);
    const float izd(1.0f-zd);

    const unsigned char V00(V000*ixd+V001*xd), V01(V010*ixd+V011*xd),
                        V10(V100*ixd+V101*xd), V11(V110*ixd+V111*xd);

    const unsigned char V0(V00*iyd+V01*yd), V1(V10*iyd+V11*yd);

    return (V0*izd+V1*zd);
}

void Volume::saveToFile(const std::string filename)
{
    std::ofstream file(filename.c_str(),std::ios::out | std::ios::binary);
    file.write(reinterpret_cast<char*>(&w),sizeof(w));
    file.write(reinterpret_cast<char*>(&h),sizeof(h));
    file.write(reinterpret_cast<char*>(&d),sizeof(d));
    file.write(reinterpret_cast<char*>(data),w*h*d);
    file.close();
}

void Volume::loadFromFile(const std::string filename)
{
    std::ifstream file(filename.c_str(),std::ios::in | std::ios::binary);
    if (file)
    {
        file.read(reinterpret_cast<char*>(&w),sizeof(w));
        file.read(reinterpret_cast<char*>(&h),sizeof(h));
        file.read(reinterpret_cast<char*>(&d),sizeof(d));
        getMemory(w,h,d);
        file.read(reinterpret_cast<char*>(data),w*h*d);
        file.close();
    }
}

size_t Volume::getWidth()
{
    return w;
}
size_t Volume::getHeight()
{
    return h;
}
size_t Volume::getDepth()
{
    return d;
}

Volume::~Volume()
{
    free(data);
    data = NULL;
}
