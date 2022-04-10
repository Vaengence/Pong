#include "BaseSprite.h"

BaseSprite::BaseSprite(const char* sFilePath)
{
	this->rtSprite = LoadTexture(sFilePath);
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

