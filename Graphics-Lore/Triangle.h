#pragma once
#include "Model.h"
class Triangle :
    public Model
{
public:
    Triangle();
    void Initialize();
    virtual void Draw() override;
private:
    glm::mat4 m_projection;
    glm::mat4 m_view;
    glm::mat4 m_model;
};

