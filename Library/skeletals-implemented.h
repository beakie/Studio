#ifndef SKELETALS_DEFINITIONUNCOMPRESSED_H
#define SKELETALS_DEFINITIONUNCOMPRESSED_H

#include "movement-jointlist.h"

#include "skeletals-definition.h"

namespace Skeletals
{
	template <typename TPOINT, typename TMATRIX>
	struct Implemented : Definition<TPOINT, TMATRIX>
	{
		Movement::JointList<TMATRIX> Joints; // Points multiplied by this matrix will transform as though fixed to joint

		Implemented()
			: Definition(),
			Joints()
		{
		}

		Implemented(UInt8 chainedBoneCount)
			: Definition(chainedBoneCount),
			Joints(chainedBoneCount)
		{
		}

		void init()
		{
			JointPlacement.populate(BoneMap, ZeroPositions, ZeroRotations);
		}

		Movement::PointList<TPOINT> getTranslatedJointPositions()
		{
			return Movement::getTranslatedJointPositions(Joints, BoneMap, ZeroPositions);
		}

		Movement::BoneFixedPointList<TPOINT> getTranslatedEndEffectors()
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

#endif // SKELETALS_DEFINITIONUNCOMPRESSED_H
