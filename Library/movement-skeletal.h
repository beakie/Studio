#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bonemap.h"
#include "movement-bonefixedpositionlist.h"
#include "movement-positionlist.h"
#include "movement-jointlist.h"

namespace Movement
{
	template <typename TPOINT, typename TMATRIX>
	struct Skeletal
	{
		JointList<TMATRIX> Joints;
		BoneMap BoneMap;
		PositionList<TPOINT> ZeroPositions; // This should be the position of the axis in 3d space. Not the bone ends!
		BoneFixedPositionList<TPOINT> EndEffectors; // Should this be relative to the bone or the body? prob bone!

		Skeletal()
		{
		}

		Skeletal(UInt8 chainedBoneCount)
			: Joints(chainedBoneCount),
			  BoneMap(chainedBoneCount),
			  ZeroPositions(chainedBoneCount)
		{
		}

		PositionList<TPOINT> getTranslatedJointPositions()
		{
			return Movement::getTranslatedJointPositions(Joints, BoneMap, ZeroPositions);
		}

		BoneFixedPositionList<TPOINT> getTranslatedEndEffectors()
		{
			return Movement::getTranslatedPositions(Joints, BoneMap, EndEffectors);
		}

		TPOINT getTranslatedEndEffector(const int endEffectorIndex)
		{
			return Movement::getTranslatedPosition(Joints, BoneMap, EndEffectors.BoneIndex[endEffectorIndex], *EndEffectors.Positions[endEffectorIndex]);
		}

		TPOINT getTranslatedBoneFixedPosition(const int parentBoneIndex, const TPOINT& position)
		{
			return Movement::getTranslatedPosition(Joints, BoneMap, parentBoneIndex, position);
		}
	};
}

#endif // MOVEMENTSKELETAL_H
