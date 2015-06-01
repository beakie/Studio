#ifndef COMMONRANGE_H
#define COMMONRANGE_H

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

#endif // COMMONRANGE_H
