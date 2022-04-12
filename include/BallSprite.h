#ifndef _BALL_H_
#define _BALL_H_

#include "BaseSprite.h"

class BallSprite : public BaseSprite
{
public:
	BallSprite(const char* SpriteImage, Object oObjectID);

	virtual void Update();

};


#endif
