#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "space2d.h"
#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-positiontranslation_.h"
#include "movement-positionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	typedef JointList<Common::Matrix3F32> JointList2d32;
	typedef JointList<Common::Matrix3F64> JointList2d64;
	typedef JointList<Common::Matrix3F> JointList2d;

	typedef JointList<Common::Matrix4F32> JointList3d32;
	typedef JointList<Common::Matrix4F64> JointList3d64;
	typedef JointList<Common::Matrix4F> JointList3d;

	typedef PositionList<Space2d::PlotF32> PositionList2d32;
	typedef PositionList<Space2d::PlotF64> PositionList2d64;
	typedef PositionList<Space2d::PlotF> PositionList2d;

	typedef PositionList<Space3d::CoordinateF32> PositionList3d32;
	typedef PositionList<Space3d::CoordinateF64> PositionList3d64;
	typedef PositionList<Space3d::CoordinateF> PositionList3d;

	typedef PositionList<Space2d::PlotF32> JointPositionList2d32;
	typedef PositionList<Space2d::PlotF64> JointPositionList2d64;
	typedef PositionList<Space2d::PlotF> JointPositionList2d;

	typedef PositionList<Space3d::CoordinateF32> JointPositionList3d32;
	typedef PositionList<Space3d::CoordinateF64> JointPositionList3d64;
	typedef PositionList<Space3d::CoordinateF> JointPositionList3d;

	typedef Skeletal<Space2d::PlotF32, Common::Matrix3F32> Skeletal2d32;
	typedef Skeletal<Space2d::PlotF64, Common::Matrix3F64> Skeletal2d64;
	typedef Skeletal<Space2d::PlotF, Common::Matrix3F> Skeletal2d;

	typedef Skeletal<Space3d::CoordinateF32, Common::Matrix4F32> Skeletal3d32;
	typedef Skeletal<Space3d::CoordinateF64, Common::Matrix4F64> Skeletal3d64;
	typedef Skeletal<Space3d::CoordinateF, Common::Matrix4F> Skeletal3d;

}

#endif // MOVEMENT_H
