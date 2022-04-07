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
	InitWindow(this->screenWidth, this->screenHeight, this->title);

	SetTargetFPS(60);
}