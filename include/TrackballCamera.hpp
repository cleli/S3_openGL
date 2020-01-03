#pragma once

#include "glm/glm.hpp"

class TrackballCamera{
    public:
        TrackballCamera();
        void moveFront(const float &delta);
        void rotateLeft(const float &degrees);
        void rotateUp(const float &degrees);
        void setPosMatrix(int l, int L, int H);
        glm::mat4 getViewMatrix() const;
        glm::mat4 getProjMatrix() const;

    private:
        float m_fDistance;
        float m_fAngleX;
        float m_fAngleY;
        glm::vec3 m_position;
};

