#pragma once

#include <Eigen/Dense>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "cube.h"

using namespace Eigen;

const double phi(const double &d);
const double norm(const glm::vec3 vec1);
const VectorXd find_omega(unsigned int nbPointsControle, std::vector<Cube> v_pointsControle);
void gener_terrain(unsigned int nbPointsControle, Cube* actualCube, std::vector<Cube> v_pointsControle);