#include "Animated.hpp"

#include <chrono>
#include <Tank/System/Mouse.hpp>
#include <Tank/System/World.hpp>

using namespace std::literals;

Animated::Animated(tank::Vectorf pos)
    : Entity(pos)
{
    anim_ = makeGraphic<tank::FrameList>(tank::Image("res/anim.png"), tank::Vectoru{16,16});
    anim_->add("anim", {0, 1}, 500ms);
    anim_->select("anim");
    anim_->start();
}

void Animated::onAdded()
{
    using tank::Mouse;

    connect(Mouse::InEntity(*this) and
            Mouse::ButtonDown(Mouse::Button::Left),
            [this]
            {
                auto dx = Mouse::delta();
                auto const& cam = getWorld()->camera;
                auto const zoom = cam.getScale();

                dx = dx.rotate(cam.getRotation());
                dx.x /= zoom.x;
                dx.y /= zoom.y;

                moveBy(dx);
            });
}
void Animated::update()
{
    anim_->setRotation(anim_->getRotation() + 1);
}
