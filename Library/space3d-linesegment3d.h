#ifndef SPACE3DLINESEGMENT3D_H
#define SPACE3DLINESEGMENT3D_H

#include "common.h"

namespace Space3d
{

	template <typename TVALUE = FloatMax>
	struct LineSegment3d
	{
		Common::Vector3<TVALUE> CoordinateFrom;
		Common::Vector3<TVALUE> CoordinateTo;

		Common::Vector3<TVALUE> getOffset() const
		{
			return CoordinateTo - CoordinateFrom;
		}

		TVALUE getLength() const
		{
			return Common::power(Common::power(CoordinateTo.Values[0] - CoordinateFrom.Values[0], 2) + Common::power(CoordinateTo.Values[1] - CoordinateFrom.Values[1], 2) + Common::power(CoordinateTo.Values[2] - CoordinateFrom.Values[2], 2), 0.5);
		}
	};

}

#endif // SPACE3DLINESEGMENT3D_H
