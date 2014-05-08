#include "Axis.hpp"

#include <iostream>
#include <cmath>
#include <Tank/System/Game.hpp>
#include <Tank/Graphics/RectangleShape.hpp>

Axis::Axis(tank::Vectorf dir)
    : tank::Entity(tank::Game::window()->getSize() / 2)
    , dir_(dir.unit())
{
    setRotation(-dir.getAngle({1.0,0.0}));
    const auto wSize = tank::Game::window()->getSize();
    auto line = makeGraphic<tank::RectangleShape>(tank::Vectorf(
        std::sqrt(wSize.x*wSize.x + wSize.y*wSize.y), 2));

    line->setOrigin(line->getSize() / 2);
    line->setPos(tank::Vectorf{0, verticalOffset});
}

void Axis::update()
{
    for (auto&& line : lines_) {
        removeGraphic(line);
    }
    lines_.clear();
    setPos(getWorld()->camera().getPos() + getWorld()->camera().getOrigin());
}

void Axis::project(Entity e)
{
    using namespace tank;

    auto& shape = e->getCollisionShape();
    const auto projection = std::minmax_element(shape.begin(), shape.end(),
        [this] (Vectord const& a, Vectord const& b) {
            return dir_.dot(a) < dir_.dot(b);
        });

    //const int lengthSign = getRotation() > 180 ? -1 : 1;
    const double length = projection.second->dot(dir_) -
                          projection.first->dot(dir_);

    float xPos = projection.first->dot(dir_);
    xPos += dir_.dot(e->getPos()) - dir_.dot(getPos());

    auto line = makeGraphic<RectangleShape>(Vectorf(length, 3));
    line->setFillColor(e->getPoly()->getFillColor());
    line->setPos(Vectorf(xPos, verticalOffset));
    lines_.push_back(line);
}
