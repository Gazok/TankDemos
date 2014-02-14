#include "MainWorld.hpp"

#include <Tank/System/Controller.hpp>

MainWorld::MainWorld()
{
    auto controllers = tank::Controllers::getConnectedControllers();
    for (auto& c : controllers)
    {
        makeEntity<Player>(c);
    }
}
