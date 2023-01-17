#pragma once

#include <windows.h>
#include <vector>
#include <string>
#include "IBoxItem.h"

/**
* Class that represents a robot.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class IRobot : public IBoxItem {
public:
	/**
	* The robot degault color
	*/
	static const IBoxItemColor defaultColor = ROBOT_COLOR;
	/**
	* The Robot default shape
	*/
	static const IBoxItemShape defaultShape = ROBOT;
	/**
	* Constructor method
	* @param start The starting position
	* @return A new instance of the IRobot class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	IRobot(COORD);
	

};