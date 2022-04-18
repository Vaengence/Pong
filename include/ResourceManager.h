#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include <vector>
#include <string>
#include <fstream>
#include "BaseSprite.h"
#include "Helper.h"
#include <random>
#include "PlayerSprite.h"
#include "BallManager.h"
#include <unordered_map>

class BaseSprite;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void InitialisePlayingScreen();
	void ImportData(std::vector<PlayerSprite*> *oPlayerSprites, BallManager *oBallManager);
	float RandomGenerator();
	void ImportSounds();
	void PlayGameSound(GameSoundType oSoundToPlay);


private:

	int screenWidth;
	int screenHeight;
	std::string gameTitle;
	std::string spritesFile;
	std::string soundsFile;
	std::unordered_map<GameSoundType, Sound> mGameSounds;
};

#endif // !_RESOURCEMANAGER_H_