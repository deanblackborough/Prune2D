#pragma once

#include <glm.hpp>

namespace Prune
{
    /**
    * @param size A glm::vec2 to set the size for the box collider
    * @param offset A glm::vec2 to set the offset for the box collider
    */
    struct BoxCollider2D
    {
    public:
        glm::vec2 size;
        glm::vec2 offset;

        BoxCollider2D(
            glm::vec2 size = glm::vec2(0),
            glm::vec2 offset = glm::vec2(0)
        ) {
            this->size = size;
            this->offset = offset;
        }
    };
}
