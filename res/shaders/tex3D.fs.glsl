#version 330 core

in vec2 vTexCoords;
in vec3 vPosition_vs; 
in vec3 vNormal_vs; 

out vec3 fFragColor;

uniform sampler2D uTexture;

void main(){
    fFragColor=texture(uTexture,vTexCoords).xyz;
}