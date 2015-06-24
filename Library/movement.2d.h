#ifndef MOVEMENT_2D_H
#define MOVEMENT_2D_H

#include "space2d.h"

#include "movement-bonemap.h"
#include "movement-bonefixedpointlist.h"
#include "movement-jointlist.h"
#include "movement-linear2dactuator.h"
#include "movement-pointlist.h"
#include "movement-pointtranslation2d_.h"
#include "movement-rotating2dmotor.h"
#include "movement-rotating2dservo.h"
#include "movement-rotating2dstepper.h"
#include "movement-rotationlist.h"

namespace Movement
{

	typedef BoneFixedPointList<Space2d::PlotF32> BoneFixedPointList2d32;
	typedef BoneFixedPointList<Space2d::PlotF64> BoneFixedPointList2d64;
	typedef BoneFixedPointList<Space2d::PlotF> BoneFixedPointList2d;

	typedef JointList<Common::Matrix3F32> JointList2d32;
	typedef JointList<Common::Matrix3F64> JointList2d64;
	typedef JointList<Common::Matrix3F> JointList2d;

	typedef PointList<Space2d::PlotF32> PointList2d32;
	typedef PointList<Space2d::PlotF64> PointList2d64;
	typedef PointList<Space2d::PlotF> PointList2d;

	typedef RotationList<Common::Vector3F32> RotationList3d32;
	typedef RotationList<Common::Vector3F64> RotationList3d64;
	typedef RotationList<Common::Vector3F> RotationList3d;

}

#endif // MOVEMENT_2D_H
