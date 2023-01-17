#pragma once

#include <windows.h>
#include "StoryText.h"
#include "StoryImage.h"
#include "IBoxItemBox.h"
#include "IBoxItemDestination.h"
#include "IRobot.h"

/**
* Enum with the type of levels
*/
enum IBoxLevelType { STORY, PUZZLE };

/**
* Class that represents a level.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class IBoxLevel {
public:
	/**
	* The default text color
	*/
	static const int defaultText = 7;
	/**
	* The level type
	*/
	IBoxLevelType type;
	/**
	* The starting coordinates
	*/
	COORD start;
	/**
	* The level title
	*/
	std::string title;
	/**
	* The list of images
	*/
	std::vector<StoryImage*> image;
	/**
	* The constructor
	* @param type The level type
	* @param start The start coordinates
	* @return A new instance of the IBoxLevel class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	IBoxLevel(IBoxLevelType type, COORD start)
	{
		this->type = type;
		this->start = start;
	}
	/**
	* Adds text to the level
	* @param text The text to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void AddText(StoryText*) = 0;
	/**
	* Adds the image to the level
	* @param image The image to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void AddImage(StoryImage* image)
	{
		this->image.push_back(image);
	}
	/**
	* Adds the boxes to the level
	* @param boxes The boxes to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void AddBox(IBoxItemBox*) = 0;
	/**
	* Adds the destinations to the level
	* @param destinations The image to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void AddDestination(IBoxItemDestination*) = 0;
	/**
	* Adds a line to the map
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void AddMapLine() = 0;
	/**
	* Adds an element to the map
	* @param y The line to insert the element
	* param x The element to insert
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void AddToMap(int, int) = 0;
	/**
	* Adds the robot to the level
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void AddRobot(IRobot*) = 0;
	/**
	* Checks for input
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void Input() = 0;
	/** 
	* Updates the level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void Update() = 0;
	/**
	* Draws the level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void Draw() = 0;
	/**
	* Deconstructs the level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	virtual void Destroy() = 0;
};