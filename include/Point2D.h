#pragma once

#ifndef _POINT2D_H_
#define _POINT2D_H_


class Point2D
{
public:

	Point2D(float x, float y);
	Point2D(const Point2D& Point2DToCopy);
	const Point2D operator+(const Point2D& Point2DToAdd);
	Point2D& operator+=(const Point2D& Point2DToAdd);
	const Point2D operator-(const Point2D& Point2DToSubtract);
	Point2D& operator-=(const Point2D& Point2DToSubtract);
	Point2D operator=(const Point2D& Point2DToAssign);
	bool operator==(const Point2D& Point2DToCompare) const;
	bool operator!=(const Point2D& right) const;

private:

	float x;
	float y;

};

#endif // !_POINT2D_H_
