#ifndef COMMON_VECTOR2_H
#define COMMON_VECTOR2_H

namespace Common
{

	template <typename TVALUE = FloatMax>
	struct Vector2
	{
		TVALUE Values[2];

		Vector2()
		{
		}

		Vector2(const Vector2<TVALUE>& vector)
		{
			Values[0] = vector.Values[0];
			Values[1] = vector.Values[1];
		}

		Vector2(TVALUE value)
		{
			Values[0] = value;
			Values[1] = value;
		}

		Vector2(TVALUE value1, TVALUE value2)
		{
			Values[0] = value1;
			Values[1] = value2;
		}

		Vector2<TVALUE>& operator=(const Vector2<TVALUE>& vector)
		{
			Values[0] = vector.Values[0];
			Values[1] = vector.Values[1];

			return *this;
		}

		Vector2<TVALUE>& operator=(const TVALUE value)
		{
			Values[0] = value;
			Values[1] = value;

			return *this;
		}

		Vector2<TVALUE> operator+(const Vector2<TVALUE>& vector) const
		{
			return Vector2<TVALUE>(*this) += vector;
		}

		Vector2<TVALUE>& operator+=(const Vector2<TVALUE>& vector)
		{
			Values[0] += vector.Values[0];
			Values[1] += vector.Values[1];

			return *this;
		}

		Vector2<TVALUE> operator+(const TVALUE value) const
		{
			return Vector2<TVALUE>(*this) += value;
		}

		Vector2<TVALUE>& operator+=(const TVALUE value)
		{
			Values[0] += value;
			Values[1] += value;

			return *this;
		}

		Vector2<TVALUE> operator-(const Vector2<TVALUE>& vector) const
		{
			return Vector2<TVALUE>(*this) -= vector;
		}

		Vector2<TVALUE>& operator-=(const Vector2<TVALUE>& vector)
		{
			Values[0] -= vector.Values[0];
			Values[1] -= vector.Values[1];

			return *this;
		}

		Vector2<TVALUE> operator-(const TVALUE value) const
		{
			return Vector2<TVALUE>(*this) -= value;
		}

		Vector2<TVALUE>& operator-=(const TVALUE value)
		{
			Values[0] -= value;
			Values[1] -= value;

			return *this;
		}

		Vector2<TVALUE> operator*(const Vector2<TVALUE>& vector) const
		{
			return Vector2<TVALUE>(*this) *= vector;
		}

		Vector2<TVALUE>& operator*=(const Vector2<TVALUE>& vector)
		{
			Values[0] *= vector.Values[0];
			Values[1] *= vector.Values[1];

			return *this;
		}

		Vector2<TVALUE> operator*(const TVALUE value) const
		{
			return Vector2<TVALUE>(*this) *= value;
		}

		Vector2<TVALUE>& operator*=(const TVALUE value)
		{
			Values[0] *= value;
			Values[1] *= value;

			return *this;
		}

		Vector2<TVALUE> operator/(const Vector2<TVALUE>& vector) const
		{
			return Vector2<TVALUE>(*this) /= vector;
		}

		Vector2<TVALUE>& operator/=(const Vector2<TVALUE>& vector)
		{
			Values[0] /= vector.Values[0];
			Values[1] /= vector.Values[1];

			return *this;
		}

		Vector2<TVALUE> operator/(const TVALUE value) const
		{
			return Vector2<TVALUE>(*this) /= value;
		}

		Vector2<TVALUE>& operator/=(const TVALUE value)
		{
			Values[0] /= value;
			Values[1] /= value;

			return *this;
		}

		Vector2<TVALUE> operator&(const Vector2<TVALUE>& vector) const
		{
			return Vector2<TVALUE>(*this) &= vector;
		}

		Vector2<TVALUE>& operator&=(const Vector2<TVALUE>& vector)
		{
			Values[0] &= vector.Values[0];
			Values[1] &= vector.Values[1];

			return *this;
		}

		Vector2<TVALUE> operator&(const TVALUE value) const
		{
			return Vector2<TVALUE>(*this) &= value;
		}

		Vector2<TVALUE>& operator&=(const TVALUE value)
		{
			Values[0] &= value;
			Values[1] &= value;

			return *this;
		}

		Vector2<TVALUE> operator|(const Vector2<TVALUE>& vector) const
		{
			return Vector2<TVALUE>(*this) |= vector;
		}

		Vector2<TVALUE>& operator|=(const Vector2<TVALUE>& vector)
		{
			Values[0] |= vector.Values[0];
			Values[1] |= vector.Values[1];

			return *this;
		}

		Vector2<TVALUE> operator|(const TVALUE value) const
		{
			return Vector2<TVALUE>(*this) |= value;
		}

		Vector2<TVALUE>& operator|=(const TVALUE value)
		{
			Values[0] |= value;
			Values[1] |= value;

			return *this;
		}

		bool operator==(const Vector2<TVALUE>& vector)
		{
			return (Values[0] == vector.Values[0]) && (Values[1] == vector.Values[1]);
		}

		bool operator==(const TVALUE value)
		{
			return (Values[0] == value) && (Values[1] == value);
		}

		TVALUE dotProduct(const Vector2<TVALUE>& vector)
		{
			return (Values[0] * vector.Values[0] + Values[1] * vector.Values[1]);
		}

		TVALUE crossProduct(const Vector2<TVALUE>& vector)
		{
			return (Values[0] * vector.Values[1]) - (Values[1] * vector.Values[0]);
		}

		bool isZero()
		{
			return (Values[0] == 0) && (Values[1] == 0);
		}

		Vector2<TVALUE>& absolute()
		{
			Values[0] = Common::abs(Values[0]);
			Values[1] = Common::abs(Values[1]);

			return *this;
		}

		Vector2<TVALUE> getAbsolute()
		{
			return Vector2<TVALUE>(*this).absolute();
		}

		Vector2<TVALUE>& negative()
		{
			Values[0] = -Values[0];
			Values[1] = -Values[1];

			return *this;
		}

		Vector2<TVALUE> getNegative()
		{
			return Vector2<TVALUE>(*this).negative();
		}

		static Vector2<TVALUE> getZero()
		{
			return Vector2<TVALUE>(0);
		}

		~Vector2()
		{
		}
	};

}

#endif // COMMON_VECTOR2_H
