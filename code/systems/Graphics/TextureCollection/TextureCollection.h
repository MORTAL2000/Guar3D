#ifndef TEXTURECOLLECTION_H
#define TEXTURECOLLECTION_H

#include <vector>
#include <string>
#include "../Texture/Texture.h"

namespace guar
{
	namespace GFX
	{
		class TextureCollection
		{
		private:
			std::vector<Texture> m_TextureVector;

		public:
			void loadDirectory(std::string aDirectoryName);

			//remove
			Texture* getTestTexture(void) { return &m_TextureVector[0]; }

			void loadDefaultTextures();

		};

	}

}

#endif