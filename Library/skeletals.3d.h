#ifndef SKELETALS_3D_H
#define SKELETALS_3D_H

#include "skeletals-definition.h"
#include "skeletals-implemented.h"

namespace Skeletals
{

	typedef Definition<Space3d::CoordinateF32> Definition3d32;
	typedef Definition<Space3d::CoordinateF64> Definition3d64;
	typedef Definition<Space3d::CoordinateF> Definition3d;

	typedef Implemented<Space3d::CoordinateF32, Common::Matrix4F32> Implemented3d32;
	typedef Implemented<Space3d::CoordinateF64, Common::Matrix4F64> Implemented3d64;
	typedef Implemented<Space3d::CoordinateF, Common::Matrix4F> Implemented3d;

}

#endif // SKELETALS_3D_H
