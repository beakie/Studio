
#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrender.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Movement::Skeletal2d skeletal(4);

	skeletal.ZeroPositions.Positions[1]->operator=({ 100, 10 });
	skeletal.ZeroPositions.Positions[2]->operator=({ 200, 10 });
	skeletal.ZeroPositions.Positions[3]->operator=({ 300, 10 });

	Common::ManagedList<Space2d::LineSegment2d<>, UInt8> lineList = BodyRender::getJointToJointBones(skeletal);

	SkeletalRender skeletalRender(&skeletal);

	//skeletalRender.renderSkeletal2d(skeletal);

	skeletalRender.show();

	return a.exec();
}
