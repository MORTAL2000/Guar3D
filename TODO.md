## Active task
#### Render a keyframe on the test model
implemented:
- hacked data path from file to uniform upload DONE
- single bone transform and weight application DONE
- ai to glm mat conversion DONE

unimplemented:
- animation channels never directly name the bones, rather they name "controllers" (parent nodes)
  - must duplicate node hierarchy to ram.
  - must apply animation offsets to duplicate.
  - must traverse duplicate to create final bone 4x4 values.

## Future tasks

creation of gfx meshes from col meshes & shapes(sphere, box, cylinder, capsule, cone), creation of col meshes from gfx meshes.
  - add methods to create collision meshes from render meshes and vice versa.
  - parameterize primitive arg for glDraw. Currenty hard coded to triangles, but point and line have
    their uses (visualizing rays and collision meshes).

implement deferred render path
 - GFX::DeferredGeoBuffer
    - Review GFX::RenderTexture
 - GFX::DeferredGeoShader
    - abstract type w capacity for children to write pos, norm, tan,bi, lin & nonlin depth etc. to textures
 - GFX::DeferredFXShader
    - abstract type that forces implementer to write to textures & attaches those textures for them.
 - ECS::DeferredRenderer
    - render component that only accepts deferred path types

Cleaning
 - clean all systems: replace needless includes with forward decs, etc.
   - remove any fwds of std because this is dangerous & may lead to undefined behaviour not only on other compilers but even other versions of msvc++ (compiler i currently use for development)
   - move all fwds into fwd headers, following precedent of iosfwd (gfxfwd, phyfwd, etc.) ie. I made the classes so I fwd them, not the clients.
   - hide the implementation fwds in gfx, there is a bit too much of that and pollutes the game programmer's
     headers with needless GLM and ASSIMP class fwds (which have no meaning to the programmer and cannot be relied on since implementation may change).
   - create resource load and unload tests to hunt for memory leaks
   - handle physics case where a new physics body fails to be added to the world (too many bodies) as this currently causes a runtime crash
    (when the ecs::rigidbody tries to get new position data from its phy::rigidbody, which is either null or pointing at someone else's memory)
 - reduce the excessive use of "friend" in ECS project.
 - remove the special initialization that gameobject does for gfx objects, this is assemetric w regards to other systems and tightly couples
 GFX to ECS, which is bad design and makes the code harder to read.
 - optimize code, especially graphics. The GFX thread tick rate is beginning to lag noticably on demo scene. This really shouldnt be the case
  at this point (shader only does ADS+shadow+anim) no ao etc.. Look at heavy math areas, look at lighting; reduce complexity add
aggressive early quit conditions etc.

Mouse input improvements
 - currently feels very coarse and deltas spike at the mercy of main thread's tick rate. Delta time also spikes occasionally. Think about this.

Buffer position & rotations for graphics system
 - when the main thread slows down enough, it is possible to see the gfx thead rendering with a mix of new and old position data, leading to slight jittering.
 double or triple buffer graphics object 4x4s and only operate on complete gfx scene states to fix.

GFX::RenderCamera
 - add FBO to implementation so that gl buffer operations do not affect the output of other cameras (in terms of depth, color, stencil, accum).
   this functionality can alternatively be implemented with scissor, but I think the FBO option is more mainstream. FBO also allows rendertextures to be attached to cameras,
   which may be a nice feature for procedural texture generation.

Later:

skeletons
 - rigged animation, cpu implementation. Will be using Ozz for this.

Voxel Terrain system:
 - PolyVox looks like a good candidate for implementation

Create online documentation
 - use Doxygen to generate wiki.

remove final hard coupling between ECS and GFX
 - Gameobject is responsible for initializing the implementation types of ECS::Renderer, camera, light. This is inconsistent with an otherwise subsystem agnostic
 ECS. Must have missed when I initially disentangled the two a month ago. Fix.

Think about clean way to incorporate gpu raycasting into GFX. Think about standardized raycasting shader API etc. (look at ShaderToy).

Finish ECS::Rigidbody <-> PHY::Rigidbody interface.
 - implement remaining abstractions for bullet collider types (sphere, capsule, cylinder, cone, trimesh)

GFX::RenderCamera
 - give cameras their own FBOs so that glClear will not wipe FBO0's buffers

Finish forward renderpath
  Clean up ortho shadow caster
  Implement point light shadow caster
  Implement spotlight shadow caster

Add collision checks for lights and cameras for deferred light culling.

Audio system. Will probably use OpenAL soft.

lightbaking system for static light data generation.
  - Plan: do lighting, shadow casting etc. as usual BUT: mul results to uv space, write results to texture & texture to disk. Texture to be sampled as usual later @ far less cost.
  - be sure to make threadsafe, want to be able to throw this on a worker thread while game is running st possible to recalculate static lights.

paralellize resource loading

review implementation LuaInterperter.cpp
derive LuaInterpreter for config file loading foreach system.

add projects to dependency solution for the dependencies that are missing (glew, glfw, bullet).
 - important for quickly building for different targets

implement findGameObject:
 what should the search procedure be? Iterative deepening depth-first search is preferred but Depth-first search would be easier to implement.
