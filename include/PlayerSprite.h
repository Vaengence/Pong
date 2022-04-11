#ifndef _PLAYERSPRITE_H_
#define _PLAYERSPRITE_H_

#include "BaseSprite.h"
#include "Enums.h"

class PlayerSprite : public BaseSprite
{
public:
	PlayerSprite(const char* SpriteImage, Object oObjectID);
	virtual void Update();
	virtual void Draw();


};

#endif // !_PLAYERSPRITE_H_