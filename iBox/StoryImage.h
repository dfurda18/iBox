#pragma once

#include <vector>
#include <string>
#include <windows.h>

/**
* Class that represents a story image.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class StoryImage {
public:
	/**
	* The image color
	*/
	int color;
	/**
	* The image position
	*/
	COORD start;
	/**
	* The image content
	*/
	std::vector<std::string> lines;
	/**
	* Constructor method
	* @param color The image color
	* @param position The image position
	* @param content The image content
	*/
	StoryImage(int, COORD, std::vector<std::string>);
};