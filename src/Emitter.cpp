#include "Emitter.h"
#include <iostream>
#include <random>

Emitter::Emitter(v3 posvec, string name)
{
	this->setName(name);
	this->setPosition(posvec);
}


Emitter::~Emitter()
{
}

string Emitter::getName()
{
	return name;
}

void Emitter::setName(string newName)
{
	this->name = newName;
}

v3 Emitter::getPosition()
{
	return pos;
}

void Emitter::setPosition(v3 posvec)
{
	this->pos = posvec;
}

void Emitter::addGenerator(v3 posvec, v3 velvec, float g, int amount, float radius, float mass, int life, int resolution, const ofColor_<unsigned char> color)
{
	this->generator.push_back(new Generator(posvec, velvec, g, amount, radius, mass, life, resolution, color));
}

std::vector<Generator*> Emitter::getGenerator()
{
	return this->generator;
}

void Emitter::draw()
{
	
	for (auto* gen : this->generator)
	{
		gen->draw();
	}
}