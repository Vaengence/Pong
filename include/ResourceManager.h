#pragma once

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	void InitialisePlayingScreen();


private:

	int screenWidth;
	int screenHeight;
	const char* title[];
};

