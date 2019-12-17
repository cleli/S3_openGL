#pragma once

#include <glm/glm.hpp>

#include "shader.h"
#include "TrackballCamera.hpp"

class Cube {
public:
    Cube();
    ~Cube();

    void draw(float j, const TrackballCamera &cam);
    
public:
    glm::vec3 position;
    bool isVisible;

private:
    unsigned int m_vao;
    unsigned int m_ib;
    Shader m_shader;
};
