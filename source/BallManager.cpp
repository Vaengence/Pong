#include "BallManager.h"

BallManager::BallManager()
{

}

void BallManager::CreateBall(const char* csLocation, Object oObjectType, Point2D oInitVelocity)
{
	this->vBallSpriteArray.push_back(new BallSprite(csLocation, oObjectType, oInitVelocity));
}

void BallManager::Update()
{
    for (std::vector<BallSprite*>::iterator iter = vBallSpriteArray.begin(); iter != vBallSpriteArray.end(); iter++)
    {
        (*iter)->Update();
    }
}

void BallManager::Draw()
{
    for (std::vector<BallSprite*>::iterator iter = vBallSpriteArray.begin(); iter != vBallSpriteArray.end(); iter++)
    {
        (*iter)->Draw();
    }
}

std::vector<BallSprite*> BallManager::GetBalls()
{
    return vBallSpriteArray;
}

void BallManager::HasCollided(const std::vector<BallSprite*>::iterator oCollidedBall)
{
    Point2D oCurrentVelocity = (*oCollidedBall)->GetVelocity();

    oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() * -1);
    (*oCollidedBall)->SetVelocity(oCurrentVelocity);
}
