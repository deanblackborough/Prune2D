#pragma once

#include <string>
#include <SDL.h>

namespace Prune 
{
    /**
     * Store the transformation properties of the entity
     *
     * @param spriteId The id of the sprite asset
     * @param width Desired with of the sprite as an int
     * @param height Desired height of the sprite as an int
     * @param SDL_Rect The SDL_Rect of the source rectangle, the source x and y and crop width and height
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
            int sourceRectWidth = 0,
            int sourceRectHeight = 0
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