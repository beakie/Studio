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

	// Skeletal Render

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

template <typename TPOINT, typename TMATRIX>
class RenderQtWidget
{
	int CenterX;
	int CenterY;

	// **

	// I could add pointers to each collection. Then I could create overloads for these functions that don't require collections as parameters.

	// **

	void renderZeroBones(const Movement::BoneMap & boneMap, Common::ICollection<TPOINT, UInt8> & zeroPositions, QPen & pen)
	{
		renderLineList(SkeletalRender::getJointToJointBoneLines(boneMap, zeroPositions), painter, this->zeroPositionBonePen, CenterX, CenterY);
	}

	// **

	void renderLineList(Common::ICollection<Common::Tuple2<Space2d::PlotF, Space2d::PlotF>, UInt8> & lineList, QPainter& painter, QPen pen, const int offsetX, const int offsetY)
	{
		painter.setPen(pen);

		for (int i = 0; i < lineList.count(); i++)
			painter.drawLine(lineList.operator[](i).Item1.Values[0] + offsetX, lineList.operator[](i).Item1.Values[1] + offsetY, lineList.operator[](i).Item2.Values[0] + offsetX, lineList.operator[](i).Item2.Values[1] + offsetY);
	}

	void renderPointList(Common::ICollection<TPOINT, UInt8> & pointList, QPainter & painter, QPen pen, QBrush brush, const int jointRadius, const int offsetX, const int offsetY)
	{
		painter.setPen(pen);
		painter.setBrush(brush);

		for (int i = 0; i < pointList.count(); i++)
			painter.drawEllipse(pointList.operator[](i).Values[0] + offsetX - jointRadius, pointList.operator[](i).Values[1] + offsetY - jointRadius, jointRadius * 2, jointRadius * 2);
	}
};
