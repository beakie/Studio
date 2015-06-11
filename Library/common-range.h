#ifndef COMMON_RANGE_H
#define COMMON_RANGE_H

namespace Common
{
	template <typename T>
	struct Range
	{
		T From;
		T To;

		Range()
		{
		}

		Range(T from, T to)
		{
			From = from;
			To = to;
		}

		~Range()
		{
		}

		T getSpan() const
		{
			return To - From;
		}
	};
}

#endif // COMMON_RANGE_H
