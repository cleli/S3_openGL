#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <string>
#include <iostream>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>

#include "../include/menu.hpp"
#include "../include/cube.h"
#include "../include/save_open.hpp"
#include "../include/radialBasicFonction.hpp"
#include "../include/discretisation.hpp"



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
        if(floor(float(current_cube/(l*L)))>0 && (current_cube!=curseur)){
            stockCube[current_cube-l*L].isVisible=false;
        }
    }

    //génération de terrain
    if(ImGui::Button("Terrain Aléatoire")){
       gener_terrainAleatoire(l, L,  H, stockCube);
    }

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
    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();

    /*if(ImGui::Button("Discrétiser")){ 
        discretiser(stockCube,l,L,H);
        std::cout<<stockCube[0].color.y<<std::endl;
    }

    ImGui::Spacing();
    ImGui::Spacing();
    ImGui::Spacing();*/

    if(ImGui::Button("Sauvegarder")){
        unsigned int taille = l*L*H;
        std::string filename, filepath;
        std::cout <<"Entrez un emplacement (ex: ./doc/) : "<<std::endl;
        std::cin>> filepath;
        std::cout <<"Entrez un nom de fichier (ex: monfichier.txt): "<<std::endl;
        std::cin>> filename;
        int file = sauvegarder(stockCube, taille, filepath, filename);
    }
    ImGui::SameLine();
    if(ImGui::Button("Charger")){
        unsigned int taille = l*L*H;
        std::string filename, filepath;
        std::cout <<"Entrez un emplacement (ex: ./doc/) : "<<std::endl;
        std::cin>> filepath;
        std::cout <<"Entrez un nom de fichier (ex: monfichier.txt): "<<std::endl;
        std::cin>> filename;
        charger(stockCube, taille, filepath, filename);
    }

    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::End();
    //ImGui::ShowDemoWindow();
}