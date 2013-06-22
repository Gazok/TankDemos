#include "Engine/System/Game.hpp"
#include "MainState.hpp"

int main()
{
    tank::Game::initialize({640, 640});
    tank::Game::makeState<MainState>();
    tank::Game::run();
    tank::Game::close();

    return 0;
}
