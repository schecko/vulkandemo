
#include <stdio.h>
#include "SDL.h"
#include "vulkan/vulkan.hpp"

int SDL_main(int argc, char* argv[]) {
	if(SDL_Init(SDL_INIT_EVERYTHING)) {
		printf("SDL failed to initialize");
		return -1;
	}

	SDL_Window* window = SDL_CreateWindow("Clear Screen Example", 100, 100, 400, 400, 0);
	if(!window) {
		printf("failed to create sdl window");
		return -1;
	}

	//VkInstance instance = NewVkInstance("Clear Screen Example", NULL, NULL);
	//SDL_assert(instance);

	return 0;
}
