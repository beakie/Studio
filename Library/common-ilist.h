#ifndef COMMON_ILIST_H
#define COMMON_ILIST_H

#include "common-icollection.h"

namespace Common
{

	template <typename TVALUE, typename TINDEX>
	struct IList : ICollection<TVALUE, TINDEX>
	{
	public:
		virtual void remove(const TINDEX index) = 0;

		virtual void add(const TVALUE& item) = 0;

		virtual void clear() = 0;
	};

}

#endif // COMMON_ILIST_H
