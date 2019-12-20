#include "cube.h"
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include "gl-exception.h"
#include "TrackballCamera.hpp"

namespace cubeData {
    //    v6----- v5
    //   /|      /|
    //  v1------v0|
    //  | |     | |
    //  | |v7---|-|v4
    //  |/      |/
    //  v2------v3
 
    glm::vec3 v0 = glm::vec3(0.5, 0.5, 0.5);
    glm::vec3 v1 = glm::vec3(-0.5, 0.5, 0.5);
    glm::vec3 v2 = glm::vec3(-0.5, -0.5, 0.5);
    glm::vec3 v3 = glm::vec3(0.5, -0.5, 0.5);
    glm::vec3 v4 = glm::vec3(0.5, -0.5, -0.5);
    glm::vec3 v5 = glm::vec3(0.5, 0.5, -0.5); 
    glm::vec3 v6 = glm::vec3(-0.5, 0.5, -0.5);
    glm::vec3 v7 = glm::vec3(-0.5, -0.5, -0.5);

    const glm::vec3 positions[] = {
        // Front v0,v1,v2,v3
        glm::vec3(0.5, 0.5, 0.5), glm::vec3(-0.5, 0.5, 0.5), glm::vec3(-0.5, -0.5, 0.5), glm::vec3(0.5, -0.5, 0.5),
        // Right v0,v3,v4,v5
        glm::vec3(0.5, 0.5, 0.5), glm::vec3(0.5, -0.5, 0.5), glm::vec3(0.5, -0.5, -0.5), glm::vec3(0.5, 0.5, -0.5),
        // Top v0,v5,v6,v5	
        glm::vec3(0.5, 0.5, 0.5), glm::vec3(0.5, 0.5, -0.5), glm::vec3(-0.5, 0.5, -0.5), glm::vec3(-0.5, 0.5, 0.5), 
        // Left v1,v6,v7,v2	
        glm::vec3(-0.5, 0.5, 0.5), glm::vec3(-0.5, 0.5, -0.5), glm::vec3(-0.5, -0.5, -0.5), glm::vec3(-0.5, -0.5, 0.5),  
        // Bottom v7,v4,v3,v2
        glm::vec3(-0.5, -0.5, -0.5), glm::vec3(0.5, -0.5, -0.5), glm::vec3(0.5, -0.5, 0.5), glm::vec3(-0.5, -0.5, 0.5), 
        // Back v4,v7,v6,v5	
        glm::vec3(0.5, -0.5, -0.5), glm::vec3(-0.5, -0.5, -0.5), glm::vec3(-0.5, 0.5, -0.5), glm::vec3(0.5, 0.5, -0.5)
    };

    /*const glm::vec3 positionsCurseur[] = {
        v0,v1, v1,v2, v2,v3, v3,v0, v0,v5, v3,v4, v4,v5, v5,v6, v6,v1, v6,v7, v7,v4, v7,v2
    };*/
    
    const glm::vec3 normals[] = {
        glm::vec3(0, 0, 1), glm::vec3(0, 0, 1), glm::vec3(0, 0, 1), glm::vec3(0, 0, 1),
        glm::vec3(1, 0, 0), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0), glm::vec3(1, 0, 0),
        glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0),
        glm::vec3(-1, 0, 0), glm::vec3(-1, 0, 0), glm::vec3(-1, 0, 0), glm::vec3(-1, 0, 0),
        glm::vec3(0,-1, 0), glm::vec3(0,-1, 0), glm::vec3(0,-1, 0), glm::vec3(0,-1, 0),
        glm::vec3(0, 0,-1), glm::vec3(0, 0,-1), glm::vec3(0, 0,-1), glm::vec3(0, 0,-1)
    };

    const unsigned short indices[] = {
        0, 1, 2,   2, 3, 0,       // front
        4, 5, 6,   6, 7, 4,       // right
        8, 9, 10,  10,11,8,       // top
        12,13,14,  14,15,12,      // left
        16,17,18,  18,19,16,      // bottom
        20,21,22,  22,23,20		  // back
    };
}

