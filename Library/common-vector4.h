#ifndef COMMON_VECTOR4_H
#define COMMON_VECTOR4_H

#include "common-matrix4.h"

namespace Common
{

	template <typename TVALUE = FloatMax>
	struct Vector4
	{
		TVALUE Values[4];

		Vector4()
		{
		}

		Vector4(const Vector4<TVALUE>& vector)
		{
			Values[0] = vector.Values[0];
			Values[1] = vector.Values[1];
			Values[2] = vector.Values[2];
			Values[3] = vector.Values[3];
		}

		Vector4(TVALUE value)
		{
			Values[0] = value;
			Values[1] = value;
			Values[2] = value;
			Values[3] = value;
		}

		Vector4(TVALUE value1, TVALUE value2, TVALUE value3, TVALUE value4)
		{
			Values[0] = value1;
			Values[1] = value2;
			Values[2] = value3;
			Values[3] = value4;
		}

		Vector4<TVALUE>& operator=(const Vector4<TVALUE>& vector)
		{
			Values[0] = vector.Values[0];
			Values[1] = vector.Values[1];
			Values[2] = vector.Values[2];
			Values[3] = vector.Values[3];

			return *this;
		}

		Vector4<TVALUE>& operator=(const TVALUE value)
		{
			Values[0] = value;
			Values[1] = value;
			Values[2] = value;
			Values[3] = value;

			return *this;
		}

		Vector4<TVALUE> operator+(const Vector4<TVALUE>& vector) const
		{
			return Vector4<TVALUE>(*this) += vector;
		}

		Vector4<TVALUE>& operator+=(const Vector4<TVALUE>& vector)
		{
			Values[0] += vector.Values[0];
			Values[1] += vector.Values[1];
			Values[2] += vector.Values[2];
			Values[3] += vector.Values[3];

			return *this;
		}

		Vector4<TVALUE> operator+(const TVALUE value) const
		{
			return Vector4<TVALUE>(*this) += value;
		}

		Vector4<TVALUE>& operator+=(const TVALUE value)
		{
			Values[0] += value;
			Values[1] += value;
			Values[2] += value;
			Values[3] += value;

			return *this;
		}

		Vector4<TVALUE> operator-(const Vector4<TVALUE>& vector) const
		{
			return Vector4<TVALUE>(*this) -= vector;
		}

		Vector4<TVALUE>& operator-=(const Vector4<TVALUE>& vector)
		{
			Values[0] -= vector.Values[0];
			Values[1] -= vector.Values[1];
			Values[2] -= vector.Values[2];
			Values[3] -= vector.Values[3];

			return *this;
		}

		Vector4<TVALUE> operator-(const TVALUE value) const
		{
			return Vector4<TVALUE>(*this) -= value;
		}

		Vector4<TVALUE>& operator-=(const TVALUE value)
		{
			Values[0] -= value;
			Values[1] -= value;
			Values[2] -= value;
			Values[3] -= value;

			return *this;
		}

		Vector4<TVALUE> operator*(const Vector4<TVALUE>& vector) const
		{
			return Vector4<TVALUE>(*this) *= vector;
		}

		Vector4<TVALUE>& operator*=(const Vector4<TVALUE>& vector)
		{
			Values[0] *= vector.Values[0];
			Values[1] *= vector.Values[1];
			Values[2] *= vector.Values[2];
			Values[3] *= vector.Values[3];

			return *this;
		}

		Vector4<TVALUE> operator*(const TVALUE value) const
		{
			return Vector4<TVALUE>(*this) *= value;
		}

		Vector4<TVALUE>& operator*=(const TVALUE value)
		{
			Values[0] *= value;
			Values[1] *= value;
			Values[2] *= value;
			Values[3] *= value;

			return *this;
		}

		Vector4<TVALUE> operator/(const Vector4<TVALUE>& vector) const
		{
			return Vector4<TVALUE>(*this) /= vector;
		}

