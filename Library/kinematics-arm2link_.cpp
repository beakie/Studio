#include "kinematics-arm2link_.h"

void Kinematics::calculateJointAngleForDistance(const double boneLength1, const double boneLength2, const double distance, double& angle, bool& isReachable)
{
	if ((boneLength1 + boneLength2) < distance)
	{
		isReachable = false;
		angle = 0;
		return;
	}

	isReachable = true;
	angle = Common::sin<double>((distance * (boneLength1 / (boneLength1 + boneLength2))) / boneLength1) * 2;
}

bool Kinematics::alignRotatingArmWithCoordinate(const double bone1Length, const double bone2Length, double& rotatingJointAngle, double& reach1JointAngle, double& reach2JointAngle)
{
	return 0.0;
}
