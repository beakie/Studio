#ifndef COMMONMATRIX2_H
#define COMMONMATRIX2_H

#include "core.h"

namespace Common
{
	template <typename TVALUE = FloatMax>
	/// <summary>
	/// 2 dimensional matrix
	/// </summary>
	struct Matrix2
	{
		/// <summary>
		/// The values of the matrix stored in [x][y] form
		/// </summary>
		TVALUE Values[2][2];

		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		Matrix2()
		{
		}

		Matrix2(const Matrix2<TVALUE>& matrix)
		{
			operator=(matrix);
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Matrix2(const TVALUE value)
		{
			operator=(value);
		}

		/// <summary>
		/// Constructs a matrix and sets each value from parameter list
		/// </summary>
		Matrix2(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x1y2, const TVALUE x2y2)
		{
			set(x1y1, x2y1, x1y2, x2y2);
		}

		/// <summary>
		/// Returns the number of rows
		/// </summary>
		UInt8 getRowCount()
		{
			return 2;
		}

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		UInt8 getColumnCount()
		{
			return 2;
		}

		/// <summary>
		/// Sets all the values to a single value
		/// </summary>
		void set(const TVALUE value)
		{
			operator=(value);
		}

		/// <summary>
		/// Sets specified value
		/// </summary>
		void set(const UInt8 x, const UInt8 y, const TVALUE value)
		{
			Values[x][y] = value;
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		void set(const Matrix2<TVALUE>& matrix)
		{
			operator=(matrix);
		}

		/// <summary>
		/// Sets each value from parameter list
		/// </summary>
		void set(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x1y2, const TVALUE x2y2)
		{
			Values[0][0] = x1y1;
			Values[0][1] = x1y2;
			Values[1][0] = x2y1;
			Values[1][1] = x2y2;
		}

		/// <summary>
		/// Gets the value
		/// </summary>
		TVALUE get(const UInt8 x, const UInt8 y)
		{
			return Values[x][y];
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE>& operator=(const TVALUE& value)
		{
			Values[0][0] = value;
			Values[0][1] = value;
			Values[1][0] = value;
			Values[1][1] = value;

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE>& operator=(const Matrix2<TVALUE>& matrix)
		{
			Values[0][0] = matrix.Values[0][0];
			Values[0][1] = matrix.Values[0][1];
			Values[1][0] = matrix.Values[1][0];
			Values[1][1] = matrix.Values[1][1];

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE> operator+(const Matrix2<TVALUE>& matrix) const
		{
			return Matrix2<TVALUE>(*this) += matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE>& operator+=(const Matrix2<TVALUE>& matrix)
		{
			set(Values[0][0] + matrix.Values[0][0],
				Values[1][0] + matrix.Values[1][0],
				Values[0][1] + matrix.Values[0][1],
				Values[1][1] + matrix.Values[1][1]);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE> operator-(const Matrix2<TVALUE>& matrix) const
		{
			return Matrix2<TVALUE>(*this) -= matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE>& operator-=(const Matrix2<TVALUE>& matrix)
		{
			set(Values[0][0] - matrix.Values[0][0],
				Values[1][0] - matrix.Values[1][0],
				Values[0][1] - matrix.Values[0][1],
				Values[1][1] - matrix.Values[1][1]);

			return this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE> operator*(const Matrix2<TVALUE>& matrix) const
		{
			return Matrix2<TVALUE>(*this) *= matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE>& operator*=(const Matrix2<TVALUE>& matrix)
		{
			set((matrix.Values[0][0] * Values[0][0]) + (matrix.Values[0][1] * Values[1][0]),
				(matrix.Values[1][0] * Values[0][0]) + (matrix.Values[1][1] * Values[1][0]),
				(matrix.Values[0][0] * Values[0][1]) + (matrix.Values[0][1] * Values[1][1]),
				(matrix.Values[1][0] * Values[0][1]) + (matrix.Values[1][1] * Values[1][1]));

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE> operator*(const TVALUE value) const
		{
			return Matrix2<TVALUE>(*this) *= value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE>& operator*=(const TVALUE value)
		{
			set(Values[0][0] * value,
				Values[1][0] * value,
				Values[0][1] * value,
				Values[1][1] * value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE> operator/(const Matrix2<TVALUE>& matrix) const
		{
			return Matrix2<TVALUE>(*this) /= matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE>& operator/=(const Matrix2<TVALUE>& matrix)
		{
			TVALUE d = matrix.getDeterminant();

			//if (d == 0)
			//	return 0;

			*this = Matrix2<TVALUE>(matrix).inverse(); //set(matrix)?

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE> operator/(const TVALUE value) const
		{
			return Matrix2<TVALUE>(*this) /= value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix2<TVALUE>& operator/=(const TVALUE value)
		{
			set(Values[0][0] / value,
				Values[1][0] / value,
				Values[0][1] / value,
				Values[1][1] / value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator==(const Matrix2<TVALUE>& matrix) const
		{
			return (Values[0][0] == matrix.Values[0][0])
				&& (Values[0][1] == matrix.Values[0][1])
				&& (Values[1][0] == matrix.Values[1][0])
				&& (Values[1][1] == matrix.Values[1][1]);
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator!=(const Matrix2<TVALUE>& matrix) const
		{
			return !operator==(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		Matrix2<TVALUE>& multiply(const Matrix2<TVALUE>& matrix)
		{
			return operator*=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		Matrix2<TVALUE>& multiply(const TVALUE value)
		{
			return operator*=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		Matrix2<TVALUE>& dotProduct(const Matrix2<TVALUE>& matrix)
		{
			return operator*=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		Matrix2<TVALUE>& scalar(const TVALUE value)
		{
			return operator*=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const Matrix2<TVALUE>& matrix) const
		{
			return operator==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		Matrix2<TVALUE>& identity()
		{
			set(1, 0, 0, 1);

			return *this;
		}

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		Matrix2<TVALUE>& zero()
		{
			return operator=(0);
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		Matrix2<TVALUE>& allOnes()
		{
			return operator=(1);
		}

		/// <summary>
		/// Transposes the matrix
		/// </summary>
		Matrix2<TVALUE>& transpose()
		{
			return transpose(*this);
		}

		/// <summary>
		/// Transposes the matrix passed
		/// </summary>
		Matrix2<TVALUE>& transpose(const Matrix2<TVALUE>& matrix)
		{
			set(matrix.Values[0][0], matrix.Values[0][1], matrix.Values[1][0], matrix.Values[1][1]);

			return *this;
		}

		/// <summary>
		/// Returns the transpose of the matrix
		/// </summary>
		Matrix2<TVALUE> getTransposed()
		{
			return Matrix2<TVALUE>(*this).transpose();
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		Matrix2<TVALUE>& inverse()
		{
			return inverse(*this);
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		Matrix2<TVALUE>& inverse(const Matrix2<TVALUE>& matrix)
		{
			set(matrix.Values[1][1], -matrix.Values[1][0], -matrix.Values[0][1], matrix.Values[0][0]);

			return *this;
		}

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		Matrix2<TVALUE> getInverted()
		{
			return Matrix2<TVALUE>(*this).inverse();
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const
		{
			return (Values[0][0] * Values[1][1]) - (Values[0][1] * Values[1][0]);
		}

		static Matrix2<TVALUE> getIdentity()
		{
			return Matrix2<TVALUE>().identity();
		}

		static Matrix2<TVALUE> getZero()
		{
			return Matrix2<TVALUE>(0);
		}

		static Matrix2<TVALUE> getAllOnes()
		{
			return Matrix2<TVALUE>(1);
		}

		//static Matrix2<TVALUE> getTransposed(const TIMPLEMENTATION& matrix);

		//static Matrix2<TVALUE> getInversed(const TIMPLEMENTATION& matrix);

		//static Matrix2<TVALUE> getAdjoint(const TIMPLEMENTATION& matrix);

		//static TVALUE getDeterminant(const TIMPLEMENTATION& matrix);

		//pivoting?

		//bool validateX(const TINDEX x) const

		//bool validateY(const TINDEX y) const

		~Matrix2()
		{
		}
	};
}

#endif // COMMONMATRIX2_H