		Vector4<TVALUE>& operator/=(const Vector4<TVALUE>& vector)
		{
			Values[0] /= vector.Values[0];
			Values[1] /= vector.Values[1];
			Values[2] /= vector.Values[2];
			Values[3] /= vector.Values[3];

			return *this;
		}

		Vector4<TVALUE> operator/(const TVALUE value) const
		{
			return Vector4<TVALUE>(*this) /= value;
		}

		Vector4<TVALUE>& operator/=(const TVALUE value)
		{
			Values[0] /= value;
			Values[1] /= value;
			Values[2] /= value;
			Values[3] /= value;

			return *this;
		}

		Vector4<TVALUE> operator&(const Vector4<TVALUE>& vector) const
		{
			return Vector4<TVALUE>(*this) &= vector;
		}

		Vector4<TVALUE>& operator&=(const Vector4<TVALUE>& vector)
		{
			Values[0] &= vector.Values[0];
			Values[1] &= vector.Values[1];
			Values[2] &= vector.Values[2];
			Values[3] &= vector.Values[3];

			return *this;
		}

		Vector4<TVALUE> operator&(const TVALUE value) const
		{
			return Vector4<TVALUE>(*this) &= value;
		}

		Vector4<TVALUE>& operator&=(const TVALUE value)
		{
			Values[0] &= value;
			Values[1] &= value;
			Values[2] &= value;
			Values[3] &= value;

			return *this;
		}

		Vector4<TVALUE> operator|(const Vector4<TVALUE>& vector) const
		{
			return Vector4<TVALUE>(*this) |= vector;
		}

		Vector4<TVALUE>& operator|=(const Vector4<TVALUE>& vector)
		{
			Values[0] |= vector.Values[0];
			Values[1] |= vector.Values[1];
			Values[2] |= vector.Values[2];
			Values[3] |= vector.Values[3];

			return *this;
		}

		Vector4<TVALUE> operator|(const TVALUE value) const
		{
			return Vector4<TVALUE>(*this) |= value;
		}

		Vector4<TVALUE>& operator|=(const TVALUE value) const
		{
			Values[0] |= value;
			Values[1] |= value;
			Values[2] |= value;
			Values[3] |= value;

			return *this;
		}

		bool operator==(const Vector4<TVALUE>& vector)
		{
			return (Values[0] == vector.Values[0]) && (Values[1] == vector.Values[1]) && (Values[2] == vector.Values[2]) && (Values[3] == vector.Values[3]);
		}

		bool operator==(const TVALUE value)
		{
			return (Values[0] == value) && (Values[1] == value) && (Values[2] == value) && (Values[3] == value);
		}

		TVALUE dotProduct(const Vector4<TVALUE> &vector)
		{
			return (Values[0] * vector.Values[0] + Values[1] * vector.Values[1] + Values[2] * vector.Values[2] + Values[3] * vector.Values[3]);
		}

		Vector4<TVALUE> crossProduct(const Vector4<TVALUE> &vector)
		{
			// todo
			Vector4<TVALUE> vector;
			return vector;
		}

		bool isZero() const
		{
			return (Values[0] == 0) && (Values[1] == 0) && (Values[2] == 0) && (Values[3] == 0);
		}

		Vector4<TVALUE>& absolute()
		{
			Values[0] = Common::abs(Values[0]);
			Values[1] = Common::abs(Values[1]);
			Values[2] = Common::abs(Values[2]);
			Values[3] = Common::abs(Values[3]);

			return *this;
		}

		Vector4<TVALUE> getAbsolute() const
		{
			return Vector4<TVALUE>(*this).absolute();
		}

		Vector4<TVALUE>& negative()
		{
			Values[0] = -Values[0];
			Values[1] = -Values[1];
			Values[2] = -Values[2];
			Values[3] = -Values[3];

			return *this;
		}

		Vector4<TVALUE> getNegative() const
		{
			return Vector4<TVALUE>(*this).negative();
		}

		static Vector4<TVALUE> getZero()
		{
			return Vector4<TVALUE>(0);
		}

		~Vector4()
		{
		}
	};

}

#endif // COMMON_VECTOR4_H
