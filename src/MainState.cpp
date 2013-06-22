#include "MainState.hpp"

#include "Engine/System/Game.hpp"

MainState::MainState()
{
    makeEntity<Drawing>(tank::Vectorf{20,20});
    tank::Game::window().setBackgroundColor(0.5f,0.f,1.f);
}
