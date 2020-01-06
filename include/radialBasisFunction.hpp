#pragma once

#include <Eigen/Dense>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "../include/cube.h"

using namespace Eigen;

//notre fonction Phi
template <typename T>
const T phi(const T &d){
    return exp(-0.2*d*d);
}

const double norm(const glm::vec3 vec1);
const VectorXd find_omega(unsigned int nbPointsControle, std::vector<Cube*> v_pointsControle);
void gener_terrain(unsigned int nbPointsControle, Cube* actualCube, const std::vector<Cube*> v_pointsControle);
void gener_terrainAleatoire(unsigned int l,unsigned int L, unsigned int H, Cube stockCube[]);