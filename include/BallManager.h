#ifndef _BALLMANAGER_H_
#define _BALLMANAGER_H_

#include "BallSprite.h"
#include "ObjectManager.h"
#include "ResourceManager.h"
#include <vector>
#include "Helper.h"
#include "Point2D.h"
#include <math.h>
#include <string>


class BallManager : public ObjectManager
{
public:
	BallManager(ResourceManager* oResources);
	void CreateBall();
	void HasCollided(std::vector<BallSprite*>::iterator oCollidedBall);
	void HasScored(std::vector<BallSprite*>::iterator oCollidedBall);

	std::vector<BallSprite*>* GetBalls();

	void InitialiseLevel(int level) override;
	void Update() override;
	void Draw() override;
	void Collisions() override;

private:
	std::vector<BallSprite*> *vBallSpriteArray;
	ResourceManager* oResources;
	int iGameLevel;
};

#endif