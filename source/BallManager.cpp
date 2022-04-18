#include "BallManager.h"

BallManager::BallManager()
{
    vBallSpriteArray = new std::vector<BallSprite*>;
}

void BallManager::CreateBall(const char* csLocation, Object oObjectType, Point2D oInitVelocity)
{
	vBallSpriteArray->push_back(new BallSprite(csLocation, oObjectType, oInitVelocity));
}

void BallManager::Update()
{
    for (std::vector<BallSprite*>::iterator iter = vBallSpriteArray->begin(); iter != vBallSpriteArray->end(); iter++)
    {
        (*iter)->Update();
    }
}

void BallManager::Draw()
{
    for (std::vector<BallSprite*>::iterator iter = vBallSpriteArray->begin(); iter != vBallSpriteArray->end(); iter++)
    {
        (*iter)->Draw();
    }
}

std::vector<BallSprite*>* BallManager::GetBalls()
{
    return vBallSpriteArray;
}

void BallManager::HasCollided(const std::vector<BallSprite*>::iterator oCollidedBall)
{
    Point2D oCurrentVelocity = (*oCollidedBall)->GetVelocity();
    oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() * -1);

    if (signbit(oCurrentVelocity.getXPos()))
    {
        oCurrentVelocity.setXPos(oCurrentVelocity.getXPos() - 0.1);
    }
    else
    {
        oCurrentVelocity.setXPos(oCurrentVelocity.getXPos() + 0.1);
    }

    if (signbit(oCurrentVelocity.getYPos()))
    {
        oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() - 0.1);
    }
    else
    {
        oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() + 0.1);
    }

    (*oCollidedBall)->SetVelocity(oCurrentVelocity);
}

void BallManager::HasScored(std::vector<BallSprite*>::iterator oCollidedBall)
{
    //(*oCollidedBall)->SetPosition();
    //(*oCollidedBall)->SetVelocity();
    //(*oCollidedBall)->get

}
