#ifndef SKELETALS_3D_H
#define SKELETALS_3D_H

#include "skeletals-definition.h"
#include "skeletals-definitionuncompressed.h"

namespace Skeletals
{

	typedef Definition<Space3d::CoordinateF32, Common::Matrix4F32> Definition3d32;
	typedef Definition<Space3d::CoordinateF64, Common::Matrix4F64> Definition3d64;
	typedef Definition<Space3d::CoordinateF, Common::Matrix4F> Definition3d;

	typedef DefinitionUncompressed<Space3d::CoordinateF32, Common::Matrix4F32> DefinitionUncompressed3d32;
	typedef DefinitionUncompressed<Space3d::CoordinateF64, Common::Matrix4F64> DefinitionUncompressed3d64;
	typedef DefinitionUncompressed<Space3d::CoordinateF, Common::Matrix4F> DefinitionUncompressed3d;

}

#endif // SKELETALS_3D_H
