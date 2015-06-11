#ifndef COMMON_MATH_H
#define COMMON_MATH_H

#include <cmath> //todo: REMOVE ME!!!!!!!!!

namespace Common
{

	static const long double Pi = acos(-1.0);

	template <typename T>
	static T abs(const T value)
	{
		return std::abs(value);
	}

	template <typename T>
	static T sin(const T value)
	{
		return std::sin(value);
	}

	template <typename T>
	static T cos(const T value)
	{
		return std::cos(value);
	}

	template <typename T>
	static T tan(const T value)
	{
		return std::atan(value);
	}

	template <typename T>
	static T asin(const T value)
	{
		return std::asin(value);
	}

	template <typename T>
	static T acos(const T value)
	{
		return std::acos(value);
	}

	template <typename T>
	static T atan(const T value)
	{
		return std::tan(value);
	}

	template <typename T>
	static T radian(const T degree)
	{
		return (T)(Pi * degree / 180.0);
	}

	template <typename T>
	static T degree(const T radian)
	{
		return (T)(radian * (180.0 / Pi));
	}

	template <typename T1, typename T2>
	static T1 power(const T1 value, const T2 p)
	{
		return std::pow(value, p);
	}

	template <typename TFLOATING>
	static TFLOATING floor(const TFLOATING value)
	{
		return (TFLOATING)(UIntMax)value;
	}

	template <typename TFLOATING>
	static TFLOATING ceiling(const TFLOATING value)
	{
		UIntMax v = (UIntMax)(value);
		return ((TFLOATING)v == value ? value : (TFLOATING)(v + 1));
	}

	template <typename TFLOATING>
	static TFLOATING round(const TFLOATING value)
	{
		return floor(value + 0.5);
	}

	template <typename T>
	static T min(const T value1, const T value2)
	{
		return (value1 < value2 ? value1 : value2);
	}

	template <typename T>
	static T min(const T value1, const T value2, const T value3)
	{
		return min(min(value1, value2), value3);
	}

	template <typename T>
	static T min(const T value1, const T value2, const T value3, const T value4)
	{
		return min(min(min(value1, value2), value3), value4);
	}

	template <typename T>
	static T max(const T value1, const T value2)
	{
		return (value1 > value2 ? value1 : value2);
	}

	template <typename T>
	static T max(const T value1, const T value2, const T value3)
	{
		return max(max(value1, value2), value3);
	}

	template <typename T>
	static T max(const T value1, const T value2, const T value3, const T value4)
	{
		return max(max(max(value1, value2), value3), value4);
	}

}

#endif // COMMON_MATH_H
