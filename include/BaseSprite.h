#ifndef _BASESPRITE_H_
#define _BASESPRITE_H_

#include <raylib.h>
#include "Point2D.h"
#include "Rect.h"
#include "Helper.h"

class BaseSprite
{
public:

	BaseSprite(const char* sFilePath, Object oObjectID );
	Texture GetTexture();
	void SetPosition(Point2D oNewPosition);
	Point2D GetPosition();
	Point2D GetVelocity();
	void SetVelocity(Point2D oNewVelocity);
	Object GetObjectID();
	bool CollissionCheck(Point2D *oOtherPosition, Rect *oOtherCollissionBox);
	Rect GetCollisionBox();
	void Draw();

	virtual void Update();

private:

	Texture2D rtSprite;
	Point2D oPosition;
	Point2D oVelocity;
	Rect oCollisionBox;
	Object oObjectID;

};

#endif // !_BASESPRITE_H_