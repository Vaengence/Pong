#include "BallSprite.h"


BallSprite::BallSprite(const char* SpriteImage, Object oObjectID)
	: BaseSprite(SpriteImage, oObjectID)
{
	Point2D oStartPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	this->SetPosition(oStartPosition);
}

void BallSprite::Update()
{


}
