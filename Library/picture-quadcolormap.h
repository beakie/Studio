#ifndef PICTUREQUADCOLORMAP_H
#define PICTUREQUADCOLORMAP_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	struct QuadColorMap
	{
		Common::Vector4<TUNITINTERVAL>* Values;
		UInt8 Size;
		TUNITINTERVAL SpacingSize;

		QuadColorMap(UInt8 size)
		{
			createValues(size);
		}

		QuadColorMap(const QuadColorMap<TUNITINTERVAL>& quadColorMap)
		{
			createValues(quadColorMap.Size);
			copyValues(quadColorMap);
		}

		QuadColorMap<TUNITINTERVAL>& operator=(const QuadColorMap<TUNITINTERVAL>& quadColorMap)
		{
			if (this != &quadColorMap)
			{
				deleteValues();
				createValues(quadColorMap.Size);
				copyValues(quadColorMap);
			}

			return *this;
		}

	private:
		void createValues(UInt8 size)
		{
			Values = new TUNITINTERVAL*[size];
			Size = size;
			SpacingSize = (float)1 / (size - 1);
		}

		void deleteValues()
		{
			delete[] Values;
		}

		void copyValues(const QuadColorMap<TUNITINTERVAL>& quadColorMap)
		{
			for (UInt8 i = 0; i < quadColorMap.Size; i++)
			{
				Values[i] = quadColorMap.Values[i];
			}
		}

	public:
		~QuadColorMap()
		{
			deleteValues();
		}
	};
}

#endif // PICTUREQUADCOLORMAP_H
