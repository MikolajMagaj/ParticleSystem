#include "ForceWind.h"

ForceWind::ForceWind(v3 posvec, v3 fvec, float r)
{
	this->setPosition(posvec);
	this->setForce(fvec);
	this->setRadius(r);
}

ForceWind::~ForceWind()
{
}

v3 ForceWind::getPosition()
{
	return pos;
}

void ForceWind::setPosition(v3 posvec)
{
	this->pos = posvec;
}

v3 ForceWind::getForce()
{
	return force;
}

void ForceWind::setForce(v3 fvec)
{
	this->force = fvec;
}

float ForceWind::getRadius()
{
	return radius;
}

void ForceWind::setRadius(float r)
{
	this->radius = r;
}

void ForceWind::draw()
{

}
