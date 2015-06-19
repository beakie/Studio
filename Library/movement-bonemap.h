#ifndef MOVEMENT_BONEMAP_H
#define MOVEMENT_BONEMAP_H

#include "core.h"
#include "common.h"

#include "movement-jointlist.h"

namespace Movement
{
	struct BoneMap
	{
		UInt8* ParentBones;
		UInt8 BoneCount;

		BoneMap()
			: ParentBones(0),
			  BoneCount(0)
		{
		}

		BoneMap(const BoneMap& boneMap)
			: BoneCount(boneMap.BoneCount)
		{
			ParentBones = new UInt8[boneMap.BoneCount];

			for (UInt8 i = 0; i < boneMap.BoneCount; i++)
				ParentBones[i] = boneMap.ParentBones[i];
		}

		BoneMap(UInt8 chainedBoneCount)
			: BoneCount(chainedBoneCount)
		{
			ParentBones = new UInt8[chainedBoneCount];

			for (UInt8 i = 0; i < chainedBoneCount; i++)
				ParentBones[i] = (i == 0 ? 0 : i - 1);
		}

		template <typename TVALUE>
		BoneMap(const JointList<TVALUE>& jointList)
			: BoneMap(jointList.JointCount)
		{
		}

		BoneMap& operator=(const BoneMap& boneMap)
		{
			UInt8* tmpParentBones = new UInt8[boneMap.BoneCount + 1];

			for (UInt8 i = 0; i < boneMap.BoneCount; i++)
				tmpParentBones[i] = boneMap.ParentBones[i];

			delete[] ParentBones;

			ParentBones = tmpParentBones;

			BoneCount = boneMap.BoneCount;

			return *this;
		}

		UInt8 addBone(UInt8 parent)
		{
			UInt8* tmpParentBones = new UInt8[BoneCount + 1];

			for (UInt8 i = 0; i < BoneCount; i++)
				tmpParentBones[i] = ParentBones[i];

			tmpParentBones[BoneCount] = parent;

			delete[] ParentBones;

			ParentBones = tmpParentBones;

			BoneCount++;

			return ParentBones[BoneCount - 1];
		}

		UInt8 addBone()
		{
			return addBone(BoneCount);
		}

		bool isParent(const UInt8 index) const
		{
			for (UInt8 i = 0; i < BoneCount; i++)
				if ((ParentBones[i] == index) && (i != index))
					return true;

			return false;
		}

		bool isChild(const UInt8 index) const
		{
			return ParentBones[index] == index;
		}

		Common::Nullable<UInt8> findChild(const UInt8 parentIndex, const Common::Nullable<UInt8> lastChildIndex = Common::Null) const
		{
			if (lastChildIndex == BoneCount)
				return Common::Null;

			UInt8 fromIndex = 0;
			if (lastChildIndex.HasValue)
				fromIndex = lastChildIndex.Value + 1;

			for (UInt8 i = fromIndex; i < BoneCount; i++)
				if ((ParentBones[i] == parentIndex) && (i != parentIndex))
					return i;

			return Common::Null;
		}

		void populateChildren(const UInt8 parentIndex) const
		{

		}

		template <typename TMATRIX>
		TMATRIX getBoneTransformMatrix(const Common::ICollection<TMATRIX, UInt8>& jointList, const UInt8 index) const
		{
			if (ParentBones[index] != index)
				return getBoneTransformMatrix<TMATRIX>(jointList, ParentBones[index]) * jointList.operator[](index);
			else
				return jointList.operator[](index);
		}

		~BoneMap()
		{
			delete[] ParentBones;
		}

	};
}

#endif // MOVEMENT_BONEMAP_H
