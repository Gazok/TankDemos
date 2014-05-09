#include "MainWorld.hpp"

#include <iterator>
#include <Tank/System/Game.hpp>
#include <Tank/System/Entity.hpp>
#include <Tank/System/Mouse.hpp>
#include <Tank/System/Keyboard.hpp>

std::vector<tank::Vectorf> normals(std::vector<tank::Vectorf> const& points);

MainWorld::MainWorld()
{
    using namespace tank;
    using Kbd = tank::Keyboard;
    using Key = tank::Key;

    std::vector<Vectorf> p1 = {{0.0, 0.0}, {100.0, 20.0}, {80.0, 100.0},{10.0, 90.0}};
    std::vector<Vectorf> p2 = {{0.0, 0.0}, {62.0, 10.0}, {60.0, 70.0},{10.0, 90.0}, { -30., 40.0}};

    satEnts_.push_back(makeEntity<SATEntity>(Game::window()->getSize()/2, p1, tank::Color{44,243,99}));

    satEnts_.push_back(makeEntity<SATEntity>(Game::window()->getSize()/2, p2, tank::Color{233,43,99}));

    /* Create axes normal to edges of first shape */
    for (auto&& axis : normals(p1)) {
        axes_.push_back(makeEntity<Axis>(axis));
    }
    for (auto&& axis : normals(p2)) {
        axes_.push_back(makeEntity<Axis>(axis));
    }

    /* Control last SATEntity with wasd */
    connect(Kbd::KeyDown(Key::W),
            [&] { satEnts_.back()->moveBy(tank::Vectorf(0,-2)); });
    connect(Kbd::KeyDown(Key::S),
            [&] { satEnts_.back()->moveBy(tank::Vectorf(0,2)); });
    connect(Kbd::KeyDown(Key::A),
            [&] { satEnts_.back()->moveBy(tank::Vectorf(-2,0)); });
    connect(Kbd::KeyDown(Key::D),
            [&] { satEnts_.back()->moveBy(tank::Vectorf(2,0)); });

    /* Right click + drag to move viewport */
    connect(Mouse::ButtonDown(Mouse::Button::Right), [&]{
                camera().setPos(camera().getPos() - Mouse::delta());
            });
}

void MainWorld::update()
{
    World::update();

    for (auto&& entity : satEnts_) {
        for (auto&& axis : axes_) {
           axis->project(entity);
        }
    }

    for (auto iter1 = satEnts_.begin(); iter1 != satEnts_.end() - 1; ++iter1)
    {
        for (auto iter2 = iter1 + 1; iter2 != satEnts_.end(); ++iter2)
        {
            bool intersection = true;
            for (auto&& axis : axes_)
            {
                if (not axis->intersect(*iter1, *iter2))
                {
                    intersection = false;
                    break;
                }
            }
            if (intersection)
            {
                (*iter1)->setIntersected();
                (*iter2)->setIntersected();
            }
        }
    }
}

std::vector<tank::Vectorf> normals(std::vector<tank::Vectorf> const& points)
{
    std::vector<tank::Vectorf> normals;
    unsigned p2;

    for (unsigned p1 = 0; p1 < points.size(); ++p1) {
        p2 = (p1 + 1) % points.size();

        normals.emplace_back((points[p1] - points[p2]).normal());
    }

    return normals;
}
