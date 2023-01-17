#pragma once
#include <vector>
#include <string>
#include "IBoxLevel.h"

/**
* Class that represents a level manager.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class IBoxLevelManager {
private:
	/**
	* The list of levels
	*/
	std::vector<IBoxLevel*> levels;
	/** 
	* The current level
	*/
	unsigned int currentLevel;
	
public:
	/**
	* A boolean to tell if all the levels are finished
	*/
	bool isFinished;

	/**
	* The constructor
	* @param fileName The json file to load the levels from
	* @return A new instance of the IBoxLevelManager class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	IBoxLevelManager(std::string);

	/**
	* Checks for input
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Input();
	/**
	* Updates the levels
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Update();
	/**
	* Deconstructs the level manager
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Destroy();

	/**
	* Shows the first level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void ShowFirstLevel();
	/**
	* Shows the next level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void ShowNextLevel();
	/**
	* Shows the current level
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void ShowLevel();
};