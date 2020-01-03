#pragma once

#include <glm/glm.hpp>

#include "cube.h"

int sauvegarder(Cube stockCube[], unsigned int taille,std::string filepath, std::string filename);
void charger(Cube stockCube[], unsigned int taille, std::string filepath, std::string filename);