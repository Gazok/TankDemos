#include "MainState.hpp"

#include "Engine/System/Game.hpp"
#include "Drawing.hpp"

MainState::MainState()
{
    tank::Game::window().setBackgroundColor(0.5f,0.f,1.f);
    makeEntity<Original>(tank::Vectorf{0,0});
    makeEntity<Clipped>(tank::Vectorf{100,0}, tank::Rect{0, 0, 20, 20});
    makeEntity<Clipped>(tank::Vectorf{200,0}, tank::Rect{10, 10, 20, 20});
    makeEntity<Clipped>(tank::Vectorf{300,0}, tank::Rect{10, 10, 30, 30});
    makeEntity<Resized>(tank::Vectorf{0,100}, tank::Vectorf{100, 100});
    makeEntity<Resized>(tank::Vectorf{100,100}, tank::Vectorf{50, 50});
    makeEntity<Resized>(tank::Vectorf{200,100}, tank::Vectorf{50, 100});
    makeEntity<Resized>(tank::Vectorf{300,100}, tank::Vectorf{100, 50});
    makeEntity<Rotated>(tank::Vectorf{50,250}, 0.f);
    makeEntity<Rotated>(tank::Vectorf{150,250}, 30.f);
    makeEntity<Rotated>(tank::Vectorf{250,250}, 60.f);
    makeEntity<Rotated>(tank::Vectorf{350,250}, 90.f);
    makeEntity<Rotated>(tank::Vectorf{450,250}, 120.f);
    makeEntity<Rotated>(tank::Vectorf{550,250}, 150.f);
    makeEntity<Rotated>(tank::Vectorf{50,350}, 180.f);
    makeEntity<Rotated>(tank::Vectorf{150,350}, 210.f);
    makeEntity<Rotated>(tank::Vectorf{250,350}, 240.f);
    makeEntity<Rotated>(tank::Vectorf{350,350}, 270.f);
    makeEntity<Rotated>(tank::Vectorf{450,350}, 300.f);
    makeEntity<Rotated>(tank::Vectorf{550,350}, 330.f);
}
