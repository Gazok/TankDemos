#ifndef SATENTITY_HPP
#define SATENTITY_HPP

#include <Tank/System/Entity.hpp>
#include <Tank/Graphics/RectangleShape.hpp>
#include <Tank/Graphics/ConvexShape.hpp>

class SATEntity : public tank::Entity
{
    using Shape = std::vector<tank::Vectord>;
    using AABB = tank::observing_ptr<tank::RectangleShape>;
    using Poly = tank::observing_ptr<tank::ConvexShape>;

    bool intersected_ = false;
    Shape collisionShape_;
    AABB aabb_;
    Poly poly_;
    const tank::Color color_;

public:
    SATEntity(tank::Vectorf,
              std::vector<tank::Vectorf> const& points,
              tank::Color);

    Shape const& getCollisionShape() const { return collisionShape_; }
    Poly const& getPoly() const { return poly_; }

    void setIntersected() {
        intersected_ = true;
    }

    virtual void update() override;
};

#endif /* SATENTITY_HPP */
