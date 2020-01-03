#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>

#include "menu.hpp"
#include "cube.h"
#include "radialBasicFonction.hpp"

std::string current_color_string="Violet";

static bool rouge=false;
static bool orange=false;
static bool jaune=false;
static bool vert=false;
static bool bleu=false;
static bool indigo=false;
static bool violet=false;

void afficheMenu(unsigned int curseur, glm::vec4* current_color, Cube stockCube[],unsigned int l,unsigned int L, unsigned int H, glm::vec3* lumiereDirectionPtr, glm::vec3* PointlumierePtr) {
    //création du menu
    ImGui::Begin("Menu");

    //couleur
    ImGui::ColorEdit4("Couleur", (float*)current_color);
    if(ImGui::Button("modifier couleur")){
        if(stockCube[curseur].isVisible==true) stockCube[curseur].color= *current_color;
    }

    ImGui::Spacing();
    ImGui::Spacing();

    //Sculpture du monde : créer, supprimer, creuser et extruder

    ImGui::Text("Sculpture : ");
    ImGui::Spacing();

    if(ImGui::Button("Créer")){ 
        stockCube[curseur].isVisible=true;
        stockCube[curseur].color= *current_color;
    }
    ImGui::SameLine();
    if(ImGui::Button("Supprimer")){ 
        stockCube[curseur].isVisible=false;
    }
    if(ImGui::Button("Extruder")){
        unsigned int current_cube = curseur;
        while(stockCube[current_cube].isVisible==true) {
            current_cube=current_cube+l*L;
        }
        if(floor(float(current_cube/(l*L)))<H-1){
            stockCube[current_cube].isVisible=true;
            stockCube[current_cube].color= *current_color;
        }
    }
    ImGui::SameLine();
    if(ImGui::Button("Creuser")){ 
        unsigned int current_cube = curseur;
        while(stockCube[current_cube].isVisible==true) {
            current_cube=current_cube+l*L;
        }
        if(floor(float(current_cube/(l*L)))>0){
            stockCube[current_cube-l*L].isVisible=false;
            stockCube[current_cube-l*L].color= *current_color;
        }
    }

    ImGui::Text("Génération terrain: ");
    if(ImGui::Button("Terrain Aléatoire")){
       gener_terrainAleatoire(l, L,  H, stockCube);
    }

   /* if(ImGui::Button("Ambiance nuit")){ 
        lumiereDirectionPtr = glm::vec3(0.0f, 0.0f, 0.0f);
        pointLumierePtr = glm::vec3(1.0f, -0.2f, 1.0f);
    }
    if(ImGui::Button("Ambiance jour")){ 
        lumiereDirectionPtr = glm::vec3(0.0f, -0.3f, -0.5f);
        PointlumierePtr = glm::vec3(0.0f, 0.867f, -1.0f);

    }*/
    ImGui::Spacing();
    ImGui::Text("Lumière directionnelle: ");
    ImGui::Spacing();
    //pour changer la lumiere directionnelle
    ImGui::PushID(0);
    ImGui::SliderFloat3("", (float*)lumiereDirectionPtr, -1, 1);
    ImGui::PopID();

    ImGui::Spacing();
    ImGui::Text("Point de lumière: ");
    ImGui::Spacing();
    //pour changer le point de lumieres
    ImGui::PushID(1);
    ImGui::SliderFloat3("", (float*)PointlumierePtr, -10, 10);
    ImGui::PopID();

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();

    //Effacer le monde
    if(ImGui::Button("Effacer tout")){ 
        for(int i=0;i<l*L*H;i++){ 
            stockCube[i].isVisible=false;
        }
    }

    ImGui::End();
    //ImGui::ShowDemoWindow();
}