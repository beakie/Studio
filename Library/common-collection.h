#ifndef COMMON_COLLECTION_H
#define COMMON_COLLECTION_H

#include "common-icollection.h"

namespace Common
{

	template <typename TVALUE, typename TINDEX = UIntMax>
	struct Collection : ICollection<TVALUE, TINDEX>
	{

	protected:
		TINDEX Count;

	public:
		TVALUE* Items;

		Collection()
		{
			Count = 0;

			Items = 0;
		}

		Collection(TINDEX count, TVALUE default)
		{
			Count = count;

			Items = new TVALUE[count];

			for (TINDEX i = 0; i < Count; i++)
				Items[i] = default;
		}

		Collection(const Collection<TVALUE, TINDEX>& collection)
		{
			Items = 0;
			operator=(collection);
		}

		TINDEX count() const
		{
			return Count;
		}

		TINDEX capacity() const
		{
			return Count;
		}

		TINDEX getIndex(const TVALUE value)
		{
			for (TINDEX i = 0; i < Count; i++)
				if (Items[i] == value)
					return i + 1;

			return 0;
		}

		Collection<TVALUE, TINDEX>& operator=(const Collection<TVALUE, TINDEX> &collection)
		{
			if (this != &collection)
			{
				TVALUE* tmp = new TVALUE[collection.capacity()];
				Count = collection.Count;

				for (TINDEX i = 0; i < Count; i++)
					tmp[i] = collection.Items[i];

				delete[] Items;

				Items = tmp;
			}

			return *this;
		}

		TVALUE & operator[] (TINDEX n)
		{
			return Items[n];
		}

		bool exists(const TVALUE value)
		{
			for (TINDEX i = 0; i < Count; i++)
				if (Items[i] == value)
					return true;

			return false;
		}

		~Collection() {
			delete[] Items;
		}
	};

}

#endif // COMMON_COLLECTION_H
