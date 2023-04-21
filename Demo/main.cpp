#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    // Create a window
    window = SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL could not create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        std::cerr << "SDL could not create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Set the renderer color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Clear the renderer with the current color
    SDL_RenderClear(renderer);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Wait for a keypress
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    quit = true;
                    break;
                default:
                    break;
            }
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
