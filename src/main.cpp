#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <iostream>
#include <ctime>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>

#include "TrackballCamera.hpp"
#include "app.h"
#include "cube.h"
#include "menu.hpp"
#include "radialBasicFonction.hpp"

int main(int argc, char *argv[]) {

    App app;

    //ciel du monde
    //glClearColor(0.45,0.8,0.94, 1.0);

    unsigned int nbPointsControle = 4;
    
    TrackballCamera camera; // création de la trackball caméra
    unsigned int l=15, L=20, H=10; // taille de notre monde

    unsigned int curseur=floor((l/2)+(3*l*L)+(l*L/2)); //Emplacement initial du curseur au milieu du haut du sol

    camera.setPosMatrix(l/2,H/2,L/2); //deplacement de la position initiale pour que la camera tourne autour du centre des cubes

    Cube stockCube[l*L*H]; // tableau qui stocke tous les cubes du monde de taille(lxLxH)
    for(int i=0;i<l*L*H;i++){ // création de notre sol de cube (5*5*3)
        stockCube[i].position = glm::vec3 (i%l,  floor(float(i/(l*L))), floor(float((i/l) % L)));
       // if(i<l*L*3) stockCube[i].isVisible=true;
       stockCube[2].isVisible=true;
        stockCube[1492].isVisible=true;
        stockCube[1420].isVisible=true;
        stockCube[2001].isVisible=true;
        stockCube[1979].isVisible=true;
    }

    //radial basic function
    stockCube[1492].poids=2;
    stockCube[1420].poids=0.5;
    stockCube[2001].poids=-1;
    stockCube[1979].poids=-0.4;

    std::vector<Cube*> v_pointsControle = {&stockCube[1492],&stockCube[1420],&stockCube[2001], &stockCube[1979]};

    bool mouse_pressed=false; //appui de la molette pour le déplacement de la trackball
    glm::vec4 current_color = glm::vec4(0.93f,0.5f, 0.93f, 0.8f);

     for(int i=0;i<l*L*H;i++){
         gener_terrain(nbPointsControle, &stockCube[i], v_pointsControle);  
        if(stockCube[i].poids >0.5){
             stockCube[i].isVisible=true;
        }
        // std::cout<< i << " poids des points : " << stockCube[i].poids << std::endl;         
     }
    
    //création et initialisation de la lumiere directionnelle
    glm::vec3 lumiereDirection = glm::vec3(-1.0f, -0.867f, 0.021f);

    //création et initialisation de la lumiere directionnelle
    glm::vec3 pointLumiere = glm::vec3(0.0f, 0.867f, -1.0f);

    while (app.isRunning()) {

        SDL_Event e;
        float zoom = 1.0f;
        while (SDL_PollEvent(&e)) {
            ImGui_ImplSDL2_ProcessEvent(&e);
            switch (e.type) {
            case SDL_QUIT: app.exit();

            case SDL_KEYDOWN:
            {   
                // déplacement du curseur seulement dans notre monde
                if (e.key.keysym.scancode == SDL_SCANCODE_LEFT) {
                    if(curseur%l>0) curseur=curseur-1;
                } 
                else if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                    if(curseur%l<l-1) curseur=curseur+1;
                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_UP) {
                    if(floor(float(curseur/(l*L)))<H-1) curseur=curseur+l*L;
                } 
                else if (e.key.keysym.scancode == SDL_SCANCODE_DOWN) {
                    if(floor(float(curseur/(l*L)))>0) curseur=curseur-l*L;
                } 
                else if (e.key.keysym.scancode == SDL_SCANCODE_O) {
                    if(floor(float((curseur/l) % L))<L-1) curseur=curseur+l;
                } 
                else if (e.key.keysym.scancode == SDL_SCANCODE_L) { 
                    if(floor(float((curseur/l) % L))>0) curseur=curseur-l;
                } 

                // Raccourcis clavier pour créer et supprimer un cube
                else if (e.key.keysym.scancode == SDL_SCANCODE_C) { 
                    stockCube[curseur].isVisible=true;
                    stockCube[curseur].color=glm::vec4(0.53f,0.3f,0.65f,0.5f);
                } 
                else if (e.key.keysym.scancode == SDL_SCANCODE_S) { 
                    stockCube[curseur].isVisible=false;
                }
                
            }
            break;

            case SDL_MOUSEWHEEL: 
            {
                if (e.wheel.y < 0)
                    camera.moveFront(-zoom); //dézoom avec la molette
                else
                    camera.moveFront(zoom); //zoom
            }
            break;
            
            //clique du bouton de la molette
            case SDL_MOUSEBUTTONDOWN :
            {
                if (e.button.button == SDL_BUTTON_MIDDLE) mouse_pressed = true;
            }
            break;

            case SDL_MOUSEBUTTONUP :
            {
                if (e.button.button == SDL_BUTTON_MIDDLE) mouse_pressed = false;
            }
            break;

            case SDL_MOUSEMOTION :
            {   
                //on ne peut bouger la trackball qu'en cliquant sur la molette de la souris
                if(mouse_pressed==true){
                    // rotation de la trackball camera
                    float speed = 1.0f;
                    if( e.motion.xrel !=0){
                        camera.rotateUp(float(e.motion.xrel)*speed);
                    }
                    if( e.motion.yrel !=0){
                        camera.rotateLeft(float(e.motion.yrel)*speed);
                    }
                }
            }
            break;

            default: break;
            };
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        app.beginFrame();

        //affichage du menu
        afficheMenu(curseur, &current_color, stockCube, l, L, H, &lumiereDirection, &pointLumiere);
        
        //affichage de notre monde initialisé avec un sol
        for(int i=0;i<l*L*H;i++){
            if(stockCube[i].isVisible==true){
                stockCube[i].draw(camera, glm::normalize(lumiereDirection), glm::normalize(pointLumiere));
            }
        }
        
        // pour que le curseur reste toujours visible
        glDisable(GL_DEPTH_TEST);
        stockCube[curseur].drawCurseur(camera);
        glEnable(GL_DEPTH_TEST);

        app.endFrame();
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    return 0;
}
