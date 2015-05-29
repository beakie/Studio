#ifndef SKELETALS_2D_H
#define SKELETALS_2D_H

#include "skeletals-armskeletal.h"
#include "skeletals-basicskeletal.h"

namespace Skeletals
{

	typedef ArmSkeletal<Space2d::PlotF32, Common::Matrix3F32> ArmSkeletal2d32;
	typedef ArmSkeletal<Space2d::PlotF64, Common::Matrix3F64> ArmSkeletal2d64;
	typedef ArmSkeletal<Space2d::PlotF, Common::Matrix3F> ArmSkeletal2d;

	typedef BasicSkeletal<Space2d::PlotF32, Common::Matrix3F32> BasicSkeletal2d32;
	typedef BasicSkeletal<Space2d::PlotF64, Common::Matrix3F64> BasicSkeletal2d64;
	typedef BasicSkeletal<Space2d::PlotF, Common::Matrix3F> BasicSkeletal2d;

}

#endif // SKELETALS_2D_H
