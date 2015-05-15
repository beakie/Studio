#ifndef COMMONUNITVECTOR_H
#define COMMONUNITVECTOR_H

#include "common-vector2.h"
#include "common-vector3.h"
#include "common-vector4.h"

namespace Common
{
	typedef Vector2<Float32> UnitVector2F32;

	typedef Vector2<Float64> UnitVector2F64;

	typedef Vector2<FloatMax> UnitVector2;

	typedef Vector3<Float32> UnitVector3F32;

	typedef Vector3<Float64> UnitVector3F64;

	typedef Vector3<FloatMax> UnitVector3;

	typedef Vector4<Float32> UnitVector4F32;

	typedef Vector4<Float64> UnitVector4F64;

	typedef Vector4<FloatMax> UnitVector4;

	template <typename TFLOATING>
	bool isValidUnitVector(const Vector2<TFLOATING>& unitVector)
	{
		return (unitVector.Values[0] + unitVector.Values[1]) == 1;
	}

	template <typename TFLOATING>
	bool isValidUnitVector(const Vector3<TFLOATING>& unitVector)
	{
		return (unitVector.Values[0] + unitVector.Values[1] + unitVector.Values[2]) == 1;
	}

	template <typename TFLOATING>
	bool isValidUnitVector(const Vector4<TFLOATING>& unitVector)
	{
		return (unitVector.Values[0] + unitVector.Values[1] + unitVector.Values[2] + unitVector.Values[3]) == 1;
	}

	template <typename TVALUE, typename TFLOATING = FloatMax>
	Vector2<TFLOATING> getUnitVector(const Vector2<TVALUE>& vector)
	{
		FloatMax magnitude = power(power(vector.Values[0], 2) + power(vector.Values[1], 2), 0.5);

		return Vector2<TFLOATING>(vector.Values[0] / magnitude, vector.Values[1] / magnitude);
	}

	template <typename TVALUE, typename TFLOATING = FloatMax>
	Vector3<TFLOATING> getUnitVector(const Vector3<TVALUE>& vector)
	{
		FloatMax magnitude = power(power(vector.Values[0], 2) + power(vector.Values[1], 2) + power(vector.Values[2], 2), 0.5);

		return Vector3<TFLOATING>(vector.Values[0] / magnitude, vector.Values[1] / magnitude, vector.Values[2] / magnitude);
	}

	template <typename TVALUE, typename TFLOATING = FloatMax>
	Vector4<TFLOATING> getUnitVector(const Vector4<TVALUE>& vector)
	{
		FloatMax magnitude = power(power(vector.Values[0], 2) + power(vector.Values[1], 2) + power(vector.Values[2], 2) + power(vector.Values[3], 2), 0.5);

		return Vector4<TFLOATING>(vector.Values[0] / magnitude, vector.Values[1] / magnitude, vector.Values[2] / magnitude, vector.Values[3] / magnitude);
	}
}

#endif // COMMONUNITVECTOR_H
