#include <iostream>
#include "IBoxPuzzle.h"
#include "IBox.h"

extern IBox* game;

IBoxPuzzle::IBoxPuzzle(COORD start) : IBoxLevel(PUZZLE, start)
{
	this->itemsCollected = 0;
	this->finished = false;
}

void IBoxPuzzle::AddText(StoryText* text)
{

}

void IBoxPuzzle::AddBox(IBoxItemBox* box)
{
	this->boxes.push_back(box);
}

void IBoxPuzzle::AddDestination(IBoxItemDestination* destination)
{
	this->destinations.push_back(destination);
}

void IBoxPuzzle::AddMapLine()
{
	std::vector<int> line;
	this->map.push_back(line);
}

void IBoxPuzzle::AddToMap(int y, int x)
{
	this->map[y].push_back(x);
}

void IBoxPuzzle::AddRobot(IRobot* robot)
{
	this->robot = robot;
}

void IBoxPuzzle::Reset()
{
	this->robot->ResetPosition();
	for (auto box : this->boxes)
	{
		box->ResetPosition();
	}
	this->itemsCollected = 0;
	this->finished = false;
}

bool IBoxPuzzle::CanMove(IBoxItem* item, IBoxItemDirection direction)
{
	COORD nextPosition = this->GetNextPosition(item, direction);
	return (nextPosition.Y > 0 
		&& nextPosition.X > 0 
		&& nextPosition.Y < this->map.size() 
		&& nextPosition.X < this->map[nextPosition.Y].size()) 
		&& this->map[nextPosition.Y][nextPosition.X] == 0;
}

void IBoxPuzzle::PaintLevel()
{
	unsigned int lineCounter;
	COORD start = { 0,0 };
	SetConsoleTextAttribute(game->console, IBoxLevel::defaultText);
	SetConsoleCursorPosition(game->console, start);
	std::cout << this->title << std::endl << "Press R to reset this level.";
	for (auto image : this->image)
	{
		start = { (short)(this->start.X + image->start.X), (short)(this->start.Y + image->start.Y) };
		SetConsoleTextAttribute(game->console, image->color);
		for (lineCounter = 0; lineCounter < image->lines.size(); lineCounter++)
		{
			SetConsoleCursorPosition(game->console, start);
			std::cout << image->lines[lineCounter];
			start.Y++;
		}
	}
}

bool IBoxPuzzle::TheresBoxAt(IBoxItem* item, IBoxItemDirection direction)
{
	COORD nextPosition = this->GetNextPosition(item, direction);
	for (auto box : this->boxes)
	{
		if (box->position.Y == nextPosition.Y && box->position.X == nextPosition.X)
		{
			return true;
		}
	}
	return false;
}

bool IBoxPuzzle::Push(IBoxItemDirection direction)
{
	COORD nextPosition = this->GetNextPosition(this->robot, direction);
	for (auto box : this->boxes)
	{
		if (box->position.Y == nextPosition.Y && box->position.X == nextPosition.X)
		{
			if (!this->TheresBoxAt(box, direction) && this->CanMove(box, direction))
			{
				box->Move(direction);
				this->UpdateStatus();
				return true;
			}
			else
			{
				return false;
			}
			
		}
	}
	return true;
}

COORD IBoxPuzzle::GetNextPosition(IBoxItem* item, IBoxItemDirection direction)
{
	short y = item->position.Y;
	short x = item->position.X;
	switch (direction)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}
	return { x, y };
}

void IBoxPuzzle::UpdateStatus()
{
	this->itemsCollected = 0;
	for (auto destination : this->destinations)
	{
		for (auto box : this->boxes)
		{
			if (destination->position.X == box->position.X && destination->position.Y == box->position.Y 
				&& destination->color == box->color 
				&& destination->shape == box->shape + 1)
			{
				this->itemsCollected++;
			}
		}
	}
	if (this->itemsCollected >= this->destinations.size())
	{
		this->finished = true;
	}
	else
	{
		this->finished = false;
	}
}

