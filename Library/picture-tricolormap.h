#ifndef PICTURE_TRICOLORMAP_H
#define PICTURE_TRICOLORMAP_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	struct TriColorMap
	{
		Common::Vector3<TUNITINTERVAL>* Values;
		UInt8 Size;
		TUNITINTERVAL SpacingSize;

		TriColorMap(UInt8 size)
		{
			createValues(size);
		}

		TriColorMap(const TriColorMap<TUNITINTERVAL>& triColorMap)
		{
			createValues(triColorMap.Size);
			copyValues(triColorMap);
		}

		TriColorMap<TUNITINTERVAL>& operator=(const TriColorMap<TUNITINTERVAL>& triColorMap)
		{
			if (this != &triColorMap)
			{
				deleteValues();
				createValues(triColorMap.Size);
				copyValues(triColorMap);
			}

			return *this;
		}
		
	private:
		void createValues(UInt8 size)
		{
			Values = new Common::Vector3<TUNITINTERVAL>[size];
			Size = size;
			SpacingSize = (float)1 / (size - 1);
		}

		void deleteValues()
		{
			delete[] Values;
		}

		void copyValues(const TriColorMap<TUNITINTERVAL>& triColorMap)
		{
			for (UInt8 i = 0; i < triColorMap.Size; i++)
			{
				Values[i] = triColorMap.Values[i];
			}
		}

	public:
		~TriColorMap()
		{
			deleteValues();
		}
	};
}

#endif // PICTURE_TRICOLORMAP_H
