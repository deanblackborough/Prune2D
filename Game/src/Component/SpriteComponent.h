#pragma once

#include <string>
#include <SDL.h>

namespace Prune 
{
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