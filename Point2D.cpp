#include "Point2D.h"
#include <iostream>
#include <cmath>

Point2D::Point2D() : x(0), y(0)
{
}

Point2D::Point2D(const double newX, const double newY) : x(newX), y(newY)
{
}

Point2D::~Point2D()
{
}

Point2D * Point2D::clone() const
{
	return new Point2D(*this);
}

bool Point2D::isPoint2D() const
{
	return true;
}

void Point2D::setX(const double newX)
{
	this->x = newX;
}

void Point2D::setY(const double newY)
{
	this->y = newY;
}

const double Point2D::getX() const
{
	return this->x;
}

const double Point2D::getY() const
{
	return this->y;
}

const double Point2D::getDistanceTo(const Point2D& point) const
{
	return sqrt((point.getX() - this->getX())*(point.getX() - this->getX()) 
			+ (point.getY() - this->getY())*(point.getY() - this->getY()));
}
