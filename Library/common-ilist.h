#ifndef COMMON_ILIST_H
#define COMMON_ILIST_H

#include "common-icollection.h"

namespace Common
{

	template <typename TIN, typename TOUT, typename TINDEX>
	struct IList : ICollection<TIN, TOUT, TINDEX>
	{
	public:
		virtual void remove(const TINDEX index) = 0;

		//virtual void add(const TIN item) = 0; // <-- BAD
		virtual void add(const TOUT& item) = 0; // <-- GOOD

		virtual void clear() = 0;

		~IList() {
		}
	};

}

#endif // COMMON_ILIST_H