Cube::Cube() 
    : m_vao(0), m_ib(0), position(0), m_shader("res/shaders/basic.vert", "res/shaders/basic.frag"),
     isVisible(0), color(0.93f,0.5f, 0.93f, 0.5f), poids(0)
{
    // ------------------ Vertex Buffer
    //positions
    unsigned int posVB;
    {
        GLCall(glGenBuffers(1, &posVB));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, posVB));
        GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData::positions), cubeData::positions, GL_STATIC_DRAW));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }

    //normales
    unsigned int normVB;
    {
        GLCall(glGenBuffers(1, &normVB));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, normVB));
        GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData::normals), cubeData::normals, GL_STATIC_DRAW));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    }

    
    // ------------------ Vertex Array
    {
        GLCall(glGenVertexArrays(1, &m_vao));
        GLCall(glBindVertexArray(m_vao));

        // Vertex input description
        //positions
        {
            GLCall(glEnableVertexAttribArray(0));
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, posVB));
            GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL));
        }

        //normales
        {
            GLCall(glEnableVertexAttribArray(1));
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, normVB));
            GLCall(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL));
        }
        
        GLCall(glBindVertexArray(0));
    }

    // ------------------ Index buffer
    {
        GLCall(glGenBuffers(1, &m_ib));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ib));
        GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeData::indices), cubeData::indices, GL_STATIC_DRAW));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
    }

    // ------------------ Default values for uniforms
    /*m_shader.bind();
    {
        glm::mat4 modelMat = glm::mat4(1.0f);
        m_shader.setUniformMat4f("uModel", modelMat);
    }
    {
        glm::mat4 viewMat = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -10.0f));
        glm::mat4 projMat = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
        glm::mat4 viewProjMat = projMat * viewMat;
        m_shader.setUniformMat4f("uViewProj", viewProjMat);

    }
    m_shader.unbind();*/
}

Cube::~Cube()
{
}


void Cube::draw(const TrackballCamera &cam, const glm::vec3 &lumiereDirection, const glm::vec3 &pointLumiere) {

    // Bind
    GLCall(glBindVertexArray(m_vao));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ib));
    m_shader.bind();

    // Update model mat uniform
    glm::mat4 modelMat = glm::translate(glm::mat4(1.0f), position);
    
    m_shader.setUniformMat4f("uModel", modelMat);
    
    //pour la camera
    m_shader.setUniformMat4f("uViewProj", cam.getProjMatrix() * cam.getViewMatrix());

    //changer de couleur à chaque cube
    m_shader.setUniform4f("uColor", color);

    //lumiere directionnelle
    m_shader.setUniform3f("uLumiereDirection", lumiereDirection.x, lumiereDirection.y, lumiereDirection.z);

    //point de lumière
    m_shader.setUniform3f("uPointLumiere", pointLumiere.x, pointLumiere.y, pointLumiere.z);

    // Draw call
    GLCall(glDrawElements(GL_TRIANGLES, sizeof(cubeData::indices), GL_UNSIGNED_SHORT, (void*) 0));
}

//afficher le curseur
void Cube::drawCurseur(const TrackballCamera &cam) {

    // Bind
    GLCall(glBindVertexArray(m_vao));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ib));
    m_shader.bind();

    // Update model mat uniform
    glm::mat4 modelMat = glm::translate(glm::mat4(1.0f), position);
    
    m_shader.setUniformMat4f("uModel", modelMat);

    //pour la camera
    m_shader.setUniformMat4f("uViewProj", cam.getProjMatrix() * cam.getViewMatrix());
    
    //couleur
    m_shader.setUniform4f("uColor", glm::vec4(1.0f,0.0f,0.0f,1.0f));

    // Draw call
    GLCall(glDrawElements(GL_LINE_STRIP, sizeof(cubeData::indices), GL_UNSIGNED_SHORT, (void*) 0));
}