#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;

out vec3 vNorm;

uniform mat4 uModel;
uniform mat4 uViewProj;


void main() {
    gl_Position = uViewProj * uModel * vec4(aPos, 1.0);
    vNorm = aNorm;
}
