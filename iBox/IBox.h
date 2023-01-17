#pragma once

#include <windows.h>
#include <vector>
#include <string>
#include "IBoxLevelManager.h"

/**
* Enum that represents the game state
*/
enum GameState { START, CONTROLS, CREDITS, PLAYING, GAMEOVER };

/**
* Class IBox that represents the IBox game.
* @author Dario Urdapilleta
* @since January 2nd 2022
* @version 1.0
*/
class IBox {
private:
	/**
	* Enum that represents the color scheme
	*/
	enum Colors { DEFAULT = 7, FRAME = 10, INSTRUCTIONS = 11, TITLE = 6, SELECTED_INSTRUCTION = 176, OCEAN = 1, LAND = 6, MARKS = 8, MARKS_VISITED = 4, CURRENT_POSITION = 20, SELECTED_NEIGHBOUR = 185 };
	/**
	* The Game state
	*/
	GameState gameState;
	/**
	* The menu options
	*/
	std::vector<std::string> mainMenuOptions;
	/**
	* The currently selected menu option.
	*/
	unsigned int mainMenuSelection;

public:
	/**
	* The level manager
	*/
	IBoxLevelManager* levelManager;
	/**
	* The Windows Console
	*/
	HANDLE console;
	/**
	* Tells the game to shut off
	*/
	bool running;
	/**
	* Constructor by default
	* @return A new instance of the IBox class
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	IBox();
	/**
	* Loads all the game elements
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Init();
	/**
	* Listens to the user input
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Input();
	/**
	* It is calld every game loop
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Update();
	/**
	* Updates the game graphically
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Draw();
	/**
	* Deecosntructor
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void Destroy();

	void ShowTitle();
	/**
	* Shows the control screen
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void ShowControls();
	/**
	* Shows the Credits screen
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void ShowCredits();
	/**
	* Starts a new game
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void StartGame();
	/**
	* Shows the Game Over screen,
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void ShowGameOver();
	/**
	* Renders the main menu items
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void RenderMainMenu();
	/**
	* Paints a square frame
	* @param start The position
	* @param size The size
	* @param color The color of the frame
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void PaintFrame(COORD, COORD, Colors);
	/**
	* Paints a block of text
	* @param content The text to paint
	* @param start The position to paint it
	* @param colot The color to paint it
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void PaintBlock(std::vector<std::string>, COORD, Colors);
	/**
	* Paints the main maneu with the proper selected item
	* @param content The menu options
	* @param start The initial position
	* @param color The unselected element color
	* @param selectedColor The selected element color
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void PaintMenu(std::vector<std::string>, COORD, int, Colors, Colors);
	/**
	* Hides the console cursor.
	* @author Dario Urdapilleta
	* @since January 2nd 2022
	* @version 1.0
	*/
	void HideCursor();
};