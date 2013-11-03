#ifndef ANIMATED_HPP
#define ANIMATED_HPP

#include <Tank/System/Entity.hpp>
#include <Tank/Utility/Vector.hpp>
#include <Tank/Graphics/FrameList.hpp>

class Animated : public tank::Entity
{
public:
    Animated(tank::Vectorf pos);

    void update() override;
    void onAdded() override;
private:
    tank::observing_ptr<tank::FrameList> anim_;
};
#endif /* ANIMATED_HPP */
