#ifndef _BALL_H_
#define _BALL_H_

#include "BaseSprite.h"
#include "Point2D.h"
#include <raylib.h>

class BallSprite : public BaseSprite
{
public:
	BallSprite(Texture2D oSpriteTexture, Object oObjectID, Point2D oInitVelocity);
	void KeepInPlay(Point2D* oCurrentPosition, Point2D* oCurrentVelocity);

	virtual void Update();

};


#endif
