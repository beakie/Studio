#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrender.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Movement::Skeletal2d skeletal(5);

	skeletal.ZeroPositions.Positions[0]->operator=({ 100, 0 });
	skeletal.ZeroPositions.Positions[1]->operator=({ 200, 0 });
	skeletal.ZeroPositions.Positions[2]->operator=({ 300, 0 });
	skeletal.ZeroPositions.Positions[3]->operator=({ 400, 0 });
	skeletal.ZeroPositions.Positions[4]->operator=({ 500, 0 });

	bool isReachable;
	double flexAngleRadian;
	Kinematics::calculateAngleForFlexJointDistance(100, 100, 50, flexAngleRadian, isReachable);
	double flexAngleDegree = Common::degree(flexAngleRadian);

	double rotateAngleRadian;
	Kinematics::calculateAlignmentForFlexJointDistance(100, 100, 50, rotateAngleRadian);
	double rotateAngleDegree = Common::degree(rotateAngleRadian);

	Common::List<double> rotationList = Common::List<double>();
	rotationList.add(5);
	rotationList.add(5);
	rotationList.add(5);
	rotationList.add(5);
	//	rotationList.add(180 - rotateAngleDegree);
//	rotationList.add(180 - flexAngleDegree);

	for (int i = 0; i < rotationList.count(); i++)
		if (rotationList.Items[i] != 0)
			skeletal.Joints.Joints[i]->set(Space2d::getRotationMatrix(Common::radian<double>(rotationList.Items[i]), skeletal.ZeroPositions.Positions[i]->Values[0], skeletal.ZeroPositions.Positions[i]->Values[1]));

	SkeletalRender skeletalRender(&skeletal);
	skeletalRender.show();

	return a.exec();
}
