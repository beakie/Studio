#ifndef MOVEMENTPOSITIONTRANSLATION2D_H
#define MOVEMENTPOSITIONTRANSLATION2D_H

#include "space2d.h"

#include "movement-bonefixedpositionlist.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-positionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	template <typename TVALUE>
	Common::Vector2<TVALUE> getTranslatedPosition(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const int parentBoneIndex, const Common::Vector2<TVALUE>& position)
	{
		return Space2d::multiplyPlotByMatrix(position, boneMap.getBoneTransformMatrix(jointList, parentBoneIndex));
	}

	template <typename TVALUE>
	PositionList<Common::Vector2<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const PositionList<Common::Vector2<TVALUE>>& jointPositions)
	{
		PositionList<Common::Vector2<TVALUE>> translatedJoints = PositionList<Common::Vector2<TVALUE>>(jointPositions.PositionCount);

		for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
			translatedJoints.Positions[i]->operator=(getTranslatedPosition(jointList, boneMap, i, *jointPositions.Positions[i]));

		return translatedJoints;
	}

	template <typename TVALUE>
	BoneFixedPositionList<Common::Vector2<TVALUE>> getTranslatedPositions(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const BoneFixedPositionList<Common::Vector2<TVALUE>>& boneFixedPositions)
	{
		BoneFixedPositionList<Common::Vector2<TVALUE>> translatedPositions = BoneFixedPositionList<Common::Vector2<TVALUE>>(boneFixedPositions.PositionCount);

		for (UInt8 i = 0; i < boneFixedPositions.PositionCount; i++)
			translatedPositions.Positions[i]->operator=(getTranslatedPosition(jointList, boneMap, boneFixedPositions.BoneIndex[i], *boneFixedPositions.Positions[i]));

		return translatedPositions;
	}

}

#endif // MOVEMENTPOSITIONTRANSLATION2D_H
