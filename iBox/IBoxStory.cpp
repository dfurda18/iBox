#include <iostream>
#include "IBox.h"
#include "IBoxStory.h"

extern IBox* game;

IBoxStory::IBoxStory() : IBoxLevel(STORY, {0,0})
{

}

void IBoxStory::AddText(StoryText* text)
{
	this->text.push_back(text);
}

void IBoxStory::AddBox(IBoxItemBox*)
{

}

void IBoxStory::AddDestination(IBoxItemDestination*)
{

}

void IBoxStory::AddMapLine()
{

}

void IBoxStory::AddToMap(int , int)
{

}

void IBoxStory::AddRobot(IRobot* robot)
{

}

void IBoxStory::Input()
{
	Sleep(100);
	if (GetKeyState(VK_RETURN) & 0x8000)
	{
		game->levelManager->ShowNextLevel();
	}
}

void IBoxStory::Update()
{
	
}

void IBoxStory::Draw()
{
	system("cls");
	unsigned int lineCounter;
	COORD start = { 0,0 };
	for (auto text : this->text)
	{
		SetConsoleTextAttribute(game->console, text->color);
		for (lineCounter = 0; lineCounter < text->lines.size(); lineCounter++)
		{
			SetConsoleCursorPosition(game->console, start);
			std::cout << text->lines[lineCounter];
			start.Y++;
		}
	}
	for (auto image : this->image)
	{
		start = image->start;
		SetConsoleTextAttribute(game->console, image->color);
		for (lineCounter = 0; lineCounter < image->lines.size(); lineCounter++)
		{
			SetConsoleCursorPosition(game->console, start);
			std::cout << image->lines[lineCounter];
			start.Y++;
		}
	}
	Sleep(1000);
}

void IBoxStory::Destroy()
{
	for (auto textElement : this->text)
	{
		delete(textElement);
	}
	for (auto imageElement : this->image)
	{
		delete(imageElement);
	}
}