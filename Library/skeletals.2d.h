#ifndef SKELETALS_2D_H
#define SKELETALS_2D_H

#include "skeletals-definition.h"
#include "skeletals-definitionuncompressed.h"

namespace Skeletals
{

	typedef Definition<Space2d::PlotF32, Common::Matrix3F32> Definition2d32;
	typedef Definition<Space2d::PlotF64, Common::Matrix3F64> Definition2d64;
	typedef Definition<Space2d::PlotF, Common::Matrix3F> Definition2d;

	typedef DefinitionUncompressed<Space2d::PlotF32, Common::Matrix3F32> DefinitionUncompressed2d32;
	typedef DefinitionUncompressed<Space2d::PlotF64, Common::Matrix3F64> DefinitionUncompressed2d64;
	typedef DefinitionUncompressed<Space2d::PlotF, Common::Matrix3F> DefinitionUncompressed2d;

}

#endif // SKELETALS_2D_H
