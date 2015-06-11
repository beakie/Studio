#ifndef SPACE3D_COORDINATE_H
#define SPACE3D_COORDINATE_H

#include "common.h"

namespace Space3d
{

	/// <summary>
	/// 1 byte precision signed coordinate
	/// </summary>
	typedef Common::Vector3<Int8> CoordinateI8;

	/// <summary>
	/// 2 byte precision signed coordinate
	/// </summary>
	typedef Common::Vector3<Int16> CoordinateI16;

	/// <summary>
	/// 4 byte precision signed coordinate
	/// </summary>
	typedef Common::Vector3<Int32> CoordinateI32;

	/// <summary>
	/// max byte precision signed coordinate
	/// </summary>
	typedef Common::Vector3<IntMax> CoordinateI;

	/// <summary>
	/// 1 byte precision unsigned coordinate
	/// </summary>
	typedef Common::Vector3<UInt8> CoordinateU8;

	/// <summary>
	/// 2 byte precision unsigned coordinate
	/// </summary>
	typedef Common::Vector3<UInt16> CoordinateU16;

	/// <summary>
	/// 4 byte precision unsigned coordinate
	/// </summary>
	typedef Common::Vector3<UInt32> CoordinateU32;

	/// <summary>
	/// max byte precision unsigned coordinate
	/// </summary>
	typedef Common::Vector3<UIntMax> CoordinateU;

	/// <summary>
	/// 4 byte precision floating number coordinate
	/// </summary>
	typedef Common::Vector3<Float32> CoordinateF32;

	/// <summary>
	/// 8 byte precision floating number coordinate
	/// </summary>
	typedef Common::Vector3<Float64> CoordinateF64;

	/// <summary>
	/// max byte precision floating number coordinate
	/// </summary>
	typedef Common::Vector3<FloatMax> CoordinateF;

	template <typename TVALUE>
	Common::Vector3<TVALUE> multiplyCoordinateByMatrix(const Common::Vector3<TVALUE>& coordinate, const Common::Matrix3<TVALUE>& matrix)
	{
		return matrix * coordinate;
	}

	template <typename TVALUE>
	Common::Vector3<TVALUE> multiplyCoordinateByMatrix(const Common::Vector3<TVALUE>& coordinate, const Common::Matrix4<TVALUE>& matrix)
	{
		Common::Vector4<TVALUE> result;

		for (UInt8 i = 0; i < 4; ++i)
			result.Values[i] = (coordinate.Values[0] * matrix.Values[0][i]) + (coordinate.Values[1] * matrix.Values[1][i]) + (coordinate.Values[2] + matrix.Values[2][i]) + matrix.Values[3][i];

		return Common::Vector3<TVALUE>(result.Values[0] / result.Values[3], result.Values[1] / result.Values[3], result.Values[2] / result.Values[3]);
	}
}

#endif // SPACE3D_COORDINATE_H
