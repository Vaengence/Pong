#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include <vector>
#include <string>
#include <fstream>
#include "BaseSprite.h"
#include "Enums.h"

class BaseSprite;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void InitialisePlayingScreen();
	void ImportData();
	const std::vector<BaseSprite*> GetSprites();


private:

	int screenWidth;
	int screenHeight;
	std::string gameTitle;
	std::string spritesFile;
	std::vector<BaseSprite*> vSpriteArray;
	
};

#endif // !_RESOURCEMANAGER_H_