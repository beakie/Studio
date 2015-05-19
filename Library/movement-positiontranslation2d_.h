#ifndef MOVEMENTPOSITIONTRANSLATION_H
#define MOVEMENTPOSITIONTRANSLATION_H

#include "space2d.h"

#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-positionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	template <typename TVALUE>
	PositionList<Common::Vector2<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const PositionList<Common::Vector2<TVALUE>>& jointPositions)
	{
		PositionList<Common::Vector2<TVALUE>> translatedJoints = PositionList<Common::Vector2<TVALUE>>(jointPositions.PositionCount);

		for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
			translatedJoints.Positions[i]->operator=(Space2d::multiplyPlotByMatrix(*jointPositions.Positions[i], boneMap.getBoneTransformMatrix(jointList, i)));

		return translatedJoints;
	}

	template <typename TVALUE>
	PositionList<Common::Vector2<TVALUE>> getTranslatedJoints(const Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>& skeletal)
	{
		return getTranslatedJoints<TVALUE>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

}

#endif // MOVEMENTPOSITIONTRANSLATION_H
