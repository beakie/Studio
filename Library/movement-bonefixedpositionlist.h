#ifndef MOVEMENT_BONEPOSITIONLIST_H
#define MOVEMENT_BONEPOSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct BoneFixedPositionList
	{
		UInt8* BoneIndex;
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
			BoneIndex = new UInt8[boneFixedPositionList.PositionCount];
			Positions = new TPOINT*[boneFixedPositionList.PositionCount];

			for (UInt8 i = 0; i < boneFixedPositionList.PositionCount; i++)
			{
				BoneIndex[i] = boneFixedPositionList.BoneIndex[i];
				Positions[i] = new TPOINT(*boneFixedPositionList.Positions[i]);
			}

			PositionCount = boneFixedPositionList.PositionCount;
		}

		BoneFixedPositionList(UInt8 size)
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

		BoneFixedPositionList<TPOINT>& operator=(const BoneFixedPositionList<TPOINT>& boneFixedPositionList)
		{
			UInt8* tmpBoneIndex = new UInt8[boneFixedPositionList.PositionCount + 1];
			TPOINT** tmpPositions = new TPOINT*[boneFixedPositionList.PositionCount + 1];

			for (UInt8 i = 0; i < boneFixedPositionList.PositionCount; i++)
			{
				tmpBoneIndex[i] = boneFixedPositionList.BoneIndex[i];
				tmpPositions[i] = new TPOINT(*boneFixedPositionList.Positions[i]);
			}

			delete[] BoneIndex;
			delete[] Positions;

			BoneIndex = tmpBoneIndex;
			Positions = tmpPositions;

			PositionCount = boneFixedPositionList.PositionCount;

			return *this;
		}

		UInt8 addPoint()
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

		~BoneFixedPositionList()
		{
			delete[] BoneIndex;

			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENT_BONEPOSITIONLIST_H
