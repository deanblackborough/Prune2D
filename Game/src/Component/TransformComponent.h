#include <glm.hpp>

namespace Prune 
{
    /**
     * Store the transformation properties of the entity
     *
     * @param A glm::vec2 for the x and y position
     * @param scale A glm::vec2 for the x and y scale
     * @param rotaion The rotation expressed as a double
     */
    struct TransformComponent
    {
    public:
        glm::vec2 position = glm::vec2(0, 0);
        glm::vec2 scale = glm::vec2(0.0);
        double rotation = 0.0f;
    };
}