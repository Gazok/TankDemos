#include "SATEntity.hpp"

SATEntity::SATEntity(tank::Vectorf pos,
                     std::vector<tank::Vectorf> const& points,
                     tank::Color c)
    : tank::Entity(pos)
    , collisionShape_ {points.begin(), points.end()}
    , color_ {c}
{
    using Poly = tank::ConvexShape;

    auto poly = std::unique_ptr<Poly> (new Poly(points));
    poly->setFillColor(c);
    poly_ = poly;

    aabb_ = makeGraphic<tank::RectangleShape>(poly->getSize());
    insertGraphic(std::unique_ptr<tank::Graphic>(std::move(poly)));

    tank::Vectorf min;
    for (auto&& p : points) {
        if (p.x < min.x) min.x = p.x;
        if (p.y < min.y) min.y = p.y;
    }

    auto hitbox = getHitbox();
    hitbox.x = min.x;
    hitbox.y = min.y;
    setHitbox(hitbox);
    aabb_->setPos(min);

    setType("SAT");
}

void SATEntity::update()
{
    if (not intersected_) {
        poly_->setFillColor(color_);
    } else {
        poly_->setFillColor({255, 255, 255});
        intersected_ = false;
    }

    if (collide("SAT").empty()) {
        aabb_->setFillColor({0, 255, 0, 50});
    } else {
        aabb_->setFillColor({255, 0, 0, 50});
    }
}
