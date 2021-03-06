/****************************************************************************/
/*																			*/
/*	This source file is used to link 'AbWidgets' array to 'PhWidgets' lib.	*/
/*	It should be placed in 'src' folder of PhAB project with 'ablibs.h' and	*/
/*	'abimport.h' so it will be compiled with other project source files to	*/
/*	link global variables of PhAB project with the library.					*/
/*																			*/
/*	Note that library folder 'PhWidgets' itself should be located also in	*/
/*	'src' directory of the project. If not- correct the include path below 	*/
/*	to match the location of 'PhWidgets' library includes.					*/
/*																			*/
/****************************************************************************/


#include <photon/PtWidget.h>

#include <vector>
#include <cstddef>

#include "ablibs.h"
#include "abimport.h"

namespace PhWidgets
{
	namespace internal
	{
		template<typename T, std::size_t N>
		inline PtWidget_t* GetABW(std::size_t n, T (&AbWidgets)[N])
		{
			PtWidget_t *widget = n < N ? AbGetABW(n) : 0;
			
			return widget;
		}

		template<typename T, std::size_t N>
		inline std::vector<PtWidget_t*> GetABW(T (&AbWidgets)[N])
		{
			std::vector<PtWidget_t*> widgets;
			
			widgets.reserve(N);
			
			for(size_t i = 0; i < N; ++i)
			{
				widgets.push_back(internal::GetABW(i, AbWidgets));
			}
					
			return widgets;
		}
	}

	PtWidget_t* GetABW(int n)
	{
		if(n < 0)
			return 0;
			
		return internal::GetABW(std::size_t(n), AbWidgets);
	}

	std::vector<PtWidget_t*> GetABW()
	{
		return internal::GetABW(AbWidgets);
	}

	size_t GetABWCount()
	{
		return sizeof(AbWidgets) / sizeof(AbWidgets[0]);
	}
}
