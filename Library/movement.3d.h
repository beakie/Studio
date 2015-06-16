#ifndef MOVEMENT_3D_H
#define MOVEMENT_3D_H

#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-bonefixedpointlist.h"
#include "movement-jointlist.h"
#include "movement-positiontranslation3d_.h"
#include "movement-pointlist.h"

namespace Movement
{

	typedef JointList<Common::Matrix4F32> JointList3d32;
	typedef JointList<Common::Matrix4F64> JointList3d64;
	typedef JointList<Common::Matrix4F> JointList3d;

	typedef PointList<Space3d::CoordinateF32> PointList3d32;
	typedef PointList<Space3d::CoordinateF64> PointList3d64;
	typedef PointList<Space3d::CoordinateF> PointList3d;

	typedef PointList<Space3d::CoordinateF32> JointPointList3d32;
	typedef PointList<Space3d::CoordinateF64> JointPointList3d64;
	typedef PointList<Space3d::CoordinateF> JointPointList3d;

}

#endif // MOVEMENT_3D_H
