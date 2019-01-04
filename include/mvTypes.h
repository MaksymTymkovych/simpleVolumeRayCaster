#ifndef _MV_TYPES_H_
#define _MV_TYPES_H_

typedef void* mvPointer_t;

#define MV_FALSE 0
#define MV_TRUE 1

typedef unsigned char mvBool_t;

typedef enum mvType_t {
    MV_TYPE_NONE    = 0,
    MV_TYPE_BOOL    = 1,
    MV_TYPE_UINT8   = 2,
    MV_TYPE_SINT8   = 3,
    MV_TYPE_UINT16  = 4,
    MV_TYPE_SINT16  = 5,
    MV_TYPE_UINT32  = 6,
    MV_TYPE_SINT32  = 7,
    MV_TYPE_FLOAT   = 8,
    MV_TYPE_DOUBLE  = 9,

    MV_TYPE_DEATH   = 0xFFFFFFFF
} mvType_t;

typedef enum mvStatus_t {
    MV_STATUS_NO_ERROR = 0,
    MV_STATUS_UNSUPPORTED_IMAGE = 1,
    MV_STATUS_FILE_OPENING_ERROR = 2,

    MV_STATUS_DEATH         = 0xFFFFFFFF
} mvStatus_t;

typedef unsigned char mvUInt8_t;
typedef signed char mvSInt8_t;
typedef unsigned short mvUInt16_t;
typedef signed short mvSInt16_t;
typedef unsigned int mvUInt32_t;
typedef signed int mvSInt32_t;
typedef float mvFloat_t;
typedef double mvDouble_t;

typedef size_t mvSize_t;


typedef struct mvSize2_t {
    mvSize_t width;
    mvSize_t height;
} mvSize2_t;


MV_INLINE mvSize2_t mvSize2(const mvSize_t width, const mvSize_t height) {
    mvSize2_t result;
    result.width = width;
    result.height = height;
    return result;
}

typedef struct mvSize3_t {
    mvSize_t width;
    mvSize_t height;
    mvSize_t depth;
} mvSize3_t;


MV_INLINE mvSize3_t mvSize3(const mvSize_t width, const mvSize_t height, const mvSize_t depth) {
    mvSize3_t result;
    result.width = width;
    result.height = height;
    result.depth = depth;
    return result;
}

typedef struct mvPoint2_t {
    mvSInt32_t x;
    mvSInt32_t y;
} mvPoint2_t;

MV_INLINE mvPoint2_t mvPoint2(const mvSInt32_t x, const mvSInt32_t y) {
    mvPoint2_t result;
    result.x = x;
    result.y = y;
    return result;
}

typedef struct mvPoint3_t {
    mvSInt32_t x;
    mvSInt32_t y;
    mvSInt32_t z;
} mvPoint3_t;

