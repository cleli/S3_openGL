#pragma once

#include <glm/glm.hpp>

#include "shader.h"
#include "TrackballCamera.hpp"

class Curseur {
public:
    Curseur();
    ~Curseur();

    void draw(glm::vec4 color, const TrackballCamera &cam);
    
public:
    glm::vec3 position;

private:
    unsigned int m_vao;
    unsigned int m_ib;
    Shader m_shader;
};