void IBoxPuzzle::Input()
{
	Sleep(100);
	if (this->finished)
	{
		if (GetKeyState(VK_RETURN) & 0x8000)
		{
			game->levelManager->ShowNextLevel();
		}
	}
	else
	{
		if (GetKeyState(0x52) & 0x8000)
		{
			this->Reset();
		}
		if (GetKeyState(VK_UP) & 0x8000)
		{
			if (this->CanMove(this->robot, UP))
			{
				if (!this->TheresBoxAt(this->robot, UP) || this->Push(UP))
				{
					this->robot->Move(UP);
				}
			}
		}
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			if (this->CanMove(this->robot, DOWN))
			{
				if (!this->TheresBoxAt(this->robot, DOWN) || this->Push(DOWN))
				{
					this->robot->Move(DOWN);
				}
			}
		}
		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			if (this->CanMove(this->robot, LEFT))
			{
				if (!this->TheresBoxAt(this->robot, LEFT) || this->Push(LEFT))
				{
					this->robot->Move(LEFT);
				}
			}
		}
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			if (this->CanMove(this->robot, RIGHT))
			{
				if (!this->TheresBoxAt(this->robot, RIGHT) || this->Push(RIGHT))
				{
					this->robot->Move(RIGHT);
				}
			}
		}
	}
}

void IBoxPuzzle::Update()
{
	this->PaintLevel();
	for (auto destination : this->destinations)
	{
		SetConsoleTextAttribute(game->console, destination->color);
		SetConsoleCursorPosition(game->console, { (short)(this->start.X + destination->position.X), (short)(this->start.Y + destination->position.Y) });
		std::cout << destination->GetShape();
	}
	for (auto box : this->boxes)
	{
		SetConsoleTextAttribute(game->console, box->color);
		SetConsoleCursorPosition(game->console, { (short)(this->start.X + box->position.X), (short)(this->start.Y + box->position.Y) });
		std::cout << box->GetShape();
	}
	SetConsoleTextAttribute(game->console, this->robot->color);
	SetConsoleCursorPosition(game->console, { (short)(this->start.X + this->robot->position.X), (short)(this->start.Y + this->robot->position.Y) });
	std::cout << this->robot->GetShape();
	if (this->finished)
	{
		unsigned int lineCounter;
		COORD start = { 4,4 };
		std::vector<std::string> frame, text;
		SetConsoleTextAttribute(game->console, 10);
		SetConsoleCursorPosition(game->console, start);
		frame.push_back("###################################################");
		frame.push_back("#                                                 #");
		frame.push_back("#                                                 #");
		frame.push_back("#                                                 #");
		frame.push_back("#                                                 #");
		frame.push_back("#                                                 #");
		frame.push_back("###################################################");

		text.push_back("    LEVEL COMPLETED!!");
		text.push_back("");
		text.push_back("Press ENTER to continue.");
		for (lineCounter = 0; lineCounter < frame.size(); lineCounter++)
		{
			SetConsoleCursorPosition(game->console, start);
			std::cout << frame[lineCounter];
			start.Y++;
		}
		start = {17,6};
		SetConsoleTextAttribute(game->console, 11);
		SetConsoleCursorPosition(game->console, start);
		for (lineCounter = 0; lineCounter < text.size(); lineCounter++)
		{
			SetConsoleCursorPosition(game->console, start);
			std::cout << text[lineCounter];
			start.Y++;
		}
	}
	
}

void IBoxPuzzle::Draw()
{
	this->Reset();
	system("cls");
	this->PaintLevel();
	Sleep(1000);
}

void IBoxPuzzle::Destroy()
{
	for (auto imageElement : this->image)
	{
		delete(imageElement);
	}
	for (auto box : this->boxes)
	{
		delete(box);
	}
	for (auto destination : this->destinations)
	{
		delete(destination);
	}
	delete(this->robot);
}