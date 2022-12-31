#pragma once
#include "Model.h"
class Triangle :
    public Model
{
public:
    Triangle();
    virtual void Draw() override;
};

