#ifndef MOVEMENT_POSITIONLIST_H
#define MOVEMENT_POSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct PositionList
	{
		TPOINT** Positions;
		UInt8 PositionCount;

		PositionList()
			: Positions(0),
			  PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		PositionList(const PositionList<TPOINT>& positionList)
		{
			Positions = new TPOINT*[positionList.PositionCount];

			for (UInt8 i = 0; i < positionList.PositionCount; i++)
				Positions[i] = new TPOINT(*positionList.Positions[i]);

			PositionCount = positionList.PositionCount;
		}

		PositionList(UInt8 size)
			: PositionCount(size)
		{
			Positions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Positions[i] = new TPOINT(TPOINT::getZero());
		}

		PositionList<TPOINT>& operator=(const PositionList<TPOINT>& positionList)
		{
			TPOINT** tmpPositions = new TPOINT*[positionList.PositionCount + 1];

			for (UInt8 i = 0; i < positionList.PositionCount; i++)
				tmpPositions[i] = new TPOINT(*positionList.Positions[i]);

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount = positionList.PositionCount;

			return *this;
		}

		UInt8 addPoint()
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

		~PositionList()
		{
			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENT_POSITIONLIST_H
