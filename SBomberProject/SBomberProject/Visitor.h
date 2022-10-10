#pragma once

class Bomb;
class Plane;

class Visitor
{
public:
    virtual void log(Bomb* e) = 0;
    virtual void log(Plane* e) = 0;
};
