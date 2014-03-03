#ifndef AXIS_HPP
#define AXIS_HPP

#include <Tank/Utility/Vector.hpp>
#include <Tank/System/Entity.hpp>
#include <Tank/Graphics/RectangleShape.hpp>
#include "SATEntity.hpp"

class Axis : public tank::Entity
{
    using Entity = tank::observing_ptr<SATEntity>;
    using Line = tank::observing_ptr<tank::RectangleShape>;
    std::vector<Line> lines_;
    tank::Vectord dir_;

public:
    static constexpr int verticalOffset = -250;
    Axis(tank::Vectorf dir);

    virtual void update() override;

    void project(Entity);
};

#endif /* AXIS_HPP */
