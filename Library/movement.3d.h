#ifndef MOVEMENT_3D_H
#define MOVEMENT_3D_H

#include "space3d.h"

#include "movement-actuatorcontrol.h"
#include "movement-bonemap.h"
#include "movement-bonefixedpointlist.h"
#include "movement-jointlist.h"
#include "movement-pointlist.h"
#include "movement-pointtranslation3d_.h"
#include "movement-rotationlist.h"

namespace Movement
{

	typedef ActuatorControl<Common::Matrix4F32> ActuatorControl3d32;
	typedef ActuatorControl<Common::Matrix4F64> ActuatorControl3d64;
	typedef ActuatorControl<Common::Matrix4F> ActuatorControl3d;

	typedef BoneFixedPointList<Space3d::CoordinateF32> BoneFixedPointList3d32;
	typedef BoneFixedPointList<Space3d::CoordinateF64> BoneFixedPointList3d64;
	typedef BoneFixedPointList<Space3d::CoordinateF> BoneFixedPointList3d;

	typedef JointList<Common::Matrix4F32> JointList3d32;
	typedef JointList<Common::Matrix4F64> JointList3d64;
	typedef JointList<Common::Matrix4F> JointList3d;

	typedef PointList<Space3d::CoordinateF32> PointList3d32;
	typedef PointList<Space3d::CoordinateF64> PointList3d64;
	typedef PointList<Space3d::CoordinateF> PointList3d;

	typedef RotationList<Common::Vector2F32> RotationList2d32;
	typedef RotationList<Common::Vector2F64> RotationList2d64;
	typedef RotationList<Common::Vector2F> RotationList2d;

}

#endif // MOVEMENT_3D_H
