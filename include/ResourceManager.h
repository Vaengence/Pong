#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include <vector>
#include <string>
#include <fstream>
#include "BaseSprite.h"
#include "Helper.h"
#include <random>
#include "PlayerSprite.h"
#include "BallSprite.h"

class BaseSprite;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void InitialisePlayingScreen();
	void ImportData(std::vector<PlayerSprite*> *oPlayerSprites, std::vector<BallSprite*> *oBallSprites);
	float RandomGenerator();


private:

	int screenWidth;
	int screenHeight;
	std::string gameTitle;
	std::string spritesFile;
};

#endif // !_RESOURCEMANAGER_H_