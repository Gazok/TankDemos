#include <Tank/System/Game.hpp>
#include "MainState.hpp"

int main()
{
    using tank::Game;

    Game::initialize({640, 640});
    Game::makeState<MainState>();
    Game::run();
}
