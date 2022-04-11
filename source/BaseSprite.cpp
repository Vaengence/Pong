#include "BaseSprite.h"

BaseSprite::BaseSprite(const char* sFilePath, Object oObjectID)
	: rtSprite{ LoadTexture(sFilePath) }
	, oObjectID{ oObjectID }
{
	;
}

void BaseSprite::Update()
{

}

void BaseSprite::Draw()
{

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

