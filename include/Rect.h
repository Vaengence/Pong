#ifndef _RECT_H_
#define _RECT_H_


class Rect
{
public:

	float left, right, top, bottom;

	Rect(float l = 0.0f, float r = 0.0f, float t = 0.0f, float b = 0.0f);
	Rect(const Rect& RectToCopy);
	const Rect& operator= (const Rect& RectToAssign);

	// This compare operator overloaded specifically to check for collision, returns true if a collission is detected between the two arguments
	bool operator== (const Rect& RectToCompare) const;

	bool operator!= (const Rect& right) const;

};

#endif // !_RECT_H_
