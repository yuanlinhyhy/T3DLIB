#include <Windows.h>
#include "T3DLIB1.h"
TCHAR szAppName[] = L"T3DLIB";
TCHAR szWndName[] = L"DrawPixel";
HRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
int GameInit();
int GameMain();
int GameShutdown();
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE , PSTR lpCmdLine, int nCmdShow )
{
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = ( HBRUSH ) GetStockObject( WHITE_BRUSH );
	wndClass.hCursor = LoadCursor( NULL, IDC_ARROW );
	wndClass.hIcon = LoadIcon( NULL, IDI_APPLICATION );
	wndClass.hInstance = hInstance;
	g_hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	if ( !RegisterClass( &wndClass ) )
	{
		MessageBox( NULL, L"×¢²á´°¿ÚÀàÊ§°Ü", L"´íÎó£¡", MB_ICONERROR );
	}
	g_hWnd = CreateWindow( szAppName, szWndName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 512, 512, NULL, NULL, hInstance, 0 );
	if ( !g_hWnd )
	{
		MessageBox( NULL, L"´´½¨´°¿ÚÊ§°Ü£¡", L"´íÎó£¡", MB_ICONERROR );
	}
	ShowWindow( g_hWnd, nCmdShow );
	UpdateWindow( g_hWnd );
	MSG msg;
	GameInit();
	while ( 1 )
	{
		if ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			if ( msg.message == WM_QUIT )
				break;
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		GameMain();
	}
	return 0;
}
HRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	static HDC hdc;
	static PAINTSTRUCT ps;
	switch ( uMsg )
	{
	case WM_SIZE:
		hdc = BeginPaint( hWnd, &ps );
		RECT rect;
		GetClientRect( hWnd, &rect );
		screen_width = rect.right - rect.left;
		screen_height = rect.bottom - rect.top;
		EndPaint( hWnd, &ps );
		return 0;
	case WM_DESTROY:
		PostQuitMessage( 0 );
		return 0;
	}
	return DefWindowProc( hWnd, uMsg, wParam, lParam );
}
int GameInit()
{
	SD_Init();
	return 1;
}
int GameMain()
{
	SD_ClearBackSurface( 0 );
	SDL_LockSurface( g_pBackSurface );
	int lpitch = ( g_pBackSurface->pitch >> 2 );
	UINT* video_buffer = ( UINT* ) g_pBackSurface->pixels;
	for ( int i = 0; i < 1000; i++ )
	{
		int x = rand() % screen_width;
		int y = rand() % screen_height;
		video_buffer[ x + y * lpitch ] = 0x00ff0000;
	}
	SDL_UnlockSurface( g_pBackSurface );
	SD_Flip();
	for ( int i = 0; i < 1000; i++ )
	{


	}
	return 1;
}
int GameShutdown()
{
	return 1;
}