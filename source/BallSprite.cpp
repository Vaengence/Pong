#include "BallSprite.h"


BallSprite::BallSprite(const char* SpriteImage, Object oObjectID, Point2D oInitVelocity)
	: BaseSprite(SpriteImage, oObjectID)
{
	Point2D oStartPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	this->SetPosition(oStartPosition);
	this->SetVelocity(oInitVelocity);
}

void BallSprite::Update()
{
	Point2D oCurrentPosition = this->GetPosition();
	Point2D oCurrentVelocity = this->GetVelocity();

	KeepInPlay(&oCurrentPosition, &oCurrentVelocity);

	this->SetVelocity(oCurrentVelocity);
	this->SetPosition(oCurrentPosition + oCurrentVelocity);



}

void BallSprite::KeepInPlay(Point2D * oCurrentPosition, Point2D * oCurrentVelocity)
{
	if (oCurrentPosition->getXPos() + oCurrentVelocity->getXPos() < 0 || oCurrentPosition->getXPos() + oCurrentVelocity->getXPos() > GetScreenWidth() - this->GetTexture().width)
	{
		oCurrentVelocity->setXPos(oCurrentVelocity->getXPos() * -1);
	}
}
