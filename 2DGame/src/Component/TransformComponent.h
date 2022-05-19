#include <glm.hpp>

namespace Prune {

    /**
     * Store the transformation properties of the entity
     *
     * @param transform A glm::vec2 for the x and y position
     * @param scale A glm::vec2 for the x and y scale
     */
    struct TransformComponent
    {
        glm::vec2 transform = glm::vec2(0, 0);
        glm::vec2 scale = glm::vec2(0.0);
    };
}