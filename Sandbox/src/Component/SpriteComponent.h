#pragma once

#include <string>
#include <SDL.h>

namespace Prune 
{
    /**
     * Add a sprite to the entity
     * 
     * @param spriteId The sprite id to load from the sprite library
     * @param width An int setting the width of the sprite
     * @param width An int setting the height of the sprite
     * @param sourceRectX An int setting the source rectangle x position on the sprite, defaults to 0
     * @param sourceRectY An int setting the source rectangle Y position on the sprite, defaults to 0
     * @param sourceRectWidth An int setting the width of the source rectangle, defaults to 64
     * @param sourceRectHeight An int setting the height of the source rectangle, defaults to 64
     */
    struct SpriteComponent
    {
    public:
        std::string spriteId;
        int width;
        int height;
        int sourceRectX;
        int sourceRectY;
        int sourceRectWidth;
        int sourceRectHeight;
        SDL_Rect sourceRect;

        SpriteComponent(
            std::string spriteId,
            int width = 0,
            int height = 0,
            int sourceRectX = 0,
            int sourceRectY = 0,
            int sourceRectWidth = 64,
            int sourceRectHeight = 64
        )
        {
            this->spriteId = spriteId;
            this->width = width;
            this->height = height;
            this->sourceRectX = sourceRectX;
            this->sourceRectY = sourceRectY;
            this->sourceRectWidth = sourceRectWidth;
            this->sourceRectHeight = sourceRectHeight;
            this->sourceRect = { sourceRectX, sourceRectY, sourceRectWidth, sourceRectHeight };
        }
    };
}
