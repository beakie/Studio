#ifndef COMMON_MANAGEDLIST_H
#define COMMON_MANAGEDLIST_H

#include "common-ilist.h"

// add insert functions

namespace Common
{

	template <typename TVALUE, typename TINDEX = UIntMax>
	struct ManagedList : IList<TVALUE, TINDEX>
	{

	protected:
		TINDEX Capacity;
		TINDEX Count;

	public:
		TVALUE** Items;

		ManagedList()
		{
			Count = 0;
			Capacity = 0;

			Items = 0;
		}

		ManagedList(const ManagedList<TVALUE, TINDEX>& list)
		{
			Items = 0;
			operator=(list);
		}

		TINDEX count() const
		{
			return Count;
		}

		TINDEX capacity() const
		{
			return Capacity;
		}

		void remove(const TINDEX index)
		{
			if (index >= Count)
				return;

			delete Items[index];

			for (TINDEX i = index; i < (Count - 1); i++)
				Items[i] = Items[i + 1];

			Count--;

			return;
		}

		void add(const TVALUE& item)
		{
			operator+=(item);
		}

		void add(const ManagedList<TVALUE, TINDEX>& list)
		{
			operator+=(list);
		}

		void resize()
		{
			resize(Capacity ? Capacity * 2 : 1);
		}

		void resize(const TINDEX capacity)
		{
			TVALUE** x = new TVALUE*[capacity];

			for (TINDEX i = 0; i < Count; i++)
				x[i] = Items[i];

			delete[] Items;

			Items = x;
			Capacity = capacity;
		}

		void clone(const ManagedList<TVALUE, TINDEX>& list)
		{
			operator=(list);
		}

		TINDEX getIndex(const TVALUE& value)
		{
			for (TINDEX i = 0; i < Count; i++)
				if (Items[i] == &value)
					return i + 1;

			return 0;
		}

		void clear()
		{
			for (TINDEX i = 0; i < Count; i++)
				delete Items[i];

			delete[] Items;

			Items = new TVALUE*[0];

			Capacity = 0;
			Count = 0;
		}

		ManagedList<TVALUE, TINDEX>& operator=(const ManagedList<TVALUE, TINDEX>& list)
		{
			if (this != &list)
			{
				TVALUE** tmp = new TVALUE*[list.Capacity];
				Capacity = list.Capacity;
				Count = list.Count; // this should be moved to end in case it fails during execution.

				for (TINDEX i = 0; i < Count; i++)
					tmp[i] = new TVALUE(*list.Items[i]);

				delete[] Items; // should this have also deleted items? (yes me thinks)

				Items = tmp;
			}

			return *this;
		}

		ManagedList<TVALUE, TINDEX>& operator+=(const TVALUE& item)
		{
			if (Count == Capacity)
				resize();

			Items[Count] = new TVALUE(item);

			Count++;

			return *this;
		}

		ManagedList<TVALUE, TINDEX>& operator+=(const ManagedList<TVALUE, TINDEX>& list)
		{
			TINDEX listCount = list.Count;

			//could be more efficient if only resizes once and then copies all items into the list itself
			for (TINDEX i = 0; i < listCount; i++)
				operator+=(list.Items[i]);

			return *this;
		}

		TVALUE operator[] (const TINDEX n) const
		{
			return TVALUE(*Items[n]);
		}

		bool exists(const TVALUE& value)
		{
			for (TINDEX i = 0; i < Count; i++)
				if (Items[i] == &value)
					return true;

			return false;
		}

		~ManagedList() {
			for (TINDEX i = 0; i < Count; i++)
				delete Items[i];

			delete[] Items;
		}
	};

}

#endif // COMMON_MANAGEDLIST_H
