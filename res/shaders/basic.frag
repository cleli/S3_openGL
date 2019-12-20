#version 330 core
out vec4 fragColor;

in vec3 vNorm;
in vec3 vworldPosition;

uniform vec4 uColor;
uniform vec3 uLumiereDirection;
uniform vec3 uPointLumiere;

void main() {
    float luminosite = max(- dot(uLumiereDirection, vNorm), 0.2);
    vec3 direction = normalize( uPointLumiere - vworldPosition);
    float luminosite2 = max(- dot(direction, vNorm), 0.2);
    float additionLuminosite = min(luminosite+luminosite2, 1);
    fragColor = vec4(uColor.xyz*additionLuminosite, 1.);
}
