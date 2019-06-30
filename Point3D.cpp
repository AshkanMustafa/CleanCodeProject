#include "Point3D.h"
#include <iostream>
#include <cmath>


Point3D::Point3D() : Point2D(), z(0)
{}

Point3D::Point3D(const double newX, const double newY, const double newZ) : Point2D(newX, newY), z(newZ)
{}

Point2D * Point3D::clone() const
{
	return new Point3D(*this);
}

bool Point3D::isPoint2D() const
{
	return false;
}

void Point3D::setZ(const double newZ)
{
	this->z = newZ;
}

const double Point3D::getZ() const
{
	return this->z;
}

const double Point3D::getDistanceTo(const Point3D& point) const
{
	return sqrt((point.getX() - this->getX())*(point.getX() - this->getX())
		+ (point.getY() - this->getY())*(point.getY() - this->getY())
		+ (point.getZ() - this->getZ())*(point.getZ() - this->getZ()));
}
