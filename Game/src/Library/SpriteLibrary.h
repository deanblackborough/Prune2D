#pragma once

#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

namespace Prune
{

    class SpriteLibrary
    {
    public:
        SpriteLibrary() = default;
        ~SpriteLibrary() = default;

        void EmptyLibrary();
        void AddSprite(
            SDL_Renderer* renderer,
            const std::string& spriteId,
            const std::string& spriteFilePath
        );
        SDL_Texture* GetSpriteTexture(const std::string& assetId);

    private:
        std::map<std::string, SDL_Texture*> m_SpriteTextures;
    };
}
