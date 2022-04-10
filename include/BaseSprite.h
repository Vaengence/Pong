#ifndef _BASESPRITE_H_
#define _BASESPRITE_H_

#include <raylib.h>

class BaseSprite
{
public:

	BaseSprite(/*const char* sFilePath*/ );
	virtual void Update();
	virtual void Draw();

private:

	Image riSpriteImage;
	Texture2D rtSprite;

};

#endif // !_BASESPRITE_H_