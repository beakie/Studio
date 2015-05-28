#ifndef COMMON_H
#define COMMON_H

#include "core.h"
#include "common-bounds_.h"
#include "common-castpixelconv.h"
#include "common-chainpixelconv.h"
#include "common-fromunitintervalpixelconv.h"
#include "common-image.h"
#include "common-imatrixadapter.h"
#include "common-ipixelconverter.h"
#include "common-list.h"
#include "common-managedlist.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-nullable.h"
#include "common-nullablenull.h"
#include "common-quaternion.h"
#include "common-scalecastpixelconv.h"
#include "common-tounitintervalpixelconv.h"
#include "common-tuple.h"
#include "common-tuplecreation_.h"
#include "common-unitinterval.h"
#include "common-unitvector.h"
#include "common-vector2.h"
#include "common-vector3.h"
#include "common-vector4.h"

namespace Common
{
	static NullableNull Null;

	/// <summary>
	/// matrix of size 2 with 1 bit values
	/// </summary>
	typedef Matrix2<UInt1> Matrix2U1;

	/// <summary>
	/// matrix of size 3 with 1 bit values
	/// </summary>
	typedef Matrix3<UInt1> Matrix3U1;

	/// <summary>
	/// matrix of size 4 with 1 bit values
	/// </summary>
	typedef Matrix4<UInt1> Matrix4U1;

	/// <summary>
	/// matrix of size 2 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt8> Matrix2U8;

	/// <summary>
	/// matrix of size 3 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt8> Matrix3U8;

	/// <summary>
	/// matrix of size 4 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt8> Matrix4U8;

	/// <summary>
	/// matrix of size 2 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt16> Matrix2U16;

	/// <summary>
	/// matrix of size 3 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt16> Matrix3U16;

	/// <summary>
	/// matrix of size 4 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt16> Matrix4U16;

	/// <summary>
	/// matrix of size 2 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt32> Matrix2U32;

	/// <summary>
	/// matrix of size 3 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt32> Matrix3U32;

	/// <summary>
	/// matrix of size 4 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt32> Matrix4U32;

	/// <summary>
	/// matrix of size 2 with max byte unsigned integer values
	/// </summary>
	typedef Matrix2<UIntMax> Matrix2U;

	/// <summary>
	/// matrix of size 3 with max byte unsigned integer values
	/// </summary>
	typedef Matrix3<UIntMax> Matrix3U;

	/// <summary>
	/// matrix of size 4 with max byte unsigned integer values
	/// </summary>
	typedef Matrix4<UIntMax> Matrix4U;

	/// <summary>
	/// matrix of size 2 with 1 byte signed integer values
	/// </summary>
	typedef Matrix2<Int8> Matrix2I8;

	/// <summary>
	/// matrix of size 3 with 1 byte signed integer values
	/// </summary>
	typedef Matrix3<Int8> Matrix3I8;

	/// <summary>
	/// matrix of size 4 with 1 byte signed integer values
	/// </summary>
	typedef Matrix4<Int8> Matrix4I8;

	/// <summary>
	/// matrix of size 2 with 2 byte signed integer values
	/// </summary>
	typedef Matrix2<Int16> Matrix2I16;

	/// <summary>
	/// matrix of size 3 with 2 byte signed integer values
	/// </summary>
	typedef Matrix3<Int16> Matrix3I16;

	/// <summary>
	/// matrix of size 4 with 2 byte signed integer values
	/// </summary>
	typedef Matrix4<Int16> Matrix4I16;

	/// <summary>
	/// matrix of size 2 with 4 byte signed integer values
	/// </summary>
	typedef Matrix2<Int32> Matrix2I32;

	/// <summary>
	/// matrix of size 3 with 4 byte signed integer values
	/// </summary>
	typedef Matrix3<Int32> Matrix3I32;

	/// <summary>
	/// matrix of size 4 with 4 byte signed integer values
	/// </summary>
	typedef Matrix4<Int32> Matrix4I32;

	/// <summary>
	/// matrix of size 2 with max byte signed integer values
	/// </summary>
	typedef Matrix2<IntMax> Matrix2I;

	/// <summary>
	/// matrix of size 3 with max byte signed integer values
	/// </summary>
	typedef Matrix3<IntMax> Matrix3I;

	/// <summary>
	/// matrix of size 4 with max byte signed integer values
	/// </summary>
	typedef Matrix4<IntMax> Matrix4I;

	/// <summary>
	/// matrix of size 2 with 32 bit floating point values
	/// </summary>
	typedef Matrix2<Float32> Matrix2F32;

	/// <summary>
	/// matrix of size 3 with 32 bit floating point values
	/// </summary>
	typedef Matrix3<Float32> Matrix3F32;

