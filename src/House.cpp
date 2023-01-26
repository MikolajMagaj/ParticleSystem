#include "House.h"

//-----------------------------------------------
House::House(v3 posvec)
{
	this->setPosition(posvec);
	this->box1.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->box11.setPosition(this->getPosition().x + 20, this->getPosition().y, this->getPosition().z);
	this->box111.setPosition(this->getPosition().x + 40, this->getPosition().y, this->getPosition().z);
	this->box1111.setPosition(this->getPosition().x + 60, this->getPosition().y, this->getPosition().z);
	this->box11111.setPosition(this->getPosition().x + 80, this->getPosition().y, this->getPosition().z);
	this->box2.setPosition(this->getPosition().x - 10, this->getPosition().y - 15, this->getPosition().z);
	this->box3.setPosition(this->getPosition().x - 10, this->getPosition().y, this->getPosition().z + 35);
	this->box33.setPosition(this->getPosition().x - 10, this->getPosition().y, this->getPosition().z - 35);
	this->cone1.setPosition(this->getPosition().x + 30, this->getPosition().y + 60, this->getPosition().z);

	this->box1.setHeight(70);
	this->box11.setHeight(70);
	this->box111.setHeight(70);
	this->box1111.setHeight(70);
	this->box11111.setHeight(70);
	this->box2.setHeight(40);
	this->box3.setHeight(25);
	this->box33.setHeight(25);
	this->cone1.setHeight(50);

	this->cone1.setRadius(70);

	this->cone1.rotateDeg(180, 1, 0, 0);

	this->box1.setWidth(20);
	this->box11.setWidth(20);
	this->box111.setWidth(20);
	this->box1111.setWidth(20);
	this->box11111.setWidth(20);
	this->box2.setWidth(2);
	this->box3.setWidth(1);
	this->box33.setWidth(1);

	this->box1.setDepth(100);
	this->box11.setDepth(100);
	this->box111.setDepth(100);
	this->box1111.setDepth(100);
	this->box11111.setDepth(100);
	this->box2.setDepth(20);
	this->box3.setDepth(25);
	this->box33.setDepth(25);


	this->material1.setDiffuseColor(ofFloatColor::red);
	this->material2.setDiffuseColor(ofFloatColor::brown);
	this->material3.setDiffuseColor(ofFloatColor::blue);
	this->material4.setDiffuseColor(ofFloatColor::darkGrey);
}

House::~House()
{
}

void House::draw()
{
	material4.begin();
		box1.draw();
		box11.draw();
		box111.draw();
		box111.draw();
		box1111.draw();
	material4.end();
	material2.begin();
		box2.draw();
	material2.end();
	material3.begin();
		box3.draw();
		box33.draw();
	material3.end();
	material1.begin();
	cone1.draw();
	material1.end();

}
