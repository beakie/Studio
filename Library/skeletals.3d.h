#ifndef SKELETALS_3D_H
#define SKELETALS_3D_H

#include "skeletals-basicskeletal.h"

namespace Skeletals
{

	typedef BasicSkeletal<Space3d::CoordinateF32, Common::Matrix4F32> BasicSkeletal3d32;
	typedef BasicSkeletal<Space3d::CoordinateF64, Common::Matrix4F64> BasicSkeletal3d64;
	typedef BasicSkeletal<Space3d::CoordinateF, Common::Matrix4F> BasicSkeletal3d;

}

#endif // SKELETALS_3D_H
