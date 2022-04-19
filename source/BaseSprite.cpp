#include "BaseSprite.h"

BaseSprite::BaseSprite(Texture2D oSpriteTexture, Object oObjectID)
	: oObjectID{ oObjectID }
	, oCollisionBox{Rect {(float)rtSprite.height, (float)rtSprite.height, (float)rtSprite.width, (float)rtSprite.width}}
	, rtSprite{oSpriteTexture}
{

}

void BaseSprite::Update()
{

}

void BaseSprite::Draw()
{
	Vector2 vTemp = { this->GetPosition().getXPos() , this->GetPosition().getYPos() };
	DrawTextureV(this->GetTexture(), vTemp, RAYWHITE);
}

void BaseSprite::SetPosition(Point2D oNewPosition)
{
	this->oPosition = oNewPosition;
}

Point2D BaseSprite::GetPosition()
{
	return this->oPosition;
}

Texture BaseSprite::GetTexture()
{
	return this->rtSprite;
}

Point2D BaseSprite::GetVelocity()
{
	return this->oVelocity;
}

void BaseSprite::SetVelocity(Point2D oNewVelocity)
{
	this->oVelocity = oNewVelocity;
}

Object BaseSprite::GetObjectID()
{
	return this->oObjectID;
}

Rect BaseSprite::GetCollisionBox()
{
	return this->oCollisionBox;
}

BaseSprite::~BaseSprite()
{
	UnloadTexture(this->rtSprite);
}

