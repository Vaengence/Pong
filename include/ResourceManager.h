#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include <vector>
#include <string>
#include <fstream>
#include "BaseSprite.h"
#include "Helper.h"
#include <random>

class BaseSprite;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void InitialisePlayingScreen();
	void ImportData();
	const std::vector<BaseSprite*> GetSprites();
	float RandomGenerator(float fLow, float fHigh);


private:

	int screenWidth;
	int screenHeight;
	std::string gameTitle;
	std::string spritesFile;
	std::vector<BaseSprite*> vSpriteArray;
};

#endif // !_RESOURCEMANAGER_H_