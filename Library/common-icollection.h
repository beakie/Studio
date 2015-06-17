#ifndef COMMON_ICOLLECTION_H
#define COMMON_ICOLLECTION_H

namespace Common
{

	template <typename TVALUE, typename TINDEX>
	struct ICollection
	{
	public:
		virtual TINDEX count() const = 0;

		//virtual TINDEX getIndex(const TVALUE value) = 0;

		virtual TVALUE operator[] (TINDEX n) = 0;

		//virtual bool exists(const TVALUE value) = 0;

		~ICollection() {
		}
	};

}

#endif // COMMON_ICOLLECTION_H
