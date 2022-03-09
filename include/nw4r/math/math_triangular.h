#ifndef NW4R_MATH_TRIANGULAR_H
#define NW4R_MATH_TRIANGULAR_H
#include "types_nw4r.h"
#include "math_types.h"

namespace nw4r
{
    namespace math
    {
        void SinCosFIdx(f32 *, f32 *, f32);

        inline void SinCosDeg(f32 *pf1, f32 *pf2, f32 f3)
        {
            SinCosFIdx(pf1, pf2, NW4R_DEG_TO_FIDX * f3);
        }

		inline void MTX34RotXYZDeg(MTX34 *pMtx, float x, float y, float z)
		{
			MTX34RotXYZFIdx(pMtx, NW4R_DEG_TO_FIDX * x, NW4R_DEG_TO_FIDX * y, NW4R_DEG_TO_FIDX * z);
		}
    }
}

#endif