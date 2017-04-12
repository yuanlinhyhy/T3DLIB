#include "T3DLIB1.h"
#include <Windows.h>
#include <SDL.h>
HWND g_hWnd = NULL;
HINSTANCE g_hInstance = NULL;
SDL_Window* g_pSDLWindow = NULL;
SDL_Surface* g_pScreenSurface = NULL;
SDL_Surface* g_pBackSurface = NULL;
int screen_width = 0;
int screen_height = 0;
int screen_bpp = 32;
int SD_Init()
{
	SDL_Init( SDL_INIT_VIDEO );
	g_pSDLWindow = SDL_CreateWindowFrom( g_hWnd );
	if ( g_pSDLWindow == NULL )
	{
		MessageBox( NULL, L"´´½¨SDL´°¿ÚÊ§°Ü£¡", L"´íÎó£¡", MB_ICONERROR );
		return 0;
	}
	g_pScreenSurface = SDL_GetWindowSurface( g_pSDLWindow );
	g_pBackSurface = SDL_CreateRGBSurface( 0, screen_width, screen_height, 32, 0, 0, 0, 0 );
	return 1;
}
int SD_ClearBackSurface( UINT color )
{
	SDL_FillRect( g_pBackSurface, NULL, color );
	return 1;
}
int SD_Flip()
{
	SDL_BlitSurface( g_pBackSurface, NULL, g_pScreenSurface, NULL );
	SDL_UpdateWindowSurface( g_pSDLWindow );
	return 1;
}