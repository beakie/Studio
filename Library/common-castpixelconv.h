#ifndef COMMONCASTPIXELCONV_H
#define COMMONCASTPIXELCONV_H

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

#endif // COMMONCASTPIXELCONV_H
