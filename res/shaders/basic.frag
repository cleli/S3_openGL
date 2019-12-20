#version 330 core
out vec4 fragColor;

in vec3 vNorm;

uniform vec4 uColor;
uniform vec3 uLumiereDirection;

void main() {
    float luminosite = max(- dot(uLumiereDirection, vNorm), 0.2);
    fragColor = vec4(uColor.xyz*luminosite, 1.);
}
