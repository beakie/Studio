#ifndef SKELETALSARMSKELETAL_H
#define SKELETALSARMSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-positionlist.h"
#include "movement-positiontranslation2d_.h"
#include "movement-positiontranslation3d_.h"

namespace Skeletals
{
	template <typename TPOINT, typename TMATRIX>
	struct ArmSkeletal
	{
		Movement::JointList<TMATRIX> Joints;
		Movement::BoneMap BoneMap;
		Movement::PositionList<TPOINT> ZeroPositions;
		TPOINT EndEffector;

		ArmSkeletal()
		{
		}

		ArmSkeletal(UInt8 chainedBoneCount)
			: Joints(chainedBoneCount),
			  BoneMap(chainedBoneCount),
			  ZeroPositions(chainedBoneCount)
		{
		}

		Movement::PositionList<TPOINT> getTranslatedJointPositions()
		{
			return Movement::getTranslatedJointPositions(Joints, BoneMap, ZeroPositions);
		}

		Movement::BoneFixedPositionList<TPOINT> getTranslatedEndEffectors()
		{
			return Movement::getTranslatedPositions(Joints, BoneMap, EndEffectorZeroPositions);
		}

		TPOINT getTranslatedJointPosition(const int jointIndex)
		{
			return Movement::getTranslatedPosition(Joints, BoneMap, jointIndex, *ZeroPositions.Positions[jointIndex]);
		}

		TPOINT getTranslatedEndEffector(const int endEffectorIndex)
		{
			return Movement::getTranslatedPosition(Joints, BoneMap, EndEffectorZeroPositions.BoneIndex[endEffectorIndex], *EndEffectorZeroPositions.Positions[endEffectorIndex]);
		}

		TPOINT getTranslatedBoneFixedPosition(const int parentBoneIndex, const TPOINT& position)
		{
			return Movement::getTranslatedPosition(Joints, BoneMap, parentBoneIndex, position);
		}
	};
}

#endif // SKELETALSARMSKELETAL_H