MV_INLINE mvPoint3_t mvPoint3(const mvSInt32_t x, const mvSInt32_t y, const mvSInt32_t z) {
    mvPoint3_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

typedef struct mvPoint2f_t {
    mvFloat_t x;
    mvFloat_t y;
} mvPoint2f_t;

MV_INLINE mvPoint2f_t mvPoint2f(const mvFloat_t x, const mvFloat_t y) {
    mvPoint2f_t result;
    result.x = x;
    result.y = y;
    return result;
}

typedef struct mvPoint3f_t {
    mvFloat_t x;
    mvFloat_t y;
    mvFloat_t z;
} mvPoint3f_t;

MV_INLINE mvPoint3f_t mvPoint3f(const mvFloat_t x, const mvFloat_t y, const mvFloat_t z) {
    mvPoint3f_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

typedef struct mvPoint2d_t {
    mvDouble_t x;
    mvDouble_t y;
} mvPoint2d_t;

MV_INLINE mvPoint2d_t mvPoint2f(const mvDouble_t x, const mvDouble_t y) {
    mvPoint2d_t result;
    result.x = x;
    result.y = y;
    return result;
}

typedef struct mvPoint3d_t {
    mvDouble_t x;
    mvDouble_t y;
    mvDouble_t z;
} mvPoint3d_t;

MV_INLINE mvPoint3d_t mvPoint3d(const mvDouble_t x, const mvDouble_t y, const mvDouble_t z) {
    mvPoint3d_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

typedef struct mvVec2u8_t {
    mvUInt8_t x;
    mvUInt8_t y;
} mvVec2u8_t;

MV_INLINE mvVec2u8_t mvVec2u8(const mvUInt8_t x, const mvUInt8_t y) {
    mvVec2u8_t result;
    result.x = x;
    result.y = y;
    return result;
}

typedef struct mvVec3u8_t {
    mvUInt8_t x;
    mvUInt8_t y;
    mvUInt8_t z;
} mvVec3u8_t;

MV_INLINE mvVec3u8_t mvVec3u8(const mvUInt8_t x, const mvUInt8_t y, const mvUInt8_t z) {
    mvVec3u8_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

typedef struct mvVec4u8_t {
    mvUInt8_t x;
    mvUInt8_t y;
    mvUInt8_t z;
    mvUInt8_t w;
} mvVec4u8_t;

MV_INLINE mvVec4u8_t mvVec4u8(const mvUInt8_t x, const mvUInt8_t y, const mvUInt8_t z, const mvUInt8_t w) {
    mvVec4u8_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    return result;
}

typedef struct mvVec2f_t {
    mvFloat_t x;
    mvFloat_t y;
} mvVec2f_t;

MV_INLINE mvVec2f_t mvVec2f(const mvFloat_t x, const mvFloat_t y) {
    mvVec2f_t result;
    result.x = x;
    result.y = y;
    return result;
}

typedef struct mvVec3f_t {
    mvFloat_t x;
    mvFloat_t y;
    mvFloat_t z;
} mvVec3f_t;

MV_INLINE mvVec3f_t mvVec3f(const mvFloat_t x, const mvFloat_t y, const mvFloat_t z) {
    mvVec3f_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

typedef struct mvVec4f_t {
    mvFloat_t x;
    mvFloat_t y;
    mvFloat_t z;
    mvFloat_t w;
} mvVec4f_t;

MV_INLINE mvVec4f_t mvVec4f(const mvFloat_t x, const mvFloat_t y, const mvFloat_t z, const mvFloat_t w) {
    mvVec4f_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    return result;
}

typedef struct mvVec2d_t {
    mvDouble_t x;
    mvDouble_t y;
} mvVec2d_t;

MV_INLINE mvVec2d_t mvVec2d(const mvDouble_t x, const mvDouble_t y) {
    mvVec2d_t result;
    result.x = x;
    result.y = y;
    return result;
}

typedef struct mvVec3d_t {
    mvDouble_t x;
    mvDouble_t y;
    mvDouble_t z;
} mvVec3d_t;

MV_INLINE mvVec3d_t mvVec3d(const mvDouble_t x, const mvDouble_t y, const mvDouble_t z) {
    mvVec3d_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

typedef struct mvVec4d_t {
    mvDouble_t x;
    mvDouble_t y;
    mvDouble_t z;
    mvDouble_t w;
} mvVec4d_t;

MV_INLINE mvVec4d_t mvVec4d(const mvDouble_t x, const mvDouble_t y, const mvDouble_t z, const mvDouble_t w) {
    mvVec4d_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    return result;
}

typedef union mvMat2f_t {
    struct {
        mvFloat_t a00,a01,a10,a11;
    };
    mvVec2f_t vec[2];
    mvFloat_t mat[4];
    mvFloat_t mat2[2][2];
} mvMat2f_t;

MV_INLINE mvMat2f_t mvMat2f(const mvFloat_t a00, const mvFloat_t a01, const mvFloat_t a10, const mvFloat_t a11) {
    mvMat2f_t result;
    result.a00 = a00;   result.a01 = a01;
    result.a10 = a10;   result.a11 = a11;
    return result;
}

MV_INLINE mvMat2f_t mvMat2f(const mvVec2f_t &x, const mvVec2f_t &y) {
    mvMat2f_t result;
    result.vec[0].x = x.x;   result.vec[0].y = x.y;
    result.vec[1].x = y.x;   result.vec[1].y = y.y;
    return result;
}

MV_INLINE mvMat2f_t mvMat2f(const mvFloat_t mat[2][2]) {
    mvMat2f_t result;
    memcpy(result.mat,mat,2 * 2 * sizeof(mvFloat_t));
    return result;
}

typedef union mvMat2d_t {
    struct {
        mvDouble_t a00,a01,a10,a11;
    };
    mvVec2d_t vec[2];
    mvDouble_t mat[4];
    mvDouble_t mat2[2][2];
} mvMat2d_t;

MV_INLINE mvMat2d_t mvMat2d(const mvDouble_t a00, const mvDouble_t a01, const mvDouble_t a10, const mvDouble_t a11) {
    mvMat2d_t result;
    result.a00 = a00;   result.a01 = a01;
    result.a10 = a10;   result.a11 = a11;
    return result;
}

MV_INLINE mvMat2d_t mvMat2d(const mvVec2d_t &x, const mvVec2d_t &y) {
    mvMat2d_t result;
    result.vec[0].x = x.x;   result.vec[0].y = x.y;
    result.vec[1].x = y.x;   result.vec[1].y = y.y;
    return result;
}

MV_INLINE mvMat2d_t mvMat2d(const mvDouble_t mat[2][2]) {
    mvMat2d_t result;
    memcpy(result.mat,mat,2 * 2 * sizeof(mvDouble_t));
    return result;
}

typedef union mvMat3f_t {
    struct {
        mvFloat_t a00,a01,a02,a10,a11,a12,a20,a21,a22;
    };
    mvVec3f_t vec[3];
    mvFloat_t mat[9];
    mvFloat_t mat2[3][3];
} mvMat3f_t;

MV_INLINE mvMat3f_t mvMat3f(const mvFloat_t a00, const mvFloat_t a01, const mvFloat_t a02,
                         const mvFloat_t a10, const mvFloat_t a11, const mvFloat_t a12,
                         const mvFloat_t a20, const mvFloat_t a21, const mvFloat_t a22) {
    mvMat3f_t result;
    result.a00 = a00;   result.a01 = a01;   result.a02 = a02;
    result.a10 = a10;   result.a11 = a11;   result.a12 = a12;
    result.a20 = a20;   result.a21 = a21;   result.a22 = a22;
    return result;
}

MV_INLINE mvMat3f_t mvMat3f(const mvVec3f_t &x, const mvVec3f_t &y, const mvVec3f_t &z) {
    mvMat3f_t result;
    result.vec[0].x = x.x;   result.vec[0].y = x.y; result.vec[0].z = x.z;
    result.vec[1].x = y.x;   result.vec[1].y = y.y; result.vec[1].z = y.z;
    result.vec[2].x = z.x;   result.vec[2].y = z.y; result.vec[2].z = z.z;
    return result;
}

MV_INLINE mvMat3f_t mvMat3f(const mvFloat_t mat[3][3]) {
    mvMat3f_t result;
    memcpy(result.mat,mat,3 * 3 * sizeof(mvFloat_t));
    return result;
}

typedef union mvMat3d_t {
    struct {
        mvDouble_t a00,a01,a02,a10,a11,a12,a20,a21,a22;
    };
    mvVec3d_t vec[3];
    mvDouble_t mat[9];
    mvDouble_t mat2[3][3];
} mvMat3d_t;

MV_INLINE mvMat3d_t mvMat3d(const mvDouble_t a00, const mvDouble_t a01, const mvDouble_t a02,
                         const mvDouble_t a10, const mvDouble_t a11, const mvDouble_t a12,
                         const mvDouble_t a20, const mvDouble_t a21, const mvDouble_t a22) {
    mvMat3d_t result;
    result.a00 = a00;   result.a01 = a01;   result.a02 = a02;
    result.a10 = a10;   result.a11 = a11;   result.a12 = a12;
    result.a20 = a20;   result.a21 = a21;   result.a22 = a22;
    return result;
}

MV_INLINE mvMat3d_t mvMat3d(const mvVec3d_t &x, const mvVec3d_t &y, const mvVec3d_t &z) {
    mvMat3d_t result;
    result.vec[0].x = x.x;   result.vec[0].y = x.y; result.vec[0].z = x.z;
    result.vec[1].x = y.x;   result.vec[1].y = y.y; result.vec[1].z = y.z;
    result.vec[2].x = z.x;   result.vec[2].y = z.y; result.vec[2].z = z.z;
    return result;
}

MV_INLINE mvMat3d_t mvMat3d(const mvDouble_t mat[3][3]) {
    mvMat3d_t result;
    memcpy(result.mat,mat,3 * 3 * sizeof(mvDouble_t));
    return result;
}

typedef union mvMat4f_t {
    struct {
        mvFloat_t a00,a01,a02,a03,a10,a11,a12,a13,a20,a21,a22,a23,a30,a31,a32,a33;
    };
    mvVec4f_t vec[4];
    mvFloat_t mat[16];
    mvFloat_t mat2[4][4];
} mvMat4f_t;


MV_INLINE mvMat4f_t mvMat4f(const mvFloat_t a00, const mvFloat_t a01, const mvFloat_t a02, const mvFloat_t a03,
                         const mvFloat_t a10, const mvFloat_t a11, const mvFloat_t a12, const mvFloat_t a13,
                         const mvFloat_t a20, const mvFloat_t a21, const mvFloat_t a22, const mvFloat_t a23,
                         const mvFloat_t a30, const mvFloat_t a31, const mvFloat_t a32, const mvFloat_t a33) {
    mvMat4f_t result;
    result.a00 = a00;   result.a01 = a01;   result.a02 = a02;   result.a03 = a03;
    result.a10 = a10;   result.a11 = a11;   result.a12 = a12;   result.a13 = a13;
    result.a20 = a20;   result.a21 = a21;   result.a22 = a22;   result.a23 = a23;
    result.a30 = a30;   result.a31 = a31;   result.a32 = a32;   result.a33 = a33;
    return result;
}

MV_INLINE mvMat4f_t mvMat4f(const mvVec4f_t &x, const mvVec4f_t &y, const mvVec4f_t &z, const mvVec4f_t &w) {
    mvMat4f_t result;
    result.vec[0].x = x.x;   result.vec[0].y = x.y; result.vec[0].z = x.z;  result.vec[0].w = x.w;
    result.vec[1].x = y.x;   result.vec[1].y = y.y; result.vec[1].z = y.z;  result.vec[1].w = y.w;
    result.vec[2].x = z.x;   result.vec[2].y = z.y; result.vec[2].z = z.z;  result.vec[2].w = z.w;
    result.vec[3].x = w.x;   result.vec[3].y = w.y; result.vec[3].z = w.z;  result.vec[3].w = w.w;
    return result;
}

MV_INLINE mvMat4f_t mvMat4f(const mvFloat_t mat[4][4]) {
    mvMat4f_t result;
    memcpy(result.mat,mat,4 * 4 * sizeof(mvFloat_t));
    return result;
}

typedef union mvMat4d_t {
    struct {
        mvDouble_t a00,a01,a02,a03,a10,a11,a12,a13,a20,a21,a22,a23,a30,a31,a32,a33;
    };
    mvVec4d_t vec[4];
    mvDouble_t mat[16];
    mvDouble_t mat2[4][4];
} mvMat4d_t;

MV_INLINE mvMat4d_t mvMat4d(const mvDouble_t a00, const mvDouble_t a01, const mvDouble_t a02, const mvDouble_t a03,
                         const mvDouble_t a10, const mvDouble_t a11, const mvDouble_t a12, const mvDouble_t a13,
                         const mvDouble_t a20, const mvDouble_t a21, const mvDouble_t a22, const mvDouble_t a23,
                         const mvDouble_t a30, const mvDouble_t a31, const mvDouble_t a32, const mvDouble_t a33) {
    mvMat4d_t result;
    result.a00 = a00;   result.a01 = a01;   result.a02 = a02;   result.a03 = a03;
    result.a10 = a10;   result.a11 = a11;   result.a12 = a12;   result.a13 = a13;
    result.a20 = a20;   result.a21 = a21;   result.a22 = a22;   result.a23 = a23;
    result.a30 = a30;   result.a31 = a31;   result.a32 = a32;   result.a33 = a33;
    return result;
}

MV_INLINE mvMat4d_t mvMat4d(const mvVec4d_t &x, const mvVec4d_t &y, const mvVec4d_t &z, const mvVec4d_t &w) {
    mvMat4d_t result;
    result.vec[0].x = x.x;   result.vec[0].y = x.y; result.vec[0].z = x.z;  result.vec[0].w = x.w;
    result.vec[1].x = y.x;   result.vec[1].y = y.y; result.vec[1].z = y.z;  result.vec[1].w = y.w;
    result.vec[2].x = z.x;   result.vec[2].y = z.y; result.vec[2].z = z.z;  result.vec[2].w = z.w;
    result.vec[3].x = w.x;   result.vec[3].y = w.y; result.vec[3].z = w.z;  result.vec[3].w = w.w;
    return result;
}

MV_INLINE mvMat4d_t mvMat4d(const mvDouble_t mat[4][4]) {
    mvMat4d_t result;
    memcpy(result.mat,mat,4 * 4 * sizeof(mvDouble_t));
    return result;
}

typedef struct mvRange_t {
    mvSInt32_t left;
    mvSInt32_t right;
} mvRange_t;

MV_INLINE mvRange_t mvRange(const mvSInt32_t left, const mvSInt32_t right) {
    mvRange_t result;
    if (left < right) {
        result.left = left;
        result.right = right;
    } else {
        result.left = right;
        result.right = left;
    }
    return result;
}

typedef struct mvRect_t {
    mvSInt32_t left;
    mvSInt32_t right;
    mvSInt32_t top;
    mvSInt32_t bottom;
} mvRect_t;

MV_INLINE mvRect_t mvRect(const mvSInt32_t left, const mvSInt32_t top, const mvSInt32_t right, const mvSInt32_t bottom) {
    mvRect_t result;
    if (left < right) {
        result.left = left;
        result.right = right;
    } else {
        result.left = right;
        result.right = left;
    }
    if (top < bottom) {
        result.top = top;
        result.bottom = bottom;
    } else {
        result.top = bottom;
        result.bottom = top;
    }
    return result;
}

typedef struct mvImage1_t {
    mvSize_t size;
    mvSize_t planes;
    mvType_t type;
    mvSize_t bytes;
    mvPointer_t data;
} mvImage1_t;

typedef struct mvImage2_t {
    mvSize2_t size;
    mvSize_t planes;
    mvType_t type;
    mvSize_t bytes;
    mvPointer_t data;
} mvImage2_t;

typedef struct mvImage3_t {
    mvSize3_t size;
    mvSize_t planes;
    mvType_t type;
    mvSize_t bytes;
    mvPointer_t data;
} mvImage3_t;

typedef struct mvColor_t {
    mvUInt8_t red, green, blue;
} mvColor_t;

MV_INLINE mvColor_t mvColor(const mvUInt8_t red, const mvUInt8_t green, const mvUInt8_t blue) {
    mvColor_t result;
    result.red = red;
    result.green = green;
    result.blue = blue;
    return result;
}

MV_INLINE mvColor_t mvColor(const mvVec3u8_t vec) {
    mvColor_t result;
    result.red = vec.x;
    result.green = vec.y;
    result.blue = vec.z;
    return result;
}

typedef struct mvColor4_t {
    mvUInt8_t red, green, blue, alpha;
} mvColor4_t;

MV_INLINE mvColor4_t mvColor4(const mvUInt8_t red, const mvUInt8_t green, const mvUInt8_t blue, const mvUInt8_t alpha) {
    mvColor4_t result;
    result.red = red;
    result.green = green;
    result.blue = blue;
    result.alpha = alpha;
    return result;
}

MV_INLINE mvColor4_t mvColor4(const mvVec4u8_t vec) {
    mvColor4_t result;
    result.red = vec.x;
    result.green = vec.y;
    result.blue = vec.z;
    result.alpha = vec.w;
    return result;
}

#endif // _MV_VEC_H_
