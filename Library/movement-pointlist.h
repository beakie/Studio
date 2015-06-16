#ifndef MOVEMENT_POSITIONLIST_H
#define MOVEMENT_POSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct PointList
	{
		TPOINT** Positions;
		UInt8 PositionCount;

		PointList()
			: Positions(0),
			  PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		PointList(const PointList<TPOINT>& pointList)
		{
			Positions = new TPOINT*[pointList.PositionCount];

			for (UInt8 i = 0; i < pointList.PositionCount; i++)
				Positions[i] = new TPOINT(*pointList.Positions[i]);

			PositionCount = pointList.PositionCount;
		}

		PointList(UInt8 size)
			: PositionCount(size)
		{
			Positions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Positions[i] = new TPOINT(TPOINT::getZero());
		}

		PointList<TPOINT>& operator=(const PointList<TPOINT>& pointList)
		{
			TPOINT** tmpPositions = new TPOINT*[pointList.PositionCount + 1];

			for (UInt8 i = 0; i < pointList.PositionCount; i++)
				tmpPositions[i] = new TPOINT(*pointList.Positions[i]);

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount = pointList.PositionCount;

			return *this;
		}

		UInt8 addPosition()
		{
			TPOINT** tmpPositions = new TPOINT*[PositionCount + 1];

			for (UInt8 i = 0; i < PositionCount; i++)
				tmpPositions[i] = Positions[i];

			tmpPositions[PositionCount] = new TPOINT(TPOINT::getZero());

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount++;

			return PositionCount - 1;
		}

		~PointList()
		{
			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENT_POSITIONLIST_H
