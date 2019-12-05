#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <debug_break/debug_break.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <unordered_map>

#include "app.h"
#include "gl-exception.h"
#include "cube-data.h"
#include "shader.h"

int main(int argc, char *argv[]) {
    App app;

    glClearColor(1, 0, 1, 1);

    // ------------------ Vertex Buffer
    unsigned int posVB;
    {
        // TODO part 1
    }
    
    // ------------------ Vertex Array
    unsigned int vao;
    {
        // TODO part 2
    }

    // ------------------ Index buffer
    unsigned int ib;
    {
        // TODO part 3
    }

    // ------------------ Shaders with uniforms
        // TODO part 5

    while (app.isRunning()) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT: app.exit();

            default: break;
            };
        }

        app.beginFrame();

        // Draw call
        // TODO part 4

        app.endFrame();
    }
    
    return 0;
}
