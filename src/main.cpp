#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

#include "app.h"
#include "cube.h"

int main(int argc, char *argv[]) {
    App app;
    Cube myCube;
    Cube myCube2;
    unsigned int l=5, L=5, H=10;

    glClearColor(1, 1, 1, 1);

    Cube stockCube[l*L*H]; // tableau qui stocke tous les cubes du monde de taille(lxLxH)
    for(int i=0;i<75;i++){
        stockCube[i].position = glm::vec3 (i%l, int(i/l), int(i/(l*L)));
    }

    while (app.isRunning()) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT: app.exit();

            case SDL_KEYDOWN:
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

            default: break;
            };
        }

        app.beginFrame();

        for(int i=0;i<75;i++){
            stockCube[i].draw();
        }
        myCube.draw();
        myCube2.draw();

        app.endFrame();
    }
    
    return 0;
}