	/// <summary>
	/// matrix of size 4 with 32 bit floating point values
	/// </summary>
	typedef Matrix4<Float32> Matrix4F32;

	/// <summary>
	/// matrix of size 2 with 64 bit floating point values
	/// </summary>
	typedef Matrix2<Float64> Matrix2F64;

	/// <summary>
	/// matrix of size 3 with 64 bit floating point values
	/// </summary>
	typedef Matrix3<Float64> Matrix3F64;

	/// <summary>
	/// matrix of size 4 with 64 bit floating point values
	/// </summary>
	typedef Matrix4<Float64> Matrix4F64;

	/// <summary>
	/// matrix of size 2 with max bit floating point values
	/// </summary>
	typedef Matrix2<FloatMax> Matrix2F;

	/// <summary>
	/// matrix of size 3 with max bit floating point values
	/// </summary>
	typedef Matrix3<FloatMax> Matrix3F;

	/// <summary>
	/// matrix of size 4 with max bit floating point values
	/// </summary>
	typedef Matrix4<FloatMax> Matrix4F;

	/// <summary>
	/// Image with 1 byte dimensions and 1 bit pixels
	/// </summary>
	typedef Image<UInt1, UInt8> Image8U1;

	/// <summary>
	/// Image with 1 byte dimensions and 1 byte pixels
	/// </summary>
	typedef Image<UInt8, UInt8> Image8U8;

	/// <summary>
	/// Image with 1 byte dimensions and 2 byte pixels
	/// </summary>
	typedef Image<UInt16, UInt8> Image8U16;

	/// <summary>
	/// Image with 1 byte dimensions and 4 byte pixels
	/// </summary>
	typedef Image<UInt32, UInt8> Image8U32;

	/// <summary>
	/// Image with 1 byte dimensions and max byte pixels
	/// </summary>
	typedef Image<UIntMax, UInt8> Image8U;

	/// <summary>
	/// Image with 1 byte dimensions and 32 bit floating point pixels
	/// </summary>
	typedef Image<Float32, UInt8> Image8F32;

	/// <summary>
	/// Image with 1 byte dimensions and 64 bit floating point pixels
	/// </summary>
	typedef Image<Float64, UInt8> Image8F64;

	/// <summary>
	/// Image with 1 byte dimensions and max bit floating point pixels
	/// </summary>
	typedef Image<FloatMax, UInt8> Image8F;

	/// <summary>
	/// Image with 2 byte dimensions and 1 bit pixels
	/// </summary>
	typedef Image<UInt1, UInt16> Image16U1;

	/// <summary>
	/// Image with 2 byte dimensions and 1 byte pixels
	/// </summary>
	typedef Image<UInt8, UInt16> Image16U8;

	/// <summary>
	/// Image with 2 byte dimensions and 2 byte pixels
	/// </summary>
	typedef Image<UInt16, UInt16> Image16U16;

	/// <summary>
	/// Image with 2 byte dimensions and 4 byte pixels
	/// </summary>
	typedef Image<UInt32, UInt16> Image16U32;

	/// <summary>
	/// Image with 2 byte dimensions and max byte pixels
	/// </summary>
	typedef Image<UIntMax, UInt16> Image16U;

	/// <summary>
	/// Image with 2 byte dimensions and 32 bit floating point pixels
	/// </summary>
	typedef Image<Float32, UInt16> Image16F32;

	/// <summary>
	/// Image with 2 byte dimensions and 64 bit floating point pixels
	/// </summary>
	typedef Image<Float64, UInt16> Image16F64;

	/// <summary>
	/// Image with 2 byte dimensions and max bit floating point pixels
	/// </summary>
	typedef Image<FloatMax, UInt16> Image16F;

	typedef Quaternion<Float32> QuaternionF32;

	typedef Quaternion<Float64> QuaternionF64;

	typedef Quaternion<FloatMax> QuaternionF;

	/// <summary>
	/// vector of size 2 with 1 bit values
	/// </summary>
	typedef Vector2<UInt1> Vector2U1;

	/// <summary>
	/// vector of size 3 with 1 bit values
	/// </summary>
	typedef Vector3<UInt1> Vector3U1;

	/// <summary>
	/// vector of size 4 with 1 bit values
	/// </summary>
	typedef Vector4<UInt1> Vector4U1;

	/// <summary>
	/// vector of size 2 with 1 byte unsigned integer values
	/// </summary>
	typedef Vector2<UInt8> Vector2U8;

	/// <summary>
	/// vector of size 3 with 1 byte unsigned integer values
	/// </summary>
	typedef Vector3<UInt8> Vector3U8;

