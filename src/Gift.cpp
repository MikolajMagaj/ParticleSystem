#include "Gift.h"

//-----------------------------------------------
Gift::Gift(v3 posvec)
{
	this->setPosition(posvec);
	this->box1.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->box2.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->box3.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);

	this->box1.setHeight(20);
	this->box2.setHeight(21);
	this->box3.setHeight(21);

	this->box1.setWidth(20);
	this->box2.setWidth(21);
	this->box3.setWidth(5);
	this->box1.setDepth(20);
	this->box2.setDepth(5);
	this->box3.setDepth(21);
	
	this->box3.rotateDeg(0, 1, 0, 90);

	this->material1.setDiffuseColor(ofColor(rand() % 256, rand() % 256, rand() % 256, 255));
	this->material2.setDiffuseColor(ofColor(rand() % 256, rand() % 256, rand() % 256, 255));
}

Gift::~Gift()
{
}

void Gift::draw()
{
	material1.begin();
		box1.draw();
	material1.end();
	material2.begin();
		box2.draw();
	material2.end();
	material2.begin();
		box3.draw();
	material2.end();
}
