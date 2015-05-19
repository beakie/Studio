#ifndef KINEMATICSJOINT2D_H
#define KINEMATICSJOINT2D_H

#include "movement.2d.h"

namespace Kinematics
{

	template <typename TVALUE>
	TVALUE calculateJointAngleForDistance(const TVALUE boneLength1, const TVALUE boneLength2)
	{
		//Common::cos<TVALUE>()
		return 0.0;
	}

	template <typename TVALUE>
	bool alignRotatingArmWithCoordinate(TVALUE& rotatingJoint, TVALUE& reachJoint1, TVALUE& reachJoint2)
	{
		return 0.0;
	}

}

#endif // KINEMATICSJOINT2D_H
