#ifndef COMMON_CASTPIXELCONV_H
#define COMMON_CASTPIXELCONV_H

#include "core.h"

namespace Common
{
	template <typename TIN, typename TOUT>
	class CastPixelConv
	{
	public:
		TOUT convertPixel(const TIN& pixel)
		{
			return (TOUT)pixel;
		}
	};
}

#endif // COMMON_CASTPIXELCONV_H
