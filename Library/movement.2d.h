#ifndef MOVEMENT_2D_H
#define MOVEMENT_2D_H

#include "space2d.h"

#include "movement-bonemap.h"
#include "movement-bonefixedpointlist.h"
#include "movement-jointlist.h"
#include "movement-linear2dactuator.h"
#include "movement-pointtranslation2d_.h"
#include "movement-pointlist.h"
#include "movement-rotating2dactuator.h"

namespace Movement
{

	typedef JointList<Common::Matrix3F32> JointList2d32;
	typedef JointList<Common::Matrix3F64> JointList2d64;
	typedef JointList<Common::Matrix3F> JointList2d;

	typedef PointList<Space2d::PlotF32> PointList2d32;
	typedef PointList<Space2d::PlotF64> PointList2d64;
	typedef PointList<Space2d::PlotF> PointList2d;

	typedef PointList<Space2d::PlotF32> JointPointList2d32;
	typedef PointList<Space2d::PlotF64> JointPointList2d64;
	typedef PointList<Space2d::PlotF> JointPointList2d;

}

#endif // MOVEMENT_2D_H
