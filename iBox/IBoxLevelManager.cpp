#include <memory>
#include <iostream>
#include <fstream>
#include "json/json.h"
#include "IBoxLevelManager.h"
#include "IBoxPuzzle.h"
#include "IBoxStory.h"
#include "IBox.h"

extern IBox* game;

IBoxLevelManager::IBoxLevelManager(std::string fileName)
{
	bool ok;
	unsigned int levelCounter, textCounter, lineCounter, boxCounter, charCounter;
	int tempColor, tempShape;
	std::string tempString;
	COORD tempCoordinate;
	std::vector<std::string> temptStringArray;

	Json::Value levels;
	Json::String errs;
	Json::CharReaderBuilder builder;
	builder["collectComments"] = false;
	std::ifstream levelsFile(fileName, std::ifstream::binary);

	this->currentLevel = 0;
	this->isFinished = false;

	ok = Json::parseFromStream(builder, levelsFile, &levels, &errs);

	if (ok)
	{
		if (levels.isArray())
		{
			for (levelCounter = 0; levelCounter < levels.size(); levelCounter++)
			{
				if (levels[levelCounter]["type"] == "PUZZLE")
				{
					if (levels[levelCounter]["start"].isArray() 
						&& levels[levelCounter]["start"][0].isInt() 
						&& levels[levelCounter]["start"][1].isInt())
					{
						tempCoordinate = {
								(short)levels[levelCounter]["start"][0].asInt(),
								(short)levels[levelCounter]["start"][1].asInt()
						};
					}
					else
					{
						tempCoordinate = { 0, 0 };
					}
					this->levels.push_back(new IBoxPuzzle(tempCoordinate));
					if (levels[levelCounter]["title"].isString())
					{
						this->levels.back()->title = levels[levelCounter]["title"].asString();
					}
					else
					{
						this->levels.back()->title = "Unknow Level.";
					}
					if (levels[levelCounter]["image"][0]["lines"].isArray())
					{
						for (textCounter = 0; textCounter < levels[levelCounter]["image"][0]["lines"].size(); textCounter++)
						{
							this->levels.back()->AddMapLine();
							tempString = levels[levelCounter]["image"][0]["lines"][textCounter].asString();
							for (charCounter = 0; charCounter < tempString.length(); charCounter++)
							{
								this->levels.back()->AddToMap(textCounter, (tempString[charCounter] == ' ' || tempString[charCounter] == '_') ? 0 : 1);
							}
						}
					}
					if (levels[levelCounter]["boxes"].isArray())
					{
						for (boxCounter = 0; boxCounter < levels[levelCounter]["boxes"].size(); boxCounter++)
						{
							if (levels[levelCounter]["boxes"][boxCounter]["color"].isInt())
							{
								tempColor = levels[levelCounter]["boxes"][boxCounter]["color"].asInt();
							}
							else
							{
								tempColor = IBoxItem::defaultColor;
							}
							if (levels[levelCounter]["boxes"][boxCounter]["shape"].isInt())
							{
								tempShape = levels[levelCounter]["boxes"][boxCounter]["shape"].asInt();
							}
							else
							{
								tempShape = IBoxItem::defaultShape;
							}
							tempCoordinate = {
												(short)levels[levelCounter]["boxes"][boxCounter]["position"][0].asInt(),
												(short)levels[levelCounter]["boxes"][boxCounter]["position"][1].asInt()
							};
							this->levels.back()->AddBox(new IBoxItemBox(tempColor, tempShape, tempCoordinate));
							tempCoordinate = {
												(short)levels[levelCounter]["boxes"][boxCounter]["destination"][0].asInt(),
												(short)levels[levelCounter]["boxes"][boxCounter]["destination"][1].asInt()
							};
							tempShape++;
							this->levels.back()->AddDestination(new IBoxItemDestination(tempColor, tempShape, tempCoordinate));
						}
					}
					if (levels[levelCounter]["initialPosition"].isArray()
						&& levels[levelCounter]["initialPosition"][0].isInt()
						&& levels[levelCounter]["initialPosition"][1].isInt())
					{
						tempCoordinate = {
								(short)levels[levelCounter]["initialPosition"][0].asInt(),
								(short)levels[levelCounter]["initialPosition"][1].asInt()
						};
					}
					else
					{
						tempCoordinate = { 1, 1 };
					}
					this->levels.back()->AddRobot(new IRobot(tempCoordinate));
				}
				else
				{
					this->levels.push_back(new IBoxStory());
					if (levels[levelCounter]["text"].isArray())
					{
						for (textCounter = 0; textCounter < levels[levelCounter]["text"].size(); textCounter++)
						{
							temptStringArray.clear();
							if (levels[levelCounter]["text"][textCounter]["lines"].isArray())
							{
								for (lineCounter = 0; lineCounter < levels[levelCounter]["text"][textCounter]["lines"].size(); lineCounter++)
								{
									temptStringArray.push_back(levels[levelCounter]["text"][textCounter]["lines"][lineCounter].asString());
								}
								this->levels.back()->AddText(new StoryText(levels[levelCounter]["text"][textCounter]["color"].asInt(), temptStringArray));
							}
							else
							{
								std::cout << "ERROR! The text content in level " + std::to_string(levelCounter) + " is not an array.";
							}
						}
					}
					else
					{
						std::cout << "ERROR! The text in level " + std::to_string(levelCounter) + " is not an array.";
					}
				}
				if (levels[levelCounter]["image"].isArray())
				{
					for (textCounter = 0; textCounter < levels[levelCounter]["image"].size(); textCounter++)
					{
						temptStringArray.clear();
						if (levels[levelCounter]["image"][textCounter]["lines"].isArray())
						{
							for (lineCounter = 0; lineCounter < levels[levelCounter]["image"][textCounter]["lines"].size(); lineCounter++)
							{
								temptStringArray.push_back(levels[levelCounter]["image"][textCounter]["lines"][lineCounter].asString());
							}
							tempCoordinate = {
												(short)levels[levelCounter]["image"][textCounter]["start"][0].asInt(),
												(short)levels[levelCounter]["image"][textCounter]["start"][1].asInt()
							};
							this->levels.back()->AddImage(new StoryImage(
								levels[levelCounter]["image"][textCounter]["color"].asInt(),
								tempCoordinate,
								temptStringArray)
							);
						}
						else
						{
							std::cout << "ERROR! The text content in level " + std::to_string(levelCounter) + " is not an array.";
						}

					}
				}
				else
				{
					std::cout << "ERROR! The image in level " + std::to_string(levelCounter) + " is not an array.";
				}
			}
		}
	}
	else
	{
		std::cout << "ERROR! The Json Wasn's parsed correctly.";
	}
}

void IBoxLevelManager::Input()
{
	this->levels[this->currentLevel]->Input();
}

void IBoxLevelManager::Update()
{
	this->levels[this->currentLevel]->Update();
}

void IBoxLevelManager::Destroy()
{
	for (auto level : this->levels)
	{
		level->Destroy();
		delete(level);
	}
}

void IBoxLevelManager::ShowFirstLevel()
{
	this->currentLevel = 0;
	this->isFinished = false;
	this->ShowLevel();
}

void IBoxLevelManager::ShowNextLevel()
{
	this->currentLevel++;
	this->ShowLevel();
}

void IBoxLevelManager::ShowLevel()
{
	if (this->currentLevel >= this->levels.size())
	{
		this->isFinished = true;
	}
	else
	{
		this->levels[this->currentLevel]->Draw();
	}
}