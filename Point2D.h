#pragma once

// class used for representation of a point in 2-dimensional space
class Point2D {
public:
	Point2D();
	Point2D(const double, const double);
	virtual ~Point2D();

	void setX(const double);
	void setY(const double);
	const double getX() const;
	const double getY() const;

	const double getDistanceTo(const Point2D&) const;

	virtual Point2D* clone() const; 
	virtual bool isPoint2D() const; // always returns true because element is pointer to Point2D

protected:
	double x;
	double y;
};