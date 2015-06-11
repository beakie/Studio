#ifndef SPACE2D_COMMON_H
#define SPACE2D_COMMON_H

#include "common.h"

#include "space2d-plot.h"

namespace Space2d
{

	template <typename T>
	FloatMax getPlotDistance(const Common::Vector2<T> &plot1, const Common::Vector2<T> &plot2)
	{
		return Common::power(Common::power((FloatMax)plot1.Values[0] - plot2.Values[0], 2) + Common::power(plot1.Values[1] - plot2.Values[1], 2), 0.5);
	}

	template <typename T>
	Common::Vector2<T> getPlotOffset(const Common::Vector2<T> &plot1, const Common::Vector2<T> &plot2)
	{
		return plot2 - plot1;
	}

	template <typename T>
	Common::Vector2<T> getPlotDiff(const Common::Vector2<T> &plot1, const Common::Vector2<T> &plot2)
	{
		return Common::Vector2<T>(Common::abs(plot1.Values[0] - plot2.Values[0]), Common::abs(plot1.Values[1] - plot2.Values[1]));
	}

}

#endif // SPACE2D_COMMON_H
