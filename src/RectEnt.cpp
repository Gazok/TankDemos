#include "RectEnt.hpp"

#include <Tank/Graphics/RectangleShape.hpp>

RectEnt::RectEnt(tank::Vectorf pos)
    : tank::Entity(pos)
{
    makeGraphic<tank::RectangleShape>(tank::Vectorf{30,30});
    auto rectGfx = makeGraphic<tank::RectangleShape>(tank::Vectorf{30,30});
    rectGfx->setOrigin({-30,0});
}
