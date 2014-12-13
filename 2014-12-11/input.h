#include "display.h"

int parse(Interface interface, Draw *fractal);
void SDL_Window_Events(SDL_Event event, Interface* interface);
int SDL_Events(Interface* interface);

typedef enum events{ 
	generate_clicked = 1,
	text_edited
} Events;