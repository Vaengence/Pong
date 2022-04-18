#ifndef _BALLMANAGER_H_
#define _BALLMANAGER_H_

#include "BallSprite.h"
#include <vector>
#include "Helper.h"
#include "Point2D.h"

class BallManager
{
public:
	BallManager();
	void CreateBall(const char* csLocation, Object oObjectType, Point2D oInitVelocity);
	void Update();
	void Draw();
	void HasCollided(const std::vector<BallSprite*>::iterator oCollidedBall);
	std::vector<BallSprite*> GetBalls();

private:
	std::vector<BallSprite*> vBallSpriteArray;
};

#endif