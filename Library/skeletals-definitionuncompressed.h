#ifndef SKELETALSDEFINITIONUNCOMPRESSED_H
#define SKELETALSDEFINITIONUNCOMPRESSED_H

#include "movement-jointlist.h"

#include "skeletals-definition.h"

namespace Skeletals
{
	template <typename TPOINT, typename TMATRIX>
	struct DefinitionUncompressed : Definition<TPOINT, TMATRIX>
	{
		Movement::JointList<TMATRIX> Joints;
		Movement::JointList<TMATRIX> JointPlacement;

		DefinitionUncompressed()
			: Definition(),
			Joints()
		{
		}

		DefinitionUncompressed(UInt8 chainedBoneCount)
			: Definition(chainedBoneCount),
			Joints(chainedBoneCount)
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

#endif // SKELETALSDEFINITIONUNCOMPRESSED_H
