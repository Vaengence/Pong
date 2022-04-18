#ifndef _BALLMANAGER_H_
#define _BALLMANAGER_H_

#include "BallSprite.h"
#include <vector>
#include "Helper.h"
#include "Point2D.h"
#include <math.h>

class BallManager
{
public:
	BallManager();
	void CreateBall(const char* csLocation, Object oObjectType, Point2D oInitVelocity);
	void Update();
	void Draw();
	void HasCollided(std::vector<BallSprite*>::iterator oCollidedBall);
	std::vector<BallSprite*>* GetBalls();
	void HasScored(std::vector<BallSprite*>::iterator oCollidedBall);

private:
	std::vector<BallSprite*> *vBallSpriteArray;
};

#endif