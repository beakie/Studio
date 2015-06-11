#ifndef KINEMATICS_JOINT2D_H
#define KINEMATICS_JOINT2D_H

#include "movement.2d.h"

namespace Kinematics
{
	void calculateAngleForFlexJointDistance(const double boneLength1, const double boneLength2, const double distance, double& angle, bool& isReachable);

	void calculateAlignmentForFlexJointDistance(const double boneLength1, const double boneLength2, const double distance, double& angle);

	bool calculateAngleForRotateJointCoordinateAlignment(const double bone1Length, const double bone2Length, double& rotatingJointAngle, double& reach1JointAngle, double& reach2JointAngle);
}

#endif // KINEMATICS_JOINT2D_H
