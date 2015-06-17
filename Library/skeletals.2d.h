#ifndef SKELETALS_2D_H
#define SKELETALS_2D_H

#include "skeletals-definition.h"
#include "skeletals-implemented.h"

namespace Skeletals
{

	typedef Definition<Space2d::PlotF32> Definition2d32;
	typedef Definition<Space2d::PlotF64> Definition2d64;
	typedef Definition<Space2d::PlotF> Definition2d;

	typedef Implemented<Space2d::PlotF32, Common::Matrix3F32> Implemented2d32;
	typedef Implemented<Space2d::PlotF64, Common::Matrix3F64> Implemented2d64;
	typedef Implemented<Space2d::PlotF, Common::Matrix3F> Implemented2d;

}

#endif // SKELETALS_2D_H
