#ifndef COMMONUNITINTERVAL_H
#define COMMONUNITINTERVAL_H

#include "common-math_.h"

namespace Common
{
	/// <summary>
	/// 4 byte unit interval (0 - 1)
	/// </summary>
	typedef Float32 UnitInterval32;
	/// <summary>
	/// 8 byte unit interval (0 - 1)
	/// </summary>
	typedef Float64 UnitInterval64;
	/// <summary>
	/// Max available size unit interval (0 - 1)
	/// </summary>
	typedef FloatMax UnitIntervalMax;

	template <typename TUNITINTERVAL>
	bool isValidUnitInterval(TUNITINTERVAL value)
	{
		return (value >= 0) && (value <= 1);
	}

	template <typename TUNITINTERVAL>
	TUNITINTERVAL trimUnitInterval(TUNITINTERVAL value)
	{
		return min<TUNITINTERVAL>(max<TUNITINTERVAL>(value, 0.0), 1.0);
	}

}

#endif // COMMONUNITINTERVAL_H
