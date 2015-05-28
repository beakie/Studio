#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bonefixedpositionlist.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-positionlist.h"
#include "movement-positiontranslation2d_.h"
#include "movement-positiontranslation3d_.h"

// THE WHOLE OF THIS SKELETAL STUFF IS JUST ONE TYPE OF IMPLEMENTATION... WHAT MATTERS ARE ITS COMPONENT AND THE STATIC METHODS THAT IMPLEMENT THEM!!!!!!!!!
// DONT LET THIS BE FORGOTTEN... IT IS VITALLY IMPORTANT!!!
// IF MAKING A SINGLE ARM MODEL, HAVING A LIST OF END EFFECTORS IS A WASTE OF MEMORY, AS LONG AS THERE ARE FUNCTIONS TO DO WHATEVER IS NEEDED FOR EVERY IMPLEMENTATION...
//   ... THEN I AM GOOD!

namespace Movement
{
	template <typename TPOINT, typename TMATRIX>
	struct Skeletal
	{
		JointList<TMATRIX> Joints; // Does this belong here? How is any of this stuff actually hanging together?
		BoneMap BoneMap;
		PositionList<TPOINT> ZeroPositions; // This should be the position of the axis in 3d space. Not the bone ends!
		BoneFixedPositionList<TPOINT> EndEffectorZeroPositions; // Should this be relative to the bone or the body? prob bone!

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

#endif // MOVEMENTSKELETAL_H
