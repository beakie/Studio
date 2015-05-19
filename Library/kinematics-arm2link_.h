#ifndef KINEMATICSJOINT2D_H
#define KINEMATICSJOINT2D_H

#include "movement.2d.h"

namespace Kinematics
{

	template <typename TPRECISION>
	TPRECISION calculateJointAngleForDistance(const TPRECISION boneLength1, const TPRECISION boneLength2)
	{
		//Common::cos<TPRECISION>()
		return 0.0;
	}

	template <typename TPRECISION>
	TPRECISION calculateAngleToAlign(const TPRECISION length1, const Space2d::LineSegment2d<TPRECISION> lineSegment)
	{
		return 0.0;
	}

}

#endif // KINEMATICSJOINT2D_H
