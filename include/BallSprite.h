#ifndef _BALL_H_
#define _BALL_H_

#include "BaseSprite.h"
#include "Point2D.h"

class BallSprite : public BaseSprite
{
public:
	BallSprite(const char* SpriteImage, Object oObjectID, Point2D oInitVelocity);

	virtual void Update();

};


#endif
