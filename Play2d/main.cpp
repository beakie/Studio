
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

	skeletal.Joints.Joints[2]->set(Space2d::getRotationMatrix(-1.57079633));

	SkeletalRender skeletalRender(&skeletal);

	skeletalRender.show();

	return a.exec();
}
