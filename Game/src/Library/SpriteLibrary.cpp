#include "SpriteLibrary.h"
#include "../Log/Log.h"

void Prune::SpriteLibrary::EmptyLibrary()
{
    // Destroy all the generated SDL textures
    for (std::pair<const std::string, SDL_Texture*> texture : m_SpriteTextures) {
        SDL_DestroyTexture(texture.second);
    }

    m_SpriteTextures.clear();
}

void Prune::SpriteLibrary::AddSprite(const std::string& spriteId, const std::string& spriteFilePath)
{
    SDL_Surface* surface = IMG_Load(spriteFilePath.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    m_SpriteTextures.emplace(spriteId, texture);

    PRUNE_LOG_INFO(
        "Added sprite {0} to SpriteLibrary with key {1}",
        spriteFilePath.c_str(),
        spriteId
    );
}

SDL_Texture* Prune::SpriteLibrary::GetSpriteTexture(const std::string& spriteId)
{
    if (m_SpriteTextures.contains(spriteId)) {
        PRUNE_LOG_INFO("Found texture for key '{0}'", spriteId);
        return m_SpriteTextures[spriteId];
    }

    PRUNE_LOG_ERROR("Unable to find texture for key '{0}'", spriteId);
    return nullptr;
}

void Prune::SpriteLibrary::SetRenderer(SDL_Renderer* renderer)
{
    m_Renderer = renderer;
}
