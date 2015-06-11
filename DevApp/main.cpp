#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <iostream>

#include "../Library/studio.h"

/*
template <>
static Picture::Rgb8 Common::getDefault<Picture::Rgb8>()
{
return Picture::Rgb8(1, 2, 3);
}
*/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	/*

	std::cout << "Starting\n";

	//Common::Image16U8 testImageb = Common::Image16U8(10, 10, 0); // Errors
	Common::Image8F32 testImage = Common::Image8F32(100, 100, 0.51);

	Picture::Image8Rgb8 testImageDisk = Picture::Qt::getArgb8Image<UInt8>(QImage("c:\\Test8.jpg"))
	.getImage<UInt8>(&Picture::getSelect1QuadChanPixelConv<UInt8>()).invert()
	.getImage<Picture::Rgb8>(&Picture::TriColorMapScaledPixelConv<Common::UnitInterval32, UInt8, UInt8>(&Picture::getRgbJetColorMap<Common::UnitInterval32>()));

	QWidget widget;
	QLabel* label = new QLabel(&widget);
	label->setPixmap(Picture::Qt::getQPixmap<UInt8>(testImageDisk));
	label->show();
	widget.show();

	std::cout << "Finished\n";

	Picture::Rgb8 rg = Picture::getGreenRgb<UInt8>();

	Common::Vector3<Common::UnitIntervalMax> ui = Picture::getGreenRgb();

	Common::UnitInterval64 ppp = 0.99;
	bool x = Common::isValidUnitInterval(ppp);
	Common::UnitInterval64 qqq = Common::trimUnitInterval(ppp);

	Common::Nullable<UInt8> kkk = 1;
	UInt8 oooi = kkk.getValueOrDefault();

	Common::Nullable<Picture::Rgb8> r111 = 1;
	Picture::Rgb8 r222 = r111;

	Common::List<Common::Nullable<int>> l = Common::List<Common::Nullable<int>>();
	l.add(2);
	l.add(Common::Nullable<int>(1));
	l.add(Common::Nullable<int>());
	l.add(Common::NullableNull());
	l.add(Common::Null);

	Common::UnitVector3 uv3 = Common::getUnitVector(Common::Vector3F(0, 1, 86)); // wrong?!

	Common::UnitVector2 uv2 = Common::getUnitVector(Common::Vector2F(-2, 1)); // wrong?!
	FloatMax test2 = pow(pow(uv2.Values[0], 2) + pow(uv2.Values[1], 2), 0.5);

	//Common::abs(Common::Vector2<float>(0, 0));

	Common::Matrix3F rot = Space2d::getRotationMatrix(Common::radian(46.0), Common::Vector2F(10.0, 20.0));

	*/

	/*

	Picture::RgbToHsvPixelConv<Common::UnitIntervalMax> rgbHsvConv = Picture::RgbToHsvPixelConv<Common::UnitIntervalMax>();
	Common::Vector3<Common::UnitIntervalMax> hsvPixel = rgbHsvConv.convertPixel(Common::Vector3<Common::UnitIntervalMax>(0.0392156862745098, 0.0784313725490196, 0.1176470588235294));

	Picture::HsvToRgbPixelConv<Common::UnitIntervalMax> hsvRgbConv = Picture::HsvToRgbPixelConv<Common::UnitIntervalMax>();
	Common::Vector3<Common::UnitIntervalMax> rgb1Pixel = hsvRgbConv.convertPixel(hsvPixel);

	Picture::RgbToCmykPixelConv<Common::UnitIntervalMax> rgbCmykConv = Picture::RgbToCmykPixelConv<Common::UnitIntervalMax>();
	Common::Vector4<Common::UnitIntervalMax> cmykPixel = rgbCmykConv.convertPixel(rgb1Pixel);

	Picture::CmykToRgbPixelConv<Common::UnitIntervalMax> cmykRgbConv = Picture::CmykToRgbPixelConv<Common::UnitIntervalMax>();
	Common::Vector3<Common::UnitIntervalMax> rgb2Pixel = cmykRgbConv.convertPixel(cmykPixel);

	Picture::RgbToArgbPixelConv<Common::UnitIntervalMax> rgbRgbaConv = Picture::RgbToArgbPixelConv<Common::UnitIntervalMax>();
	Common::Vector4<Common::UnitIntervalMax> argbPixel = rgbRgbaConv.convertPixel(rgb2Pixel);

	Picture::ArgbToRgbPixelConv<Common::UnitIntervalMax> rgbaRgbConv = Picture::ArgbToRgbPixelConv<Common::UnitIntervalMax>();
	Common::Vector3<Common::UnitIntervalMax> rgb3Pixel = rgbaRgbConv.convertPixel(argbPixel);

	*/

	/*
	// OLD STUFF
	Skeletals::BasicSkeletal<> skeletal = Skeletals::BasicSkeletal<>();

	Movement::JointList<> jointList = Movement::JointList<>();

	skeletal.addArm(&jointList.addJoint())
	.addBone(&jointList.addJoint())
	.addBone(&jointList.addJoint());

	Movement::ActuatorManager64 actuatorManager = Movement::ActuatorManager64();

	actuatorManager.addActuator(Movement::RotatingActuator64(Common::Vector3F(0.0, 0.0, 0.0), Common::Vector3F(10.0, 10.0, 10.0)));

	actuatorManager.addBoneLink(actuatorManager.Actuators[0], skeletal.Arms[0]);
	actuatorManager.addBoneLink(&actuatorManager.addActuator(Movement::LinearActuator64(Common::Vector3F(0.0, 0.0, 0.0), Common::Vector3F(10.0, 10.0, 10.0))), skeletal.Arms[0]->ChildrenBones[0]);

	Common::Matrix4F transformMatrix = actuatorManager.setPosition(0, 0.5).getTransformMatrix(0);
	*/

	/*
	//Skeletals::BasicSkeletal3d skeletal(4);

	//skeletal.ZeroPositions.Positions[1]->operator=({ 100, 0, 0 }); // Should these be decimal? What space coordinates am i using? Does it matter if I'm just applying to matrices?
	//skeletal.ZeroPositions.Positions[2]->operator=({ 200, 0, 0 });
	//skeletal.ZeroPositions.Positions[3]->operator=({ 300, 0, 0 });

	//Common::ManagedList<Space3d::LineSegment3d<>, UInt8> lineList = BodyRender::getJointToJointBones(skeletal);
	*/

	// Missing UInt32 bound stuff

	/*
	//Common::ToUnitIntervalPixelConv<Int8> convToUnitInterval = Common::ToUnitIntervalPixelConv<Int8>();
	//Common::FromUnitIntervalPixelConv<Int8> convFromUnitInterval = Common::FromUnitIntervalPixelConv<Int8>();

	//Common::UnitIntervalMax i = convToUnitInterval.convertPixel(13);
	//Int8 ui = convFromUnitInterval.convertPixel(i);
	*/

	Skeletals::Implemented2d skeletal(4);

	skeletal.ZeroPositions.Positions[1]->operator=({ 100, 0 }); // Should these be decimal? What space coordinates am i using? Does it matter if I'm just applying to matrices?
	skeletal.ZeroPositions.Positions[2]->operator=({ 200, 0 });
	skeletal.ZeroPositions.Positions[3]->operator=({ 300, 0 });

	Common::ManagedList<Common::Tuple2<Space2d::PlotF64, Space2d::PlotF64>, UInt8> lineList = SkeletalRender::getJointToJointBoneLines(skeletal.BoneMap, skeletal.ZeroPositions);

	return a.exec();
}
