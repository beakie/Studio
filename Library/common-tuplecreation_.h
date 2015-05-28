#ifndef COMMONTUPLECREATION_H
#define COMMONTUPLECREATION_H

#include "core.h"

#include "common-tuple.h"

namespace Common
{
	template <typename T1>
	static Tuple1<T1> createTuple(T1 item1)
	{
		return Tuple1<T1>(item1);
	}

	template <typename T1, typename T2>
	static Tuple2<T1, T2> createTuple(T1 item1, T2 item2)
	{
		return Tuple2<T1, T2>(item1, item2);
	}

	template <typename T1, typename T2, typename T3>
	static Tuple3<T1, T2, T3> createTuple(T1 item1, T2 item2, T3 item3)
	{
		return Tuple3<T1, T2, T3>(item1, item2, item3);
	}

	template <typename T1, typename T2, typename T3, typename T4>
	static Tuple4<T1, T2, T3, T4> createTuple(T1 item1, T2 item2, T3 item3, T4 item4)
	{
		return Tuple4<T1, T2, T3, T4>(item1, item2, item3, item4);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	static Tuple5<T1, T2, T3, T4, T5> createTuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5)
	{
		return Tuple5<T1, T2, T3, T4, T5>(item1, item2, item3, item4, item5);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	static Tuple6<T1, T2, T3, T4, T5, T6> createTuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6)
	{
		return Tuple6<T1, T2, T3, T4, T5, T6>(item1, item2, item3, item4, item5, item6);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	static Tuple7<T1, T2, T3, T4, T5, T6, T7> createTuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7)
	{
		return Tuple7<T1, T2, T3, T4, T5, T6, T7>(item1, item2, item3, item4, item5, item6, item7);
	}

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	static Tuple8<T1, T2, T3, T4, T5, T6, T7, T8> createTuple(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, T8 item8)
	{
		return Tuple8<T1, T2, T3, T4, T5, T6, T7, T8>(item1, item2, item3, item4, item5, item6, item7, item8);
	}
}

#endif // COMMONTUPLECREATION_H
