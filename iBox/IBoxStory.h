#pragma once

#include <windows.h>
#include <vector>
#include <string>
#include "IBoxLevel.h"
#include "StoryText.h"
#include "StoryImage.h"
#include "IRobot.h"

/**
* Class that represents a story level.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class IBoxStory : public IBoxLevel {
public:
	/**
	* The story text
	*/
	std::vector<StoryText*> text;

	/**
	* The constructor
	* @return A new instance of the IBoxStory class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	IBoxStory();

	/**
	* Adds text to the level
	* @param text The text to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void AddText(StoryText*);
	/**
	* Adds the image to the level
	* @param image The image to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void AddImage(StoryImage*);
	/**
	* Adds the boxes to the level
	* @param boxes The boxes to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void AddBox(IBoxItemBox*);
	/**
	* Adds the destinations to the level
	* @param destinations The image to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void AddDestination(IBoxItemDestination*);
	/**
	* Adds a line to the map
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void AddMapLine();
	/**
	* Adds an element to the map
	* @param y The line to insert the element
	* param x The element to insert
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void AddToMap(int, int);
	/**
	* Adds the robot to the level
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void AddRobot(IRobot*);
	/**
	* Checks for input
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Input();
	/**
	* Updates the level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Update();
	/**
	* Draws the level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Draw();
	/**
	* Deconstructs the level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Destroy();
};