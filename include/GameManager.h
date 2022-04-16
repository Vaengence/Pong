#ifndef _GAMEMANEGER_H_
#define _GAMEMANAGER_H_

#include "ResourceManager.h"
#include <raylib.h>
#include "Helper.h"
#include "BallSprite.h"
#include "PlayerSprite.h"

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
	std::vector<PlayerSprite*> vPlayerSpriteArray;
	std::vector<BallSprite*> vBallSpriteArray;

};

#endif // !_POINT2D_H_