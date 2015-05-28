#ifndef MOVEMENTBONEPOSITIONLIST_H
#define MOVEMENTBONEPOSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct BoneFixedPositionList
	{
		TPOINT** Positions;
		UInt8 PositionCount;

		BoneFixedPositionList()
			: Positions(0),
			PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		BoneFixedPositionList(const BoneFixedPositionList<TPOINT>& boneFixedPositionList)
		{
			Positions = new TPOINT*[boneFixedPositionList.PositionCount];

			for (UInt8 i = 0; i < boneFixedPositionList.PositionCount; i++)
				Positions[i] = new TPOINT(*boneFixedPositionList.Positions[i]);

			PositionCount = boneFixedPositionList.PositionCount;
		}

		BoneFixedPositionList(UInt8 size)
			: PositionCount(size)
		{
			Positions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Positions[i] = new TPOINT(TPOINT::getZero());
		}

		BoneFixedPositionList<TPOINT>& operator=(const BoneFixedPositionList<TPOINT>& boneFixedPositionList)
		{
			TPOINT** tmpPositions = new TPOINT*[boneFixedPositionList.PositionCount + 1];

			for (UInt8 i = 0; i < boneFixedPositionList.PositionCount; i++)
				tmpPositions[i] = new TPOINT(*boneFixedPositionList.Positions[i]);

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount = boneFixedPositionList.PositionCount;

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

		~BoneFixedPositionList()
		{
			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENTBONEPOSITIONLIST_H
