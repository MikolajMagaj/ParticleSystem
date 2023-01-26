#include "Collection.h"
#include <math.h>
#include <iostream>

Collection::Collection()
{
	//Emitter snow
	this->addEmitter(v3(50, 500, 0), "snow");

	//Emitter fire
	this->addEmitter(v3(0, 0, 0), "fire");

	this->addPoint(v3(-200, 50, -100), 0.5);
	this->addWind(v3(-200, 0, 200), v3(1, 0.1, -1), 1);

	for (auto* emit : this->emitter)
	{
		if (emit->getName() == "snow")
		{
			emit->addGenerator(emit->getPosition(), v3(0, -10, 0), 9.81, 20, 1, 1, 200, 1, ofColor::white);
		}

		if (emit->getName() == "fire")
		{
			emit->addGenerator(emit->getPosition(), v3(0, 5, 0), 0.0, 3, 1, 1, 100, 1, ofColor::orange);
		}
	}
	//dodanie drzew 
	for (auto i = 0; i < 50; i++)
	{
		float x = - 450 + (rand() % 901);
		float z = - 450 + (rand() % 901);
		if ((x >= -75 && x <= 500) && (z >= -150 && z <= 150))
		{
			i--;	
		}
		else
		{
			this->addObject(v3(x, 60, z), 1);
		}
	}
	//prezentów
	for (auto i = 1; i <= 8; i++)
	{
		int x = 300;
		int z = 45;
		this->addObject(v3(x - (11 * i), 10, (pow(-1, i) * z) + (pow(-1, i) * i * 8)), 2);
	}
	for (auto i = 1; i <= 6; i++)
	{
		int x = 290;
		int z = 45;
		this->addObject(v3(x - (8 * i), 30, (pow(-1, i) * z) + (pow(-1, i) * i * 10)), 2);
	}
	for (auto i = 1; i <= 4; i++)
	{
		int x = 280;
		int z = 45;
		this->addObject(v3(x - (6 * i), 50, (pow(-1, i) * z) + (pow(-1, i) * i * 12)), 2);
	}


	//ogniska
	this->addObject(v3(0, 20, 0), 3);

	//domu
	this->addObject(v3(330, 35, 0), 4);

}


Collection::~Collection()
{
}

void Collection::addEmitter(v3 posvec, string name)
{
	this->emitter.push_back(new Emitter(posvec, name));
}

void Collection::addPoint(v3 posvec, float force)
{
	this->forcepoint.push_back(new ForcePoint(posvec, force));
}

void Collection::addWind(v3 posvec, v3 fvec, float force)
{
	this->wind.push_back(new ForceWind(posvec, fvec, force));
}

void Collection::addObject(v3 posvec, int value)
{
	switch (value)
	{
	case 1:
		this->object.push_back(new Tree(posvec));
		break;
	case 2:
		this->object.push_back(new Gift(posvec));
		break;
	case 3:
		this->object.push_back(new Fireplace(posvec));
		break;
	case 4:
		this->object.push_back(new House(posvec));
		break;
	default:
		break;
	}
}

void Collection::collectionUpdate()
{
	for (auto* emit : this->emitter)
	{
		if (emit->getName() == "snow")
		{
			for (auto* gen : emit->getGenerator())
			{
				gen->generate(&particle, 500);
			}
		}

		if (emit->getName() == "fire")
		{
			for (auto* gen : emit->getGenerator())
			{
				gen->generate(&particle, 20);
			}
		}
	}

	float fx;
	float fy;
	float fz;
	for (auto* point : this->forcepoint)
	{
		for (auto* part : this->particle)
		{

			((part->getPosition().x - point->getPosition().x > 0.0) ? fx = 1 : fx = -1);
			((part->getPosition().y - point->getPosition().y > 0.0) ? fy = 1 : fy = -1);
			((part->getPosition().z - point->getPosition().z > 0.0) ? fz = 1 : fz = -1);
			part->addForce(v3(fx * point->getForce(), fy * point->getForce(), fz * point->getForce()));
		}
	}

	float dist;
	for (auto* w : this->wind)
	{
		for (auto* part : this->particle)
		{
			dist = sqrt(pow(part->getPosition().x - w->getPosition().x, 2) * pow(part->getPosition().y - w->getPosition().y, 2));
			if (dist < w->getRadius())
			{
				part->addForce(v3(w->getForce().x, w->getForce().y, w->getForce().z));
			}
		}
	}
}

void Collection::particleUpdate()
{
	unsigned counter = 0;
	for (auto* part : this->particle)
	{
		part->updateParticle(0.1);
		if (part->getLife() == part->getMaxLife())
		{
			delete this->particle.at(counter);
			this->particle.erase(this->particle.begin() + counter);
		}

		if (part->getPosition().y <= -30)
		{
			delete this->particle.at(counter);
			this->particle.erase(this->particle.begin() + counter);
		}
		++counter;
	}
}

void Collection::draw()
{
	for (auto* emit : this->emitter)
	{
		emit->draw();
	}

	for (auto* part : this->particle)
	{
		part->draw();
	}

	for (auto* point : this->forcepoint)
	{
		point->draw();
	}

	for (auto* w : this->wind)
	{
		w->draw();
	}

	for (auto* obj : this->object)
	{
		obj->draw();
	}
}


