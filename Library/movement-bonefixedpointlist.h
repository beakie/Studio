#ifndef MOVEMENT_BONEFIXEDPOINTLIST_H
#define MOVEMENT_BONEFIXEDPOINTLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct BoneFixedPointList
		: Common::ICollection<Common::Tuple2<int, TPOINT>, UInt8>
	{
		UInt8* BoneIndex;
		TPOINT** Points;
		UInt8 PointCount;

		BoneFixedPointList()
			: Points(0),
			PointCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		BoneFixedPointList(const BoneFixedPointList<TPOINT>& boneFixedPointList)
		{
			BoneIndex = new UInt8[boneFixedPointList.PointCount];
			Points = new TPOINT*[boneFixedPointList.PointCount];

			for (UInt8 i = 0; i < boneFixedPointList.PointCount; i++)
			{
				BoneIndex[i] = boneFixedPointList.BoneIndex[i];
				Points[i] = new TPOINT(*boneFixedPointList.Points[i]);
			}

			PointCount = boneFixedPointList.PointCount;
		}

		BoneFixedPointList(UInt8 size)
			: PointCount(size)
		{
			BoneIndex = new UInt8[size];
			Points = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
			{
				BoneIndex[i] = 0;
				Points[i] = new TPOINT(TPOINT::getZero());
			}
		}

		BoneFixedPointList<TPOINT>& operator=(const BoneFixedPointList<TPOINT>& boneFixedPointList)
		{
			UInt8* tmpBoneIndex = new UInt8[boneFixedPointList.PointCount + 1];
			TPOINT** tmpPoints = new TPOINT*[boneFixedPointList.PointCount + 1];

			for (UInt8 i = 0; i < boneFixedPointList.PointCount; i++)
			{
				tmpBoneIndex[i] = boneFixedPointList.BoneIndex[i];
				tmpPoints[i] = new TPOINT(*boneFixedPointList.Points[i]);
			}

			delete[] BoneIndex;
			delete[] Points;

			BoneIndex = tmpBoneIndex;
			Points = tmpPoints;

			PointCount = boneFixedPointList.PointCount;

			return *this;
		}

		UInt8 addPoint()
		{
			UInt8* tmpBoneIndex = new UInt8[PointCount + 1];
			TPOINT** tmpPoints = new TPOINT*[PointCount + 1];

			for (UInt8 i = 0; i < PointCount; i++)
			{
				tmpBoneIndex[i] = BoneIndex[i];
				tmpPoints[i] = Points[i];
			}

			tmpBoneIndex[PointCount] = 0;
			tmpPoints[PointCount] = new TPOINT(TPOINT::getZero());

			delete[] BoneIndex;
			delete[] Points;

			BoneIndex = tmpBoneIndex;
			Points = tmpPoints;

			PointCount++;

			return PointCount - 1;
		}

		UInt8 count() const
		{
			return PointCount;
		}

		Common::Tuple2<int, TPOINT> operator[] (UInt8 n) const
		{
			return Common::Tuple2<int, TPOINT>(BoneIndex[n], *Points[n]);
		}

		~BoneFixedPointList()
		{
			delete[] BoneIndex;

			for (UInt8 i = 0; i < PointCount; i++)
				delete Points[i];

			delete[] Points;
		}

	};
}

#endif // MOVEMENT_BONEFIXEDPOINTLIST_H
