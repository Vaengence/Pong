#ifndef _PLAYERSPRITE_H_
#define _PLAYERSPRITE_H_

#include "BaseSprite.h"
#include "Helper.h"
#include <raylib.h>

class PlayerSprite : public BaseSprite
{
public:
	PlayerSprite(Texture2D oSpriteTexture, Object oObjectID);

	int GetPlayerScore();
	void SetPlayerScore(int iScore);

	virtual void Update();

private:
	int iPlayerScore;


};

#endif // !_PLAYERSPRITE_H_