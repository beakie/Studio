#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrenderwidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Skeletals::Implemented2d skeletal(5);

	skeletal.ZeroPositions.Points[0]->operator=({ 0, 0 });
	skeletal.ZeroPositions.Points[1]->operator=({ 75, 0 });
	skeletal.ZeroPositions.Points[2]->operator=({ 100, 0 });
	skeletal.ZeroPositions.Points[3]->operator=({ 150, 0 });
	skeletal.ZeroPositions.Points[4]->operator=({ 200, 0 });

	bool isReachable;
	double flexAngleRadian;
	Kinematics::calculateAngleForFlexJointDistance(50, 50, 50, flexAngleRadian, isReachable);
	double flexAngleDegree = Common::degree(flexAngleRadian);

	Common::List<double> rotationList = Common::List<double>();
	//rotationList.add(180 - flexAngleDegree);
	rotationList.add(45);
	rotationList.add(45);
	rotationList.add(45);
	rotationList.add(45);
	rotationList.add(45);

	for (int i = 0; i < rotationList.count(); i++)
		if (rotationList.Items[i] != 0)
			skeletal.Joints.Joints[i]->set(Space2d::getRotationMatrix(Common::radian<double>(rotationList.Items[i]), skeletal.ZeroPositions.Points[i]->Values[0], skeletal.ZeroPositions.Points[i]->Values[1]));

	SkeletalRenderWidget<Space2d::PlotF, Common::Matrix3F> skeletalRenderWidget(&skeletal);
	skeletalRenderWidget.show();

	//skeletalRenderWidget.Skeletal->getTranslatedEndEffectors();
	//skeletalRenderWidget.Skeletal->getTranslatedJointPositions();
	//skeletalRenderWidget.Skeletal->getTranslatedEndEffector(0);
	//skeletalRenderWidget.Skeletal->getTranslatedBoneFixedPosition(0, Space2d::PlotF64(10, 10));
	//skeletalRenderWidget.Skeletal->getTranslatedJointPosition(0);

	SkeletalRender::getJointToBoneFixedPositionLines(Movement::getTranslatedJointPositions(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions), skeletal.EndEffectorZeroPositions);

	Movement::ActuatorControl2d actuatorControl = Movement::ActuatorControl2d();
	actuatorControl.add(Movement::Linear2dActuator<FloatMax>());
	actuatorControl.add(Movement::Rotating2dServo<FloatMax>());
	actuatorControl.add(Movement::Rotating2dStepper<FloatMax>());
	actuatorControl.add(Movement::Rotating2dMotor<FloatMax>());
	
	// This method can be used by some derivative of the angle calc functions. They know what type
	//   they expect, and can cast whats needed after being supplied an ActuatorControl and indexes.
	actuatorControl.get<Movement::Linear2dActuator<FloatMax>>(0).Translation = 2;

	return a.exec();
}