	/// <summary>
	/// vector of size 4 with 1 byte unsigned integer values
	/// </summary>
	typedef Vector4<UInt8> Vector4U8;

	/// <summary>
	/// vector of size 2 with 2 byte unsigned integer values
	/// </summary>
	typedef Vector2<UInt16> Vector2U16;

	/// <summary>
	/// vector of size 3 with 2 byte unsigned integer values
	/// </summary>
	typedef Vector3<UInt16> Vector3U16;

	/// <summary>
	/// vector of size 4 with 2 byte unsigned integer values
	/// </summary>
	typedef Vector4<UInt16> Vector4U16;

	/// <summary>
	/// vector of size 2 with 4 byte unsigned integer values
	/// </summary>
	typedef Vector2<UInt32> Vector2U32;

	/// <summary>
	/// vector of size 3 with 4 byte unsigned integer values
	/// </summary>
	typedef Vector3<UInt32> Vector3U32;

	/// <summary>
	/// vector of size 4 with 4 byte unsigned integer values
	/// </summary>
	typedef Vector4<UInt32> Vector4U32;

	/// <summary>
	/// vector of size 2 with max byte unsigned integer values
	/// </summary>
	typedef Vector2<UIntMax> Vector2U;

	/// <summary>
	/// vector of size 3 with max byte unsigned integer values
	/// </summary>
	typedef Vector3<UIntMax> Vector3U;

	/// <summary>
	/// vector of size 4 with max byte unsigned integer values
	/// </summary>
	typedef Vector4<UIntMax> Vector4U;

	/// <summary>
	/// vector of size 2 with 1 byte signed integer values
	/// </summary>
	typedef Vector2<Int8> Vector2I8;

	/// <summary>
	/// vector of size 3 with 1 byte signed integer values
	/// </summary>
	typedef Vector3<Int8> Vector3I8;

	/// <summary>
	/// vector of size 4 with 1 byte signed integer values
	/// </summary>
	typedef Vector4<Int8> Vector4I8;

	/// <summary>
	/// vector of size 2 with 2 byte signed integer values
	/// </summary>
	typedef Vector2<Int16> Vector2I16;

	/// <summary>
	/// vector of size 3 with 2 byte signed integer values
	/// </summary>
	typedef Vector3<Int16> Vector3I16;

	/// <summary>
	/// vector of size 4 with 2 byte signed integer values
	/// </summary>
	typedef Vector4<Int16> Vector4I16;

	/// <summary>
	/// vector of size 2 with 4 byte signed integer values
	/// </summary>
	typedef Vector2<Int32> Vector2I32;

	/// <summary>
	/// vector of size 3 with 4 byte signed integer values
	/// </summary>
	typedef Vector3<Int32> Vector3I32;

	/// <summary>
	/// vector of size 4 with 4 byte signed integer values
	/// </summary>
	typedef Vector4<Int32> Vector4I32;

	/// <summary>
	/// vector of size 2 with max byte signed integer values
	/// </summary>
	typedef Vector2<IntMax> Vector2I;

	/// <summary>
	/// vector of size 3 with max byte signed integer values
	/// </summary>
	typedef Vector3<IntMax> Vector3I;

	/// <summary>
	/// vector of size 4 with max byte signed integer values
	/// </summary>
	typedef Vector4<IntMax> Vector4I;

	/// <summary>
	/// vector of size 2 with 32 bit floating point values
	/// </summary>
	typedef Vector2<Float32> Vector2F32;

	/// <summary>
	/// vector of size 3 with 32 bit floating point values
	/// </summary>
	typedef Vector3<Float32> Vector3F32;

	/// <summary>
	/// vector of size 4 with 32 bit floating point values
	/// </summary>
	typedef Vector4<Float32> Vector4F32;

	/// <summary>
	/// vector of size 2 with 64 bit floating point values
	/// </summary>
	typedef Vector2<Float64> Vector2F64;

	/// <summary>
	/// vector of size 3 with 64 bit floating point values
	/// </summary>
	typedef Vector3<Float64> Vector3F64;

	/// <summary>
	/// vector of size 4 with 64 bit floating point values
	/// </summary>
	typedef Vector4<Float64> Vector4F64;

	/// <summary>
	/// vector of size 2 with max bit floating point values
	/// </summary>
	typedef Vector2<FloatMax> Vector2F;

	/// <summary>
	/// vector of size 3 with max bit floating point values
	/// </summary>
	typedef Vector3<FloatMax> Vector3F;

	/// <summary>
	/// vector of size 4 with max bit floating point values
	/// </summary>
	typedef Vector4<FloatMax> Vector4F;

}

#endif // COMMON_H
