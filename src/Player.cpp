#include "Player.hpp"

#include <iostream>
#include <Tank/Graphics/CircleShape.hpp>

Player::Player(Controller c)
    : Entity({0,0})
    , controller_{c}
{
    makeGraphic<tank::CircleShape>(10)->setFillColor({255,0,128});
}

void Player::update()
{
    setPos(getPos() + controller_->leftStick()*10);
}
