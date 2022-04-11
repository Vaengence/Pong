#ifndef _GAMEMANEGER_H_
#define _GAMEMANAGER_H_

#include "ResourceManager.h"
#include <raylib.h>

class GameManager
{
public:

	GameManager();
	~GameManager();
	void StartGame();
	void GameLoop();
	void Update();
	void Draw();

private:

	ResourceManager *oResources;

};

#endif // !_POINT2D_H_