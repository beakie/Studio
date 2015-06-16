#ifndef MOVEMENT_POINTLIST_H
#define MOVEMENT_POINTLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct PointList
	{
		TPOINT** Points;
		UInt8 PointCount;

		PointList()
			: Points(0),
			  PointCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		PointList(const PointList<TPOINT>& pointList)
		{
			Points = new TPOINT*[pointList.PointCount];

			for (UInt8 i = 0; i < pointList.PointCount; i++)
				Points[i] = new TPOINT(*pointList.Points[i]);

			PointCount = pointList.PointCount;
		}

		PointList(UInt8 size)
			: PointCount(size)
		{
			Points = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Points[i] = new TPOINT(TPOINT::getZero());
		}

		PointList<TPOINT>& operator=(const PointList<TPOINT>& pointList)
		{
			TPOINT** tmpPoints = new TPOINT*[pointList.PointCount + 1];

			for (UInt8 i = 0; i < pointList.PointCount; i++)
				tmpPoints[i] = new TPOINT(*pointList.Points[i]);

			delete[] Points;

			Points = tmpPoints;

			PointCount = pointList.PointCount;

			return *this;
		}

		UInt8 addPoint()
		{
			TPOINT** tmpPoints = new TPOINT*[PointCount + 1];

			for (UInt8 i = 0; i < PointCount; i++)
				tmpPoints[i] = Points[i];

			tmpPoints[PointCount] = new TPOINT(TPOINT::getZero());

			delete[] Points;

			Points = tmpPoints;

			PointCount++;

			return PointCount - 1;
		}

		~PointList()
		{
			for (UInt8 i = 0; i < PointCount; i++)
				delete Points[i];

			delete[] Points;
		}

	};
}

#endif // MOVEMENT_POINTLIST_H
