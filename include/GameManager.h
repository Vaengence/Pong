#ifndef _GAMEMANEGER_H_
#define _GAMEMANAGER_H_

#include "ResourceManager.h"
#include <raylib.h>
#include "Helper.h"
#include "PlayerSprite.h"
#include "Rect.h"
#include <iterator>
#include "BallManager.h"

class GameManager
{
public:

	GameManager();
	~GameManager();
	void StartGame();
	void GameLoop();
	void Update();
	void RunCollisions();
	void Draw();

	bool Goal(BallSprite* oCurrentBall);
	bool CollisionCheck(PlayerSprite* oCurrentPlayer, BallSprite* oCurrentBall);

private:

	ResourceManager *oResources;
	GameState oCurrentGameState;
	std::vector<PlayerSprite*> vPlayerSpriteArray;
	BallManager *oBallManager;

};

#endif // !_POINT2D_H_