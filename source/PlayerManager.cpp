#include "PlayerManager.h"


PlayerManager::PlayerManager(ResourceManager* oResources)
	: oResources{oResources}
{
	this->mPlayerSprites = new std::unordered_map<Object, PlayerSprite*>;
}

PlayerManager::~PlayerManager()
{

}

void PlayerManager::InitialiseLevel(int iLevel)
{
	this->iGameLevel = iLevel;
	//iLevel for future use.
	CreatePlayers(2);
}

void PlayerManager::CreatePlayers(int iNumPlayers)
{
	//iNumPlayers will ultimately be adjustable by player, but at the moment, forced to 2. 

	mPlayerSprites->insert({ Object::PLAYER_ONE_SPRITE, new PlayerSprite(oResources->CreateTexture(Object::PLAYER_ONE_SPRITE), Object::PLAYER_ONE_SPRITE) });

	if (iNumPlayers == 2)
	{
		mPlayerSprites->insert({ Object::PLAYER_TWO_SPRITE, new PlayerSprite(oResources->CreateTexture(Object::PLAYER_TWO_SPRITE), Object::PLAYER_TWO_SPRITE) });
	}
}

std::unordered_map<Object, PlayerSprite*>* PlayerManager::GetPlayers()
{
	return mPlayerSprites;
}

void PlayerManager::PlayerScored(Object oPlayer)
{
	int oCurrentScore = mPlayerSprites->at(oPlayer)->GetPlayerScore();

	oCurrentScore = oCurrentScore + 10;

	mPlayerSprites->at(oPlayer)->SetPlayerScore(oCurrentScore);
}


void PlayerManager::Update()
{
	for (std::unordered_map<Object, PlayerSprite*>::iterator iter = mPlayerSprites->begin(); iter != mPlayerSprites->end(); iter++)
	{
		iter->second->Update();
	}
}

void PlayerManager::Draw()
{
	for (std::unordered_map<Object, PlayerSprite*>::iterator iter = mPlayerSprites->begin(); iter != mPlayerSprites->end(); iter++)
	{
		iter->second->Draw();

		int iCurrentScore = iter->second->GetPlayerScore();
		std::string sCurrentScore = std::to_string(iCurrentScore);

		if (iter->second->GetObjectID() == Object::PLAYER_ONE_SPRITE)
		{
			DrawText(sCurrentScore.c_str(), (GetScreenWidth() / 10) * 9, (GetScreenHeight() / 5) * 3, 100, {0, 0, 255, 80});
		}

		if (iter->second->GetObjectID() == Object::PLAYER_TWO_SPRITE)
		{
			DrawText(sCurrentScore.c_str(), GetScreenWidth() / 10, GetScreenHeight() / 5, 100, {255, 0, 0, 80});
		}
		
	}
}

void PlayerManager::Collisions()
{

}