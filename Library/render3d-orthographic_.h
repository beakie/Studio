#ifndef RENDER3D_ORTHOGRAPHIC_H
#define RENDER3D_ORTHOGRAPHIC_H

#include "common.h"
#include "space2d.h"
#include "space3d.h"

namespace Render3d
{

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getProjectionMatrixOrthoXY()
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  0.0,
										 0.0,  1.0,  0.0,  0.0,
										 0.0,  0.0,  0.0,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getProjectionMatrixOrthoXZ()
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  0.0,
										 0.0,  0.0,  0.0,  0.0,
										 0.0,  0.0,  1.0,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getProjectionMatrixOrthoYZ()
	{
		return Common::Matrix4<TVALUE>(  0.0,  0.0,  0.0,  0.0,
										 0.0,  1.0,  0.0,  0.0,
										 0.0,  0.0,  1.0,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix2<TVALUE> getPlotOrthoXY(Common::Vector3<TVALUE>& coordinate)
	{
		return Common::Matrix2<TVALUE>(coordinate.Values[0], coordinate.Values[1]);
	}

	template <typename TVALUE>
	Common::Matrix2<TVALUE> getPlotOrthoXZ(Common::Vector3<TVALUE>& coordinate)
	{
		return Common::Matrix2<TVALUE>(coordinate.Values[0], coordinate.Values[2]);
	}

	template <typename TVALUE>
	Common::Matrix2<TVALUE> getPlotOrthoYZ(Common::Vector3<TVALUE>& coordinate)
	{
		return Common::Matrix2<TVALUE>(coordinate.Values[1], coordinate.Values[2]);
	}
}

#endif // RENDER3D_ORTHOGRAPHIC_H
