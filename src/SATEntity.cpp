#include "SATEntity.hpp"

SATEntity::SATEntity(tank::Vectorf pos,
                     std::vector<tank::Vectorf> const& points,
                     tank::Color c)
    : tank::Entity(pos)
    , collisionShape_{points.begin(), points.end()}
{
    using Poly = tank::ConvexShape;

    auto poly = std::unique_ptr<Poly> (new Poly(points));
    poly_ = poly;
    aabb_ = makeGraphic<tank::RectangleShape>(poly->getSize());
    poly->setFillColor(c);
    //poly->centreOrigin();
    insertGraphic(std::unique_ptr<tank::Graphic>(std::move(poly)));
    //aabb_->centreOrigin();
    setType("SAT");
}

void SATEntity::update()
{
    if (collide("SAT").empty()) {
        aabb_->setFillColor({0,255,0,50});
    } else {
        aabb_->setFillColor({255,0,0,50});
    }
}
