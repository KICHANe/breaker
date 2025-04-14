#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_audio.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_opengl.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>

#ifndef _WIN32
	#include <Windows.h>
#else
	#include <unistd.h>
#endif

#include "error.h"
#include "player.h"
#include "settings.h"
#include "damage.h"

int main(int argc, char* argv[]) {
//	ARGUMENTS 	//
	ArgHandler SessionArgs;
	SessionArgs.x = NULL;
	SessionArgs.y = NULL;
	if(argc > 0) {
		for (int i; i < (argc + 1); i++) {
			switch(argv) {
				case "x":
					i++;
					SessionArgs.x = atoi(argv[i])
					break;
				case "y":
					i++;
					SessionArgs.y = atoi(argv[i]);
					break;
				case "d":
					printf("Starting in Debug Mode.");
					SessionArgs.debug = true;
				else:
					Error(ERR2);
					break;
			}
		}
	}
	
	// SDL Initialization
	if(SDL_Init(SDL_INIT_VIDEO != 0) {
		Error(ERR1);
		return 1;
	} if(SessionArgs.x == NULL || SessionArgs.y == NULL) {
		SDL_DisplayMode mode;
		if(SDL_GetPrimaryDisplayMode(&mode) != 0) {
			Error(ERR3);
			return 1;
		}
		SessionArgs.x = mode.w;
		SessionArgs.y = mode.h;
	} if (MIX_Init(MIX_INIT_FLAC) != 0) {
		Error(ERR4);
		return -1;
	} if(SDL_Init(SDL_INIT_IMAGE) != 0) {
		Error(ERR5);
		reutrn -1;
	} if(SessionArgs.debug == true) {
		SDL_Window* DebugWindow = SDL_CreateWindow("Debug Viewer", 500, 500, SDL_WINDOW_OPENGL);
		if(DebugWindow == nullptr) {
			Error(ERR6);
			return -1;
		}
	}

		
	// SDL Widndowing
	SDL_Window* MainWindow = SDL_CreateWindow("Breaker Engine 3D Session", SessionArgs.x, SessionArgs.y, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
	if(MainWindow == nullptr) {
		Error(ERR7);
		return -1;
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	// SDL_MIXER INIT //
	

	//	GL SETUP	//
	glViewport(0, 0, SessionArgs.x, SessionArgs.y);

	// Initial GameObjects
	Player mainPlayer = Player_init(0, 0, 0, 0, 110);

	// 
	bool run = true;
	SDL_Event event;

	// DeltaTimes
	double currentTime;
	double lastTime;
	double deltaTime;
	lastTime = SDL_GetTicks();

	// HUDS
	bool PauseMenu = false;
	bool MainMenu = true;
	bool OptionsMenu = false;


	while(run) {
		currentTime = SDL_GetTicks();
		deltaTime = currentTime - lastTime;
		currentTime = lastTime;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = 0;
			}
			// Keyboard Periodic
			if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
				PauseMenu = true;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			

		if (MainMenu == true && PauseMenu == true) {
			DrawErrorScreen()
		}
		




		SDL_GL_SwapWindow(MainWindow);
	}

	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
    	SDL_Quit();
    	return 0;
}
