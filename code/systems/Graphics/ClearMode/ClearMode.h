#ifndef GUAR_GRAPHICS_CLEARMODE_H
#define GUAR_GRAPHICS_CLEARMODE_H

namespace guar
{
	namespace GFX
	{
		namespace ClearMode
		{
			typedef unsigned int ClearModeCode;

			extern const ClearModeCode ColorBuffer        ; 
			extern const ClearModeCode DepthBuffer        ; 
			extern const ClearModeCode AccumulationBuffer ; 
			extern const ClearModeCode StencilBuffer      ; 

		}

	}

}

#endif