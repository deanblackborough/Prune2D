#include <glm.hpp>

namespace Prune 
{
    /**
     * Store the transform properties of the entity
     *
     * @param translation A glm::vec2 for the x and y translation
     * @param scale A glm::vec2 for the x and y scale
     * @param rotaion The rotation expressed as a double
     */
    struct TransformComponent
    {
    public:
        glm::vec2 translation = glm::vec2(0, 0);
        glm::vec2 scale = glm::vec2(0.0);
        double rotation = 0.0f;
    };
}
