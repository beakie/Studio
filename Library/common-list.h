#ifndef COMMON_LIST_H
#define COMMON_LIST_H

// add insert functions

namespace Common
{

	template <typename TVALUE, typename TINDEX = UIntMax>
	/// <summary>
	/// 1 dimensional list of values
	/// </summary>
	struct List
	{

	protected:
		TINDEX Capacity;
		TINDEX Count;

	public:
		TVALUE* Items;

		List()
		{
			Count = 0;
			Capacity = 0;

			Items = 0;
		}

		List(const List<TVALUE, TINDEX>& list)
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

		List<TVALUE, TINDEX>& remove(const TINDEX index)
		{
			if (index >= Count)
				return *this;

			for (TINDEX i = index; i < (Count - 1); i++)
				Items[i] = Items[i + 1];

			Count--;

			return *this;
		}

		List<TVALUE, TINDEX>& add(const TVALUE item)
		{
			return operator+=(item);
		}

		List<TVALUE, TINDEX>& add(const List<TVALUE, TINDEX>& list)
		{
			return operator+=(list);
		}

		void resize()
		{
			resize(Capacity ? Capacity * 2 : 1);
		}

		void resize(const TINDEX capacity)
		{
			TVALUE *x = new TVALUE[capacity];

			for (TINDEX i = 0; i < Count; i++)
				x[i] = Items[i];

			delete[] Items;

			Items = x;
			Capacity = capacity;
		}

		void clone(const List<TVALUE, TINDEX>& list)
		{
			operator=(list);
		}

		TINDEX getIndex(const TVALUE value)
		{
			for (TINDEX i = 0; i < Count; i++)
				if (Items[i] == value)
					return i + 1;

			return 0;
		}

		void clear()
		{
			delete[] Items;

			Items = new TVALUE[0];

			Capacity = 0;
			Count = 0;
		}

		List<TVALUE, TINDEX>& operator=(const List<TVALUE, TINDEX> &list)
		{
			if (this != &list)
			{
				TVALUE* tmp = new TVALUE[list.Capacity];
				Capacity = list.Capacity;
				Count = list.Count;

				for (TINDEX i = 0; i < Count; i++)
					tmp[i] = list.Items[i];

				delete[] Items;

				Items = tmp;
			}

			return *this;
		}

		List<TVALUE, TINDEX> & operator+=(const TVALUE item)
		{
			if (Count == Capacity)
				resize();

			Items[Count] = item;

			Count++;

			return *this;
		}

		List<TVALUE, TINDEX> & operator+=(const List<TVALUE, TINDEX>& list)
		{
			TINDEX listCount = list.Count;

			//could be more efficient if only resizes once and then copies all items into the list itself
			for (TINDEX i = 0; i < listCount; i++)
				addItem(list.Items[i]);

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

		~List() {
			delete[] Items;
		}
	};

}

#endif // COMMON_LIST_H
