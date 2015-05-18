#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrender.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Movement::Skeletal2d skeletal(4);

	skeletal.ZeroPositions.Positions[1]->operator=({ 100, 0 });
	skeletal.ZeroPositions.Positions[2]->operator=({ 200, 0 });
	skeletal.ZeroPositions.Positions[3]->operator=({ 300, 0 });

	int jointIndex1 = 1;
	double jointRotation1 = Common::radian<double>(10.0);
	skeletal.Joints.Joints[jointIndex1]->set(Space2d::getRotationMatrix(jointRotation1, skeletal.ZeroPositions.Positions[jointIndex1]->Values[0], skeletal.ZeroPositions.Positions[jointIndex1]->Values[1]));

	int jointIndex2 = 2;
	double jointRotation2 = Common::radian<double>(10.0);
	skeletal.Joints.Joints[jointIndex2]->set(Space2d::getRotationMatrix(jointRotation2, skeletal.ZeroPositions.Positions[jointIndex2]->Values[0], skeletal.ZeroPositions.Positions[jointIndex2]->Values[1]));

	SkeletalRender skeletalRender(&skeletal);
	skeletalRender.show();

	return a.exec();
}
