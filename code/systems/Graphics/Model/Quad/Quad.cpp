#include "Quad.h"

#include <stdio.h>
#include "../../OpenGL/OpenGL.h"
#include "../../VertexFormat/VertexFormat.h"
//#include <iostream>
#include <vector>

using namespace guar;
using namespace GFX;

static Vertex::Data genData()
{
    ////Push data to buffer
    Vertex::Data vertexes;
    float size = 1.0f;
                                      //           x,               y,        z,   u,   v,  Nx,  Ny,   Nz,
    vertexes.push_back(Vertex::create(size -(size/2),  size -(size/2),  0.0, 1.0, 0.0, 0.0, 0.0, 1.0)); // 1--0
    vertexes.push_back(Vertex::create(0.0  -(size/2),  size -(size/2),  0.0, 0.0, 0.0, 0.0, 0.0, 1.0)); // | /
    vertexes.push_back(Vertex::create(0.0  -(size/2),  0.0  -(size/2),  0.0, 0.0, 1.0, 0.0, 0.0, 1.0)); // 2
    
    vertexes.push_back(Vertex::create(size -(size/2),  size -(size/2),  0.0, 1.0, 0.0, 0.0, 0.0, 1.0)); //    0
    vertexes.push_back(Vertex::create(0.0  -(size/2),  0.0  -(size/2),  0.0, 0.0, 1.0, 0.0, 0.0, 1.0)); //  / |
    vertexes.push_back(Vertex::create(size -(size/2),  0.0  -(size/2),  0.0, 1.0, 1.0, 0.0, 0.0, 1.0)); // 1--2
    
    return vertexes;
    
}

Quad::Quad() : Model::Model("Quad",genData()){}