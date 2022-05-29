#include <glm.hpp>

namespace Prune 
{
    /**
     * Set the velocity for the entity, expressed in desired number of pixels to move across the 
     * screen per second
     *
     * @param velocity A glm::vec2 for the x and y velocity
     */
    struct VelocityComponent
    {
    public:
        glm::vec2 velocity = glm::vec2(0, 0);
    };
}
