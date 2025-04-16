#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <SDL3/SDL.h>
#include <GL/gl.h>
#include <GL/glew.h>
#include <SDL3/SDL_mixer.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_opengl.h>

#include "GameInstance.h"
#include "BSPSystems.h"
#include "EngineConfigs.h"

typedef struct EngineInstance {
    SDL_Window* window;
    SDL_GL_Context GLContext;
    SDL_Event event;
    int error_status;
    bool shouldRun;
    int width, height;
} EngineInstance;

EngineInstance EngineInit() {
    EngineInstance a;
    if(!SDL_Init(SDL_INIT_VIDEO)) {
        a.error_status = 1;
        return a;
    } if (!SDL_Init(SDL_INIT_IMAGE)) {
        a.error_status = 2;
    } if (!Mix_Init(MIX_INIT_FLAC)) {
        a.error_status = 3;
    }

    a.window = SDL_CreateWindow(GetGameName(), );
}

void CleanupRoutine(EngineInstance inst) {
    SDL_GL_DeleteContext(inst->);
    SDL_DestroyWindow()
}

int main() {
    EngineInstance engine = EngineInit();
    GameInstance instance = InstanceInit();
    
    
    
}