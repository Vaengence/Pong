#ifndef _PLAYERSPRITE_H_
#define _PLAYERSPRITE_H_

#include "BaseSprite.h"

class PlayerSprite : public BaseSprite
{
public:
	PlayerSprite();
	virtual void Update();
	virtual void Draw();
};

#endif // !_PLAYERSPRITE_H_