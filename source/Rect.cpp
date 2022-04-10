#include "Rect.h"

Rect::Rect(float left, float right, float top, float bottom)
{
	this->left = left, this->right = right, this->top = top, this->bottom = bottom;
}

Rect::Rect(const Rect& RectToCopy)
{
	left = RectToCopy.left;
	right = RectToCopy.right;
	top = RectToCopy.top;
	bottom = RectToCopy.bottom;

}
const Rect& Rect::operator= (const Rect& RectToAssign)
{
	this->left = RectToAssign.left;
	this->right = RectToAssign.right;
	this->top = RectToAssign.top;
	this->bottom = RectToAssign.bottom;
	return *this;
}

// This compare operator overloaded specifically to check for collision, returns true if a collission is detected between the two arguments
bool Rect::operator== (const Rect& RectToCompare) const
{
	return (this->left == RectToCompare.left && this->right == RectToCompare.right && this->top == RectToCompare.top && this->bottom == RectToCompare.bottom);
}
bool Rect::operator!= (const Rect& right) const
{
	return !(*this == right);
}