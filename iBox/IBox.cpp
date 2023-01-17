#include <windows.h>
#include<iostream>
#include "IBox.h"

IBox::IBox()
{
	this->console = GetStdHandle(STD_OUTPUT_HANDLE);
}

void IBox::Init()
{
	this->running = true;
	this->mainMenuOptions.push_back("START");
	this->mainMenuOptions.push_back("CONTROLS");
	this->mainMenuOptions.push_back("CREDITS");
	this->mainMenuOptions.push_back("QUIT");
	this->levelManager = new IBoxLevelManager("game.json");
	this->HideCursor();
	this->ShowTitle();
	
}

void IBox::Input()
{
	switch (this->gameState)
	{
	case START:
		// Menu selection hnadling
		if (GetKeyState(VK_RETURN) & 0x8000)
		{
			switch (this->mainMenuSelection)
			{
			case 0:
				this->StartGame();
				break;
			case 1:
				this->ShowControls();
				break;
			case 2:
				this->ShowCredits();
				break;
			case 3:
			default:
				SetConsoleTextAttribute(this->console, this->DEFAULT);
				this->running = false;
			}
			
		}
		// Menu movement
		if (GetKeyState(VK_UP) & 0x8000)
		{
			if (this->mainMenuSelection > 0) {
				this->mainMenuSelection--;
			}
			Sleep(200);
		}
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			if (this->mainMenuSelection < this->mainMenuOptions.size() - 1) {
				this->mainMenuSelection++;
			}
			Sleep(200);
		}
		break;
	case CONTROLS:
	case CREDITS:
	case GAMEOVER:
		Sleep(100);
		if (GetKeyState(VK_RETURN) & 0x8000)
		{
			this->ShowTitle();
		}
		break;
	case PLAYING:
		this->levelManager->Input();
		break;
	}
}

void IBox::Update()
{
	switch (this->gameState)
	{
	case START:
		this->RenderMainMenu();
		break;
	case PLAYING:
		if (this->levelManager->isFinished)
		{
			this->ShowGameOver();
		}
		else 
		{
			this->levelManager->Update();
		}
		break;
	}
}

void IBox::Draw()
{
	COORD startingPoint = { 0,0 };
	COORD size = { 0,0 };
	std::vector<std::string> titleArray;
	std::vector<std::string> controlsArray;
	std::vector<std::string> creditsArray;
	std::vector<std::string> gameoverArray;
	system("cls");
	switch (this->gameState)
	{
	case START:
		startingPoint = { 5,1 };
		size = { 89,15 };
		this->PaintFrame(startingPoint, size, this->FRAME);
		titleArray.push_back(" .----------------.   .----------------.   .----------------.   .----------------.");
		titleArray.push_back("| .--------------. | | .--------------. | | .--------------. | | .--------------. |");
		titleArray.push_back("| |       _      | | | |   ______     | | | |     ____     | | | |  ____  ____  | |");
		titleArray.push_back("| |      (_)     | | | |  |_   _ \\    | | | |   .'    `.   | | | | |_  _||_  _| | |");
		titleArray.push_back("| |       _      | | | |    | |_) |   | | | |  /  .--.  \\  | | | |   \\ \\__/ /   | |");
		titleArray.push_back("| |      | |     | | | |    |  __'.   | | | |  | |    | |  | | | |    > __ <    | |");
		titleArray.push_back("| |      | |     | | | |   _| |__) |  | | | |  \\  `--'  /  | | | |  _/ /  \\ \\_  | |");
		titleArray.push_back("| |      |_|     | | | |  |_______/   | | | |   `.____.'   | | | | |____||____| | |");
		titleArray.push_back("| |              | | | |              | | | |              | | | |              | |");
		titleArray.push_back("| '--------------' | | '--------------' | | '--------------' | | '--------------' |");
		titleArray.push_back("'----------------'   '----------------'   '----------------'   '----------------'");
		startingPoint = { 8,3 };
		this->PaintBlock(titleArray, startingPoint, this->TITLE);
		startingPoint = { 42,18 };
		size = { 16,8 };
		this->PaintFrame(startingPoint, size, this->FRAME);
		Sleep(500);
		break;
	case CONTROLS:
		startingPoint = { 5,1 };
		size = { 39,14 };
		this->PaintFrame(startingPoint, size, this->FRAME);
		controlsArray.push_back("            MENUS");
		controlsArray.push_back("Menu navigation: Up and Down keys");
		controlsArray.push_back("Accept selection: ENTER key");
		controlsArray.push_back("");
		controlsArray.push_back("          GAMEPLAY");
		controlsArray.push_back("Move: Arrow keys");
		controlsArray.push_back("Pause: ESC key");
		controlsArray.push_back("Reset: R key");
		controlsArray.push_back("");
		controlsArray.push_back("    Press ENTER to return.");
		startingPoint = { 8,3 };
		this->PaintBlock(controlsArray, startingPoint, this->INSTRUCTIONS);
		Sleep(1000);
		break;
	case CREDITS:
		startingPoint = { 5,1 };
		size = { 45,9 };
		this->PaintFrame(startingPoint, size, this->FRAME);
		creditsArray.push_back("       Created and developed by");
		creditsArray.push_back("");
		creditsArray.push_back("          Dario Urdapilleta");
		creditsArray.push_back("");
		creditsArray.push_back("Press ENTER to return to the main menu.");
		startingPoint = { 8,3 };
		this->PaintBlock(creditsArray, startingPoint, this->INSTRUCTIONS);
		Sleep(1000);
		break;
	case GAMEOVER:
		startingPoint = { 5,1 };
		size = { 89,14 };
		this->PaintFrame(startingPoint, size, this->FRAME);

		gameoverArray.push_back(" _______                      _______");
		gameoverArray.push_back("(_______)                    (_______)");
		gameoverArray.push_back(" _   ___ _____ ____  _____    _     _ _   _ _____  ____");
		gameoverArray.push_back("| | (_  (____ |    \\| ___ |  | |   | | | | | ___ |/ ___)");
		gameoverArray.push_back("| |___) / ___ | | | | ____|  | |___| |\\ V /| ____| |");
		gameoverArray.push_back("\\_____ /\\_____|_|_|_|_____)   \\_____/  \\_/ |_____)_|");

		gameoverArray.push_back("");
		gameoverArray.push_back("");
		gameoverArray.push_back("        Press ENTER to return to the main menu.");
		startingPoint = { 25,3 };
		this->PaintBlock(gameoverArray, startingPoint, this->TITLE);
		Sleep(1000);
		break;
	}
}

