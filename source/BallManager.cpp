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
    Point2D oTempVelocity = { 
        oResources->RandomGenerator() + iGameLevel, 
        oResources->RandomGenerator() + iGameLevel };
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


void BallManager::HasCollided(const std::vector<BallSprite*>::iterator oCollidedBall)
{
    Point2D oCurrentVelocity = (*oCollidedBall)->GetVelocity();
    oCurrentVelocity.setYPos(oCurrentVelocity.getYPos() * -1);

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
