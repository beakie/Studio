#ifndef COMMON_ICOLLECTION_H
#define COMMON_ICOLLECTION_H

namespace Common
{

	template <typename TVALUE, typename TINDEX>
	struct ICollection
	{
	public:
		virtual TINDEX count() const = 0;

		virtual TVALUE operator[] (const TINDEX n) = 0;
	};

}

#endif // COMMON_ICOLLECTION_H
