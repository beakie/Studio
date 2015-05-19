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
	bool alignRotatingArmWithCoordinate(const TVALUE bone1Length, const TVALUE bone2Length, TVALUE& rotatingJointAngle, TVALUE& reach1JointAngle, TVALUE& reach2JointAngle)
	{
		return 0.0;
	}

	template <typename TVALUE>
	bool alignRotatingArmWithCoordinate(const TVALUE bone1Length, const TVALUE bone2Length, Common::Matrix4<TVALUE>& rotatingJointMatrix, Common::Matrix4<TVALUE>& reach1JointMatrix, Common::Matrix4<TVALUE>& reach2JointMatrix)
	{
		TVALUE rotatingJointAngle;
		TVALUE reach1JointAngle;
		TVALUE reach2JointAngle;

		alignRotatingArmWithCoordinate(bone1Length, bone2Length, rotatingJointAngle, reach1JointAngle, reach2JointAngle);

		//rotatingJointMatrix = Space3d::getRotationMatrix()
	}

}

#endif // KINEMATICSJOINT2D_H
