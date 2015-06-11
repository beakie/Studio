#ifndef COMMON_QUATERNION_H
#define COMMON_QUATERNION_H

#include "core.h"
#include "common-vector3.h"

namespace Common
{
	template <typename TVALUE = FloatMax>
	struct Quaternion
	{
		Vector3<TVALUE> V;
		TVALUE W;

		Quaternion()
		{
		}

		Quaternion(const Quaternion<TVALUE>& quaternion)
		{
			operator=(quaternion);
		}

		Quaternion(const Vector3<TVALUE>& v, const TVALUE w)
		{
			V = v;
			W = w;
		}

		Quaternion(const TVALUE x, const TVALUE y, const TVALUE z, const TVALUE w)
		{
			V.Values[0] = x;
			V.Values[1] = y;
			V.Values[2] = z;
			W = w;
		}

		Quaternion<TVALUE>& operator=(const Quaternion<TVALUE>& quaternion)
		{
			V = quaternion.V;
			W = quaternion.W;

			return *this;
		}

		Quaternion<TVALUE> operator*(const Quaternion<TVALUE>& quaternion) const
		{
			return Quaternion<TVALUE>(*this) *= quaternion;
		}

		Quaternion<TVALUE>& operator*=(const Quaternion<TVALUE>& quaternion)
		{
			return operator=(((W * quaternion.W) - (X * quaternion.X) - (Y * quaternion.Y) - (Z * quaternion.Z)),
								((W * quaternion.X) + (X * quaternion.W) + (Y * quaternion.Z) - (Z * quaternion.Y)),
								((W * quaternion.Y) - (X * quaternion.Z) + (Y * quaternion.W) + (Z * quaternion.X)),
								((W * quaternion.Z) + (X * quaternion.Y) - (Y * quaternion.X) + (Z * quaternion.W)))
		}

		~Quaternion()
		{
		}
	};
}

#endif // COMMON_QUATERNION_H
