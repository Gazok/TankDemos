#ifndef MAINSTATE_HPP
#define MAINSTATE_HPP

#include <Tank/System/State.hpp>
#include <Tank/Graphics/Font.hpp>

class MainState : public tank::State
{
public:
    MainState();

    static tank::Font font;

    void update() override;
};

#endif /* MAINSTATE_HPP */
