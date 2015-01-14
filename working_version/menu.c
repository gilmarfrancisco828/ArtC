#include "display.h"

/* Main Menu */
void launch_menu() {
  Menu menu;
  SDL_Win_Init(&menu.window, "Art.C");
  SDL_TTF_Init();
  menu.hover = 0;

  do {
    initialise_main_menu(&menu);
    display_popup_text(&menu);
    render_update_clear(menu.window);
 
    menu.state = SDL_Main_Menu_Events(&menu);
    main_menu_actions(&menu);
  //SDL shut_down, TTF shut down, free memory)

  } while(!menu.window.finished);
  
  atexit(SDL_Quit);
}

int challenge_menu(Menu* challenges) {

  challenges->hover = 0;
  while(challenges->state != main_menu) {
    initialise_challenges_menu(challenges);
    display_popup_text(challenges);
    render_update_clear(challenges->window);

    challenges->state = SDL_Challenges_Menu_Events(challenges);
    challenge_menu_actions(challenges);
  }
  return 0;
}

int help_menu(Menu* help) {
  while(help->state != main_menu) {
    display_help_menu(help);
    render_update_clear(help->window);
    help->state = SDL_Help_Menu_Events(help);
    help_menu_actions(help);
  }
  return 0;
}

/* Act based on whether any buttons in the main menu were pressed */ 
void main_menu_actions(Menu* menu) {
  switch (menu->state) {
    case canvas: 
      interface(menu, canvas_mode, "canvas.txt"); 
      //SDL_RenderClear(menu->window.renderer);
      //display_main_menu(menu); 
      break;
    case challenges_menu:
      challenge_menu(menu);
      //SDL_RenderClear(menu->window.renderer);
      //display_main_menu(menu); 
      break;
    case options_menu:
      help_menu(menu);
      break;
    case quit:
      menu->window.finished = 1;
      break;
    default: return;
  }
}

void challenge_menu_actions(Menu* challenges) {
    
    switch (challenges->state) {
      case beginner: 
        interface(challenges, challenge_mode, BEGINNER);
        break;
      case intermediate:
        interface(challenges, challenge_mode, INTERMEDIATE);
        break;
      case expert:
        interface(challenges, challenge_mode, EXPERT);
        break;
      case main_menu:
        challenges->state = main_menu;
        break;
      default: return;
    }
}

void help_menu_actions(Menu* help) {
    
    switch (help->state) {
      case back: 
        help->state = main_menu;
        break;
      default: return;
    }
}
