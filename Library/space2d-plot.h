#ifndef SPACE2D_PLOT_H
#define SPACE2D_PLOT_H

#include "common.h"

namespace Space2d
{

	/// <summary>
	/// 1 byte precision signed plot
	/// </summary>
	typedef Common::Vector2<Int8> PlotI8;

	/// <summary>
	/// 2 byte precision signed plot
	/// </summary>
	typedef Common::Vector2<Int16> PlotI16;

	/// <summary>
	/// 4 byte precision signed plot
	/// </summary>
	typedef Common::Vector2<Int32> PlotI32;

	/// <summary>
	/// max byte precision signed plot
	/// </summary>
	typedef Common::Vector2<IntMax> PlotI;

	/// <summary>
	/// 1 byte precision unsigned plot
	/// </summary>
	typedef Common::Vector2<UInt8> PlotU8;

	/// <summary>
	/// 2 byte precision unsigned plot
	/// </summary>
	typedef Common::Vector2<UInt16> PlotU16;

	/// <summary>
	/// 4 byte precision unsigned plot
	/// </summary>
	typedef Common::Vector2<UInt32> PlotU32;

	/// <summary>
	/// max byte precision unsigned plot
	/// </summary>
	typedef Common::Vector2<UIntMax> PlotU;

	/// <summary>
	/// 4 byte precision floating number plot
	/// </summary>
	typedef Common::Vector2<Float32> PlotF32;

	/// <summary>
	/// 8 byte precision floating number plot
	/// </summary>
	typedef Common::Vector2<Float64> PlotF64;

	/// <summary>
	/// max byte precision floating number plot
	/// </summary>
	typedef Common::Vector2<FloatMax> PlotF;

	template <typename TVALUE>
	Common::Vector2<TVALUE> multiplyPlotByMatrix(const Common::Vector2<TVALUE>& plot, const Common::Matrix2<TVALUE>& matrix)
	{
		return plot * matrix;
	}

	template <typename TVALUE>
	Common::Vector2<TVALUE> multiplyPlotByMatrix(const Common::Vector2<TVALUE>& plot, const Common::Matrix3<TVALUE>& matrix)
	{
		Common::Vector3<TVALUE> result;

		for (UInt8 i = 0; i < 3; ++i)
			result.Values[i] = (plot.Values[0] * matrix.Values[0][i]) + (plot.Values[1] * matrix.Values[1][i]) + matrix.Values[2][i];

		return Common::Vector2<TVALUE>(result.Values[0] / result.Values[2], result.Values[1] / result.Values[2]);
	}

}

#endif // SPACE2D_PLOT_H
