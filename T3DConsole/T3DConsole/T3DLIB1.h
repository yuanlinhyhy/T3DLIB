#ifndef _T3DLIB1_H
#define _T3DLIB1_H
#include <Windows.h>
#include <SDL.h>
extern HWND g_hWnd;
extern HINSTANCE g_hInstance;
extern SDL_Window* g_pSDLWindow;
extern SDL_Surface* g_pScreenSurface;
extern SDL_Surface* g_pBackSurface;
extern int screen_width;
extern int screen_height;
extern int screen_bpp;
int SD_Init();
int SD_ClearBackSurface( UINT color );
int SD_Flip();
#endif