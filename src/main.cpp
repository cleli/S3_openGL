#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <iostream>

#include "TrackballCamera.hpp"
#include "app.h"
#include "cube.h"

int main(int argc, char *argv[]) {

    App app;
    Cube myCube;
   
    TrackballCamera camera; // création de la trackball caméra
    unsigned int l=5, L=5, H=10; // taille de notre monde

    //glClearColor(1, 1, 1, 1);
    

    Cube stockCube[l*L*H]; // tableau qui stocke tous les cubes du monde de taille(lxLxH)
    for(int i=0;i<75;i++){ // création de notre sol de cube (5*5*3)
        stockCube[i].position = glm::vec3 (i%l,  floor(float(i/(l*L))), floor(float((i/l) % L)) );
    }

    while (app.isRunning()) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT: app.exit();

            case SDL_KEYDOWN:
            {   
                float zoom = 1.0f;
                // déplacement d'un cube
                if (e.key.keysym.scancode == SDL_SCANCODE_LEFT) {
                    myCube.position.x--;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                    myCube.position.x++;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_UP) {
                    myCube.position.y++;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_DOWN) {
                    myCube.position.y--;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_PAGEUP) {
                    myCube.position.z++;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_PAGEDOWN) {
                    myCube.position.z--;
                }
                // zoom et dezoom de la trackball camera
                else if (e.key.keysym.scancode == SDL_SCANCODE_Z){
                    //std::cout<<"Z pressed"<<std::endl;
                    camera.moveFront(zoom);
                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_D){
                   // std::cout<<"D pressed"<<std::endl;
                    camera.moveFront(-zoom);
                }
            }
            break;

            

            case SDL_MOUSEMOTION :
            {
                // rotation de la trackball camera
                float speed = 1.0f;
                //std::cout<<"mouse move";
                if( e.motion.xrel !=0){
                    camera.rotateUp(float(e.motion.xrel)*speed);
                }
                if( e.motion.yrel !=0){
                    camera.rotateLeft(float(e.motion.yrel)*speed);
                }
            }
            break;

            default: break;
            };
        }
       
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        app.beginFrame();

        //affichage de notre sol de cubes
        float j=0;
        for(int i=0;i<75;i++){
            j+=0.01;
            stockCube[i].draw(j, camera);
        }

        myCube.draw(1, camera);
        

        app.endFrame();
    }
    
    return 0;
}
