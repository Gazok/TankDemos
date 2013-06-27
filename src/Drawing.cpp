#include "Drawing.hpp"
#include "Engine/Graphics/Image.hpp"

Original::Original(tank::Vectorf pos)
    : Entity(pos)
{
    setGraphic<tank::Image>("res/ball.png");
}

Clipped::Clipped(tank::Vectorf pos, tank::Rect clip)
    : Entity(pos)
{
    setGraphic<tank::Image>("res/ball.png");
    getGraphic().setClip(clip);
}

Resized::Resized(tank::Vectorf pos, tank::Vectorf dimensions)
    : Entity(pos)
{
    setGraphic<tank::Image>("res/ball.png");
    getGraphic().setSize(dimensions);
}

Rotated::Rotated(tank::Vectorf pos, float angle)
    : Entity(pos)
{
    setGraphic<tank::Image>("res/ball.png")->setOrigin(getGraphic().getSize() / 2);

    setRotation(angle);
}
