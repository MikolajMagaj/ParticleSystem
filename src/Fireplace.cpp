#include "Fireplace.h"

Fireplace::Fireplace(v3 posvec)
{

	for (int d = 0; d < 360; d += 72)
	{
		this->cylinder.push_back(new ofCylinderPrimitive());
	}

	int deg1 = 0;
	for (auto* cyl : this->cylinder)
	{
		float x = 10 * cos(deg1 * (PI / 180)) + this->getPosition().x;
		float z = 10 * sin(deg1 * (PI / 180)) + this->getPosition().z;
		cyl->setPosition(x, this->getPosition().y + 20, z);
		cyl->setRadius(3);
		cyl->setHeight(35);
		deg1 += 72;
	}

	cylinder[0]->rotateDeg(33, 0, 0, 1);
	cylinder[1]->rotateDeg(33, -1, 0, 0);
	cylinder[2]->rotateDeg(25, -1, 0, -1);
	cylinder[3]->rotateDeg(20, 1, 0, -1);
	cylinder[4]->rotateDeg(33, 1, 0, 0);
	
	for (int d = 0; d < 360; d += 45)
	{
		this->sphere.push_back(new ofIcoSpherePrimitive());
	}

	int deg2 = 0;
	for (auto* sph : this->sphere)
	{
		float x = 20 * cos(deg2 * (PI / 180)) + this->getPosition().x;
		float z = 20 * sin(deg2 * (PI / 180)) + this->getPosition().z;
		sph->setPosition(x, this->getPosition().y, z);
		sph->setResolution(1);
		sph->setRadius(10);
		deg2 += 45;
	}

	this->material1.setDiffuseColor(ofFloatColor::brown);
	this->material2.setDiffuseColor(ofFloatColor::darkGray);
}

Fireplace::~Fireplace()
{
}

void Fireplace::draw()
{
	material1.begin();
	for (auto* cyl : this->cylinder)
	{
		cyl->draw();
	}
	material1.end();

	material2.begin();
	for (auto* sph : this->sphere)
	{
		sph->draw();
	}
	material2.end();
}
