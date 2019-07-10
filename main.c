#include <SDL.h>
#include <stdio.h>

void main() {
    printf("hello world\n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *wind;
    SDL_Renderer *rend;
    printf("about to create window\n");
    if (SDL_CreateWindowAndRenderer(400,
                            400,
                            0,
                            &wind,
                            &rend)) {
        printf("Failed to create something or other\n");
        SDL_Quit();
        return;
    }

    SDL_SetRenderDrawColor(rend, 255, 0, 0,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(rend);
    SDL_RenderPresent(rend);
    SDL_Event evt;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&evt)) {
            printf("got event\n");
            switch (evt.type) {
                case SDL_WINDOWEVENT:
                    printf("window event\n");
                    break;
                case SDL_MOUSEMOTION:
                    printf("mouse motion\n");
                    SDL_SetRenderDrawColor(rend, 0, 255, 0, SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawPoint(rend, evt.motion.x, evt.motion.y);
                    SDL_RenderPresent(rend);
                    break;
                case SDL_QUIT:
                    printf("quitting\n");
                    quit = 1;
                default:
                    printf("something else\n");
            }
        }
        usleep(1000);
    }

    SDL_Quit();
}
