#include "ClearMode.h"

#include "../OpenGL/OpenGL.h"

using namespace guar;
using namespace GFX;
using namespace ClearMode;

const ClearModeCode ClearMode::ColorBuffer        = GL_COLOR_BUFFER_BIT   ;
const ClearModeCode ClearMode::DepthBuffer        = GL_DEPTH_BUFFER_BIT   ;
const ClearModeCode ClearMode::AccumulationBuffer = GL_ACCUM_BUFFER_BIT   ;
const ClearModeCode ClearMode::StencilBuffer      = GL_STENCIL_BUFFER_BIT ;