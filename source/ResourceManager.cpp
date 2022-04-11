#include "ResourceManager.h"
#include <raylib.h>
#include <iostream>
#include <sstream>
#include "PlayerSprite.h"


ResourceManager::ResourceManager()
	: screenWidth{800}
	, screenHeight{450}
	, gameTitle{"Slightly OK Pong Clone"}
	, spritesFile{"./resources/data/sprites.txt"}
{

}

void ResourceManager::InitialisePlayingScreen()
{
	const char* gameTitle = this->gameTitle.c_str();
	InitWindow(this->screenWidth, this->screenHeight, gameTitle);
	SetTargetFPS(60);

}

void ResourceManager::ImportData()
{
	//Code to read in Sprite Data. Not so useful with three sprites, intended to be expandable. 
	std::ifstream ifsSprites;
	try
	{
		ifsSprites.open(spritesFile.c_str());
	}
	catch (...)
	{
		std::cout << "There was a problem loading the Sprites file" << '\n'; // To catch if the file is missing, won't open etc
		exit(EXIT_FAILURE);
	}


	// Imports Sprites and creates sprites based on listed sprite type in associated file and Object enum. 
	int sTypeTemp;
	std::string sTempString;
	std::string sLocationTemp;
	std::stringstream ssTempStream;

	while (!ifsSprites.eof())
	{
		std::getline(ifsSprites, sTempString);
		ssTempStream << sTempString;
		ssTempStream >> sTypeTemp >> sLocationTemp;
		ssTempStream.str("");
		ssTempStream.clear();

		Object input = (Object)sTypeTemp;

		switch (input)
		{
		case Object::PLAYER_ONE_SPRITE:
			{
				BaseSprite a = PlayerSprite(sLocationTemp.c_str(), input);
				this->vSpriteArray.push_back(&a);
				break;
			}

		case Object::PLAYER_TWO_SPRITE:
			{
				BaseSprite b = PlayerSprite(sLocationTemp.c_str(), input);
				this->vSpriteArray.push_back(&b);
				break;
			}

		case Object::BALL:
			{
				BaseSprite c = PlayerSprite(sLocationTemp.c_str(), input);
				this->vSpriteArray.push_back(&c);
				break;
			}

		}
		
	}

	ifsSprites.close();

}

ResourceManager::~ResourceManager()
{

}