#include "ResourceManager.h"
#include <raylib.h>
#include <iostream>
#include <sstream>
#include "PlayerSprite.h"
#include "BallSprite.h"
#include <algorithm>
#include "Helper.h"


ResourceManager::ResourceManager()
	: screenWidth{800}
	, screenHeight{450}
	, gameTitle{"Slightly OK Pong Clone"}
	, spritesFile{"./resources/data/sprites.txt"}
	, soundsFile{"./resources/data/sounds.txt"}
{

}

void ResourceManager::InitialisePlayingScreen()
{
	const char* gameTitle = this->gameTitle.c_str();
	InitWindow(this->screenWidth, this->screenHeight, gameTitle);
	InitAudioDevice();
	SetTargetFPS(60);

}

void ResourceManager::ImportData(std::vector<PlayerSprite*>* oPlayerSprites, BallManager* oBallManager)
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
				oPlayerSprites->push_back(new PlayerSprite(sLocationTemp.c_str(), input));
				break;
			}

		case Object::PLAYER_TWO_SPRITE:
			{
				oPlayerSprites->push_back(new PlayerSprite(sLocationTemp.c_str(), input));
				break;
			}

		case Object::BALL:
			{
			Point2D oInitVelocity = { RandomGenerator(), RandomGenerator() };
				oBallManager->CreateBall(sLocationTemp.c_str(), input, oInitVelocity);
				break;
			}

		}
		
	}

	ifsSprites.close();

}

void ResourceManager::ImportSounds()
{
	//Code to read in Sound Data
	std::ifstream ifsSounds;
	try
	{
		ifsSounds.open(soundsFile.c_str());
	}
	catch (...)
	{
		std::cout << "There was a problem loading the Sounds file" << '\n'; // To catch if the file is missing, won't open etc
		exit(EXIT_FAILURE);
	}


	// Imports Sounds and add them to game sound array
	int sTypeTemp;
	std::string sTempString;
	std::string sLocationTemp;
	std::stringstream ssTempStream;

	while (!ifsSounds.eof())
	{
		std::getline(ifsSounds, sTempString);
		ssTempStream << sTempString;
		ssTempStream >> sTypeTemp >> sLocationTemp;
		ssTempStream.str("");
		ssTempStream.clear();

		GameSoundType input = (GameSoundType)sTypeTemp;
		Sound tempSound = LoadSound(sLocationTemp.c_str());

		mGameSounds.insert({input, tempSound});

	}

	ifsSounds.close();
}



float ResourceManager::RandomGenerator()
{
	std::random_device randomDevice;
	std::default_random_engine randomGenerator(randomDevice());
	std::uniform_real_distribution<float> distribution(-3.0f, 3.0f);

	return distribution(randomDevice);

}

void ResourceManager::PlayGameSound(GameSoundType oSoundToPlay)
{
	
	PlaySound(mGameSounds.at(oSoundToPlay));
}

ResourceManager::~ResourceManager()
{

}