void IBox::Destroy()
{
	this->levelManager->Destroy();
	delete(this->levelManager);
}

void IBox::ShowTitle()
{
	this->gameState = START;
	this->mainMenuSelection = 0;
	this->Draw();
}

void IBox::ShowControls()
{
	this->gameState = CONTROLS;
	this->Draw();
}

void IBox::ShowCredits()
{
	this->gameState = CREDITS;
	this->Draw();
}

void IBox::StartGame()
{
	this->gameState = PLAYING;
	this->levelManager->ShowFirstLevel();
}

void IBox::ShowGameOver()
{
	this->gameState = GAMEOVER;
	this->Draw();
}

void IBox::RenderMainMenu()
{
	COORD start = { 46,20 };
	COORD size = { 89,15 };
	this->PaintMenu(this->mainMenuOptions, start, this->mainMenuSelection, this->INSTRUCTIONS, this->SELECTED_INSTRUCTION);
}

void IBox::PaintFrame(COORD start, COORD size, Colors color)
{
	COORD counter;
	std::vector<std::string> frameArray;
	std::string frameLine;
	/*
		Paint a # frame:
		#######
		#     #
		#     #
		#######
	*/
	for (counter.Y = 0; counter.Y < size.Y; counter.Y++)
	{
		frameLine = "";
		for (counter.X = 0; counter.X < size.X; counter.X++)
		{
			if (counter.Y == 0 || counter.Y == size.Y - 1 || counter.X == 0 || counter.X == size.X - 1)
			{
				frameLine += "#";
			}
			else
			{
				frameLine += " ";
			}

		}
		frameArray.push_back(frameLine);
	}
	this->PaintBlock(frameArray, start, color);
}

void IBox::PaintBlock(std::vector<std::string> content, COORD start, Colors color)
{
	SetConsoleTextAttribute(this->console, color);
	// Paint the content line by line from the start position
	for (unsigned int lineCounter = 0; lineCounter < content.size(); lineCounter++)
	{
		SetConsoleCursorPosition(this->console, start);
		std::cout << content[lineCounter];
		start.Y++;
	}
}

void IBox::PaintMenu(std::vector<std::string> content, COORD start, int selected, Colors color, Colors selectedColor)
{
	// Paint each menu option
	for (unsigned int lineCounter = 0; lineCounter < content.size(); lineCounter++)
	{
		if (lineCounter == selected)
		{
			SetConsoleTextAttribute(this->console, selectedColor);
		}
		else
		{
			SetConsoleTextAttribute(this->console, color);
		}
		SetConsoleCursorPosition(this->console, start);
		std::cout << content[lineCounter];
		start.Y++;
	}
}

void IBox::HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}