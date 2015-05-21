#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrender.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Movement::Skeletal2d skeletal(2);

	skeletal.ZeroPositions.Positions[0]->operator=({ 100, 0 });
	skeletal.ZeroPositions.Positions[1]->operator=({ 220, 0 });

	Common::List<double> rotationList = Common::List<double>();
	rotationList.add(0);
	rotationList.add(10);

	for (int i = 0; i < rotationList.count(); i++)
		if (rotationList.Items[i] != 0)
			skeletal.Joints.Joints[i]->set(Space2d::getRotationMatrix(Common::radian<double>(rotationList.Items[i]), skeletal.ZeroPositions.Positions[i]->Values[0], skeletal.ZeroPositions.Positions[i]->Values[1]));

	bool isReachable;

	Kinematics::calculateJointAngleForDistance(100, 120, 50, rotationList[1], isReachable);

	SkeletalRender skeletalRender(&skeletal);
	skeletalRender.show();

	return a.exec();
}
