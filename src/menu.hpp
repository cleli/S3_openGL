#pragma once

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "cube.h"

void afficheMenu(unsigned int curseur, glm::vec4* current_color, Cube stockCube[], unsigned int l, unsigned int L, unsigned int H, glm::vec3* lumiereDirectionPtr, glm::vec3* PointlumierePtr);