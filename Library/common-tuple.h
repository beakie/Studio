#ifndef COMMONTUPLE_H
#define COMMONTUPLE_H

#include "core.h"

namespace Common
{
	template <typename T1>
	struct Tuple1
	{
		T1 Item1;

		Tuple1()
		{
		}

		Tuple1(T1 item1)
		{
			Item1 = item1;
		}

		~Tuple1()
		{
		}
	};

	template <typename T1, typename T2>
	struct Tuple2
	{
		T1 Item1;
		T2 Item2;

		Tuple2()
		{
		}

		Tuple2(T1 item1, T2 item2)
		{
			Item1 = item1;
			Item2 = item2;
		}

		~Tuple2()
		{
		}
	};

	template <typename T1, typename T2, typename T3>
	struct Tuple3
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;

		Tuple3()
		{
		}

		Tuple3(T1 item1, T2 item2, T3 item3)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
		}

		~Tuple3()
		{
		}
	};

	template <typename T1, typename T2, typename T3, typename T4>
	struct Tuple4
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;

		Tuple4()
		{
		}

		Tuple4(T1 item1, T2 item2, T3 item3, T4 item4)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
		}

		~Tuple4()
		{
		}
	};

	template <typename T1, typename T2, typename T3, typename T4, typename T5>
	struct Tuple5
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;

		Tuple5()
		{
		}

		Tuple5(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
			Item5 = item5;
		}

		~Tuple5()
		{
		}
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

		Tuple6()
		{
		}

		Tuple6(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
			Item5 = item5;
			Item6 = item6;
		}

		~Tuple6()
		{
		}
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

		Tuple7()
		{
		}

		Tuple7(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
			Item5 = item5;
			Item6 = item6;
			Item7 = item7;
		}

		~Tuple7()
		{
		}
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

		Tuple8()
		{
		}

		Tuple8(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, T8 item8)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
			Item5 = item5;
			Item6 = item6;
			Item7 = item7;
			Item8 = item8;
		}

		~Tuple8()
		{
		}
	};
}

#endif // COMMONTUPLE_H
