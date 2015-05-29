#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrenderwidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Skeletals::BasicSkeletal2d skeletal(5);

	skeletal.ZeroPositions.Positions[0]->operator=({ 0, 0 });
	skeletal.ZeroPositions.Positions[1]->operator=({ 75, 0 });
	skeletal.ZeroPositions.Positions[2]->operator=({ 100, 0 });
	skeletal.ZeroPositions.Positions[3]->operator=({ 150, 0 });
	skeletal.ZeroPositions.Positions[4]->operator=({ 200, 0 });

	bool isReachable;
	double flexAngleRadian;
	Kinematics::calculateAngleForFlexJointDistance(50, 50, 50, flexAngleRadian, isReachable);
	double flexAngleDegree = Common::degree(flexAngleRadian);

	Common::List<double> rotationList = Common::List<double>();
	//rotationList.add(180 - flexAngleDegree);
	rotationList.add(0);
	rotationList.add(90); // why does having two (or more) 90s give a diff first joint angle than a single 90

	for (int i = 0; i < rotationList.count(); i++)
		if (rotationList.Items[i] != 0)
			skeletal.Joints.Joints[i]->set(Space2d::getRotationMatrix(Common::radian<double>(rotationList.Items[i]), skeletal.ZeroPositions.Positions[i]->Values[0], skeletal.ZeroPositions.Positions[i]->Values[1]));

	SkeletalRenderWidget<Space2d::PlotF, Common::Matrix3F> skeletalRenderWidget(&skeletal);
	skeletalRenderWidget.show();

	//skeletalRenderWidget.Skeletal->getTranslatedEndEffectors();
	//skeletalRenderWidget.Skeletal->getTranslatedJointPositions();
	//skeletalRenderWidget.Skeletal->getTranslatedEndEffector(0);
	//skeletalRenderWidget.Skeletal->getTranslatedBoneFixedPosition(0, Space2d::PlotF64(10, 10));
	//skeletalRenderWidget.Skeletal->getTranslatedJointPosition(0);

	return a.exec();
}
