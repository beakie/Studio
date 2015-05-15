#ifndef COMMONTUPLE_H
#define COMMONTUPLE_H

#include "core.h"

namespace Common
{
	template <typename T1 = FloatMax>
	struct Tuple1
	{
		T1 Item1;
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax>
	struct Tuple2
	{
		T1 Item1;
		T2 Item2;
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax>
	struct Tuple3
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax>
	struct Tuple4
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax, typename T5 = FloatMax>
	struct Tuple5
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax, typename T5 = FloatMax, typename T6 = FloatMax>
	struct Tuple6
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
		T6 Item6;
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax, typename T5 = FloatMax, typename T6 = FloatMax, typename T7 = FloatMax>
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

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax, typename T5 = FloatMax, typename T6 = FloatMax, typename T7 = FloatMax, typename T8 = FloatMax>
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
