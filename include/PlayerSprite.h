#ifndef _PLAYERSPRITE_H_
#define _PLAYERSPRITE_H_

#include "BaseSprite.h"
#include "Helper.h"
#include <raylib.h>

class PlayerSprite : public BaseSprite
{
public:
	PlayerSprite(Texture2D oSpriteTexture, Object oObjectID);

	virtual void Update();


};

#endif // !_PLAYERSPRITE_H_