#ifndef _MV_LOOKUP_TABLE_H_
#define _MV_LOOKUP_TABLE_H_
#include <initializer_list>
#include <vector>
#include <algorithm>

MV_INLINE mvImage1_t mvCreateLookUpTable(std::initializer_list<std::pair<mvUInt8_t,mvColor4_t>> points) {
    std::vector<std::pair<mvUInt8_t,mvColor4_t>> ps(begin(points),end(points));
    std::sort(ps.begin(),ps.end(),[](const std::pair<mvUInt8_t,mvColor4_t> & a, const std::pair<mvUInt8_t,mvColor4_t> & b) -> bool
              {
                return a.first < b.first;
              });
    mvImage1_t result = mvImage(256,4,MV_TYPE_UINT8);
    if (ps.size()<=2) {
        //return LookUp table grayscale & alpha = 0xF0
        mvColor4_t *pPixel(reinterpret_cast<mvColor4_t *> (result.data));
        for (mvUInt8_t pos = 0; pos<=0xFF; ++pos, ++pPixel) {
            (*pPixel) = mvColor4(pos,pos,pos,0xF0);
        }
    } else if (ps.size()==2) {
        //linear interpolation, between first and second value;
        const mvColor4_t color0(ps[0].second), color1(ps[1].second);
        mvColor4_t *pPixel(reinterpret_cast<mvColor4_t *> (result.data));
        for (mvUInt8_t pos = 0; pos<=0xFF; ++pos, ++pPixel) {
                (*pPixel) = mvColor4((mvUInt8_t)mvLerp(color0.red,color1.red,pos/255),
                                    (mvUInt8_t)mvLerp(color0.green,color1.green,pos/255),
                                    (mvUInt8_t)mvLerp(color0.blue,color1.blue,pos/255),
                                    (mvUInt8_t)mvLerp(color0.alpha,color1.alpha,pos/255));
        }
    } else {
        //Cubic interpolation, need 4 values. first index must be 0, last 255
        mvColor4_t color0, color1, color2, color3;
        mvUInt8_t v1,v2;
        for (int i=0; i<ps.size()-1; ++i) {
            v1 = ps[i].first;
            v2 = ps[i+1].first;
            color1 = ps[i].second;
            color2 = ps[i+1].second;
            if (i == 0) {
                color0 = mvColor4(0,0,0,0);
            } else {
                color0 = ps[i-1].second;
            }
            if (i == ps.size()-1) {
                color3 = mvColor4(0,0,0,0);
            } else {
                color3= ps[i+2].second;
            }
            mvFloat_t iDistance = 1.0f/(v2-v1);
            mvColor4_t *pPixel(reinterpret_cast<mvColor4_t *> (result.data));
            pPixel +=v1;
            for (int v=v1; v<=v2; ++v, ++pPixel) {
                mvFloat_t nv = ((mvFloat_t)(v-v1))*iDistance;
                const mvUInt8_t red = (mvUInt8_t) mvSplineInterpolation(color0.red,color1.red,color2.red,color3.red,nv);
                const mvUInt8_t green = (mvUInt8_t) mvSplineInterpolation(color0.green,color1.green,color2.green,color3.green,nv);
                const mvUInt8_t blue = (mvUInt8_t) mvSplineInterpolation(color0.blue,color1.blue,color2.blue,color3.blue,nv);
                const mvUInt8_t alpha = (mvUInt8_t) mvSplineInterpolation(color0.alpha,color1.alpha,color2.alpha,color3.alpha,nv);
                (*pPixel) = mvColor4(red,green,blue,alpha);
            }
        }

    }

    return result;
}




#endif // _MV_LOOKUP_TABLE_H_
