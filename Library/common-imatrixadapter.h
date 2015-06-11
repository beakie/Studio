#ifndef COMMON_IMATRIXADAPTER_H
#define COMMON_IMATRIXADAPTER_H

#include "core.h"

namespace Common
{
	template <typename TVALUE>
	/// <summary>
	/// Matrix adapter interface
	/// </summary>
	struct IMatrixAdapter
	{
		/// <summary>
		/// Returns the number of rows
		/// </summary>
		virtual UInt8 getRowCount() = 0;

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		virtual UInt8 getColumnCount() = 0;

		virtual ~IMatrixAdapter()
		{
		}
	};
}

#endif // COMMON_IMATRIXADAPTER_H
