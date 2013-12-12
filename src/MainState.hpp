#ifndef MAINSTATE_HPP
#define MAINSTATE_HPP

#include <Tank/System/World.hpp>
#include <Tank/Graphics/Font.hpp>

class MainWorld : public tank::World
{
public:
    MainWorld();

    static tank::Font font;
};

#endif /* MAINSTATE_HPP */
