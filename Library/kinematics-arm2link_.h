#ifndef KINEMATICSJOINT2D_H
#define KINEMATICSJOINT2D_H

#include "movement.2d.h"

namespace Kinematics
{
	void calculateJointAngleForDistance(const double boneLength1, const double boneLength2, const double distance, double& angle, bool& isReachable);

	bool alignRotatingArmWithCoordinate(const double bone1Length, const double bone2Length, double& rotatingJointAngle, double& reach1JointAngle, double& reach2JointAngle);

}

#endif // KINEMATICSJOINT2D_H
