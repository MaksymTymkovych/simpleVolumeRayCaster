#ifndef _MV_H_
#define _MV_H_

#ifndef MV_INLINE
#ifdef _MSC_VER
  #define MV_INLINE __forceinline
#else
  #define MV_INLINE inline
#endif
#endif

#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstddef>
#include <cmath>

#include "mvTypes.h"
#include "mvMath.h"
#include "mvImages.h"

#include "mvBitmap.h"

#include "mvRaw.h"

#include "mvLookUpTable.h"

#include "mvVisualizations.h"

#include "mvVolumeVisulaizations.h"

#endif // _MV_H_
