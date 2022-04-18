#ifndef _BALL_H_
#define _BALL_H_

#include "BaseSprite.h"
#include "Point2D.h"

class BallSprite : public BaseSprite
{
public:
	BallSprite(const char* SpriteImage, Object oObjectID, Point2D oInitVelocity);
	void KeepInPlay(Point2D* oCurrentPosition, Point2D* oCurrentVelocity);

	virtual void Update();

};


#endif
