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

	Common::List<double> rotationList = Common::List<double>();
	rotationList.add(0);
	rotationList.add(10);
	rotationList.add(10);
	rotationList.add(0);

	for (int i = 0; i < rotationList.count(); i++)
		if (rotationList.Items[i] != 0)
			skeletal.Joints.Joints[i]->set(Space2d::getRotationMatrix(Common::radian<double>(rotationList.Items[i]), skeletal.ZeroPositions.Positions[i]->Values[0], skeletal.ZeroPositions.Positions[i]->Values[1]));

	SkeletalRender skeletalRender(&skeletal);
	skeletalRender.show();

	return a.exec();
}
