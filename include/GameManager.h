#ifndef _GAMEMANEGER_H_
#define _GAMEMANAGER_H_

#include "ResourceManager.h"
#include <raylib.h>
#include "Helper.h"

class GameManager
{
public:

	GameManager();
	~GameManager();
	void StartGame();
	void GameLoop();
	void Update();
	bool CollissionCheck();
	void Draw();

private:

	ResourceManager *oResources;
	GameState oCurrentGameState;

};

#endif // !_POINT2D_H_