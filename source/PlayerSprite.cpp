#include "PlayerSprite.h"

PlayerSprite::PlayerSprite(Texture2D oSpriteTexture, Object oObjectID)
	: BaseSprite(oSpriteTexture, oObjectID)
{
	// Sets initial values for the Player One on import
	if (oObjectID == Object::PLAYER_ONE_SPRITE)
	{
		Point2D oStartPosition;
		int x = (GetScreenWidth() / 2) - this->GetTexture().width / 2;
		int y = (GetScreenHeight() - 50);
		oStartPosition.setXPos((float)x);
		oStartPosition.setYPos((float)y);
		this->SetPosition(oStartPosition);
	}

	if (oObjectID == Object::PLAYER_TWO_SPRITE)
	{
		Point2D oStartPosition;
		int x = (GetScreenWidth() / 2) - this->GetTexture().width / 2;
		int y = (50);
		oStartPosition.setXPos((float)x);
		oStartPosition.setYPos((float)y);
		this->SetPosition(oStartPosition);
	}
}


void PlayerSprite::Update()
{
	// Controls for Left and Right movement of Player one

	if (this->GetObjectID() == Object::PLAYER_ONE_SPRITE)
	{
		if (IsKeyDown(KEY_A))
		{
			Point2D oCurrentVelocity = this->GetVelocity();
			oCurrentVelocity.setXPos(-8.0f);
			this->SetVelocity(oCurrentVelocity);
		}

		if (IsKeyReleased(KEY_A))
		{
			Point2D oCurrentVelocity = this->GetVelocity();
			oCurrentVelocity.setXPos(0.0f);
			this->SetVelocity(oCurrentVelocity);
		}

		if (IsKeyDown(KEY_D))
		{
			Point2D oCurrentVelocity = this->GetVelocity();
			oCurrentVelocity.setXPos(8.0f);
			this->SetVelocity(oCurrentVelocity);
		}

		if (IsKeyReleased(KEY_D))
		{
			Point2D oCurrentVelocity = this->GetVelocity();
			oCurrentVelocity.setXPos(0.0f);
			this->SetVelocity(oCurrentVelocity);
		}
	}

	if (this->GetObjectID() == Object::PLAYER_TWO_SPRITE)
	{
		if (IsKeyDown(KEY_LEFT))
		{
			Point2D oCurrentVelocity = this->GetVelocity();
			oCurrentVelocity.setXPos(-8.0f);
			this->SetVelocity(oCurrentVelocity);
		}

		if (IsKeyReleased(KEY_LEFT))
		{
			Point2D oCurrentVelocity = this->GetVelocity();
			oCurrentVelocity.setXPos(0.0f);
			this->SetVelocity(oCurrentVelocity);
		}

		if (IsKeyDown(KEY_RIGHT))
		{
			Point2D oCurrentVelocity = this->GetVelocity();
			oCurrentVelocity.setXPos(8.0f);
			this->SetVelocity(oCurrentVelocity);
		}

		if (IsKeyReleased(KEY_RIGHT))
		{
			Point2D oCurrentVelocity = this->GetVelocity();
			oCurrentVelocity.setXPos(0.0f);
			this->SetVelocity(oCurrentVelocity);
		}
	}

	//Sets position of new location dependant on button presses above
	this->SetPosition(this->GetPosition() + this->GetVelocity());

	//These statements stop the player from leaving the screen
	if (this->GetPosition().getXPos() < 0)
	{
		this->SetPosition(Point2D(0.0f, this->GetPosition().getYPos()));
	}

	if (this->GetPosition().getXPos() > GetScreenWidth() - this->GetTexture().width)
	{
		this->SetPosition(Point2D((float)GetScreenWidth() - this->GetTexture().width, this->GetPosition().getYPos()));
	}
}
