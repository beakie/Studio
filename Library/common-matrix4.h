#ifndef COMMONMATRIX4_H
#define COMMONMATRIX4_H

#include "core.h"

namespace Common
{
	template <typename TVALUE = FloatMax>
	/// <summary>
	/// 4 dimensional matrix
	/// </summary>
	struct Matrix4
	{
		/// <summary>
		/// The values of the matrix stored in [x][y] form
		/// </summary>
		TVALUE Values[4][4];

		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		Matrix4()
		{
		}

		Matrix4(const Matrix4<TVALUE>& matrix)
		{
			operator=(matrix);
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Matrix4(const TVALUE value)
		{
			operator=(value);
		}

		/// <summary>
		/// Constructs a matrix and sets each value from parameter list
		/// </summary>
		Matrix4(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x4y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x4y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3, const TVALUE x4y3, const TVALUE x1y4, const TVALUE x2y4, const TVALUE x3y4, const TVALUE x4y4)
		{
			set(x1y1, x2y1, x3y1, x4y1, x1y2, x2y2, x3y2, x4y2, x1y3, x2y3, x3y3, x4y3, x1y4, x2y4, x3y4, x4y4);
		}

		/// <summary>
		/// Returns the number of rows
		/// </summary>
		UInt8 getRowCount()
		{
			return 4;
		}

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		UInt8 getColumnCount()
		{
			return 4;
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
		void set(const Matrix4<TVALUE>& matrix)
		{
			operator=(matrix);
		}

		/// <summary>
		/// Sets each value from parameter list
		/// </summary>
		void set(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x4y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x4y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3, const TVALUE x4y3, const TVALUE x1y4, const TVALUE x2y4, const TVALUE x3y4, const TVALUE x4y4)
		{
			Values[0][0] = x1y1;
			Values[0][1] = x1y2;
			Values[0][2] = x1y3;
			Values[0][3] = x1y4;
			Values[1][0] = x2y1;
			Values[1][1] = x2y2;
			Values[1][2] = x2y3;
			Values[1][3] = x2y4;
			Values[2][0] = x3y1;
			Values[2][1] = x3y2;
			Values[2][2] = x3y3;
			Values[2][3] = x3y4;
			Values[3][0] = x4y1;
			Values[3][1] = x4y2;
			Values[3][2] = x4y3;
			Values[3][3] = x4y4;
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
		Matrix4<TVALUE>& operator=(const TVALUE& value)
		{
			Values[0][0] = value;
			Values[0][1] = value;
			Values[0][2] = value;
			Values[0][3] = value;
			Values[1][0] = value;
			Values[1][1] = value;
			Values[1][2] = value;
			Values[1][3] = value;
			Values[2][0] = value;
			Values[2][1] = value;
			Values[2][2] = value;
			Values[2][3] = value;
			Values[3][0] = value;
			Values[3][1] = value;
			Values[3][2] = value;
			Values[3][3] = value;

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator=(const Matrix4<TVALUE>& matrix)
		{
			Values[0][0] = matrix.Values[0][0];
			Values[0][1] = matrix.Values[0][1];
			Values[0][2] = matrix.Values[0][2];
			Values[0][3] = matrix.Values[0][3];
			Values[1][0] = matrix.Values[1][0];
			Values[1][1] = matrix.Values[1][1];
			Values[1][2] = matrix.Values[1][2];
			Values[1][3] = matrix.Values[1][3];
			Values[2][0] = matrix.Values[2][0];
			Values[2][1] = matrix.Values[2][1];
			Values[2][2] = matrix.Values[2][2];
			Values[2][3] = matrix.Values[2][3];
			Values[3][0] = matrix.Values[3][0];
			Values[3][1] = matrix.Values[3][1];
			Values[3][2] = matrix.Values[3][2];
			Values[3][3] = matrix.Values[3][3];

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator+(const Matrix4<TVALUE>& matrix) const
		{
			return Matrix4<TVALUE>(*this) += matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator+=(const Matrix4<TVALUE>& matrix)
		{
			set(Values[0][0] + matrix.Values[0][0],
				Values[1][0] + matrix.Values[1][0],
				Values[2][0] + matrix.Values[2][0],
				Values[3][0] + matrix.Values[3][0],
				Values[0][1] + matrix.Values[0][1],
				Values[1][1] + matrix.Values[1][1],
				Values[2][1] + matrix.Values[2][1],
				Values[3][1] + matrix.Values[3][1],
				Values[0][2] + matrix.Values[0][2],
				Values[1][2] + matrix.Values[1][2],
				Values[2][2] + matrix.Values[2][2],
				Values[3][2] + matrix.Values[3][2],
				Values[0][3] + matrix.Values[0][3],
				Values[1][3] + matrix.Values[1][3],
				Values[2][3] + matrix.Values[2][3],
				Values[3][3] + matrix.Values[3][3]);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator-(const Matrix4<TVALUE>& matrix) const
		{
			return Matrix4<TVALUE>(*this) -= matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator-=(const Matrix4<TVALUE>& matrix)
		{
			set(Values[0][0] - matrix.Values[0][0],
				Values[1][0] - matrix.Values[1][0],
				Values[2][0] - matrix.Values[2][0],
				Values[3][0] - matrix.Values[3][0],
				Values[0][1] - matrix.Values[0][1],
				Values[1][1] - matrix.Values[1][1],
				Values[2][1] - matrix.Values[2][1],
				Values[3][1] - matrix.Values[3][1],
				Values[0][2] - matrix.Values[0][2],
				Values[1][2] - matrix.Values[1][2],
				Values[2][2] - matrix.Values[2][2],
				Values[3][2] - matrix.Values[3][2],
				Values[0][3] - matrix.Values[0][3],
				Values[1][3] - matrix.Values[1][3],
				Values[2][3] - matrix.Values[2][3],
				Values[3][3] - matrix.Values[3][3]);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator*(const Matrix4<TVALUE>& matrix) const
		{
			return Matrix4<TVALUE>(*this) *= matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator*=(const Matrix4<TVALUE>& matrix)
		{
			set((matrix.Values[0][0] * Values[0][0]) + (matrix.Values[0][1] * Values[1][0]) + (matrix.Values[0][2] * Values[2][0]) + (matrix.Values[0][3] * Values[3][0]),
				(matrix.Values[1][0] * Values[0][0]) + (matrix.Values[1][1] * Values[1][0]) + (matrix.Values[1][2] * Values[2][0]) + (matrix.Values[1][3] * Values[3][0]),
				(matrix.Values[2][0] * Values[0][0]) + (matrix.Values[2][1] * Values[1][0]) + (matrix.Values[2][2] * Values[2][0]) + (matrix.Values[2][3] * Values[3][0]),
				(matrix.Values[3][0] * Values[0][0]) + (matrix.Values[3][1] * Values[1][0]) + (matrix.Values[3][2] * Values[2][0]) + (matrix.Values[3][3] * Values[3][0]),
				(matrix.Values[0][0] * Values[0][1]) + (matrix.Values[0][1] * Values[1][1]) + (matrix.Values[0][2] * Values[2][1]) + (matrix.Values[0][3] * Values[2][1]),
				(matrix.Values[1][0] * Values[0][1]) + (matrix.Values[1][1] * Values[1][1]) + (matrix.Values[1][2] * Values[2][1]) + (matrix.Values[1][3] * Values[2][1]),
				(matrix.Values[2][0] * Values[0][1]) + (matrix.Values[2][1] * Values[1][1]) + (matrix.Values[2][2] * Values[2][1]) + (matrix.Values[2][3] * Values[2][1]),
				(matrix.Values[3][0] * Values[0][1]) + (matrix.Values[3][1] * Values[1][1]) + (matrix.Values[3][2] * Values[2][1]) + (matrix.Values[3][3] * Values[2][1]),
				(matrix.Values[0][0] * Values[0][2]) + (matrix.Values[0][1] * Values[1][2]) + (matrix.Values[0][2] * Values[2][2]) + (matrix.Values[0][3] * Values[2][2]),
				(matrix.Values[1][0] * Values[0][2]) + (matrix.Values[1][1] * Values[1][2]) + (matrix.Values[1][2] * Values[2][2]) + (matrix.Values[1][3] * Values[2][2]),
				(matrix.Values[2][0] * Values[0][2]) + (matrix.Values[2][1] * Values[1][2]) + (matrix.Values[2][2] * Values[2][2]) + (matrix.Values[2][3] * Values[2][2]),
				(matrix.Values[3][0] * Values[0][2]) + (matrix.Values[3][1] * Values[1][2]) + (matrix.Values[3][2] * Values[2][2]) + (matrix.Values[3][3] * Values[2][2]),
				(matrix.Values[0][0] * Values[0][3]) + (matrix.Values[0][1] * Values[1][3]) + (matrix.Values[0][2] * Values[2][3]) + (matrix.Values[0][3] * Values[2][3]),
				(matrix.Values[1][0] * Values[0][3]) + (matrix.Values[1][1] * Values[1][3]) + (matrix.Values[1][2] * Values[2][3]) + (matrix.Values[1][3] * Values[2][3]),
				(matrix.Values[2][0] * Values[0][3]) + (matrix.Values[2][1] * Values[1][3]) + (matrix.Values[2][2] * Values[2][3]) + (matrix.Values[2][3] * Values[2][3]),
				(matrix.Values[3][0] * Values[0][3]) + (matrix.Values[3][1] * Values[1][3]) + (matrix.Values[3][2] * Values[2][3]) + (matrix.Values[3][3] * Values[2][3]));

			//is this really more efficient than looping?

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator*(const TVALUE value) const
		{
			return Matrix4<TVALUE>(*this) *= value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator*=(const TVALUE value)
		{
			set(Values[0][0] * value,
				Values[1][0] * value,
				Values[2][0] * value,
				Values[3][0] * value,
				Values[0][1] * value,
				Values[1][1] * value,
				Values[2][1] * value,
				Values[3][1] * value,
				Values[0][2] * value,
				Values[1][2] * value,
				Values[2][2] * value,
				Values[3][2] * value,
				Values[1][3] * value,
				Values[2][3] * value,
				Values[3][3] * value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator/(const Matrix4<TVALUE>& matrix) const
		{
			return Matrix4<TVALUE>(*this) /= matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator/=(const Matrix4<TVALUE>& matrix)
		{
			TVALUE d = matrix.getDeterminant();

			//if (d == 0)
			//	return 0;

			*this = Matrix4<TVALUE>(matrix).inverse();
			
			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator/(const TVALUE value) const
		{
			return Matrix4<TVALUE>(*this) /= value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>&  operator/=(const TVALUE value)
		{
			set(Values[0][0] / value,
				Values[1][0] / value,
				Values[2][0] / value,
				Values[3][0] / value,
				Values[0][1] / value,
				Values[1][1] / value,
				Values[2][1] / value,
				Values[3][1] / value,
				Values[0][2] / value,
				Values[1][2] / value,
				Values[2][2] / value,
				Values[3][2] / value,
				Values[0][3] / value,
				Values[1][3] / value,
				Values[2][3] / value,
				Values[3][3] / value);

			return *this;
		}

		bool operator==(const Matrix4<TVALUE>& matrix)
		{
			return (Values[0][0] == matrix.Values[0][0])
					&& (Values[0][1] == matrix.Values[0][1])
					&& (Values[0][2] == matrix.Values[0][2])
					&& (Values[0][3] == matrix.Values[0][3])
					&& (Values[1][0] == matrix.Values[1][0])
					&& (Values[1][1] == matrix.Values[1][1])
					&& (Values[1][2] == matrix.Values[1][2])
					&& (Values[1][3] == matrix.Values[1][3])
					&& (Values[2][0] == matrix.Values[2][0])
					&& (Values[2][1] == matrix.Values[2][1])
					&& (Values[2][2] == matrix.Values[2][2])
					&& (Values[2][3] == matrix.Values[2][3])
					&& (Values[3][0] == matrix.Values[3][0])
					&& (Values[3][1] == matrix.Values[3][1])
					&& (Values[3][2] == matrix.Values[3][2])
					&& (Values[3][3] == matrix.Values[3][3]);
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator!=(const Matrix4<TVALUE>& matrix) const
		{
			return !operator==(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		Matrix4<TVALUE>& multiply(const Matrix4<TVALUE>& matrix)
		{
			return operator*=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		Matrix4<TVALUE>& multiply(const TVALUE value)
		{
			return operator*=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		Matrix4<TVALUE>& dotProduct(const Matrix4<TVALUE>& matrix)
		{
			return operator*=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		Matrix4<TVALUE>& scalar(const TVALUE value)
		{
			return operator*=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const Matrix4<TVALUE>& matrix) const
		{
			return operator==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		Matrix4<TVALUE>& identity()
		{
			set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

			return *this;
		}

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		Matrix4<TVALUE>& zero()
		{
			return operator=(0);
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		Matrix4<TVALUE>& allOnes()
		{
			return operator=(1);
		}

		/// <summary>
		/// Transposes the matrix
		/// </summary>
		Matrix4<TVALUE>& transpose()
		{
			return transpose(*this);
		}

		/// <summary>
		/// Transposes the matrix passed
		/// </summary>
		Matrix4<TVALUE>& transpose(const Matrix4<TVALUE>& matrix)
		{
			set(matrix.Values[0][0], matrix.Values[0][1], matrix.Values[0][2], matrix.Values[0][3],
				matrix.Values[1][0], matrix.Values[1][1], matrix.Values[1][2], matrix.Values[1][3],
				matrix.Values[2][0], matrix.Values[2][1], matrix.Values[2][2], matrix.Values[2][3],
				matrix.Values[3][0], matrix.Values[3][1], matrix.Values[3][2], matrix.Values[3][3]);

			return *this;
		}

		/// <summary>
		/// Returns the transpose of the matrix
		/// </summary>
		Matrix4<TVALUE> getTransposed()
		{
			return Matrix2<TVALUE>(*this).transpose();
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		Matrix4<TVALUE>& inverse()
		{
			return inverse(*this);
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		Matrix4<TVALUE>& inverse(const Matrix4<TVALUE>& matrix)
		{
			//todo
			return *this;
		}

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		Matrix4<TVALUE> getInverted()
		{
			return Matrix2<TVALUE>(*this).inverse();
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const
		{
			// Leibniz
			return Values[0][0] * Values[1][1] * Values[2][2] * Values[3][3] + Values[0][0] * Values[2][1] * Values[3][2] * Values[1][3] + Values[0][0] * Values[3][1] * Values[1][2] * Values[2][3]
					+ Values[1][0] * Values[0][1] * Values[3][2] * Values[2][3] + Values[1][0] * Values[2][1] * Values[0][2] * Values[3][3] + Values[1][0] * Values[3][1] * Values[2][2] * Values[0][3]
					+ Values[2][0] * Values[0][1] * Values[1][2] * Values[3][3] + Values[2][0] * Values[1][1] * Values[3][2] * Values[0][3] + Values[2][0] * Values[3][1] * Values[0][2] * Values[1][3]
					+ Values[3][0] * Values[0][1] * Values[2][2] * Values[1][3] + Values[3][0] * Values[1][1] * Values[0][2] * Values[2][3] + Values[3][0] * Values[2][1] * Values[1][2] * Values[0][3]
					− Values[0][0] * Values[1][1] * Values[3][2] * Values[2][3] − Values[0][0] * Values[2][1] * Values[1][2] * Values[3][3] − Values[0][0] * Values[3][1] * Values[2][2] * Values[1][3]
					− Values[1][0] * Values[0][1] * Values[2][2] * Values[3][3] − Values[1][0] * Values[2][1] * Values[3][2] * Values[0][3] − Values[1][0] * Values[3][1] * Values[0][2] * Values[2][3]
					− Values[2][0] * Values[0][1] * Values[3][2] * Values[1][3] − Values[2][0] * Values[1][1] * Values[0][2] * Values[3][3] − Values[2][0] * Values[3][1] * Values[1][2] * Values[0][3]
					− Values[3][0] * Values[0][1] * Values[1][2] * Values[2][3] − Values[3][0] * Values[1][1] * Values[2][2] * Values[0][3] − Values[3][0] * Values[2][1] * Values[0][2] * Values[1][3];
		}

		static Matrix4<TVALUE> getIdentity()
		{
			return Matrix4<TVALUE>().identity();
		}

		static Matrix4<TVALUE> getZero()
		{
			return Matrix4<TVALUE>(0);
		}

		static Matrix4<TVALUE> getAllOnes()
		{
			return Matrix4<TVALUE>(1);
		}

		~Matrix4()
		{
		}

	};
}

#endif // COMMONMATRIX4_H
