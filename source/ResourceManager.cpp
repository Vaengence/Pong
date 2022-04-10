#include "ResourceManager.h"
#include <raylib.h>

ResourceManager::ResourceManager()
	: screenWidth{800}
	, screenHeight{450}
	, title{"Slightly OK Pong Clone"}
{

}

void ResourceManager::InitialisePlayingScreen()
{
	InitWindow(this->screenWidth, this->screenHeight, *title);

	SetTargetFPS(60);
}

ResourceManager::~ResourceManager()
{

}