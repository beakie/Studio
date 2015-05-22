#include "kinematics-arm2link_.h"

void Kinematics::calculateAngleForFlexJointDistance(const double boneLength1, const double boneLength2, const double distance, double& angle, bool& isReachable)
{
	if ((boneLength1 + boneLength2) < distance)
	{
		angle = Common::Pi;
		isReachable = false;
		return;
	}

	isReachable = true;
	angle = Common::acos<double>(((boneLength1 * boneLength1) + (boneLength1 * boneLength1) - (distance * distance)) / (2 * boneLength1 * boneLength2));
}

void Kinematics::calculateAlignmentForFlexJointDistance(const double boneLength1, const double boneLength2, const double distance, double& angle)
{
}

bool Kinematics::calculateAngleForRotateJointCoordinateAlignment(const double bone1Length, const double bone2Length, double& rotatingJointAngle, double& reach1JointAngle, double& reach2JointAngle)
{
	return 0.0;
}
