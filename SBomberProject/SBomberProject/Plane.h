#pragma once

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;

    virtual void DrawBody() const = 0;
    virtual void DrawWings() const = 0;
    virtual void DrawTail() const = 0;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

private:

};

