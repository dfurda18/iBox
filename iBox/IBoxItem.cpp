#include "IBoxItem.h"

IBoxItem::IBoxItem(int color, int shape, COORD position)
{
	this->color = IBoxItem::GetColorEnum(color);
	this->shape = IBoxItem::GetShapeEnum(shape);
	this->position = position;
	this->initialPosition = position;
}
void IBoxItem::ResetPosition()
{
	this->position = this->initialPosition;
}

char IBoxItem::GetShape()
{
	// Needed for the character set
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	switch (this->shape)
	{
	case ROBOT:
		return (char)157;
	case SQUARE:
		return (char)197;
	case SMALL_SQUARE:
		return (char)206;
	case CIRCLE:
		return (char)64;
	case SMALL_CIRCLE:
		return (char)79;
	default:
		return SQUARE;
	}
}

void IBoxItem::Move(IBoxItemDirection direction)
{
	switch (direction)
	{
	case UP:
		this->position.Y--;
		break;
	case DOWN:
		this->position.Y++;
		break;
	case LEFT:
		this->position.X--;
		break;
	case RIGHT:
		this->position.X++;
		break;
	default:
		break;
	}
}
