#ifndef COMMON_ICOLLECTION_H
#define COMMON_ICOLLECTION_H

namespace Common
{

	template <typename TIN, typename TOUT, typename TINDEX>
	struct ICollection
	{
	public:
		virtual TINDEX count() const = 0;

		//virtual TINDEX getIndex(const TIN value) = 0;

		virtual TOUT operator[] (TINDEX n) = 0;

		//virtual bool exists(const TIN value) = 0;

		~ICollection() {
		}
	};

}

#endif // COMMON_ICOLLECTION_H
