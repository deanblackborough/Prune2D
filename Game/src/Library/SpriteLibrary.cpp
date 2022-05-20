#include "SpriteLibrary.h"

void Prune::SpriteLibrary::EmptyLibrary()
{
    // Destroy all the generated SDL textures
    for (std::pair<const std::string, SDL_Texture*> texture : m_SpriteTextures) {
        SDL_DestroyTexture(texture.second);
    }

    m_SpriteTextures.clear();
}

void Prune::SpriteLibrary::AddSprite(SDL_Renderer* renderer, const std::string& spriteId, const std::string& spriteFilePath)
{
    SDL_Surface* surface = IMG_Load(spriteFilePath.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    m_SpriteTextures.emplace(spriteId, texture);
}
