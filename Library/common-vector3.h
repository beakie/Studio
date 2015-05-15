#ifndef COMMONVECTOR3_H
#define COMMONVECTOR3_H

namespace Common
{

	template <typename TVALUE = FloatMax>
	struct Vector3
	{
		TVALUE Values[3];

		Vector3()
		{
		}

		Vector3(const Vector3<TVALUE>& vector)
		{
			Values[0] = vector.Values[0];
			Values[1] = vector.Values[1];
			Values[2] = vector.Values[2];
		}

		Vector3(TVALUE value)
		{
			Values[0] = value;
			Values[1] = value;
			Values[2] = value;
		}

		Vector3(TVALUE value1, TVALUE value2, TVALUE value3)
		{
			Values[0] = value1;
			Values[1] = value2;
			Values[2] = value3;
		}

		Vector3<TVALUE>& operator=(const Vector3<TVALUE>& vector)
		{
			Values[0] = vector.Values[0];
			Values[1] = vector.Values[1];
			Values[2] = vector.Values[2];

			return *this;
		}

		Vector3<TVALUE>& operator=(const TVALUE value)
		{
			Values[0] = value;
			Values[1] = value;
			Values[2] = value;

			return *this;
		}

		Vector3<TVALUE> operator+(const Vector3<TVALUE>& vector) const
		{
			return Vector3<TVALUE>(*this) += vector;
		}

		Vector3<TVALUE>& operator+=(const Vector3<TVALUE>& vector)
		{
			Values[0] += vector.Values[0];
			Values[1] += vector.Values[1];
			Values[2] += vector.Values[2];

			return *this;
		}

		Vector3<TVALUE> operator+(const TVALUE value) const
		{
			return Vector3<TVALUE>(*this) += value;
		}

		Vector3<TVALUE>& operator+=(const TVALUE value)
		{
			Values[0] += value;
			Values[1] += value;
			Values[2] += value;

			return *this;
		}

		Vector3<TVALUE> operator-(const Vector3<TVALUE>& vector) const
		{
			return Vector3<TVALUE>(*this) -= vector;
		}

		Vector3<TVALUE>& operator-=(const Vector3<TVALUE>& vector)
		{
			Values[0] -= vector.Values[0];
			Values[1] -= vector.Values[1];
			Values[2] -= vector.Values[2];

			return *this;
		}

		Vector3<TVALUE> operator-(const TVALUE value) const
		{
			return Vector3<TVALUE>(*this) -= value;
		}

		Vector3<TVALUE>& operator-=(const TVALUE value)
		{
			Values[0] -= value;
			Values[1] -= value;
			Values[2] -= value;

			return *this;
		}

		Vector3<TVALUE> operator*(const Vector3<TVALUE>& vector) const
		{
			return Vector3<TVALUE>(*this) *= vector;
		}

		Vector3<TVALUE>& operator*=(const Vector3<TVALUE>& vector)
		{
			Values[0] *= vector.Values[0];
			Values[1] *= vector.Values[1];
			Values[2] *= vector.Values[2];

			return *this;
		}

		Vector3<TVALUE> operator*(const TVALUE value) const
		{
			return Vector3<TVALUE>(*this) *= value;
		}

		Vector3<TVALUE>& operator*=(const TVALUE value)
		{
			Values[0] *= value;
			Values[1] *= value;
			Values[2] *= value;

			return *this;
		}

		Vector3<TVALUE> operator/(const Vector3<TVALUE>& vector) const
		{
			return Vector3<TVALUE>(*this) /= vector;
		}

		Vector3<TVALUE>& operator/=(const Vector3<TVALUE>& vector)
		{
			Values[0] /= vector.Values[0];
			Values[1] /= vector.Values[1];
			Values[2] /= vector.Values[2];

			return *this;
		}

		Vector3<TVALUE> operator/(const TVALUE value) const
		{
			return Vector3<TVALUE>(*this) /= value;
		}

		Vector3<TVALUE>& operator/=(const TVALUE value)
		{
			Values[0] /= value;
			Values[1] /= value;
			Values[2] /= value;

			return *this;
		}

		Vector3<TVALUE> operator&(const Vector3<TVALUE>& vector) const
		{
			return Vector3<TVALUE>(*this) &= vector;
		}

		Vector3<TVALUE>& operator&=(const Vector3<TVALUE>& vector)
		{
			Values[0] &= vector.Values[0];
			Values[1] &= vector.Values[1];
			Values[2] &= vector.Values[2];

			return *this;
		}

		Vector3<TVALUE> operator&(const TVALUE value) const
		{
			return Vector3<TVALUE>(*this) &= value;
		}

		Vector3<TVALUE>& operator&=(const TVALUE value)
		{
			Values[0] &= value;
			Values[1] &= value;
			Values[2] &= value;

			return *this;
		}

		Vector3<TVALUE> operator|(const Vector3<TVALUE>& vector) const
		{
			return Vector3<TVALUE>(*this) |= vector;
		}

		Vector3<TVALUE>& operator|=(const Vector3<TVALUE>& vector)
		{
			Values[0] |= vector.Values[0];
			Values[1] |= vector.Values[1];
			Values[2] |= vector.Values[2];

			return *this;
		}

		Vector3<TVALUE> operator|(const TVALUE value) const
		{
			return Vector3<TVALUE>(*this) |= value;
		}

		Vector3<TVALUE>& operator|=(const TVALUE value)
		{
			Values[0] |= value;
			Values[1] |= value;
			Values[2] |= value;

			return *this;
		}

		bool operator==(const Vector3<TVALUE>& vector)
		{
			return (Values[0] == vector.Values[0]) && (Values[1] == vector.Values[1]) && (Values[2] == vector.Values[2]);
		}

		bool operator==(const TVALUE value)
		{
			return (Values[0] == value) && (Values[1] == value) && (Values[2] == value);
		}

		TVALUE dotProduct(const Vector3<TVALUE>& vector)
		{
			return (Values[0] * vector.Values[0] + Values[1] * vector.Values[1] + Values[2] * vector.Values[2]);
		}

		Vector3<TVALUE> crossProduct(const Vector3<TVALUE>& vector)
		{
			return Vector3<TVALUE>((Values[1] * vector.Values[2] - Values[2] * vector.Values[1]),
				(Values[2] * vector.Values[0] - Values[0] * vector.Values[2]),
				(Values[0] * vector.Values[1] - Values[1] * vector.Values[0]));
		}

		bool isZero()
		{
			return (Values[0] == 0) && (Values[1] == 0) && (Values[2] == 0);
		}

		Vector3<TVALUE>& absolute()
		{
			Values[0] = Common::abs(Values[0]);
			Values[1] = Common::abs(Values[1]);
			Values[2] = Common::abs(Values[2]);

			return *this;
		}

		Vector3<TVALUE> getAbsolute()
		{
			return Vector3<TVALUE>(*this).absolute();
		}

		Vector3<TVALUE>& negative()
		{
			Values[0] = -Values[0];
			Values[1] = -Values[1];
			Values[2] = -Values[2];

			return *this;
		}

		Vector3<TVALUE> getNegative()
		{
			return Vector3<TVALUE>(*this).negative();
		}

		static Vector3<TVALUE> getZero()
		{
			return Vector3<TVALUE>(0);
		}

		~Vector3()
		{
		}
	};

}

#endif // COMMONVECTOR3_H

