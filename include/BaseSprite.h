#ifndef _BASESPRITE_H_
#define _BASESPRITE_H_

#include <raylib.h>
#include "Point2D.h"

class BaseSprite
{
public:

	BaseSprite(const char* sFilePath );
	virtual void Update();
	virtual void Draw();
	Texture GetTexture();

private:

	Texture2D rtSprite;
	Point2D oPosition;
	Point2D oVelocity;

};

#endif // !_BASESPRITE_H_