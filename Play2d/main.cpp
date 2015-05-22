#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrender.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Movement::Skeletal2d skeletal(2);

	skeletal.ZeroPositions.Positions[0]->operator=({ 100, 0 });
	skeletal.ZeroPositions.Positions[1]->operator=({ 200, 0 });

	bool isReachable;
	double angleRadian;
	Kinematics::calculateFlexJointAngleForDistance(100, 100, 141.421356237, angleRadian, isReachable);
	
	double angleDegree = Common::degree(angleRadian);

	Common::List<double> rotationList = Common::List<double>();
	rotationList.add(180 - angleDegree);

	for (int i = 0; i < rotationList.count(); i++)
		if (rotationList.Items[i] != 0)
			skeletal.Joints.Joints[i]->set(Space2d::getRotationMatrix(Common::radian<double>(rotationList.Items[i]), skeletal.ZeroPositions.Positions[i]->Values[0], skeletal.ZeroPositions.Positions[i]->Values[1]));

	SkeletalRender skeletalRender(&skeletal);
	skeletalRender.show();

	return a.exec();
}
