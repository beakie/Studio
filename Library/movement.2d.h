#ifndef MOVEMENT_2D_H
#define MOVEMENT_2D_H

#include "space2d.h"

#include "movement-bonemap.h"
#include "movement-bonefixedpositionlist.h"
#include "movement-jointlist.h"
#include "movement-linear2dactuator.h"
#include "movement-positiontranslation2d_.h"
#include "movement-positionlist.h"
#include "movement-rotating2dactuator.h"

namespace Movement
{

	typedef JointList<Common::Matrix3F32> JointList2d32;
	typedef JointList<Common::Matrix3F64> JointList2d64;
	typedef JointList<Common::Matrix3F> JointList2d;

	typedef PositionList<Space2d::PlotF32> PositionList2d32;
	typedef PositionList<Space2d::PlotF64> PositionList2d64;
	typedef PositionList<Space2d::PlotF> PositionList2d;

	typedef PositionList<Space2d::PlotF32> JointPositionList2d32;
	typedef PositionList<Space2d::PlotF64> JointPositionList2d64;
	typedef PositionList<Space2d::PlotF> JointPositionList2d;

}

#endif // MOVEMENT_2D_H
