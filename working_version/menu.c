#include "menu.h"

/* Main Menu */
void launch_menu() {
    Menu menu;
    SDL_Win_Init(&menu.window, "Art.C");
    SDL_TTF_Init();
    menu.hover = 0;

    do {
        initialise_main_menu(&menu);
        display_popup_text(&menu);
        render_update(menu.window);
 
        menu.state = SDL_Main_Menu_Events(&menu);
        main_menu_actions(&menu);

        //SDL shut_down, TTF shut down, free memory)
      } while(!menu.window.finished);
  
    atexit(SDL_Quit);
}

void initialise_main_menu(Menu* main_menu) {
    main_menu->menu_font = SDL_Load_Font("display/font/Edo.ttf", 
                                           BUTTON_FONT_SIZE);
    main_menu->state = 0;

    display_main_menu(main_menu);
}

/* Act based on whether any buttons in the main menu were pressed */ 
void main_menu_actions(Menu* main_menu) {
    switch (main_menu->state) {
        case canvas: 
            interface(main_menu, canvas_mode, "program_txt_files/canvas.txt"); 
            //SDL_RenderClear(main_menu->window.renderer);
            //display_main_menu(main_menu); 
            break;
        case challenges_menu_choice:
           challenges_menu(main_menu);
           //SDL_RenderClear(main_menu->window.renderer);
           //display_main_menu(main_menu); 
           break;
        case options_menu_choice:
            help_menu(main_menu);
            break;
        case quit:
            main_menu->window.finished = 1;
            break;
        default: 
            return;
    }
}

int challenges_menu(Menu* challenges) {
    challenges->hover = 0;
    challenges->state = 0;
    while(challenges->state != main_menu) {
        initialise_challenges_menu(challenges);
        display_popup_text(challenges);
        render_update(challenges->window);
        challenges->state = SDL_Challenges_Menu_Events(challenges);
        challenges_menu_actions(challenges);
    }
    return 0;
}

void initialise_challenges_menu(Menu* challenges) {
    display_challenges_menu(challenges);
}

void challenges_menu_actions(Menu* challenges) {
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
        default: 
            return;
    }
}

int help_menu(Menu* help) {
    while(help->state != main_menu) {
        initialise_help_menu(help);
        render_update(help->window);
        help->state = SDL_Help_Menu_Events(help);
        help_menu_actions(help);
    }
    return 0;
}

void initialise_help_menu(Menu* help) {
    display_help_menu(help);
}

void help_menu_actions(Menu* help) {
    switch (help->state) {
        case back: 
            help->state = main_menu;
            break;
        default: 
            return;
    }
}
