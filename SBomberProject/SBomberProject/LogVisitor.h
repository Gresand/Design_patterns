#pragma once
#include "Visitor.h"
#include "MyTools.h"
#include "Bomb.h"
#include "Plane.h"
#include "Singletone.h"

class LogVisitor : Visitor
{
public:
    void log(Bomb* e) override;
    void log(Plane* e) override;
};