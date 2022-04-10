#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void InitialisePlayingScreen();

	enum Object
	{
		PLAYER_ONE_SPRITE,
		PLAYER_TWO_SPRITE,
		BALL
	};


private:

	int screenWidth;
	int screenHeight;
	const char* title[];
};

#endif // !_RESOURCEMANAGER_H_