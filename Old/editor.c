#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <SDL3/SDL_mixer.h>
#include <SDL3/SDL_image.h>
#include <GL/glew.h>

#include "map_editor.h"
#include "gui_colors.h"
#include "errors.h"

int main(int argc, char* argv[]) {
	EditorArgs SystemArgs;	
	if(argc < 0) {
		if(argc > 2) {
			printf("Too Many Operations\n");
			return 1;
		}
		else {
			SystemArgs.map_path = argv[1];
		}
	}

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* editor = SDL_CreateWindow("Pegboard", 640, 480, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(editor);


	int running = 1;
	SDL_Event event;
	while(running) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_EVENT_QUIT) {
				running = 0;
			}
		}
		
	}

	SDL_GL_DeleteContext(glContext);
	SDL_DesroyWindow(editor);
	SDL_Quit();
	return 0;
}	
