#include "kinematics-arm2link_.h"

void Kinematics::calculateFlexJointAngleForDistance(const double boneLength1, const double boneLength2, const double distance, double& angle, bool& isReachable)
{
	if ((boneLength1 + boneLength2) < distance)
	{
		angle = 2.0;
		isReachable = false;
		return;
	}
	else
		isReachable = true;

	double boneLength1DistancePercentage = boneLength1 / (boneLength1 + boneLength2);

	double boneLength1Adjacent = distance * boneLength1DistancePercentage;

	double boneLength1Angle = Common::cos<double>(boneLength1Adjacent / boneLength1);

	angle = boneLength1Angle * 2;
}

bool Kinematics::calculateRotateJointForCoordinateAlignment(const double bone1Length, const double bone2Length, double& rotatingJointAngle, double& reach1JointAngle, double& reach2JointAngle)
{
	return 0.0;
}
