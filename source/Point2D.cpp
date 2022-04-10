#include "Point2D.h"

Point2D::Point2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point2D::Point2D(const Point2D& Point2DToCopy)
{
	x = Point2DToCopy.x;
	y = Point2DToCopy.y;
}

const Point2D Point2D::operator+(const Point2D& Point2DToAdd)
{
	Point2D oNewCopy;
	oNewCopy.x = this->x + Point2DToAdd.x;
	oNewCopy.y = this->y + Point2DToAdd.y;
	return oNewCopy;
}

Point2D& Point2D::operator+=(const Point2D& Point2DToAdd)
{
	this->x = this->x + Point2DToAdd.x;
	this->y = this->y + Point2DToAdd.y;
	return *this;
}

const Point2D Point2D::operator-(const Point2D& Point2DToSubtract)
{
	Point2D oNewCopy;
	oNewCopy.x = this->x - Point2DToSubtract.x;
	oNewCopy.y = this->y - Point2DToSubtract.y;
	return oNewCopy;
}

Point2D& Point2D::operator-=(const Point2D& Point2DToSubtract)
{
	this->x = this->x - Point2DToSubtract.x;
	this->y = this->y - Point2DToSubtract.y;
	return *this;
}
Point2D Point2D::operator=(const Point2D& Point2DToAssign)
{
	if (this != &Point2DToAssign)
	{
		this->x = Point2DToAssign.x;
		this->y = Point2DToAssign.y;
	}
	return *this;
}
bool Point2D::operator==(const Point2D& Point2DToCompare) const
{
	return (this->x == Point2DToCompare.x && this->y == Point2DToCompare.y);
}
bool Point2D::operator!=(const Point2D& right) const
{
	return !(*this == right);
}