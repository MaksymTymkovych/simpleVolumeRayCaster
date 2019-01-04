#ifndef _MV_MATH_H_
#define _MV_MATH_H_
#include "mvTypes.h"

#define MV_MATH_EPSILON_D   1E-14
#define MV_MATH_EPSILON_F   1E-6

#define MV_PI_D 3.141592653589793238462
#define MV_PI_F 3.14159265358979f

MV_INLINE mvDouble_t mvAbs(const mvFloat_t &a) {
    return fabs(a);
}

MV_INLINE mvDouble_t mvAbs(const mvDouble_t &a) {
    return fabs(a);
}

MV_INLINE mvDouble_t mvDistance(const mvVec2d_t &a) {
    return sqrt(a.x*a.x + a.y*a.y);
}

MV_INLINE mvDouble_t mvDistance(const mvVec3d_t &a) {
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

MV_INLINE mvDouble_t mvDistance(const mvVec4d_t &a) {
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w);
}

MV_INLINE mvFloat_t mvDistance(const mvVec2f_t &a) {
    return sqrtf(a.x*a.x + a.y*a.y);
}

MV_INLINE mvFloat_t mvDistance(const mvVec3f_t &a) {
    return sqrtf(a.x*a.x + a.y*a.y + a.z*a.z);
}

MV_INLINE mvFloat_t mvDistance(const mvVec4f_t &a) {
    return sqrtf(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w);
}

MV_INLINE mvDouble_t mvDistanceSqr(const mvVec2d_t &a) {
    return a.x*a.x + a.y*a.y;
}

