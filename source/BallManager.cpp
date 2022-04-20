#include "BallManager.h"

BallManager::BallManager(ResourceManager* oResources)
    : oResources{oResources}
{
    vBallSpriteArray = new std::vector<BallSprite*>;
}

void BallManager::InitialiseLevel(int level)
{
    this->iGameLevel = level;

    for (int i = 0; i < iGameLevel; i++)
    {
        CreateBall();    
    }
}

void BallManager::CreateBall()
{
    
    Texture2D tTempTexture = oResources->CreateTexture(Object::BALL);
    Point2D oTempVelocity;

    float fTempX = oResources->RandomGenerator();
    float fTempY = oResources->RandomGenerator();

    if (!signbit(fTempX))
        fTempX = fTempX + iGameLevel;
    else
        fTempX = fTempX - iGameLevel;

    if (!signbit(fTempY))
        fTempY = fTempY + iGameLevel;
    else
        fTempY = fTempY - iGameLevel;

    oTempVelocity = { fTempX, fTempY };


    vBallSpriteArray->push_back(new BallSprite(tTempTexture, Object::BALL, oTempVelocity));

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


void BallManager::HasCollided(const std::vector<BallSprite*>::iterator oCollidedBall, CollisionType sCollisionType, Point2D oPlayerVelocity)
{
    Point2D oCurrentVelocity = (*oCollidedBall)->GetVelocity();
   // Point2D oCurrentPosition = (*oCollidedBall)->GetPosition();

    switch (sCollisionType)
    {
    case CollisionType::STANDARD:
        //Sets the ball to reverse the Y direction on hitting a paddle
        oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() * -1);
        break;

    case CollisionType::PLAYER_LEFT_SIDE:
        if (!signbit(oCurrentVelocity.getXPos()) && signbit(oPlayerVelocity.getXPos()))
        {
            oCurrentVelocity.setXPos(oCurrentVelocity.getXPos() * -1);
        }

        if (signbit(oCurrentVelocity.getXPos()) && signbit(oPlayerVelocity.getXPos()))
        {
            oCurrentVelocity.setXPos(oCurrentVelocity.getXPos() + oPlayerVelocity.getXPos() / 4);
        }

        break;

    case CollisionType::PLAYER_RIGHT_SIDE:
        //Sets the ball to reverse the X direction on hitting a paddle
        if (signbit(oCurrentVelocity.getXPos()) && !signbit(oPlayerVelocity.getXPos()))
        {
            oCurrentVelocity.setXPos(oCurrentVelocity.getXPos() * -1);
        }

        if (!signbit(oCurrentVelocity.getXPos()) && !signbit(oPlayerVelocity.getXPos()))
        {
            oCurrentVelocity.setXPos(oCurrentVelocity.getXPos() + oPlayerVelocity.getXPos() / 4);
        }

        break;
    }

    //These statements speed up the ball by a little bit each time it hits a paddle
    if (signbit(oCurrentVelocity.getXPos()))
    {
        oCurrentVelocity.setXPos(oCurrentVelocity.getXPos() - 0.1f);
    }
    else
    {
        oCurrentVelocity.setXPos(oCurrentVelocity.getXPos() + 0.1f);
    }

    if (signbit(oCurrentVelocity.getYPos()))
    {
        oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() - 0.1f);
    }
    else
    {
        oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() + 0.1f);
    }

   // (*oCollidedBall)->SetPosition(oCurrentPosition);
    (*oCollidedBall)->SetVelocity(oCurrentVelocity);
}

void BallManager::HasScored(std::vector<BallSprite*>::iterator oCollidedBall)
{
    vBallSpriteArray->erase(oCollidedBall);
    CreateBall();

}

void BallManager::Collisions()
{

}
