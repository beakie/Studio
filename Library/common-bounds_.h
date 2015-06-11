#ifndef COMMON_BOUNDS_H
#define COMMON_BOUNDS_H

#include "core.h"

namespace Common
{
	template <typename T>
	static T getUpperBound();

	template <typename T>
	static T getLowerBound();

	template <typename T>
	static T getDefault();

	template <>
	static UInt1 getLowerBound<UInt1>()
	{
		return 0;
	}

	template <>
	static UInt1 getUpperBound<UInt1>()
	{
		return 1;
	}

	template <>
	static UInt1 getDefault<UInt1>()
	{
		return 0;
	}

	template <>
	static Int8 getLowerBound<Int8>()
	{
		return -127;
	}

	template <>
	static Int8 getUpperBound<Int8>()
	{
		return 127;
	}

	template <>
	static Int8 getDefault<Int8>()
	{
		return 0;
	}

	template <>
	static UInt8 getLowerBound<UInt8>()
	{
		return 0;
	}

	template <>
	static UInt8 getUpperBound<UInt8>()
	{
		return 255;
	}

	template <>
	static UInt8 getDefault<UInt8>()
	{
		return 0;
	}

	template <>
	static Int16 getLowerBound<Int16>()
	{
		return -32767;
	}

	template <>
	static Int16 getUpperBound<Int16>()
	{
		return 32767;
	}

	template <>
	static Int16 getDefault<Int16>()
	{
		return 0;
	}

	template <>
	static UInt16 getLowerBound<UInt16>()
	{
		return 0;
	}

	template <>
	static UInt16 getUpperBound<UInt16>()
	{
		return 65535;
	}

	template <>
	static UInt16 getDefault<UInt16>()
	{
		return 0;
	}

	template <>
	static Int32 getLowerBound<Int32>()
	{
		return -2147483647;
	}

	template <>
	static Int32 getUpperBound<Int32>()
	{
		return 2147483647;
	}

	template <>
	static Int32 getDefault<Int32>()
	{
		return 0;
	}

	template <>
	static Float32 getLowerBound<Float32>()
	{
		return -3400000000000000000;
	}

	template <>
	static Float32 getUpperBound<Float32>()
	{
		return 3400000000000000000;
	}

	template <>
	static Float32 getDefault<Float32>()
	{
		return 0;
	}
}

#endif // COMMON_BOUNDS_H
