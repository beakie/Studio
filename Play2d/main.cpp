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

	int jointIndex = 1;
	double jointRotation = Common::radian<double>(10.0);

	skeletal.Joints.Joints[jointIndex]->set(Space2d::getRotationMatrix(jointRotation, skeletal.ZeroPositions.Positions[jointIndex]->Values[0], skeletal.ZeroPositions.Positions[jointIndex]->Values[1]));

	SkeletalRender skeletalRender(&skeletal);
	skeletalRender.show();

	return a.exec();
}
