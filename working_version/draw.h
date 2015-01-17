#include "display.h"
#include <stdlib.h>

#define  COLOUR_SIZE  17

void draw_sdl(SDL_Win *window, Draw *fractal, int x, int y, 
                int size, float angle, int i);

void draw_colour(SDL_Win *window, Draw *fractal, int i);
void find_and_set_colour(SDL_Win *window, Draw *fractal, int i);
void write_random_colour(Draw *fractal, int i);

void draw_shape(SDL_Win *window, Draw *fractal, int x, int y, 
                  int size, float angle, int i);
void find_and_draw_shape(SDL_Win *window, Draw *fractal, int x, int y, 
                           int size, float angle, int i);
void write_random_shape(Draw *fractal, int i);

void Draw_Line(SDL_Renderer* renderer, int x, int y, 
                 int size, float angle, int thickness);
void Draw_Square(SDL_Renderer* renderer, int x, int y, int l, float angle);
void Draw_Circle(SDL_Renderer *renderer, int cx, int cy, int r);
void Draw_Tri(SDL_Renderer *renderer, int x, int y, int size, float angle);
void SDL_Line(SDL_Renderer* renderer, int xs, int ys, int xe, int ye, 
                 int thickness, float angle);
void Draw_Image(SDL_Win *window, int x, int y, int size);
