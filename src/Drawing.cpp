#include "Drawing.hpp"
#include "Engine/Graphics/Image.hpp"

Drawing::Drawing(tank::Vectorf const& pos)
    : Entity(pos)
{
    setGraphic<tank::Image>("res/testimg.png");
}
