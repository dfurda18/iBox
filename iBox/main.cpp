#ifndef UNICODE
#define UNICODE
#endif 

#define WIN32_LEAN_AND_MEAN 
#define VC_EXTRALEAN

#include <windows.h>
#include<iostream>
#include <string>
#include "IBox.h"

IBox* game;

int main()
{
	game = new IBox();
	game->Init();
	while (game->running)
	{
		game->Update();
		game->Input();
	}
	system("cls");
	game->Destroy();
	delete(game);
	system("pause");
	return 0;
}