#pragma once

#include <glm/glm.hpp>

#include "shader.h"
#include "TrackballCamera.hpp"

class Cube {
public:
    Cube();
    ~Cube();

    void draw(const TrackballCamera &cam,  const glm::vec3 &lumiereDirection, const glm::vec3 &pointLumiere);
    void drawCurseur(const TrackballCamera &cam);
    
public:
    glm::vec3 position;
    glm::vec4 color;
    bool isVisible;
    double poids;

private:
    unsigned int m_vao;
    unsigned int m_ib;
    Shader m_shader;
};
