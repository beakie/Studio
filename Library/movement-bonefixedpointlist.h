#ifndef MOVEMENT_BONEFIXEDPOINTLIST_H
#define MOVEMENT_BONEFIXEDPOINTLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct BoneFixedPointList
	{
		UInt8* BoneIndex;
		TPOINT** Positions;
		UInt8 PositionCount;

		BoneFixedPointList()
			: Positions(0),
			PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		BoneFixedPointList(const BoneFixedPointList<TPOINT>& boneFixedPointList)
		{
			BoneIndex = new UInt8[boneFixedPointList.PositionCount];
			Positions = new TPOINT*[boneFixedPointList.PositionCount];

			for (UInt8 i = 0; i < boneFixedPointList.PositionCount; i++)
			{
				BoneIndex[i] = boneFixedPointList.BoneIndex[i];
				Positions[i] = new TPOINT(*boneFixedPointList.Positions[i]);
			}

			PositionCount = boneFixedPointList.PositionCount;
		}

		BoneFixedPointList(UInt8 size)
			: PositionCount(size)
		{
			BoneIndex = new UInt8[size];
			Positions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
			{
				BoneIndex[i] = 0;
				Positions[i] = new TPOINT(TPOINT::getZero());
			}
		}

		BoneFixedPointList<TPOINT>& operator=(const BoneFixedPointList<TPOINT>& boneFixedPointList)
		{
			UInt8* tmpBoneIndex = new UInt8[boneFixedPointList.PositionCount + 1];
			TPOINT** tmpPositions = new TPOINT*[boneFixedPointList.PositionCount + 1];

			for (UInt8 i = 0; i < boneFixedPointList.PositionCount; i++)
			{
				tmpBoneIndex[i] = boneFixedPointList.BoneIndex[i];
				tmpPositions[i] = new TPOINT(*boneFixedPointList.Positions[i]);
			}

			delete[] BoneIndex;
			delete[] Positions;

			BoneIndex = tmpBoneIndex;
			Positions = tmpPositions;

			PositionCount = boneFixedPointList.PositionCount;

			return *this;
		}

		UInt8 addPosition()
		{
			UInt8* tmpBoneIndex = new UInt8[PositionCount + 1];
			TPOINT** tmpPositions = new TPOINT*[PositionCount + 1];

			for (UInt8 i = 0; i < PositionCount; i++)
			{
				tmpBoneIndex[i] = BoneIndex[i];
				tmpPositions[i] = Positions[i];
			}

			tmpBoneIndex[PositionCount] = 0;
			tmpPositions[PositionCount] = new TPOINT(TPOINT::getZero());

			delete[] BoneIndex;
			delete[] Positions;

			BoneIndex = tmpBoneIndex;
			Positions = tmpPositions;

			PositionCount++;

			return PositionCount - 1;
		}

		~BoneFixedPointList()
		{
			delete[] BoneIndex;

			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENT_BONEFIXEDPOINTLIST_H
