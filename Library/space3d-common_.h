#ifndef SPACE3D_COMMON_H
#define SPACE3D_COMMON_H

#include "common.h"

#include "space3d-coordinate.h"

namespace Space3d
{

	template <typename T>
	FloatMax getCoordinateDistance(const Common::Vector3<T> &coordinate1, const Common::Vector3<T> &coordinate2)
	{
		return Common::power(Common::power((FloatMax)coordinate1.Values[0] - coordinate2.Values[0], 2) + Common::power(coordinate1.Values[1] - coordinate2.Values[1], 2) + Common::power(coordinate1.Values[2] - coordinate2.Values[2], 2), 0.5);
	}

	template <typename T>
	Common::Vector3<T> getCoordinateOffset(const Common::Vector3<T> &coordinate1, const Common::Vector3<T> &coordinate2)
	{
		return coordinate2 - coordinate1;
	}

	template <typename T>
	Common::Vector3<T> getCoordinateDiff(const Common::Vector3<T> &coordinate1, const Common::Vector3<T> &coordinate2)
	{
		return Common::Vector3<T>(Common::abs(coordinate1.Values[0] - coordinate2.Values[0]), Common::abs(coordinate1.Values[1] - coordinate2.Values[1]), Common::abs(coordinate1.Values[2] - coordinate2.Values[2]));
	}

}

#endif // SPACE3D_COMMON_H
