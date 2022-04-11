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

Texture BaseSprite::GetTexture()
{
	return this->rtSprite;
}

