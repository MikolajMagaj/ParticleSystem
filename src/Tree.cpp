#include "Tree.h"

Tree::Tree(v3 posvec)
{
	this->setPosition(posvec);
	this->cone1.setPosition(this->getPosition().x, this->getPosition().y, this->getPosition().z);
	this->cone2.setPosition(this->getPosition().x, this->getPosition().y + 40, this->getPosition().z);
	this->cone3.setPosition(this->getPosition().x, this->getPosition().y + 70, this->getPosition().z);
	
	this->cylinder1.setPosition(this->getPosition().x, this->getPosition().y - 45, this->getPosition().z);

	this->cone1.setHeight(70);
	this->cone2.setHeight(60);
	this->cone3.setHeight(50);

	this->cylinder1.setHeight(30);

	this->cone1.setRadius(40);
	this->cone2.setRadius(30);
	this->cone3.setRadius(20);

	this->cylinder1.setRadius(12);

	this->cone1.rotateDeg(180, 1, 0, 0);
	this->cone2.rotateDeg(180, 1, 0, 0);
	this->cone3.rotateDeg(180, 1, 0, 0);
	this->material1.setDiffuseColor(ofFloatColor::darkGreen);
	this->material2.setDiffuseColor(ofFloatColor::brown);
}

Tree::~Tree()
{
}

void Tree::draw()
{
	material1.begin();
		cone1.draw();
		cone2.draw();
		cone3.draw();
	material1.end();
	material2.begin();
		cylinder1.draw();
	material2.end();
}
