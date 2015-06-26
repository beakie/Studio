#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrenderwidget.h"

// Removed 26/06/2015 12:36

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// Skeletal

	Skeletals::Implemented2d skeletal(5);

	skeletal.ZeroPositions.Points[0]->operator=({ 0, 0 });
	skeletal.ZeroPositions.Points[1]->operator=({ 50, 0 });
	skeletal.ZeroPositions.Points[2]->operator=({ 100, 0 });
	skeletal.ZeroPositions.Points[3]->operator=({ 150, 0 });
	skeletal.ZeroPositions.Points[4]->operator=({ 200, 0 });

	SkeletalRenderWidget<Space2d::PlotF, Common::Matrix3F> skeletalRenderWidget(&skeletal);
	skeletalRenderWidget.show();

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
