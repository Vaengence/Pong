#include "PlayerManager.h"


PlayerManager::PlayerManager(ResourceManager* oResources)
	: oResources{oResources}
{
	this->vPlayerSprites = new std::vector<PlayerSprite*>;
}

PlayerManager::~PlayerManager()
{

}

void PlayerManager::InitialiseLevel(int iLevel)
{
	//iLevel for future use.
	CreatePlayers(2);
}

void PlayerManager::CreatePlayers(int iNumPlayers)
{
	//iNumPlayers will ultimately be adjustable by player, but at the moment, forced to 2. 

	vPlayerSprites->push_back(new PlayerSprite(oResources->CreateTexture(Object::PLAYER_ONE_SPRITE), Object::PLAYER_ONE_SPRITE));

	if (iNumPlayers == 2)
	{
		vPlayerSprites->push_back(new PlayerSprite(oResources->CreateTexture(Object::PLAYER_TWO_SPRITE), Object::PLAYER_TWO_SPRITE));
	}
}

std::vector<PlayerSprite*>* PlayerManager::GetPlayers()
{
	return vPlayerSprites;
}


void PlayerManager::Update()
{
	for (std::vector<PlayerSprite*>::iterator iter = vPlayerSprites->begin(); iter != vPlayerSprites->end(); iter++)
	{
		(*iter)->Update();
	}
}

void PlayerManager::Draw()
{
	for (std::vector<PlayerSprite*>::iterator iter = vPlayerSprites->begin(); iter != vPlayerSprites->end(); iter++)
	{
		(*iter)->Draw();
	}
}

void PlayerManager::Collisions()
{

}