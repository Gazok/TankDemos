#include "Engine/System/Game.hpp"

int main()
{
    Game::initialize();
    Game::makeState<MainState>();
    Game::run();
    Game::close();

    return 0;
}
