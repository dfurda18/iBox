#pragma once

#include <windows.h>
#include <vector>
#include <string>
#include "IBoxItem.h"

/**
* Class that represents a box.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class IBoxItemBox : public IBoxItem {
public:
	/**
	* The constructor
	* @param color The item color
	* @param shape The item shape
	* @param position The item position
	* @return A new instance of the IBoxItemBox class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	IBoxItemBox(int, int, COORD);
};