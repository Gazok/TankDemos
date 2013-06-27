#include "Engine/Utility/Vector.hpp"
#include "Engine/Utility/Rect.hpp"
#include "Engine/System/Entity.hpp"

class Original : public tank::Entity
{
public:
    Original(tank::Vectorf pos);
};

class Clipped : public tank::Entity
{
public:
    Clipped(tank::Vectorf pos, tank::Rect clip);
};

class Resized : public tank::Entity
{
public:
    Resized(tank::Vectorf pos, tank::Vectorf dimensions);
};

class Rotated : public tank::Entity
{
public:
    Rotated(tank::Vectorf pos, float angle);
};
