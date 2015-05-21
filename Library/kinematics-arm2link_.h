#ifndef KINEMATICSJOINT2D_H
#define KINEMATICSJOINT2D_H

#include "movement.2d.h"

namespace Kinematics
{
	template<typename T>
	void calculateJointAngleForDistance(const double boneLength1, const double boneLength2, const double distance, double& angle, bool& isReachable)
	{
		if ((boneLength1 + boneLength2) < distance)
		{
			angle = 0;
			isReachable = false;
			return;
		}
		else
			isReachable = true;

		double boneLength1DistancePercentage = boneLength1 / (boneLength1 + boneLength2);

		double boneLength1Opposite = distance * boneLength1DistancePercentage;

		//double boneLength1Adjacent = Common::power((boneLength1Hypotenuse * boneLength1Hypotenuse) - (boneLength1 * boneLength1), 0.5);

		double boneLength1Angle = Common::sin<double>(boneLength1Opposite / boneLength1);

		angle = boneLength1Angle * 2;
	}

	template<typename T>
	bool alignRotatingArmWithCoordinate(const double bone1Length, const double bone2Length, double& rotatingJointAngle, double& reach1JointAngle, double& reach2JointAngle)
	{
		return 0.0;
	}

}

#endif // KINEMATICSJOINT2D_H
