#pragma once
#include "Point2D.h"

// class used for representation of a point in 3-dimensional space
class Point3D : public Point2D {
public:
	Point3D();
	Point3D(const double, const double, const double);

	void setZ(const double);
	const double getZ() const;

	const double getDistanceTo(const Point3D&) const;

	virtual Point2D* clone() const override;
	bool isPoint2D() const override; //returns false because element is not a pointer to Point2D, but to Point3D

private:
	double z;
};