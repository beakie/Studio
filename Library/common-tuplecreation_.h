#ifndef COMMONTUPLECREATION_H
#define COMMONTUPLECREATION_H

#include "core.h"

#include "common-tuple.h"

namespace Common
{
	template <typename T1>
	static Tuple1<T1> createTuple(T1 value1)
	{
		return Tuple1<T1>()
	}
}

#endif // COMMONTUPLECREATION_H
