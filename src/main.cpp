#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <TrackballCamera.hpp>

#include "app.h"
#include "cube.h"

int main(int argc, char *argv[]) {
    glClearColor(1, 1, 1, 1);
    unsigned int l=5, L=5, H=10;
    App app;
    Cube myCube;
    //Cube myCube2;
    TrackballCamera camera; 

    Cube stockCube[l*L*H]; // tableau qui stocke tous les cubes du monde de taille(lxLxH)
    for(int i=0;i<75;i++){
        stockCube[i].position = glm::vec3 (i%l, int(i/l), int(i/(l*L)));
    }

    // Activation de la detection de la profondeur 
    glEnable(GL_DEPTH_TEST);

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.0f), // Angle vertical de vue
                (float) (WINDOW_WIDTH / WINDOW_HEIGTH), // Ratio de la fenetre
                0.1f, // Near
                100.f); // Far

    glm::mat4 MVMatrix, NormalMatrix, globalMVMatrix;

    while (app.isRunning()) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT: app.exit();

            case SDL_KEYDOWN:
            {
                //Déplacement d'un  cube avec les flèches du clavier
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
                //Zoom et dezoom de la TrackballCamera
                else if (e.key.keysym.sym == SDLK_z) {
                    camera.moveFront(1.0f);
                } 
                else if (e.key.keysym.sym == SDLK_d) {
                    camera.moveFront(-1.0f);              
                }
            }
            break;
/*
            case SDL_MOUSEMOTION: 
            {
                //Rotation de la TrackballCamera avec le curseur de la souris
                if ( e.motion.xrel != 0 ) {
                    camera.rotateUp( float(e.motion.xrel) * 1.0f);
                }
                if ( e.motion.yrel != 0 ) {
                    camera.rotateLeft( float(e.motion.yrel) * 1.0f);
                }

            }
            break;*/

            default: 
            break;
            };
        }

        globalMVMatrix = camera.getViewMatrix();
        
        app.beginFrame();

        for(int i=0;i<75;i++){
            stockCube[i].draw();
        }
        myCube.draw();

        //myCube2.draw();


        app.endFrame();
    }
    
    return 0;
}
