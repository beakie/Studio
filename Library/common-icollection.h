#ifndef COMMON_ICOLLECTION_H
#define COMMON_ICOLLECTION_H

namespace Common
{

	template <typename TOUT, typename TINDEX>
	struct ICollection
	{
	public:
		virtual TINDEX count() const = 0;

		virtual TOUT operator[] (TINDEX n) = 0;

		~ICollection() {
		}
	};

}

#endif // COMMON_ICOLLECTION_H
