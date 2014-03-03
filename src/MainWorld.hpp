#ifndef MAINWORLD_HPP
#define MAINWORLD_HPP

#include <Tank/System/World.hpp>
#include "SATEntity.hpp"
#include "Axis.hpp"

class MainWorld : public tank::World
{
    std::vector<tank::Vectorf> points_;
    std::vector<tank::observing_ptr<Axis>> axes_;

    std::vector<tank::observing_ptr<SATEntity>> satEnts_;
public:
    MainWorld();

    virtual void update() override;
};
#endif /* MAINWORLD_HPP */
