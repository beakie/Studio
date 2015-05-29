#ifndef SPACE2DLINESEGMENT2D_H
#define SPACE2DLINESEGMENT2D_H

#include "common.h"

namespace Space2d
{

	template <typename TVALUE = FloatMax>
	struct LineSegment2d
	{
		Common::Vector2<TVALUE> PlotFrom;
		Common::Vector2<TVALUE> PlotTo;

		Common::Vector2<TVALUE> getOffset() const
		{
			return PlotTo - PlotFrom;
		}

		TVALUE getLength() const
		{
			return Common::power(Common::power(PlotTo.Values[0] - PlotFrom.Values[0], 2) + Common::power(PlotTo.Values[1] - PlotFrom.Values[1], 2), 0.5);
		}
	};

}

#endif // SPACE2DLINESEGMENT2D_H
