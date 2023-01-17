#pragma once
#include <vector>
#include <string>

/**
* Class that represent a story text
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class StoryText {
public:
	/**
	* The text color
	*/
	int color;
	/**
	* The text content
	*/
	std::vector<std::string> lines;
	/**
	* Cosntructor method
	* @param color The text color
	* @param lines The text content
	* @return A new instance of the StoryText class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	StoryText(int, std::vector<std::string>);
};