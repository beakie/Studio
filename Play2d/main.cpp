#include <QApplication>

#include "../Library/studio.h"

#include "skeletalrenderwidget.h"

template <typename T>
struct IFoo
{
	virtual void test(T param) = 0;
};

struct Bar : IFoo<int>
{
	void test(int param)
	{
	}
};

struct Baz
{
};

struct Qux : IFoo<Baz&>
{
	void test(Baz& param)
	{
	}
};

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

	Movement::Linear2dActuator<float> linearActuator;
	Movement::Rotating2dActuator<float> rotatingActuator;

	/*
	Common::Collection<unsigned int, int> collection;
	Common::List<unsigned int, int> list;

	collection = Common::Collection<unsigned int, int>();
	collection = Common::Collection<unsigned int, int>(5, 1);
	collection = Common::Collection<unsigned int, int>(collection);

	list = Common::List<unsigned int, int>();
//	list = Common::List<unsigned int, int>(collection);
	list = Common::List<unsigned int, int>(list);
	*/

	Bar bar = Bar();
	int i = 123;
	bar.test(i);

	Qux qux = Qux();
	Baz b = Baz();
	qux.test(b);

	return a.exec();
}
