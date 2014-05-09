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
    for (auto&& projection : projections_) {
        removeGraphic(projection);
    }
    projections_.clear();
    setPos(getWorld()->camera().getPos() + getWorld()->camera().getOrigin());
}

void Axis::project(Entity e)
{
    using namespace tank;

    double left, right;
    std::tie(left, right) = project(e->getCollisionShape());

    const double length = right - left;

    float pos = left;
    pos += dir_.dot(e->getPos()) - dir_.dot(getPos());

    auto line = makeGraphic<RectangleShape>(Vectorf(length, 3));
    line->setFillColor(e->getPoly()->getFillColor());
    line->setPos(Vectorf(pos, verticalOffset));
    projections_.push_back(line);
}

bool Axis::intersect(Entity a, Entity b)
{
    if (a->getCollisionShape().size() > 1 and b->getCollisionShape().size() > 1)
    {
        double leftA, leftB, rightA, rightB;
        std::tie(leftA, rightA) = project(a->getCollisionShape());
        std::tie(leftB, rightB) = project(b->getCollisionShape());

        const double posA = a->getPos().dot(dir_);
        const double posB = b->getPos().dot(dir_);

        leftA += posA;
        rightA += posA;
        leftB += posB;
        rightB += posB;

        if (leftA > rightB) return false;
        if (rightA < leftB) return false;
        return true;
    }
    else
    {
        return false;
    }
}

std::pair<double, double> Axis::project(Shape const& vs)
{
    std::function<double (tank::Vectord)> dot =
    [this] (tank::Vectord v) -> double {
        return v.dot(dir_);
    };

    std::vector<double> projection;
    std::transform(vs.begin(), vs.end(), std::back_inserter(projection), dot);

    const auto iters = std::minmax_element(projection.begin(),
                                           projection.end());

    return { *(iters.first), *(iters.second) };
}
