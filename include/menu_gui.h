#ifndef MENU_GUI_H
#define MENU_GUI_H

#include <SDL.h>

// Initialize ImGui menu system (call after SDL_CreateRenderer)
int menu_gui_init(SDL_Window* window, SDL_Renderer* renderer);

// Shutdown ImGui menu system
void menu_gui_shutdown();

// Process SDL events for ImGui (call before game input processing)
// Returns true if ImGui consumed the event (menu is active)
bool menu_gui_process_event(const SDL_Event* event);

// Begin a new ImGui frame (call once per frame before rendering)
void menu_gui_begin_frame();

// Render ImGui overlay (call after game framebuffer, before SDL_RenderPresent)
void menu_gui_render();

// Toggle settings menu (F1)
void menu_gui_toggle_settings();

// Toggle debug menu (F2)
void menu_gui_toggle_debug();

// Returns true if any menu is active (blocks game input)
bool menu_gui_is_active();

// Set callback for File->Quit
void menu_gui_set_quit_callback(void (*callback)());

// ROM path management
void menu_gui_set_rom_path(const char* path);
const char* menu_gui_get_rom_path();
void menu_gui_set_rom_callback(void (*callback)(const char* path));

#endif // MENU_GUI_H
