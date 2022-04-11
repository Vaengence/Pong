#include "PlayerSprite.h"

PlayerSprite::PlayerSprite(const char* SpriteImage, Object oObjectID)
	: BaseSprite(SpriteImage, oObjectID)
{
	if (oObjectID == Object::PLAYER_ONE_SPRITE)
	{
		Point2D oStartPosition;
		int x = (GetScreenWidth() / 2) - this->GetTexture().width / 2;
		int y = (GetScreenHeight() - 50);
		oStartPosition.setXPos(x);
		oStartPosition.setYPos(y);
		this->SetPosition(oStartPosition);
	}
}


void PlayerSprite::Update()
{

}

void PlayerSprite::Draw()
{
	DrawTexture(this->GetTexture(), this->GetPosition().getXPos(), this->GetPosition().getYPos(), RAYWHITE);
}
