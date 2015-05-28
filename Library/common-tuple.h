#ifndef COMMONTUPLE_H
#define COMMONTUPLE_H

#include "core.h"

namespace Common
{
	template <typename T1>
	struct Tuple1
	{
		T1 Item1;
	};

	template <typename T1, typename T2>
	struct Tuple2
	{
		T1 Item1;
		T2 Item2;
	};

	template <typename T1, typename T2, typename T3>
	struct Tuple3
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
	};

	template <typename T1, typename T2, typename T3, typename T4>
	struct Tuple4
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
	};

	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	struct Tuple5
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
	};

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
	struct Tuple6
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
		T6 Item6;
	};

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
	struct Tuple7
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
		T6 Item6;
		T7 Item7;
	};

	template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
	struct Tuple8
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
		T6 Item6;
		T7 Item7;
		T8 Item8;
	};
}

#endif // COMMONTUPLE_H
