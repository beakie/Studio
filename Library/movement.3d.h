#ifndef MOVEMENT_3D_H
#define MOVEMENT_3D_H

#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-bonepositionlist.h"
#include "movement-jointlist.h"
#include "movement-positiontranslation3d_.h"
#include "movement-positionlist.h"
#include "movement-skeletal.h"
#include "movement-skeletalmanifest.h"

namespace Movement
{

	typedef JointList<Common::Matrix4F32> JointList3d32;
	typedef JointList<Common::Matrix4F64> JointList3d64;
	typedef JointList<Common::Matrix4F> JointList3d;

	typedef PositionList<Space3d::CoordinateF32> PositionList3d32;
	typedef PositionList<Space3d::CoordinateF64> PositionList3d64;
	typedef PositionList<Space3d::CoordinateF> PositionList3d;

	typedef PositionList<Space3d::CoordinateF32> JointPositionList3d32;
	typedef PositionList<Space3d::CoordinateF64> JointPositionList3d64;
	typedef PositionList<Space3d::CoordinateF> JointPositionList3d;

	typedef Skeletal<Space3d::CoordinateF32, Common::Matrix4F32> Skeletal3d32;
	typedef Skeletal<Space3d::CoordinateF64, Common::Matrix4F64> Skeletal3d64;
	typedef Skeletal<Space3d::CoordinateF, Common::Matrix4F> Skeletal3d;

	typedef SkeletalManifest<Space3d::CoordinateF32, Common::Matrix4F32> SkeletalManifest3d32;
	typedef SkeletalManifest<Space3d::CoordinateF64, Common::Matrix4F64> SkeletalManifest3d64;
	typedef SkeletalManifest<Space3d::CoordinateF, Common::Matrix4F> SkeletalManifest3d;

}

#endif // MOVEMENT_3D_H
