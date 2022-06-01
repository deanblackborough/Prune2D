#pragma once

#include <glm.hpp>

namespace Prune
{
    /**
    * Add a box collider to the entity for the collision system
    * 
    * @param size A glm::vec2 to set the size for the box collider
    * @param offset A glm::vec2 to set the offset for the box collider
    */
    struct BoxColliderComponent
    {
    public:
        glm::vec2 size;
        glm::vec2 offset;

        BoxColliderComponent(
            glm::vec2 size = glm::vec2(0),
            glm::vec2 offset = glm::vec2(0)
        ) {
            this->size = size;
            this->offset = offset;
        }
    };
}
