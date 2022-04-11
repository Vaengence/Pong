#include "PlayerSprite.h"

PlayerSprite::PlayerSprite(const char* SpriteImage, Object oObjectID)
	: BaseSprite(SpriteImage, oObjectID)
{
	if (oObjectID == Object::PLAYER_ONE_SPRITE)
	{
		Point2D oStartPosition = (GetScreenWidth() / 2, GetScreenHeight() + 20);
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
