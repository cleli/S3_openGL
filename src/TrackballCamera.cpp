#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/constants.hpp>

#include "../include/TrackballCamera.hpp"

TrackballCamera::TrackballCamera()
    : m_fDistance(-50.0f), m_fAngleX(0.0f), m_fAngleY(0.0f), m_position(0.f, 0.f, 0.f)
{
}

void TrackballCamera::moveFront(const float &delta) 
{
    m_fDistance += delta;
}

void TrackballCamera::rotateLeft(const float &degrees) 
{
    m_fAngleX += degrees;
}

void TrackballCamera::rotateUp(const float &degrees) 
{
    m_fAngleY += degrees;
}

void TrackballCamera::setPosMatrix(int l, int L, int H)
{
    m_position = glm::vec3(l,L,H);
}

glm::mat4 TrackballCamera::getViewMatrix() const
{
    glm::mat4 view_matrix = glm::mat4(1.f);
    
    view_matrix = glm::translate( view_matrix, glm::vec3(0.0f, 0.0f, m_fDistance));
    view_matrix = glm::rotate( view_matrix, glm::radians(m_fAngleX), glm::vec3(1.0f, 0.0f, 0.0f));
    view_matrix = glm::rotate( view_matrix, glm::radians(m_fAngleY), glm::vec3(0.0f, 1.0f, 0.0f));
    view_matrix = glm::translate( view_matrix, -m_position);
    return view_matrix;
}

glm::mat4 TrackballCamera::getProjMatrix() const
{
    glm::mat4 projMat = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
    return projMat;
}

