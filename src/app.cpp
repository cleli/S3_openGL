#include "../include/app.h"

#include <glad/glad.h>
#include <spdlog/spdlog.h>
#include <debug_break/debug_break.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>

bool App::m_instanciated = false;
int WINDOW_WIDTH=800;
int WINDOW_HEIGTH=800;

App::App() : m_running(true){
    assert(!m_instanciated && "App already created !");
	m_instanciated = true;

    spdlog::set_pattern("[%l] %^ %v %$");

	initSDL();
	initImGui();

	glEnable(GL_DEPTH_TEST);
}

App::~App() {
	SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void App::beginFrame() const {
	// activation de l'opacité ( pour la transparence des cubes )
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(m_window);
	ImGui::NewFrame();
}

void App::endFrame() const {
	// Render ImGui
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	//
	SDL_GL_SwapWindow(m_window);
}

/////////////////////////////////////////////////////////////////////////////
//////////////////////////// GETTERS & SETTERS //////////////////////////////
/////////////////////////////////////////////////////////////////////////////

bool App::isRunning() const { return m_running; }
void App::exit() { m_running = false; }

/////////////////////////////////////////////////////////////////////////////
///////////////////////////// PRIVATE METHODS ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void App::initSDL() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		spdlog::critical("[SDL2] Unable to initialize SDL: {}", SDL_GetError());
		debug_break();
	}
	
    // Use OpenGL 3.3
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_GL_LoadLibrary(NULL);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	// Various attributes
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);	
	
	m_window = SDL_CreateWindow(
		"World IMaker !",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGTH,
		SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI
    );
	if (m_window == nullptr) {
        spdlog::critical("[SDL2] Window is null: {}", SDL_GetError());
        debug_break();
    }

    m_glContext = SDL_GL_CreateContext(m_window);
    if (m_glContext == nullptr) {
        spdlog::critical("[SDL2] OpenGL context is null: {}",  SDL_GetError());
        debug_break();
    }

	SDL_GL_MakeCurrent(m_window, m_glContext);
    SDL_GL_SetSwapInterval(1); // Enable vsync

	if (!gladLoadGL()) {
		spdlog::critical("[Glad] Glad not init");
		debug_break();
	}
}

//---------------initialisation IMGUI

void App::initImGui(){

#if __APPLE__
		const char* glslVersion = "#version 150";
#else
		const char* glslVersion = "#version 130";
#endif
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui_ImplSDL2_InitForOpenGL(m_window, m_glContext);
		ImGui_ImplOpenGL3_Init(glslVersion);
		ImGui::StyleColorsClassic();
}