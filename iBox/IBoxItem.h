#pragma once

#include <vector>
#include <string>
#include <windows.h>

/**
* The enum for the item colors
*/
enum IBoxItemColor { SIX = 6, SEVEN = 7, ROBOT_COLOR = 9};
/**
* The enum for the shapes
*/
enum IBoxItemShape { ROBOT = 0, SQUARE = 1, SMALL_SQUARE = 2, CIRCLE = 4, SMALL_CIRCLE = 5};
/**
* The enum for the moving directions
*/
enum IBoxItemDirection { UP, DOWN, LEFT, RIGHT };

/**
* Class that represents a game item.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class IBoxItem {
public:
	/**
	* The default color of an item
	*/
	static const int defaultColor = 6;
	/**
	* The default shape of an item
	*/
	static const int defaultShape = 0;
	/**
	* The colors
	*/
	IBoxItemColor color;
	/**
	* The shape
	*/
	IBoxItemShape shape;
	/**
	* The position
	*/
	COORD position;
	/**
	* The initial position
	*/
	COORD initialPosition;
	/**
	* The constructor method
	* @param color The item color
	* @param shape The item shape
	* @param position The item position
	* @return A new instance of the IBoxItem class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	IBoxItem(int, int, COORD);
	/**
	* Resets the item to its initial position
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void ResetPosition();
	/**
	* Returns the items shape
	* @return The character with the corresponding shape
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	char GetShape();
	/**
	* Moves the item towards a direction
	* @param direction The direction that the item will move.
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Move(IBoxItemDirection);
	/**
	* Gets the color enum from an int
	* @param color The number of the enum
	* @return The correcponding enum value
	*/
	static IBoxItemColor GetColorEnum(int color)
	{
		switch (color)
		{
		case 6:
			return SIX;
		case 7:
			return SEVEN;
		default:
			return SEVEN;
		}
	}
	/**
	* Gets the shape enum from an int
	* @param shape The int that represents the shape
	* @return The corresponding enum
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	static IBoxItemShape GetShapeEnum(int shape)
	{
		switch (shape)
		{
		case 0:
			return ROBOT;
		case 1:
			return SQUARE;
		case 2:
			return SMALL_SQUARE;
		case 3:
			return CIRCLE;
		case 4:
			return SMALL_CIRCLE;
		default:
			return SQUARE;
		}
	}
};
