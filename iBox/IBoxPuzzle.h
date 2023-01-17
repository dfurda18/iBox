#pragma once
#include <windows.h>
#include <vector>
#include <string>
#include "IBoxLevel.h"
#include "IRobot.h"

/**
* Class that represents a puzzle level.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class IBoxPuzzle : public IBoxLevel {
public:
	/**
	* The lsit of boxes
	*/
	std::vector<IBoxItemBox*> boxes;
	/**
	* The list of destinations
	*/
	std::vector<IBoxItemDestination*> destinations;
	/**
	* The map
	*/
	std::vector<std::vector<int>> map;
	/**
	* A pointer to the robot
	*/
	IRobot* robot;
	/**
	* The amount of items collected
	*/
	int itemsCollected;
	/**
	* A boolean to tell if the game is finished
	*/
	bool finished;

	/**
	* The constructor
	* @param start The start coordinates
	* @return A new instance of the IBoxPuzzle class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	IBoxPuzzle(COORD);

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
	* Resets the level
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Reset();
	/**
	* Checks if an item can move torwards a direction
	* @param item the item to check
	* @param direction The diretion to check
	* @return True if there's no obstacles for the item.
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	bool CanMove(IBoxItem*, IBoxItemDirection);
	/**
	* Paints the leve map
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void PaintLevel();
	/**
	* Checks if there's a box in on a direction from the item
	* @param item The item to check
	* @param direciton The direction to check
	* @return True if there's a box at the direction from the item's position
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	bool TheresBoxAt(IBoxItem*, IBoxItemDirection);
	/**
	* Pushes an item towards a direction form the robot's position
	* @direction The direction to push
	* @return True if the robot was able to push successfully or move.
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	bool Push(IBoxItemDirection);
	/**
	* Gets the next position from an item and a direction
	* @param item The item to get the starting position from
	* @param direction The direction to move to
	* @return The coordinates of the next position.
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	COORD GetNextPosition(IBoxItem*, IBoxItemDirection);
	/**
	* Checks if the level has been completed
	* @param robot The robot to add
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void UpdateStatus();

};