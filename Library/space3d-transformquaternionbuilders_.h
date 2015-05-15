#ifndef SPACE3DTRANSFORMQUATERNIONBUILDERS_H
#define SPACE3DTRANSFORMQUATERNIONBUILDERS_H

#include "common.h"

namespace Space3d
{
	template <typename TVALUE>
	Common::Quaternion<TVALUE> getRotationQuaternion(const TVALUE axisX, const TVALUE axisY, const TVALUE axisZ, const TVALUE rotation)
	{
		TVALUE s = Common::sin(rotation / 2);
		return Common::Quaternion<TVALUE>(Common::Vector3<TVALUE>(axisX * s, axisY * s, axisZ * s), Common::cos(rotation / 2));
	}
}

#endif // SPACE3DTRANSFORMQUATERNIONBUILDERS_H
