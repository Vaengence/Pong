#ifndef _BASESPRITE_H_
#define _BASESPRITE_H_

#include <raylib.h>
#include "Point2D.h"
#include "Rect.h"
#include "Enums.h"

class BaseSprite
{
public:

	BaseSprite(const char* sFilePath, Object oObjectID );
	virtual void Update();
	virtual void Draw();
	Texture GetTexture();

private:

	Texture2D rtSprite;
	Point2D oPosition;
	Point2D oVelocity;
	Rect oCollisionBox;
	Object oObjectID;

};

#endif // !_BASESPRITE_H_