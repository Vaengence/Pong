#ifndef _PLAYERMANAGER_H
#define _PLAYERMANAGER_H

#include "PlayerSprite.h"
#include "ObjectManager.h"
#include "ResourceManager.h"


class PlayerManager : public ObjectManager
{
public:

	PlayerManager(ResourceManager* oResources);
	~PlayerManager();

	void CreatePlayers(int iNumPlayers);

	std::vector<PlayerSprite*>* GetPlayers();

	void InitialiseLevel(int level) override;
	void Update() override;
	void Draw() override;
	void Collisions() override;

private:

	std::vector<PlayerSprite*>* vPlayerSprites;
	ResourceManager* oResources;
	int iGameLevel;
};

#endif // !_PLAYERMANAGER_H