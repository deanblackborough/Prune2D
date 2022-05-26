#pragma once

#include <SDL.h>

namespace Prune
{
    /**
     * Set up the sprite animation properties for the AnimateSpriteSystem, the AnimateSpriteSystem
     * fetches all entities with an AnimateSpriteSystem and a SpriteComponent
     *
     * @param startFrame The start frame, defaults to 1
     * @param animationFrames The number of frames in the sprite map
     * @param frameSpeed The desired framespeed expressed as frames per second
     * @param startTime The time returned from SDL_GetTicks()
     */
    struct AnimatedSpriteComponent
    {
    public:
        int startFrame;
        int animationFrames;
        int frameSpeed;
        int startTime;

        AnimatedSpriteComponent(
            int startFrame = 1,
            int animationFrames = 2,
            int frameSpeed = 4
        )
        {
            this->startFrame = startFrame;
            this->animationFrames = animationFrames;
            this->frameSpeed = frameSpeed;
            this->startTime = SDL_GetTicks();
        }
    };
}
