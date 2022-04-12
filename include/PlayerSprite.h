#ifndef _PLAYERSPRITE_H_
#define _PLAYERSPRITE_H_

#include "BaseSprite.h"
#include "Helper.h"

class PlayerSprite : public BaseSprite
{
public:
	PlayerSprite(const char* SpriteImage, Object oObjectID);

	virtual void Update();


};

#endif // !_PLAYERSPRITE_H_