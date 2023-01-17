#include "StoryImage.h"

StoryImage::StoryImage(int color, COORD start, std::vector<std::string> lines)
{
	this->color = color;
	this->start = start;
	this->lines = lines;
}