#pragma once

#include "Plane.h"
#include <iostream>

class ColorPlane : public Plane
{
public:
    void DrawBody() const override;
    void DrawWings() const override;
    void DrawTail() const override;
};

