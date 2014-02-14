#include <Tank/System/Entity.hpp>

#include <Tank/System/Controller.hpp>

class Player : public tank::Entity
{
    using Controller = tank::observing_ptr<tank::Controller>;
    Controller controller_;

public:
    Player(Controller c);

    virtual void update() override;
};