MV_INLINE mvDouble_t mvDistanceSqr(const mvVec3d_t &a) {
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

MV_INLINE mvDouble_t mvDistanceSqr(const mvVec4d_t &a) {
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

MV_INLINE mvFloat_t mvDistanceSqr(const mvVec2f_t &a) {
    return a.x*a.x + a.y*a.y;
}

MV_INLINE mvFloat_t mvDistanceSqr(const mvVec3f_t &a) {
    return a.x*a.x + a.y*a.y + a.z*a.z;
}

MV_INLINE mvFloat_t mvDistanceSqr(const mvVec4f_t &a) {
    return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

MV_INLINE mvVec2d_t mvNormalize(const mvVec2d_t &a) {
    mvVec2d_t result;
    mvDouble_t ilen(1.0/mvDistance(a));
    result.x = a.x*ilen;
    result.y = a.y*ilen;
    return result;
}

MV_INLINE mvVec3d_t mvNormalize(const mvVec3d_t &a) {
    mvVec3d_t result;
    mvDouble_t ilen(1.0/mvDistance(a));
    result.x = a.x*ilen;
    result.y = a.y*ilen;
    result.z = a.z*ilen;
    return result;
}

MV_INLINE mvVec4d_t mvNormalize(const mvVec4d_t &a) {
    mvVec4d_t result;
    mvDouble_t ilen(1.0/mvDistance(a));
    result.x = a.x*ilen;
    result.y = a.y*ilen;
    result.z = a.z*ilen;
    result.w = a.w*ilen;
    return result;
}

MV_INLINE mvVec2f_t mvNormalize(const mvVec2f_t &a) {
    mvVec2f_t result;
    mvFloat_t ilen(1.0/mvDistance(a));
    result.x = a.x*ilen;
    result.y = a.y*ilen;
    return result;
}

MV_INLINE mvVec3f_t mvNormalize(const mvVec3f_t &a) {
    mvVec3f_t result;
    mvFloat_t ilen(1.0/mvDistance(a));
    result.x = a.x*ilen;
    result.y = a.y*ilen;
    result.z = a.z*ilen;
    return result;
}

MV_INLINE mvVec4f_t mvNormalize(const mvVec4f_t &a) {
    mvVec4f_t result;
    mvFloat_t ilen(1.0/mvDistance(a));
    result.x = a.x*ilen;
    result.y = a.y*ilen;
    result.z = a.z*ilen;
    result.w = a.w*ilen;
    return result;
}

MV_INLINE mvVec2d_t operator + (const mvVec2d_t &a, const mvVec2d_t &b) {
    mvVec2d_t result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

MV_INLINE mvVec3d_t operator + (const mvVec3d_t &a, const mvVec3d_t &b) {
    mvVec3d_t result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

MV_INLINE mvVec4d_t operator + (const mvVec4d_t &a, const mvVec4d_t &b) {
    mvVec4d_t result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;
    return result;
}

MV_INLINE mvVec2f_t operator + (const mvVec2f_t &a, const mvVec2f_t &b) {
    mvVec2f_t result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

MV_INLINE mvVec3f_t operator + (const mvVec3f_t &a, const mvVec3f_t &b) {
    mvVec3f_t result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

MV_INLINE mvVec4f_t operator + (const mvVec4f_t &a, const mvVec4f_t &b) {
    mvVec4f_t result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;
    return result;
}

MV_INLINE mvVec2d_t operator - (const mvVec2d_t &a, const mvVec2d_t &b) {
    mvVec2d_t result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

MV_INLINE mvVec3d_t operator - (const mvVec3d_t &a, const mvVec3d_t &b) {
    mvVec3d_t result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

MV_INLINE mvVec4d_t operator - (const mvVec4d_t &a, const mvVec4d_t &b) {
    mvVec4d_t result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;
    return result;
}

MV_INLINE mvVec2f_t operator - (const mvVec2f_t &a, const mvVec2f_t &b) {
    mvVec2f_t result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

MV_INLINE mvVec3f_t operator - (const mvVec3f_t &a, const mvVec3f_t &b) {
    mvVec3f_t result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

MV_INLINE mvVec4f_t operator - (const mvVec4f_t &a, const mvVec4f_t &b) {
    mvVec4f_t result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;
    return result;
}

MV_INLINE mvVec2d_t operator - (const mvVec2d_t &a) {
    mvVec2d_t result;
    result.x = - a.x;
    result.y = - a.y;
    return result;
}

MV_INLINE mvVec3d_t operator - (const mvVec3d_t &a) {
    mvVec3d_t result;
    result.x = - a.x;
    result.y = - a.y;
    result.z = - a.z;
    return result;
}

MV_INLINE mvVec4d_t operator - (const mvVec4d_t &a) {
    mvVec4d_t result;
    result.x = - a.x;
    result.y = - a.y;
    result.z = - a.z;
    result.w = - a.w;
    return result;
}

MV_INLINE mvVec2f_t operator - (const mvVec2f_t &a) {
    mvVec2f_t result;
    result.x = - a.x;
    result.y = - a.y;
    return result;
}

MV_INLINE mvVec3f_t operator - (const mvVec3f_t &a) {
    mvVec3f_t result;
    result.x = - a.x;
    result.y = - a.y;
    result.z = - a.z;
    return result;
}

MV_INLINE mvVec4f_t operator - (const mvVec4f_t &a) {
    mvVec4f_t result;
    result.x = - a.x;
    result.y = - a.y;
    result.z = - a.z;
    result.w = - a.w;
    return result;
}

/**
        dot product
*/
MV_INLINE mvDouble_t operator * (const mvVec2d_t &a, const mvVec2d_t &b) {
    return a.x*b.x + a.y*b.y;
}

MV_INLINE mvDouble_t operator * (const mvVec3d_t &a, const mvVec3d_t &b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

MV_INLINE mvDouble_t operator * (const mvVec4d_t &a, const mvVec4d_t &b) {
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

MV_INLINE mvFloat_t operator * (const mvVec2f_t &a, const mvVec2f_t &b) {
    return a.x*b.x + a.y*b.y;
}

MV_INLINE mvFloat_t operator * (const mvVec3f_t &a, const mvVec3f_t &b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

MV_INLINE mvFloat_t operator * (const mvVec4f_t &a, const mvVec4f_t &b) {
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

MV_INLINE mvVec2d_t operator * (const mvVec2d_t &a, const mvDouble_t b) {
    mvVec2d_t result;
    result.x = a.x*b;
    result.y = a.y*b;
    return result;
}

MV_INLINE mvVec3d_t operator * (const mvVec3d_t &a, const mvDouble_t b) {
    mvVec3d_t result;
    result.x = a.x*b;
    result.y = a.y*b;
    result.z = a.z*b;
    return result;
}

MV_INLINE mvVec4d_t operator * (const mvVec4d_t &a, const mvDouble_t b) {
    mvVec4d_t result;
    result.x = a.x*b;
    result.y = a.y*b;
    result.z = a.z*b;
    result.w = a.w*b;
    return result;
}

MV_INLINE mvVec2f_t operator * (const mvVec2f_t &a, const mvFloat_t b) {
    mvVec2f_t result;
    result.x = a.x*b;
    result.y = a.y*b;
    return result;
}

MV_INLINE mvVec3f_t operator * (const mvVec3f_t &a, const mvFloat_t b) {
    mvVec3f_t result;
    result.x = a.x*b;
    result.y = a.y*b;
    result.z = a.z*b;
    return result;
}

MV_INLINE mvVec4f_t operator * (const mvVec4f_t &a, const mvFloat_t b) {
    mvVec4f_t result;
    result.x = a.x*b;
    result.y = a.y*b;
    result.z = a.z*b;
    result.w = a.w*b;
    return result;
}

MV_INLINE mvVec2d_t operator * (const mvFloat_t a, const mvVec2d_t &b) {
    mvVec2d_t result;
    result.x = a*b.x;
    result.y = a*b.y;
    return result;
}

MV_INLINE mvVec3d_t operator * (const mvFloat_t a, const mvVec3d_t &b) {
    mvVec3d_t result;
    result.x = a*b.x;
    result.y = a*b.y;
    result.z = a*b.z;
    return result;
}

MV_INLINE mvVec4d_t operator * (const mvFloat_t a, const mvVec4d_t &b) {
    mvVec4d_t result;
    result.x = a*b.x;
    result.y = a*b.y;
    result.z = a*b.z;
    result.w = a*b.w;
    return result;
}

MV_INLINE mvVec2f_t operator * (const mvFloat_t a, const mvVec2f_t &b) {
    mvVec2f_t result;
    result.x = a*b.x;
    result.y = a*b.y;
    return result;
}

MV_INLINE mvVec3f_t operator * (const mvFloat_t a, const mvVec3f_t &b) {
    mvVec3f_t result;
    result.x = a*b.x;
    result.y = a*b.y;
    result.z = a*b.z;
    return result;
}

MV_INLINE mvVec4f_t operator * (const mvFloat_t a, const mvVec4f_t &b) {
    mvVec4f_t result;
    result.x = a*b.x;
    result.y = a*b.y;
    result.z = a*b.z;
    result.w = a*b.w;
    return result;
}

MV_INLINE mvVec2d_t operator / (const mvVec2d_t &a, const mvDouble_t b) {
    mvVec2d_t result;
    mvDouble_t ib(1.0/b);
    result.x = a.x*ib;
    result.y = a.y*ib;
    return result;
}

MV_INLINE mvVec3d_t operator / (const mvVec3d_t &a, const mvDouble_t b) {
    mvVec3d_t result;
    mvDouble_t ib(1.0/b);
    result.x = a.x*ib;
    result.y = a.y*ib;
    result.z = a.z*ib;
    return result;
}

MV_INLINE mvVec4d_t operator / (const mvVec4d_t &a, const mvDouble_t b) {
    mvVec4d_t result;
    mvDouble_t ib(1.0/b);
    result.x = a.x*ib;
    result.y = a.y*ib;
    result.z = a.z*ib;
    result.w = a.w*ib;
    return result;
}

MV_INLINE mvVec2f_t operator / (const mvVec2f_t &a, const mvFloat_t b) {
    mvVec2f_t result;
    mvFloat_t ib(1.0f/b);
    result.x = a.x*ib;
    result.y = a.y*ib;
    return result;
}

MV_INLINE mvVec3f_t operator / (const mvVec3f_t &a, const mvFloat_t b) {
    mvVec3f_t result;
    mvFloat_t ib(1.0f/b);
    result.x = a.x*ib;
    result.y = a.y*ib;
    result.z = a.z*ib;
    return result;
}

MV_INLINE mvVec4f_t operator / (const mvVec4f_t &a, const mvFloat_t b) {
    mvVec4f_t result;
    mvFloat_t ib(1.0f/b);
    result.x = a.x*ib;
    result.y = a.y*ib;
    result.z = a.z*ib;
    result.w = a.w*ib;
    return result;
}

MV_INLINE mvDouble_t mvCosAngle(const mvVec2d_t &a, const mvVec2d_t &b) {
    mvDouble_t result;
    result = a*b/(mvDistance(a)*mvDistance(b));
    return result;
}

MV_INLINE mvDouble_t mvCosAngle(const mvVec3d_t &a, const mvVec3d_t &b) {
    mvDouble_t result;
    result = a*b/(mvDistance(a)*mvDistance(b));
    return result;
}

MV_INLINE mvFloat_t mvCosAngle(const mvVec2f_t &a, const mvVec2f_t &b) {
    mvFloat_t result;
    result = a*b/(mvDistance(a)*mvDistance(b));
    return result;
}

MV_INLINE mvFloat_t mvCosAngle(const mvVec3f_t &a, const mvVec3f_t &b) {
    mvFloat_t result;
    result = a*b/(mvDistance(a)*mvDistance(b));
    return result;
}

MV_INLINE mvVec3d_t mvCross(const mvVec3d_t &a, const mvVec3d_t &b) {
    mvVec3d_t result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

MV_INLINE mvVec3f_t mvCross(const mvVec3f_t &a, const mvVec3f_t &b) {
    mvVec3f_t result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvVec2f_t &v) {
	return os<<"["<<v.x<<", "<<v.y<<"]";
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvVec2d_t &v) {
	return os<<"["<<v.x<<", "<<v.y<<"]";
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvVec3f_t &v) {
	return os<<"["<<v.x<<", "<<v.y<<", "<<v.z<<"]";
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvVec3d_t &v) {
	return os<<"["<<v.x<<", "<<v.y<<", "<<v.z<<"]";
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvVec4f_t &v) {
	return os<<"["<<v.x<<", "<<v.y<<", "<<v.z<<", "<<v.w<<"]";
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvVec4d_t &v) {
	return os<<"["<<v.x<<", "<<v.y<<", "<<v.z<<", "<<v.w<<"]";
}

MV_INLINE mvVec2f_t operator /(const mvFloat_t &a, const mvVec2f_t &b) {
    return mvVec2f(a/b.x, a/b.y);
}

MV_INLINE mvVec2d_t operator /(const mvDouble_t &a, const mvVec2d_t &b) {
    return mvVec2d(a/b.x, a/b.y);
}

MV_INLINE mvVec3f_t operator /(const mvFloat_t &a, const mvVec3f_t &b) {
    return mvVec3f(a/b.x, a/b.y, a/b.z);
}

MV_INLINE mvVec3d_t operator /(const mvDouble_t &a, const mvVec3d_t &b) {
    return mvVec3d(a/b.x, a/b.y, a/b.z);
}

MV_INLINE mvVec4f_t operator /(const mvFloat_t &a, const mvVec4f_t &b) {
    return mvVec4f(a/b.x, a/b.y, a/b.z, a/b.w);
}

MV_INLINE mvVec4d_t operator /(const mvDouble_t &a, const mvVec4d_t &b) {
    return mvVec4d(a/b.x, a/b.y, a/b.z, a/b.w);
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvMat2f_t &m) {
	return os<<m.vec[0]<<std::endl<<m.vec[1];
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvMat2d_t &m) {
	return os<<m.vec[0]<<std::endl<<m.vec[1];
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvMat3f_t &m) {
	return os<<m.vec[0]<<std::endl<<m.vec[1]<<std::endl<<m.vec[2];
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvMat3d_t &m) {
	return os<<m.vec[0]<<std::endl<<m.vec[1]<<std::endl<<m.vec[2];
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvMat4f_t &m) {
	return os<<m.vec[0]<<std::endl<<m.vec[1]<<std::endl<<m.vec[2]<<std::endl<<m.vec[3];
}

MV_INLINE std::ostream & operator <<(std::ostream & os, const mvMat4d_t &m) {
	return os<<m.vec[0]<<std::endl<<m.vec[1]<<std::endl<<m.vec[2]<<std::endl<<m.vec[3];
}

MV_INLINE mvMat2f_t operator - (const mvMat2f_t &a) {
    return mvMat2f(-a.a00,-a.a01,
                   -a.a10,-a.a11);
}

MV_INLINE mvMat2f_t operator + (const mvMat2f_t &a, const mvMat2f_t &b) {
    return mvMat2f(a.a00 + b.a00,a.a01 + b.a01,
                   a.a10 + b.a10,a.a11 + b.a11);
}

MV_INLINE mvMat2f_t operator - (const mvMat2f_t &a, const mvMat2f_t &b) {
    return mvMat2f(a.a00 - b.a00,a.a01 - b.a01,
                   a.a10 - b.a10,a.a11 - b.a11);
}

MV_INLINE mvVec2f_t operator * (const mvMat2f_t &mat, const mvVec2f_t &vec) {
    return mvVec2f(mat.a00*vec.x + mat.a01*vec.y,
                   mat.a10*vec.x + mat.a11*vec.y);
}

MV_INLINE mvMat2f_t operator * (const mvMat2f_t &a, const mvMat2f_t &b) {
    return mvMat2f(a.a00*b.a00 + a.a01*b.a10,
                   a.a00*b.a01 + a.a01*b.a11,
                   a.a10*b.a00 + a.a11*b.a10,
                   a.a10*b.a01 + a.a11*b.a11);
}

MV_INLINE mvMat2f_t operator * (const mvMat2f_t &mat, const mvFloat_t &m) {
    return mvMat2f(mat.a00*m, mat.a01*m,
                   mat.a10*m, mat.a11*m);
}

MV_INLINE void mvZero(mvMat2f_t* result) {
    (*result) = mvMat2f(0.0f,0.0f,
                        0.0f,0.0f);
}

MV_INLINE void mvIdentity(mvMat2f_t* result) {
    (*result) = mvMat2f(1.0f,0.0f,
                        0.0f,1.0f);
}

MV_INLINE mvMat2f_t mvTranspose(const mvMat2f_t &mat) {
    return mvMat2f(mat.a00,mat.a10,
                   mat.a01,mat.a11);
}

MV_INLINE mvFloat_t mvDeterminant(const mvMat2f_t &mat) {
    return mat.a00*mat.a11 - mat.a01*mat.a10;
}

MV_INLINE mvBool_t mvInverse(const mvMat2f_t &mat, mvMat2f_t* result ) {
    mvFloat_t det = mvDeterminant(mat);
    if (mvAbs(det) < MV_MATH_EPSILON_F) {
        return MV_FALSE;
    }

    mvFloat_t iDet = 1.0f / det;

    result->a00 = mat.a11 * iDet;
    result->a01 = mat.a01 * iDet;
    result->a10 = mat.a10 * iDet;
    result->a11 = mat.a00 * iDet;

    return MV_TRUE;
}

MV_INLINE mvMat2d_t operator - (const mvMat2d_t &a) {
    return mvMat2d(-a.a00,-a.a01,
                   -a.a10,-a.a11);
}

MV_INLINE mvMat2d_t operator + (const mvMat2d_t &a, const mvMat2d_t &b) {
    return mvMat2d(a.a00 + b.a00,a.a01 + b.a01,
                   a.a10 + b.a10,a.a11 + b.a11);
}

MV_INLINE mvMat2d_t operator - (const mvMat2d_t &a, const mvMat2d_t &b) {
    return mvMat2d(a.a00 - b.a00,a.a01 - b.a01,
                   a.a10 - b.a10,a.a11 - b.a11);
}

MV_INLINE mvVec2d_t operator * (const mvMat2d_t &mat, const mvVec2d_t &vec) {
    return mvVec2d(mat.a00*vec.x + mat.a01*vec.y,
                   mat.a10*vec.x + mat.a11*vec.y);
}

MV_INLINE mvMat2d_t operator * (const mvMat2d_t &a, const mvMat2d_t &b) {
    return mvMat2d(a.a00*b.a00 + a.a01*b.a10,
                   a.a00*b.a01 + a.a01*b.a11,
                   a.a10*b.a00 + a.a11*b.a10,
                   a.a10*b.a01 + a.a11*b.a11);
}

MV_INLINE mvMat2d_t operator * (const mvMat2d_t &mat, const mvDouble_t &m) {
    return mvMat2d(mat.a00*m, mat.a01*m,
                   mat.a10*m, mat.a11*m);
}

MV_INLINE void mvZero(mvMat2d_t* result) {
    (*result) = mvMat2d(0.0,0.0,
                        0.0,0.0);
}

MV_INLINE void mvIdentity(mvMat2d_t* result) {
    (*result) = mvMat2d(1.0,0.0,
                        0.0,1.0);
}

MV_INLINE mvMat2d_t mvTranspose(const mvMat2d_t &mat) {
    return mvMat2d(mat.a00,mat.a10,
                   mat.a01,mat.a11);
}

MV_INLINE mvDouble_t mvDeterminant(const mvMat2d_t &mat) {
    return mat.a00*mat.a11 - mat.a01*mat.a10;
}

MV_INLINE mvBool_t mvInverse(const mvMat2d_t &mat, mvMat2d_t* result ) {
    mvDouble_t det = mvDeterminant(mat);
    if (mvAbs(det) < MV_MATH_EPSILON_D) {
        return MV_FALSE;
    }

    mvDouble_t iDet = 1.0 / det;

    result->a00 = mat.a11 * iDet;
    result->a01 = mat.a01 * iDet;
    result->a10 = mat.a10 * iDet;
    result->a11 = mat.a00 * iDet;

    return MV_TRUE;
}

MV_INLINE mvMat3f_t operator - (const mvMat3f_t &a) {
    return mvMat3f(-a.a00,-a.a01,-a.a02,
                   -a.a10,-a.a11,-a.a12,
                   -a.a20,-a.a21,-a.a22);
}

MV_INLINE mvMat3f_t operator + (const mvMat3f_t &a, const mvMat3f_t &b) {
    return mvMat3f(a.a00 + b.a00,a.a01 + b.a01,a.a02 + b.a02,
                   a.a10 + b.a10,a.a11 + b.a11,a.a12 + b.a12,
                   a.a20 + b.a20,a.a21 + b.a21,a.a22 + b.a22);
}

MV_INLINE mvMat3f_t operator - (const mvMat3f_t &a, const mvMat3f_t &b) {
    return mvMat3f(a.a00 - b.a00,a.a01 - b.a01,a.a02 - b.a02,
                   a.a10 - b.a10,a.a11 - b.a11,a.a12 - b.a12,
                   a.a20 - b.a20,a.a21 - b.a21,a.a22 - b.a22);
}

MV_INLINE mvVec3f_t operator * (const mvMat3f_t &mat, const mvVec3f_t &vec) {
    return mvVec3f(mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z,
                   mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z,
                   mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z);
}

MV_INLINE mvMat3f_t operator * (const mvMat3f_t &a, const mvMat3f_t &b) {
    return mvMat3f(a.a00*b.a00 + a.a01*b.a10 + a.a02*b.a20,
                   a.a00*b.a01 + a.a01*b.a11 + a.a02*b.a21,
                   a.a00*b.a02 + a.a01*b.a12 + a.a02*b.a22,

                   a.a10*b.a00 + a.a11*b.a10 + a.a12*b.a20,
                   a.a10*b.a01 + a.a11*b.a11 + a.a12*b.a21,
                   a.a10*b.a02 + a.a11*b.a12 + a.a12*b.a22,

                   a.a20*b.a00 + a.a21*b.a10 + a.a22*b.a20,
                   a.a20*b.a01 + a.a21*b.a11 + a.a22*b.a21,
                   a.a20*b.a02 + a.a21*b.a12 + a.a22*b.a22);
}

MV_INLINE mvMat3f_t operator * (const mvMat3f_t &mat, const mvFloat_t &m) {
    return mvMat3f(mat.a00*m, mat.a01*m, mat.a02*m,
                   mat.a10*m, mat.a11*m, mat.a12*m,
                   mat.a20*m, mat.a21*m, mat.a22*m);
}

MV_INLINE void mvZero(mvMat3f_t* result) {
    (*result) = mvMat3f(0.0f,0.0f,0.0f,
                        0.0f,0.0f,0.0f,
                        0.0f,0.0f,0.0f);
}

MV_INLINE void mvIdentity(mvMat3f_t* result) {
    (*result) = mvMat3f(1.0f,0.0f,0.0f,
                        0.0f,1.0f,0.0f,
                        0.0f,0.0f,1.0f);
}

MV_INLINE mvMat3f_t mvTranspose(const mvMat3f_t &mat) {
    return mvMat3f(mat.a00,mat.a10,mat.a20,
                   mat.a01,mat.a11,mat.a21,
                   mat.a02,mat.a12,mat.a22);
}

MV_INLINE mvFloat_t mvDeterminant(const mvMat3f_t &mat) {
    return mat.a00*mat.a11*mat.a22
         - mat.a00*mat.a12*mat.a21
         - mat.a01*mat.a10*mat.a22
         + mat.a01*mat.a12*mat.a20
         + mat.a02*mat.a10*mat.a21
         - mat.a02*mat.a11*mat.a20;
}

MV_INLINE mvBool_t mvInverse(const mvMat3f_t &mat, mvMat3f_t* result ) {
    mvFloat_t det = mvDeterminant(mat);
    if (mvAbs(det) < MV_MATH_EPSILON_F) {
        return MV_FALSE;
    }

    mvFloat_t iDet = 1.0f / det;

    result->mat[0] =  (mat.mat[4]*mat.mat[8] - mat.mat[5]*mat.mat[7]) * iDet;
    result->mat[1] = -(mat.mat[1]*mat.mat[8] - mat.mat[7]*mat.mat[2]) * iDet;
    result->mat[2] =  (mat.mat[1]*mat.mat[5] - mat.mat[4]*mat.mat[2]) * iDet;

    result->mat[3] = -(mat.mat[3]*mat.mat[8] - mat.mat[5]*mat.mat[6]) * iDet;
    result->mat[4] =  (mat.mat[0]*mat.mat[8] - mat.mat[6]*mat.mat[2]) * iDet;
    result->mat[5] = -(mat.mat[0]*mat.mat[5] - mat.mat[3]*mat.mat[2]) * iDet;

    result->mat[6] =  (mat.mat[3]*mat.mat[7] - mat.mat[6]*mat.mat[4]) * iDet;
    result->mat[7] = -(mat.mat[0]*mat.mat[7] - mat.mat[6]*mat.mat[1]) * iDet;
    result->mat[8] =  (mat.mat[0]*mat.mat[4] - mat.mat[1]*mat.mat[3]) * iDet;

    return MV_TRUE;
}

MV_INLINE mvMat3d_t operator - (const mvMat3d_t &a) {
    return mvMat3d(-a.a00,-a.a01,-a.a02,
                   -a.a10,-a.a11,-a.a12,
                   -a.a20,-a.a21,-a.a22);
}

MV_INLINE mvMat3d_t operator + (const mvMat3d_t &a, const mvMat3d_t &b) {
    return mvMat3d(a.a00 + b.a00,a.a01 + b.a01,a.a02 + b.a02,
                   a.a10 + b.a10,a.a11 + b.a11,a.a12 + b.a12,
                   a.a20 + b.a20,a.a21 + b.a21,a.a22 + b.a22);
}

MV_INLINE mvMat3d_t operator - (const mvMat3d_t &a, const mvMat3d_t &b) {
    return mvMat3d(a.a00 - b.a00,a.a01 - b.a01,a.a02 - b.a02,
                   a.a10 - b.a10,a.a11 - b.a11,a.a12 - b.a12,
                   a.a20 - b.a20,a.a21 - b.a21,a.a22 - b.a22);
}

MV_INLINE mvVec3d_t operator * (const mvMat3d_t &mat, const mvVec3d_t &vec) {
    return mvVec3d(mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z,
                   mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z,
                   mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z);
}

MV_INLINE mvMat3d_t operator * (const mvMat3d_t &a, const mvMat3d_t &b) {
    return mvMat3d(a.a00*b.a00 + a.a01*b.a10 + a.a02*b.a20,
                   a.a00*b.a01 + a.a01*b.a11 + a.a02*b.a21,
                   a.a00*b.a02 + a.a01*b.a12 + a.a02*b.a22,

                   a.a10*b.a00 + a.a11*b.a10 + a.a12*b.a20,
                   a.a10*b.a01 + a.a11*b.a11 + a.a12*b.a21,
                   a.a10*b.a02 + a.a11*b.a12 + a.a12*b.a22,

                   a.a20*b.a00 + a.a21*b.a10 + a.a22*b.a20,
                   a.a20*b.a01 + a.a21*b.a11 + a.a22*b.a21,
                   a.a20*b.a02 + a.a21*b.a12 + a.a22*b.a22);
}

MV_INLINE mvMat3d_t operator * (const mvMat3d_t &mat, const mvDouble_t &m) {
    return mvMat3d(mat.a00*m, mat.a01*m, mat.a02*m,
                   mat.a10*m, mat.a11*m, mat.a12*m,
                   mat.a20*m, mat.a21*m, mat.a22*m);
}

MV_INLINE void mvZero(mvMat3d_t* result) {
    (*result) = mvMat3d(0.0,0.0,0.0,
                        0.0,0.0,0.0,
                        0.0,0.0,0.0);
}

MV_INLINE void mvIdentity(mvMat3d_t* result) {
    (*result) = mvMat3d(1.0,0.0,0.0,
                        0.0,1.0,0.0,
                        0.0,0.0,1.0);
}

MV_INLINE mvMat3d_t mvTranspose(const mvMat3d_t &mat) {
    return mvMat3d(mat.a00,mat.a10,mat.a20,
                   mat.a01,mat.a11,mat.a21,
                   mat.a02,mat.a12,mat.a22);
}

MV_INLINE mvDouble_t mvDeterminant(const mvMat3d_t &mat) {
    return mat.a00*mat.a11*mat.a22
         - mat.a00*mat.a12*mat.a21
         - mat.a01*mat.a10*mat.a22
         + mat.a01*mat.a12*mat.a20
         + mat.a02*mat.a10*mat.a21
         - mat.a02*mat.a11*mat.a20;
}

MV_INLINE mvBool_t mvInverse(const mvMat3d_t &mat, mvMat3d_t* result ) {
    mvDouble_t det = mvDeterminant(mat);
    if (mvAbs(det) < MV_MATH_EPSILON_D) {
        return MV_FALSE;
    }

    mvDouble_t iDet = 1.0 / det;

    result->mat[0] =  (mat.mat[4]*mat.mat[8] - mat.mat[5]*mat.mat[7]) * iDet;
    result->mat[1] = -(mat.mat[1]*mat.mat[8] - mat.mat[7]*mat.mat[2]) * iDet;
    result->mat[2] =  (mat.mat[1]*mat.mat[5] - mat.mat[4]*mat.mat[2]) * iDet;

    result->mat[3] = -(mat.mat[3]*mat.mat[8] - mat.mat[5]*mat.mat[6]) * iDet;
    result->mat[4] =  (mat.mat[0]*mat.mat[8] - mat.mat[6]*mat.mat[2]) * iDet;
    result->mat[5] = -(mat.mat[0]*mat.mat[5] - mat.mat[3]*mat.mat[2]) * iDet;

    result->mat[6] =  (mat.mat[3]*mat.mat[7] - mat.mat[6]*mat.mat[4]) * iDet;
    result->mat[7] = -(mat.mat[0]*mat.mat[7] - mat.mat[6]*mat.mat[1]) * iDet;
    result->mat[8] =  (mat.mat[0]*mat.mat[4] - mat.mat[1]*mat.mat[3]) * iDet;

    return MV_TRUE;
}

MV_INLINE mvMat4f_t operator - (const mvMat4f_t &a) {
    return mvMat4f(-a.a00,-a.a01,-a.a02,-a.a03,
                   -a.a10,-a.a11,-a.a12,-a.a13,
                   -a.a20,-a.a21,-a.a22,-a.a23,
                   -a.a30,-a.a31,-a.a32,-a.a33);
}

MV_INLINE mvMat4f_t operator + (const mvMat4f_t &a, const mvMat4f_t &b) {
    return mvMat4f(a.a00 + b.a00,a.a01 + b.a01,a.a02 + b.a02,a.a03 + b.a03,
                   a.a10 + b.a10,a.a11 + b.a11,a.a12 + b.a12,a.a13 + b.a13,
                   a.a20 + b.a20,a.a21 + b.a21,a.a22 + b.a22,a.a23 + b.a23,
                   a.a30 + b.a30,a.a31 + b.a31,a.a32 + b.a32,a.a33 + b.a33);
}

MV_INLINE mvMat4f_t operator - (const mvMat4f_t &a, const mvMat4f_t &b) {
    return mvMat4f(a.a00 - b.a00,a.a01 - b.a01,a.a02 - b.a02,a.a03 - b.a03,
                   a.a10 - b.a10,a.a11 - b.a11,a.a12 - b.a12,a.a13 - b.a13,
                   a.a20 - b.a20,a.a21 - b.a21,a.a22 - b.a22,a.a23 - b.a23,
                   a.a30 - b.a30,a.a31 - b.a31,a.a32 - b.a32,a.a33 - b.a33);
}

MV_INLINE mvVec4f_t operator * (const mvMat4f_t &mat, const mvVec4f_t &vec) {
    return mvVec4f(mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z + mat.a03*vec.w,
                   mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z + mat.a13*vec.w,
                   mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z + mat.a23*vec.w,
                   mat.a30*vec.x + mat.a31*vec.y + mat.a32*vec.z + mat.a33*vec.w);
}

MV_INLINE mvVec3f_t operator * (const mvMat4f_t &mat, const mvVec3f_t &vec) {
    mvFloat_t f = mat.vec[3].x * vec.x + mat.vec[3].y * vec.y + mat.vec[3].z * vec.z + mat.vec[3].w;
    if (f == 0.0f) {
        return mvVec3f(0.0f,0.0f,0.0f);
    }
    if (f == 1.0f) {
        return mvVec3f(mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z + mat.a03,
                       mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z + mat.a13,
                       mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z + mat.a23);
    } else {
        mvFloat_t iF = 1.0f/f;
        return mvVec3f((mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z + mat.a03)*iF,
                       (mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z + mat.a13)*iF,
                       (mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z + mat.a23)*iF);
    }

}

MV_INLINE mvMat4f_t operator * (const mvMat4f_t &a, const mvMat4f_t &b) {
    return mvMat4f(a.a00*b.a00 + a.a01*b.a10 + a.a02*b.a20 + a.a03*b.a30,
                   a.a00*b.a01 + a.a01*b.a11 + a.a02*b.a21 + a.a03*b.a31,
                   a.a00*b.a02 + a.a01*b.a12 + a.a02*b.a22 + a.a03*b.a32,
                   a.a00*b.a03 + a.a01*b.a13 + a.a02*b.a23 + a.a03*b.a33,

                   a.a10*b.a00 + a.a11*b.a10 + a.a12*b.a20 + a.a13*b.a30,
                   a.a10*b.a01 + a.a11*b.a11 + a.a12*b.a21 + a.a13*b.a31,
                   a.a10*b.a02 + a.a11*b.a12 + a.a12*b.a22 + a.a13*b.a32,
                   a.a10*b.a03 + a.a11*b.a13 + a.a12*b.a23 + a.a13*b.a33,

                   a.a20*b.a00 + a.a21*b.a10 + a.a22*b.a20 + a.a23*b.a30,
                   a.a20*b.a01 + a.a21*b.a11 + a.a22*b.a21 + a.a23*b.a31,
                   a.a20*b.a02 + a.a21*b.a12 + a.a22*b.a22 + a.a23*b.a32,
                   a.a20*b.a03 + a.a21*b.a13 + a.a22*b.a23 + a.a23*b.a33,

                   a.a30*b.a00 + a.a31*b.a10 + a.a32*b.a20 + a.a33*b.a30,
                   a.a30*b.a01 + a.a31*b.a11 + a.a32*b.a21 + a.a33*b.a31,
                   a.a30*b.a02 + a.a31*b.a12 + a.a32*b.a22 + a.a33*b.a32,
                   a.a30*b.a03 + a.a31*b.a13 + a.a32*b.a23 + a.a33*b.a33);
}

MV_INLINE mvMat4f_t operator * (const mvMat4f_t &mat, const mvFloat_t &m) {
    return mvMat4f(mat.a00*m, mat.a01*m, mat.a02*m, mat.a03*m,
                   mat.a10*m, mat.a11*m, mat.a12*m, mat.a13*m,
                   mat.a20*m, mat.a21*m, mat.a22*m, mat.a23*m,
                   mat.a30*m, mat.a31*m, mat.a32*m, mat.a33*m);
}

MV_INLINE void mvZero(mvMat4f_t* result) {
    (*result) = mvMat4f(0.0f,0.0f,0.0f,0.0f,
                        0.0f,0.0f,0.0f,0.0f,
                        0.0f,0.0f,0.0f,0.0f,
                        0.0f,0.0f,0.0f,0.0f);
}

MV_INLINE void mvIdentity(mvMat4f_t* result) {
    (*result) = mvMat4f(1.0f,0.0f,0.0f,0.0f,
                        0.0f,1.0f,0.0f,0.0f,
                        0.0f,0.0f,1.0f,0.0f,
                        0.0f,0.0f,0.0f,1.0f);
}

MV_INLINE mvMat4f_t mvTranspose(const mvMat4f_t &mat) {
    return mvMat4f(mat.a00,mat.a10,mat.a20,mat.a30,
                   mat.a01,mat.a11,mat.a21,mat.a31,
                   mat.a02,mat.a12,mat.a22,mat.a32,
                   mat.a03,mat.a13,mat.a23,mat.a33);
}

//ID software (c)
MV_INLINE mvFloat_t mvDeterminant(const mvMat4f_t &mat) {
    mvFloat_t result;

    mvFloat_t d2_01_01, d2_01_02, d2_01_03, d2_01_12, d2_01_13, d2_01_23;
    d2_01_01 = mat.mat2[0][0] * mat.mat2[1][1] - mat.mat2[0][1] * mat.mat2[1][0];
    d2_01_02 = mat.mat2[0][0] * mat.mat2[1][2] - mat.mat2[0][2] * mat.mat2[1][0];
    d2_01_03 = mat.mat2[0][0] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][0];
    d2_01_12 = mat.mat2[0][1] * mat.mat2[1][2] - mat.mat2[0][2] * mat.mat2[1][1];
    d2_01_13 = mat.mat2[0][1] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][1];
    d2_01_23 = mat.mat2[0][2] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][2];

    mvFloat_t d3_201_012, d3_201_013, d3_201_023, d3_201_123;
    d3_201_012 = mat.mat2[2][0] * d2_01_12 - mat.mat2[2][1] * d2_01_02 + mat.mat2[2][2] * d2_01_01;
    d3_201_013 = mat.mat2[2][0] * d2_01_13 - mat.mat2[2][1] * d2_01_03 + mat.mat2[2][3] * d2_01_01;
    d3_201_023 = mat.mat2[2][0] * d2_01_23 - mat.mat2[2][2] * d2_01_03 + mat.mat2[2][3] * d2_01_02;
    d3_201_123 = mat.mat2[2][1] * d2_01_23 - mat.mat2[2][2] * d2_01_13 + mat.mat2[2][3] * d2_01_12;

  result = ( - d3_201_123 * mat.mat2[3][0] + d3_201_023 * mat.mat2[3][1] - d3_201_013 * mat.mat2[3][2] + d3_201_012 * mat.mat2[3][3] );

  return result;
}

//ID software (c)
MV_INLINE mvBool_t mvInverse(const mvMat4f_t &mat, mvMat4f_t* result ) {

    mvFloat_t d2_01_01, d2_01_02, d2_01_03, d2_01_12, d2_01_13, d2_01_23;
    d2_01_01 = mat.mat2[0][0] * mat.mat2[1][1] - mat.mat2[0][1] * mat.mat2[1][0];
    d2_01_02 = mat.mat2[0][0] * mat.mat2[1][2] - mat.mat2[0][2] * mat.mat2[1][0];
    d2_01_03 = mat.mat2[0][0] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][0];
    d2_01_12 = mat.mat2[0][1] * mat.mat2[1][2] - mat.mat2[0][2] * mat.mat2[1][1];
    d2_01_13 = mat.mat2[0][1] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][1];
    d2_01_23 = mat.mat2[0][2] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][2];

    mvFloat_t d3_201_012, d3_201_013, d3_201_023, d3_201_123;
    d3_201_012 = mat.mat2[2][0] * d2_01_12 - mat.mat2[2][1] * d2_01_02 + mat.mat2[2][2] * d2_01_01;
    d3_201_013 = mat.mat2[2][0] * d2_01_13 - mat.mat2[2][1] * d2_01_03 + mat.mat2[2][3] * d2_01_01;
    d3_201_023 = mat.mat2[2][0] * d2_01_23 - mat.mat2[2][2] * d2_01_03 + mat.mat2[2][3] * d2_01_02;
    d3_201_123 = mat.mat2[2][1] * d2_01_23 - mat.mat2[2][2] * d2_01_13 + mat.mat2[2][3] * d2_01_12;

    mvFloat_t det = ( - d3_201_123 * mat.mat2[3][0] + d3_201_023 * mat.mat2[3][1] - d3_201_013 * mat.mat2[3][2] + d3_201_012 * mat.mat2[3][3] );
    if (mvAbs(det) < MV_MATH_EPSILON_F) {
        return MV_FALSE;
    }

    mvFloat_t iDet = 1.0f / det;

    mvFloat_t d2_03_01, d2_03_02, d2_03_03, d2_03_12, d2_03_13, d2_03_23;
    d2_03_01 = mat.mat2[0][0] * mat.mat2[3][1] - mat.mat2[0][1] * mat.mat2[3][0];
    d2_03_02 = mat.mat2[0][0] * mat.mat2[3][2] - mat.mat2[0][2] * mat.mat2[3][0];
    d2_03_03 = mat.mat2[0][0] * mat.mat2[3][3] - mat.mat2[0][3] * mat.mat2[3][0];
    d2_03_12 = mat.mat2[0][1] * mat.mat2[3][2] - mat.mat2[0][2] * mat.mat2[3][1];
    d2_03_13 = mat.mat2[0][1] * mat.mat2[3][3] - mat.mat2[0][3] * mat.mat2[3][1];
    d2_03_23 = mat.mat2[0][2] * mat.mat2[3][3] - mat.mat2[0][3] * mat.mat2[3][2];

    mvFloat_t d2_13_01, d2_13_02, d2_13_03, d2_13_12, d2_13_13, d2_13_23;
    d2_13_01 = mat.mat2[1][0] * mat.mat2[3][1] - mat.mat2[1][1] * mat.mat2[3][0];
    d2_13_02 = mat.mat2[1][0] * mat.mat2[3][2] - mat.mat2[1][2] * mat.mat2[3][0];
    d2_13_03 = mat.mat2[1][0] * mat.mat2[3][3] - mat.mat2[1][3] * mat.mat2[3][0];
    d2_13_12 = mat.mat2[1][1] * mat.mat2[3][2] - mat.mat2[1][2] * mat.mat2[3][1];
    d2_13_13 = mat.mat2[1][1] * mat.mat2[3][3] - mat.mat2[1][3] * mat.mat2[3][1];
    d2_13_23 = mat.mat2[1][2] * mat.mat2[3][3] - mat.mat2[1][3] * mat.mat2[3][2];

    mvFloat_t d3_203_012, d3_203_013, d3_203_023, d3_203_123;
    d3_203_012 = mat.mat2[2][0] * d2_03_12 - mat.mat2[2][1] * d2_03_02 + mat.mat2[2][2] * d2_03_01;
    d3_203_013 = mat.mat2[2][0] * d2_03_13 - mat.mat2[2][1] * d2_03_03 + mat.mat2[2][3] * d2_03_01;
    d3_203_023 = mat.mat2[2][0] * d2_03_23 - mat.mat2[2][2] * d2_03_03 + mat.mat2[2][3] * d2_03_02;
    d3_203_123 = mat.mat2[2][1] * d2_03_23 - mat.mat2[2][2] * d2_03_13 + mat.mat2[2][3] * d2_03_12;

    mvFloat_t d3_213_012, d3_213_013, d3_213_023, d3_213_123;
    d3_213_012 = mat.mat2[2][0] * d2_13_12 - mat.mat2[2][1] * d2_13_02 + mat.mat2[2][2] * d2_13_01;
    d3_213_013 = mat.mat2[2][0] * d2_13_13 - mat.mat2[2][1] * d2_13_03 + mat.mat2[2][3] * d2_13_01;
    d3_213_023 = mat.mat2[2][0] * d2_13_23 - mat.mat2[2][2] * d2_13_03 + mat.mat2[2][3] * d2_13_02;
    d3_213_123 = mat.mat2[2][1] * d2_13_23 - mat.mat2[2][2] * d2_13_13 + mat.mat2[2][3] * d2_13_12;

    mvFloat_t d3_301_012, d3_301_013, d3_301_023, d3_301_123;
    d3_301_012 = mat.mat2[3][0] * d2_01_12 - mat.mat2[3][1] * d2_01_02 + mat.mat2[3][2] * d2_01_01;
    d3_301_013 = mat.mat2[3][0] * d2_01_13 - mat.mat2[3][1] * d2_01_03 + mat.mat2[3][3] * d2_01_01;
    d3_301_023 = mat.mat2[3][0] * d2_01_23 - mat.mat2[3][2] * d2_01_03 + mat.mat2[3][3] * d2_01_02;
    d3_301_123 = mat.mat2[3][1] * d2_01_23 - mat.mat2[3][2] * d2_01_13 + mat.mat2[3][3] * d2_01_12;

    result->mat2[0][0] = - d3_213_123 * iDet;
    result->mat2[1][0] = + d3_213_023 * iDet;
    result->mat2[2][0] = - d3_213_013 * iDet;
    result->mat2[3][0] = + d3_213_012 * iDet;

    result->mat2[0][1] = + d3_203_123 * iDet;
    result->mat2[1][1] = - d3_203_023 * iDet;
    result->mat2[2][1] = + d3_203_013 * iDet;
    result->mat2[3][1] = - d3_203_012 * iDet;

    result->mat2[0][2] = + d3_301_123 * iDet;
    result->mat2[1][2] = - d3_301_023 * iDet;
    result->mat2[2][2] = + d3_301_013 * iDet;
    result->mat2[3][2] = - d3_301_012 * iDet;

    result->mat2[0][3] = - d3_201_123 * iDet;
    result->mat2[1][3] = + d3_201_023 * iDet;
    result->mat2[2][3] = - d3_201_013 * iDet;
    result->mat2[3][3] = + d3_201_012 * iDet;

    return MV_TRUE;
}

MV_INLINE mvMat4d_t operator - (const mvMat4d_t &a) {
    return mvMat4d(-a.a00,-a.a01,-a.a02,-a.a03,
                   -a.a10,-a.a11,-a.a12,-a.a13,
                   -a.a20,-a.a21,-a.a22,-a.a23,
                   -a.a30,-a.a31,-a.a32,-a.a33);
}

MV_INLINE mvMat4d_t operator + (const mvMat4d_t &a, const mvMat4d_t &b) {
    return mvMat4d(a.a00 + b.a00,a.a01 + b.a01,a.a02 + b.a02,a.a03 + b.a03,
                   a.a10 + b.a10,a.a11 + b.a11,a.a12 + b.a12,a.a13 + b.a13,
                   a.a20 + b.a20,a.a21 + b.a21,a.a22 + b.a22,a.a23 + b.a23,
                   a.a30 + b.a30,a.a31 + b.a31,a.a32 + b.a32,a.a33 + b.a33);
}

MV_INLINE mvMat4d_t operator - (const mvMat4d_t &a, const mvMat4d_t &b) {
    return mvMat4d(a.a00 - b.a00,a.a01 - b.a01,a.a02 - b.a02,a.a03 - b.a03,
                   a.a10 - b.a10,a.a11 - b.a11,a.a12 - b.a12,a.a13 - b.a13,
                   a.a20 - b.a20,a.a21 - b.a21,a.a22 - b.a22,a.a23 - b.a23,
                   a.a30 - b.a30,a.a31 - b.a31,a.a32 - b.a32,a.a33 - b.a33);
}

MV_INLINE mvVec4d_t operator * (const mvMat4d_t &mat, const mvVec4d_t &vec) {
    return mvVec4d(mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z + mat.a03*vec.w,
                   mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z + mat.a13*vec.w,
                   mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z + mat.a23*vec.w,
                   mat.a30*vec.x + mat.a31*vec.y + mat.a32*vec.z + mat.a33*vec.w);
}

MV_INLINE mvVec3d_t operator * (const mvMat4d_t &mat, const mvVec3d_t &vec) {
    mvDouble_t f = mat.vec[3].x * vec.x + mat.vec[3].y * vec.y + mat.vec[3].z * vec.z + mat.vec[3].w;
    if (f == 0.0) {
        return mvVec3d(0.0,0.0, 0.0);
    }
    if (f == 1.0) {
        return mvVec3d(mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z + mat.a03,
                       mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z + mat.a13,
                       mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z + mat.a23);
    } else {
        mvFloat_t iF = 1.0/f;
        return mvVec3d((mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z + mat.a03)*iF,
                       (mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z + mat.a13)*iF,
                       (mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z + mat.a23)*iF);
    }

}

MV_INLINE mvMat4d_t operator * (const mvMat4d_t &a, const mvMat4d_t &b) {
    return mvMat4d(a.a00*b.a00 + a.a01*b.a10 + a.a02*b.a20 + a.a03*b.a30,
                   a.a00*b.a01 + a.a01*b.a11 + a.a02*b.a21 + a.a03*b.a31,
                   a.a00*b.a02 + a.a01*b.a12 + a.a02*b.a22 + a.a03*b.a32,
                   a.a00*b.a03 + a.a01*b.a13 + a.a02*b.a23 + a.a03*b.a33,

                   a.a10*b.a00 + a.a11*b.a10 + a.a12*b.a20 + a.a13*b.a30,
                   a.a10*b.a01 + a.a11*b.a11 + a.a12*b.a21 + a.a13*b.a31,
                   a.a10*b.a02 + a.a11*b.a12 + a.a12*b.a22 + a.a13*b.a32,
                   a.a10*b.a03 + a.a11*b.a13 + a.a12*b.a23 + a.a13*b.a33,

                   a.a20*b.a00 + a.a21*b.a10 + a.a22*b.a20 + a.a23*b.a30,
                   a.a20*b.a01 + a.a21*b.a11 + a.a22*b.a21 + a.a23*b.a31,
                   a.a20*b.a02 + a.a21*b.a12 + a.a22*b.a22 + a.a23*b.a32,
                   a.a20*b.a03 + a.a21*b.a13 + a.a22*b.a23 + a.a23*b.a33,

                   a.a30*b.a00 + a.a31*b.a10 + a.a32*b.a20 + a.a33*b.a30,
                   a.a30*b.a01 + a.a31*b.a11 + a.a32*b.a21 + a.a33*b.a31,
                   a.a30*b.a02 + a.a31*b.a12 + a.a32*b.a22 + a.a33*b.a32,
                   a.a30*b.a03 + a.a31*b.a13 + a.a32*b.a23 + a.a33*b.a33);
}

MV_INLINE mvMat4d_t operator * (const mvMat4d_t &mat, const mvDouble_t &m) {
    return mvMat4d(mat.a00*m, mat.a01*m, mat.a02*m, mat.a03*m,
                   mat.a10*m, mat.a11*m, mat.a12*m, mat.a13*m,
                   mat.a20*m, mat.a21*m, mat.a22*m, mat.a23*m,
                   mat.a30*m, mat.a31*m, mat.a32*m, mat.a33*m);
}

MV_INLINE void mvZero(mvMat4d_t* result) {
    (*result) = mvMat4d(0.0,0.0,0.0,0.0,
                        0.0,0.0,0.0,0.0,
                        0.0,0.0,0.0,0.0,
                        0.0,0.0,0.0,0.0);
}

MV_INLINE void mvIdentity(mvMat4d_t* result) {
    (*result) = mvMat4d(1.0,0.0,0.0,0.0,
                        0.0,1.0,0.0,0.0,
                        0.0,0.0,1.0,0.0,
                        0.0,0.0,0.0,1.0);
}

MV_INLINE mvMat4d_t mvTranspose(const mvMat4d_t &mat) {
    return mvMat4d(mat.a00,mat.a10,mat.a20,mat.a30,
                   mat.a01,mat.a11,mat.a21,mat.a31,
                   mat.a02,mat.a12,mat.a22,mat.a32,
                   mat.a03,mat.a13,mat.a23,mat.a33);
}

//ID software (c)
MV_INLINE mvDouble_t mvDeterminant(const mvMat4d_t &mat) {
    mvDouble_t result;

    mvDouble_t d2_01_01, d2_01_02, d2_01_03, d2_01_12, d2_01_13, d2_01_23;
    d2_01_01 = mat.mat2[0][0] * mat.mat2[1][1] - mat.mat2[0][1] * mat.mat2[1][0];
    d2_01_02 = mat.mat2[0][0] * mat.mat2[1][2] - mat.mat2[0][2] * mat.mat2[1][0];
    d2_01_03 = mat.mat2[0][0] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][0];
    d2_01_12 = mat.mat2[0][1] * mat.mat2[1][2] - mat.mat2[0][2] * mat.mat2[1][1];
    d2_01_13 = mat.mat2[0][1] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][1];
    d2_01_23 = mat.mat2[0][2] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][2];

    mvDouble_t d3_201_012, d3_201_013, d3_201_023, d3_201_123;
    d3_201_012 = mat.mat2[2][0] * d2_01_12 - mat.mat2[2][1] * d2_01_02 + mat.mat2[2][2] * d2_01_01;
    d3_201_013 = mat.mat2[2][0] * d2_01_13 - mat.mat2[2][1] * d2_01_03 + mat.mat2[2][3] * d2_01_01;
    d3_201_023 = mat.mat2[2][0] * d2_01_23 - mat.mat2[2][2] * d2_01_03 + mat.mat2[2][3] * d2_01_02;
    d3_201_123 = mat.mat2[2][1] * d2_01_23 - mat.mat2[2][2] * d2_01_13 + mat.mat2[2][3] * d2_01_12;

  result = ( - d3_201_123 * mat.mat2[3][0] + d3_201_023 * mat.mat2[3][1] - d3_201_013 * mat.mat2[3][2] + d3_201_012 * mat.mat2[3][3] );

  return result;
}

//ID software (c)
MV_INLINE mvBool_t mvInverse(const mvMat4d_t &mat, mvMat4d_t* result ) {

    mvDouble_t d2_01_01, d2_01_02, d2_01_03, d2_01_12, d2_01_13, d2_01_23;
    d2_01_01 = mat.mat2[0][0] * mat.mat2[1][1] - mat.mat2[0][1] * mat.mat2[1][0];
    d2_01_02 = mat.mat2[0][0] * mat.mat2[1][2] - mat.mat2[0][2] * mat.mat2[1][0];
    d2_01_03 = mat.mat2[0][0] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][0];
    d2_01_12 = mat.mat2[0][1] * mat.mat2[1][2] - mat.mat2[0][2] * mat.mat2[1][1];
    d2_01_13 = mat.mat2[0][1] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][1];
    d2_01_23 = mat.mat2[0][2] * mat.mat2[1][3] - mat.mat2[0][3] * mat.mat2[1][2];

    mvDouble_t d3_201_012, d3_201_013, d3_201_023, d3_201_123;
    d3_201_012 = mat.mat2[2][0] * d2_01_12 - mat.mat2[2][1] * d2_01_02 + mat.mat2[2][2] * d2_01_01;
    d3_201_013 = mat.mat2[2][0] * d2_01_13 - mat.mat2[2][1] * d2_01_03 + mat.mat2[2][3] * d2_01_01;
    d3_201_023 = mat.mat2[2][0] * d2_01_23 - mat.mat2[2][2] * d2_01_03 + mat.mat2[2][3] * d2_01_02;
    d3_201_123 = mat.mat2[2][1] * d2_01_23 - mat.mat2[2][2] * d2_01_13 + mat.mat2[2][3] * d2_01_12;

    mvDouble_t det = ( - d3_201_123 * mat.mat2[3][0] + d3_201_023 * mat.mat2[3][1] - d3_201_013 * mat.mat2[3][2] + d3_201_012 * mat.mat2[3][3] );
    if (mvAbs(det) < MV_MATH_EPSILON_F) {
        return MV_FALSE;
    }

    mvDouble_t iDet = 1.0f / det;

    mvDouble_t d2_03_01, d2_03_02, d2_03_03, d2_03_12, d2_03_13, d2_03_23;
    d2_03_01 = mat.mat2[0][0] * mat.mat2[3][1] - mat.mat2[0][1] * mat.mat2[3][0];
    d2_03_02 = mat.mat2[0][0] * mat.mat2[3][2] - mat.mat2[0][2] * mat.mat2[3][0];
    d2_03_03 = mat.mat2[0][0] * mat.mat2[3][3] - mat.mat2[0][3] * mat.mat2[3][0];
    d2_03_12 = mat.mat2[0][1] * mat.mat2[3][2] - mat.mat2[0][2] * mat.mat2[3][1];
    d2_03_13 = mat.mat2[0][1] * mat.mat2[3][3] - mat.mat2[0][3] * mat.mat2[3][1];
    d2_03_23 = mat.mat2[0][2] * mat.mat2[3][3] - mat.mat2[0][3] * mat.mat2[3][2];

    mvDouble_t d2_13_01, d2_13_02, d2_13_03, d2_13_12, d2_13_13, d2_13_23;
    d2_13_01 = mat.mat2[1][0] * mat.mat2[3][1] - mat.mat2[1][1] * mat.mat2[3][0];
    d2_13_02 = mat.mat2[1][0] * mat.mat2[3][2] - mat.mat2[1][2] * mat.mat2[3][0];
    d2_13_03 = mat.mat2[1][0] * mat.mat2[3][3] - mat.mat2[1][3] * mat.mat2[3][0];
    d2_13_12 = mat.mat2[1][1] * mat.mat2[3][2] - mat.mat2[1][2] * mat.mat2[3][1];
    d2_13_13 = mat.mat2[1][1] * mat.mat2[3][3] - mat.mat2[1][3] * mat.mat2[3][1];
    d2_13_23 = mat.mat2[1][2] * mat.mat2[3][3] - mat.mat2[1][3] * mat.mat2[3][2];

    mvDouble_t d3_203_012, d3_203_013, d3_203_023, d3_203_123;
    d3_203_012 = mat.mat2[2][0] * d2_03_12 - mat.mat2[2][1] * d2_03_02 + mat.mat2[2][2] * d2_03_01;
    d3_203_013 = mat.mat2[2][0] * d2_03_13 - mat.mat2[2][1] * d2_03_03 + mat.mat2[2][3] * d2_03_01;
    d3_203_023 = mat.mat2[2][0] * d2_03_23 - mat.mat2[2][2] * d2_03_03 + mat.mat2[2][3] * d2_03_02;
    d3_203_123 = mat.mat2[2][1] * d2_03_23 - mat.mat2[2][2] * d2_03_13 + mat.mat2[2][3] * d2_03_12;

    mvDouble_t d3_213_012, d3_213_013, d3_213_023, d3_213_123;
    d3_213_012 = mat.mat2[2][0] * d2_13_12 - mat.mat2[2][1] * d2_13_02 + mat.mat2[2][2] * d2_13_01;
    d3_213_013 = mat.mat2[2][0] * d2_13_13 - mat.mat2[2][1] * d2_13_03 + mat.mat2[2][3] * d2_13_01;
    d3_213_023 = mat.mat2[2][0] * d2_13_23 - mat.mat2[2][2] * d2_13_03 + mat.mat2[2][3] * d2_13_02;
    d3_213_123 = mat.mat2[2][1] * d2_13_23 - mat.mat2[2][2] * d2_13_13 + mat.mat2[2][3] * d2_13_12;

    mvDouble_t d3_301_012, d3_301_013, d3_301_023, d3_301_123;
    d3_301_012 = mat.mat2[3][0] * d2_01_12 - mat.mat2[3][1] * d2_01_02 + mat.mat2[3][2] * d2_01_01;
    d3_301_013 = mat.mat2[3][0] * d2_01_13 - mat.mat2[3][1] * d2_01_03 + mat.mat2[3][3] * d2_01_01;
    d3_301_023 = mat.mat2[3][0] * d2_01_23 - mat.mat2[3][2] * d2_01_03 + mat.mat2[3][3] * d2_01_02;
    d3_301_123 = mat.mat2[3][1] * d2_01_23 - mat.mat2[3][2] * d2_01_13 + mat.mat2[3][3] * d2_01_12;

    result->mat2[0][0] = - d3_213_123 * iDet;
    result->mat2[1][0] = + d3_213_023 * iDet;
    result->mat2[2][0] = - d3_213_013 * iDet;
    result->mat2[3][0] = + d3_213_012 * iDet;

    result->mat2[0][1] = + d3_203_123 * iDet;
    result->mat2[1][1] = - d3_203_023 * iDet;
    result->mat2[2][1] = + d3_203_013 * iDet;
    result->mat2[3][1] = - d3_203_012 * iDet;

    result->mat2[0][2] = + d3_301_123 * iDet;
    result->mat2[1][2] = - d3_301_023 * iDet;
    result->mat2[2][2] = + d3_301_013 * iDet;
    result->mat2[3][2] = - d3_301_012 * iDet;

    result->mat2[0][3] = - d3_201_123 * iDet;
    result->mat2[1][3] = + d3_201_023 * iDet;
    result->mat2[2][3] = - d3_201_013 * iDet;
    result->mat2[3][3] = + d3_201_012 * iDet;

    return MV_TRUE;
}

MV_INLINE mvMat4f_t mvOrthogonalProjection(const mvFloat_t left, const mvFloat_t right,
                                           const mvFloat_t bottom, const mvFloat_t top,
                                           const mvFloat_t near, const mvFloat_t far) {
    mvMat4f_t result;
    mvIdentity(&result);
    mvFloat_t rl(right - left), tb(top - bottom), fn(far - near);
    result.a00 = 2.0f / rl;
    result.a11 = 2.0f / tb;
    result.a22 = - 2.0f / fn;

    result.a03 = - (right + left) / rl;
    result.a13 = - (top + bottom) / tb;
    result.a23 = - (far + near) / fn;
    return result;
}

MV_INLINE mvMat4d_t mvOrthogonalProjection(const mvDouble_t left, const mvDouble_t right,
                                           const mvDouble_t bottom, const mvDouble_t top,
                                           const mvDouble_t near, const mvDouble_t far) {
    mvMat4d_t result;
    mvIdentity(&result);
    mvDouble_t rl(right - left), tb(top - bottom), fn(far - near);
    result.a00 = 2.0 / rl;
    result.a11 = 2.0 / tb;
    result.a22 = - 2.0 / fn;

    result.a03 = - (right + left) / rl;
    result.a13 = - (top + bottom) / tb;
    result.a23 = - (far + near) / fn;
    return result;
}

MV_INLINE mvMat4f_t mvPerspectiveProjection(const mvFloat_t fovy, const mvFloat_t aspect,
                                            const mvFloat_t near, const mvFloat_t far) {
    mvMat4f_t result;

    mvZero(&result);

    mvFloat_t f(1.0f/tanf(fovy/2.0f));
    mvFloat_t nf(near - far);


    result.a00 = f/aspect;
    result.a11 = f;
    result.a22 = (far + near)/nf;
    result.a23 = 2.0f*far*near/nf;
    result.a33 = -1.0f;


    return result;
}

MV_INLINE mvMat4d_t mvPerspectiveProjection(const mvDouble_t fovy, const mvDouble_t aspect,
                                            const mvDouble_t near, const mvDouble_t far) {
    mvMat4d_t result;

    mvZero(&result);

    mvDouble_t f(1.0/tanf(fovy/2.0));
    mvDouble_t nf(near - far);


    result.a00 = f/aspect;
    result.a11 = f;
    result.a22 = (far + near)/nf;
    result.a23 = 2.0*far*near/nf;
    result.a33 = -1.0;


    return result;
}

MV_INLINE mvMat4f_t mvTranslationMatrix(const mvFloat_t x, const mvFloat_t y, const mvFloat_t z) {
    mvMat4f_t result;
    mvIdentity(&result);
    result.a03 = x;
    result.a13 = y;
    result.a23 = z;
    return result;
}

MV_INLINE mvMat4d_t mvTranslationMatrix(const mvDouble_t x, const mvDouble_t y, const mvDouble_t z) {
    mvMat4d_t result;
    mvIdentity(&result);
    result.a03 = x;
    result.a13 = y;
    result.a23 = z;
    return result;
}

MV_INLINE void mvTranslate(mvMat4f_t &mat, const mvFloat_t x, const mvFloat_t y, const mvFloat_t z) {
    mat = mat * mvTranslationMatrix(x,y,z);
    return;
}

MV_INLINE void mvTranslate(mvMat4d_t &mat, const mvDouble_t x, const mvDouble_t y, const mvDouble_t z) {
    mat = mat * mvTranslationMatrix(x,y,z);
    return;
}

MV_INLINE mvMat3f_t mvRotationMatrix3f(const mvFloat_t angle, const mvFloat_t x, const mvFloat_t y, const mvFloat_t z) {
    mvMat3f_t result;
    mvVec3f_t u = mvNormalize(mvVec3f(x,y,z));
    mvFloat_t angle_rad(angle*MV_PI_F/180),
              cos_angle(cosf(angle_rad)),
              sin_angle(sinf(angle_rad)),
              one_minus_cos_angle(1.0f-cos_angle),
              uxuy(u.x*u.y),
              uxuz(u.x*u.z),
              uyuz(u.y*u.z),
              uxsin_angle(u.x*sin_angle),
              uysin_angle(u.y*sin_angle),
              uzsin_angle(u.z*sin_angle),
              uxuyone_minus_cos_angle(uxuy*one_minus_cos_angle),
              uxuzone_minus_cos_angle(uxuz*one_minus_cos_angle),
              uyuzone_minus_cos_angle(uyuz*one_minus_cos_angle);

    result.a00 = cos_angle + u.x*u.x*one_minus_cos_angle;
    result.a01 = uxuyone_minus_cos_angle - uzsin_angle;
    result.a02 = uxuzone_minus_cos_angle + uysin_angle;

    result.a10 = uxuyone_minus_cos_angle + uzsin_angle;
    result.a11 = cos_angle + u.y*u.y*one_minus_cos_angle;
    result.a12 = uyuzone_minus_cos_angle - uxsin_angle;

    result.a20 = uxuzone_minus_cos_angle - uysin_angle;
    result.a21 = uyuzone_minus_cos_angle + uxsin_angle;
    result.a22 = cos_angle + u.z*u.z*one_minus_cos_angle;

    return result;
}

MV_INLINE mvMat3d_t mvRotationMatrix3d(const mvDouble_t angle, const mvDouble_t x, const mvDouble_t y, const mvDouble_t z) {
    mvMat3d_t result;
    mvVec3d_t u = mvNormalize(mvVec3d(x,y,z));
    mvDouble_t angle_rad(angle*MV_PI_D/180),
               cos_angle(cos(angle_rad)),
               sin_angle(sin(angle_rad)),
               one_minus_cos_angle(1.0-cos_angle),
               uxuy(u.x*u.y),
               uxuz(u.x*u.z),
               uyuz(u.y*u.z),
               uxsin_angle(u.x*sin_angle),
               uysin_angle(u.y*sin_angle),
               uzsin_angle(u.z*sin_angle),
               uxuyone_minus_cos_angle(uxuy*one_minus_cos_angle),
               uxuzone_minus_cos_angle(uxuz*one_minus_cos_angle),
               uyuzone_minus_cos_angle(uyuz*one_minus_cos_angle);

    result.a00 = cos_angle + u.x*u.x*one_minus_cos_angle;
    result.a01 = uxuyone_minus_cos_angle - uzsin_angle;
    result.a02 = uxuzone_minus_cos_angle + uysin_angle;

    result.a10 = uxuyone_minus_cos_angle + uzsin_angle;
    result.a11 = cos_angle + u.y*u.y*one_minus_cos_angle;
    result.a12 = uyuzone_minus_cos_angle - uxsin_angle;

    result.a20 = uxuzone_minus_cos_angle - uysin_angle;
    result.a21 = uyuzone_minus_cos_angle + uxsin_angle;
    result.a22 = cos_angle + u.z*u.z*one_minus_cos_angle;

    return result;
}

MV_INLINE mvMat4f_t mvRotationMatrix4f(const mvFloat_t angle, const mvFloat_t x, const mvFloat_t y, const mvFloat_t z) {
    mvMat4f_t result;
    mvVec3f_t u = mvNormalize(mvVec3f(x,y,z));
    mvFloat_t angle_rad(angle*MV_PI_F/180),
              cos_angle(cosf(angle_rad)),
              sin_angle(sinf(angle_rad)),
              one_minus_cos_angle(1.0f-cos_angle),
              uxuy(u.x*u.y),
              uxuz(u.x*u.z),
              uyuz(u.y*u.z),
              uxsin_angle(u.x*sin_angle),
              uysin_angle(u.y*sin_angle),
              uzsin_angle(u.z*sin_angle),
              uxuyone_minus_cos_angle(uxuy*one_minus_cos_angle),
              uxuzone_minus_cos_angle(uxuz*one_minus_cos_angle),
              uyuzone_minus_cos_angle(uyuz*one_minus_cos_angle);

    result.a00 = cos_angle + u.x*u.x*one_minus_cos_angle;
    result.a01 = uxuyone_minus_cos_angle - uzsin_angle;
    result.a02 = uxuzone_minus_cos_angle + uysin_angle;
    result.a03 = 0.0f;

    result.a10 = uxuyone_minus_cos_angle + uzsin_angle;
    result.a11 = cos_angle + u.y*u.y*one_minus_cos_angle;
    result.a12 = uyuzone_minus_cos_angle - uxsin_angle;
    result.a13 = 0.0f;

    result.a20 = uxuzone_minus_cos_angle - uysin_angle;
    result.a21 = uyuzone_minus_cos_angle + uxsin_angle;
    result.a22 = cos_angle + u.z*u.z*one_minus_cos_angle;
    result.a23 = 0.0f;

    result.a30 = 0.0f;
    result.a31 = 0.0f;
    result.a32 = 0.0f;
    result.a33 = 1.0f;

    return result;
}

MV_INLINE mvMat4d_t mvRotationMatrix4d(const mvDouble_t angle, const mvDouble_t x, const mvDouble_t y, const mvDouble_t z) {
    mvMat4d_t result;
    mvVec3d_t u = mvNormalize(mvVec3d(x,y,z));
    mvDouble_t angle_rad(angle*MV_PI_D/180),
               cos_angle(cos(angle_rad)),
               sin_angle(sin(angle_rad)),
               one_minus_cos_angle(1.0-cos_angle),
               uxuy(u.x*u.y),
               uxuz(u.x*u.z),
               uyuz(u.y*u.z),
               uxsin_angle(u.x*sin_angle),
               uysin_angle(u.y*sin_angle),
               uzsin_angle(u.z*sin_angle),
               uxuyone_minus_cos_angle(uxuy*one_minus_cos_angle),
               uxuzone_minus_cos_angle(uxuz*one_minus_cos_angle),
               uyuzone_minus_cos_angle(uyuz*one_minus_cos_angle);

    result.a00 = cos_angle + u.x*u.x*one_minus_cos_angle;
    result.a01 = uxuyone_minus_cos_angle - uzsin_angle;
    result.a02 = uxuzone_minus_cos_angle + uysin_angle;
    result.a03 = 0.0;

    result.a10 = uxuyone_minus_cos_angle + uzsin_angle;
    result.a11 = cos_angle + u.y*u.y*one_minus_cos_angle;
    result.a12 = uyuzone_minus_cos_angle - uxsin_angle;
    result.a13 = 0.0;

    result.a20 = uxuzone_minus_cos_angle - uysin_angle;
    result.a21 = uyuzone_minus_cos_angle + uxsin_angle;
    result.a22 = cos_angle + u.z*u.z*one_minus_cos_angle;
    result.a23 = 0.0;

    result.a30 = 0.0;
    result.a31 = 0.0;
    result.a32 = 0.0;
    result.a33 = 1.0;

    return result;
}

MV_INLINE void mvRotate(mvMat3f_t &mat, const mvFloat_t angle, const mvFloat_t x, const mvFloat_t y, const mvFloat_t z) {
    mat = mat * mvRotationMatrix3f(angle,x,y,z);
    return;
}

MV_INLINE void mvRotate(mvMat3d_t &mat, const mvDouble_t angle, const mvDouble_t x, const mvDouble_t y, const mvDouble_t z) {
    mat = mat * mvRotationMatrix3d(angle,x,y,z);
    return;
}

MV_INLINE void mvRotate(mvMat4f_t &mat, const mvFloat_t angle, const mvFloat_t x, const mvFloat_t y, const mvFloat_t z) {
    mat = mat * mvRotationMatrix4f(angle,x,y,z);
    return;
}

MV_INLINE void mvRotate(mvMat4d_t &mat, const mvDouble_t angle, const mvDouble_t x, const mvDouble_t y, const mvDouble_t z) {
    mat = mat * mvRotationMatrix4d(angle,x,y,z);
    return;
}

MV_INLINE mvMat4f_t mvLookAt(const mvFloat_t eyeX, const mvFloat_t eyeY, const mvFloat_t eyeZ,
                             const mvFloat_t centerX, const mvFloat_t centerY, const mvFloat_t centerZ,
                             const mvFloat_t upX, const mvFloat_t upY, const mvFloat_t upZ) {
    mvMat4f_t result;

    mvVec3f_t u(mvVec3f(upX,upY,upZ)),
              f(mvNormalize(mvVec3f(centerX,centerY,centerZ)-mvVec3f(eyeX,eyeY,eyeZ))),
              s(mvNormalize(mvCross(f,u)));

    u = mvNormalize(mvCross(f,s));

    result.a00 =  s.x; result.a01 =  s.y; result.a02 = s.z;  result.a03 = 0.0f;
    result.a10 =  u.x; result.a11 =  u.y; result.a12 = u.z;  result.a13 = 0.0f;
    result.a20 = -f.x; result.a21 = -f.y; result.a22 = -f.z; result.a23 = 0.0f;
    result.a30 = 0.0f; result.a31 = 0.0f; result.a32 = 0.0f; result.a33 = 1.0f;

    mvTranslate(result,-eyeX,-eyeY,-eyeZ);
    return result;
}

MV_INLINE mvMat4d_t mvLookAt(const mvDouble_t eyeX, const mvDouble_t eyeY, const mvDouble_t eyeZ,
                             const mvDouble_t centerX, const mvDouble_t centerY, const mvDouble_t centerZ,
                             const mvDouble_t upX, const mvDouble_t upY, const mvDouble_t upZ) {
    mvMat4d_t result;

    mvVec3d_t u(mvVec3d(upX,upY,upZ)),
              f(mvNormalize(mvVec3d(centerX,centerY,centerZ)-mvVec3d(eyeX,eyeY,eyeZ))),
              s(mvNormalize(mvCross(f,u)));

    u = mvNormalize(mvCross(f,s));

    result.a00 =  s.x; result.a01 =  s.y; result.a02 = s.z;  result.a03 = 0.0f;
    result.a10 =  u.x; result.a11 =  u.y; result.a12 = u.z;  result.a13 = 0.0f;
    result.a20 = -f.x; result.a21 = -f.y; result.a22 = -f.z; result.a23 = 0.0f;
    result.a30 = 0.0f; result.a31 = 0.0f; result.a32 = 0.0f; result.a33 = 1.0f;

    mvTranslate(result,-eyeX,-eyeY,-eyeZ);
    return result;
}

template <typename T>
MV_INLINE void mvMinMax(const T &a, const T &b, T &min, T &max) {
    if (a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    }
}

template <typename T>
MV_INLINE T mvMin(const T &a, const T &b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

template <typename T>
MV_INLINE T mvMax(const T &a, const T &b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

MV_INLINE mvUInt32_t mvFloor4(const mvUInt32_t &value) {
    return ((value>>2)<<2);
}

MV_INLINE mvUInt32_t mvCeil4(const mvUInt32_t &value) {
    return (((value+3)>>2)<<2);
}

template <typename T>
MV_INLINE T mvClamp(const T &value, const T &min, const T &max) {
    if (value<min) return min;
    if (value>max) return max;
    return value;
}
template <typename T>
MV_INLINE T mvLerp(const T &v0, const T &v1, const mvFloat_t t) {
    return (1.0 - t)*v0 + t*v1;
}

MV_INLINE mvFloat_t mvSplineInterpolation(const mvFloat_t v0, const mvFloat_t v1, const mvFloat_t v2, const mvFloat_t v3, const mvFloat_t t) {
    const mvFloat_t a((v1 - v2)*1.5f + (v3 - v0)*0.5f);
    const mvFloat_t b(v0 - v1*2.5f + v2*2.0f - v3*0.5f);
    const mvFloat_t c((v2 - v0)*0.5f);
    const mvFloat_t d(v1);
    return (((a*t + b)*t) + c)*t + d;
}
#endif // _MV_MATH_H_
