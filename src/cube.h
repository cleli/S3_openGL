#pragma once

#include <glm/glm.hpp>

#include "shader.h"
#include "TrackballCamera.hpp"

class Cube {
public:
    Cube();
    ~Cube();

    void draw(glm::vec4 color, const TrackballCamera &cam);
    void drawCurseur(const TrackballCamera &cam);
    
public:
    glm::vec3 position;
    bool isVisible;

private:
    unsigned int m_vao;
    unsigned int m_ib;
    Shader m_shader;
};
