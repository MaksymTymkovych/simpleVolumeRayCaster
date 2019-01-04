#ifndef _MV_VISUALIZATIONS_H_
#define _MV_VISUALIZATIONS_H_



typedef struct mvRay_t {
    mvVec3f_t position;
    mvVec3f_t direction;
} mvRay_t;

MV_INLINE mvRay_t mvRay(const mvVec3f_t &position, const mvVec3f_t &direction) {
    mvRay_t result;
    result.position = position;
    result.direction = mvNormalize(direction);
    return result;
}

typedef struct mvPlane_t {
    mvVec3f_t normal;
    mvFloat_t d;
} mvPlane_t;

MV_INLINE mvPlane_t mvPlane(const mvVec3f_t &normal, const mvVec3f_t &point) {
    mvPlane_t result;
    result.normal = mvNormalize(normal);
    result.d = normal * point;
    return result;
}

typedef struct mvSphere_t {
    mvVec3f_t position;
    mvFloat_t radius;
} mvSphere_t;

MV_INLINE mvSphere_t mvSphere(const mvVec3f_t &position, const mvFloat_t radius) {
    mvSphere_t result;
    result.position = position;
    result.radius = radius;
    return result;
}

typedef struct mvTriangle_t {
    mvVec3f_t v0;
    mvVec3f_t v1;
    mvVec3f_t v2;
} mvTriangle_t;

MV_INLINE mvTriangle_t mvTriangle(const mvVec3f_t &v0, const mvVec3f_t &v1, const mvVec3f_t &v2) {
    mvTriangle_t result;
    result.v0 = v0;
    result.v1 = v1;
    result.v2 = v2;
    return result;
}

typedef struct mvBoxAABB_t {
    mvVec3f_t min;
    mvVec3f_t max;
} mvBoxAABB_t;

MV_INLINE mvBoxAABB_t mvBoxAABB(const mvVec3f_t min, const mvVec3f_t max) {
    mvBoxAABB_t result;
    if (min.x < max.x) {
        result.min.x = min.x;
        result.max.x = max.x;
    } else {
        result.min.x = max.x;
        result.max.x = min.x;
    }
    if (min.y < max.y) {
        result.min.y = min.y;
        result.max.y = max.y;
    } else {
        result.min.y = max.y;
        result.max.y = min.y;
    }
    if (min.z < max.z) {
        result.min.z = min.z;
        result.max.z = max.z;
    } else {
        result.min.z = max.z;
        result.max.z = min.z;
    }
    return result;
}

MV_INLINE mvBool_t mvIntersection(const mvRay_t &ray, const mvSphere_t &sphere, mvFloat_t &t0, mvFloat_t &t1) {

    mvVec3f_t o(ray.position - sphere.position);
    mvFloat_t b((o * ray.direction));
    mvFloat_t c(mvDistanceSqr(o)-sphere.radius*sphere.radius);
    mvFloat_t d(b*b - c);
    if (d<0.0f) {
        return MV_FALSE;
    }

    if (d==0.0f) {
        t0 = t1 = (-b);
    } else {
        mvFloat_t sqrt_d(sqrtf(d));
        t0 = ( -b - sqrt_d );
        t1 = ( -b + sqrt_d );
    }
    return MV_TRUE;
}

MV_INLINE mvBool_t mvIntersection(const mvRay_t &ray, const mvPlane_t &plane, mvFloat_t &t) {
    mvFloat_t d(plane.normal * ray.direction);
    if( d != 0.0f) {
        t = (- (plane.normal*ray.position) + plane.d)/d;
        return (t >= 0.0f);
    }

   return MV_FALSE;
}

MV_INLINE mvBool_t mvIntersection(const mvRay_t &ray, const mvBoxAABB_t &box, mvFloat_t &tmin, mvFloat_t &tmax) {
    mvVec3f_t idir(1.0f/ray.direction);
    mvFloat_t lo = idir.x*(box.min.x - ray.position.x);
    mvFloat_t hi = idir.x*(box.max.x - ray.position.x);
    mvMinMax(lo,hi,tmin,tmax);

    mvFloat_t lo1 = idir.y*(box.min.y - ray.position.y);
    mvFloat_t hi1 = idir.y*(box.max.y - ray.position.y);
    mvFloat_t tmin_temp, tmax_temp;
    mvMinMax(lo1,hi1,tmin_temp,tmax_temp);

    tmin = mvMax(tmin, tmin_temp);
    tmax = mvMin(tmax, tmax_temp);

    mvFloat_t lo2 = idir.z*(box.min.z - ray.position.z);
    mvFloat_t hi2 = idir.z*(box.max.z - ray.position.z);
    mvMinMax(lo2,hi2,tmin_temp,tmax_temp);
    tmin = mvMax(tmin, tmin_temp);
    tmax = mvMin(tmax, tmax_temp);

    return (tmin <= tmax) && (tmax > 0.f);
}

MV_INLINE mvBool_t mvIntersection(const mvRay_t &ray, const mvBoxAABB_t &box,const mvMat3f_t &iModelMatrix, mvFloat_t &tmin, mvFloat_t &tmax) {
    mvVec3f_t idir;
    idir = 1.0f / ( iModelMatrix * ray.direction );
    mvFloat_t lo = idir.x*(box.min.x - ray.position.x);
    mvFloat_t hi = idir.x*(box.max.x - ray.position.x);
    mvMinMax(lo,hi,tmin,tmax);

    mvFloat_t lo1 = idir.y*(box.min.y - ray.position.y);
    mvFloat_t hi1 = idir.y*(box.max.y - ray.position.y);
    mvFloat_t tmin_temp, tmax_temp;
    mvMinMax(lo1,hi1,tmin_temp,tmax_temp);

    tmin = mvMax(tmin, tmin_temp);
    tmax = mvMin(tmax, tmax_temp);

    mvFloat_t lo2 = idir.z*(box.min.z - ray.position.z);
    mvFloat_t hi2 = idir.z*(box.max.z - ray.position.z);
    mvMinMax(lo2,hi2,tmin_temp,tmax_temp);
    tmin = mvMax(tmin, tmin_temp);
    tmax = mvMin(tmax, tmax_temp);

    return (tmin <= tmax) && (tmax > 0.f);
}

#endif // _MV_VISUALIZATIONS_H_
