#ifndef SKELETALS_3D_H
#define SKELETALS_3D_H

#include "skeletals-armskeletal.h"
#include "skeletals-basicskeletal.h"
#include "skeletals-definition.h"

namespace Skeletals
{

	typedef ArmSkeletal<Space3d::CoordinateF32, Common::Matrix4F32> ArmSkeletal3d32;
	typedef ArmSkeletal<Space3d::CoordinateF64, Common::Matrix4F64> ArmSkeletal3d64;
	typedef ArmSkeletal<Space3d::CoordinateF, Common::Matrix4F> ArmSkeletal3d;

	typedef BasicSkeletal<Space3d::CoordinateF32, Common::Matrix4F32> BasicSkeletal3d32;
	typedef BasicSkeletal<Space3d::CoordinateF64, Common::Matrix4F64> BasicSkeletal3d64;
	typedef BasicSkeletal<Space3d::CoordinateF, Common::Matrix4F> BasicSkeletal3d;

}

#endif // SKELETALS_3D_H
