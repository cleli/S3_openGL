#version 330 core
out vec4 fragColor;

uniform float uColor;

void main() {
    fragColor = vec4(0.5f, uColor, 0.0f, 1.0f);
}
