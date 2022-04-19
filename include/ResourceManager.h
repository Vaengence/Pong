#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include <vector>
#include <string>
#include <fstream>
#include "Helper.h"
#include <random>
#include <unordered_map>
#include <string>
#include <raylib.h>

class BaseSprite;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void InitialisePlayingScreen();
	void ImportData();
	float RandomGenerator();
	void ImportSounds();
	void PlayGameSound(GameSoundType oSoundToPlay);
	Texture2D CreateTexture(Object oTypeToCreate);


private:

	int screenWidth;
	int screenHeight;
	std::string gameTitle;
	std::string spritesFile;
	std::string soundsFile;
	std::unordered_map<GameSoundType, Sound> mGameSounds;
	std::unordered_map<Object, std::string> mGameTextures;
};

#endif // !_RESOURCEMANAGER_H_