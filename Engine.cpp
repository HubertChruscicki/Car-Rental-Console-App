#include "Engine.h"

Engine::Engine()
{
	this->horsePower = 0;
}

Engine::Engine(int horsePower)
{
	this->horsePower = horsePower;
}

void Engine::setHorsePower(int horsePower)
{
	this->horsePower = horsePower;
}

int Engine::getHorsePower() const
{
	return this->horsePower;
}


CombustionEngine::CombustionEngine()
{
	this->capacity = 0;
	this->horsePower = 0;
}

CombustionEngine::CombustionEngine(int horsePower, int capacity)
{
	this->horsePower = horsePower;
	this->capacity = capacity;
}

void CombustionEngine::setCapacity(int capacity)
{
	this->capacity = capacity;
}

int CombustionEngine::getCapacity() const
{
	return this->capacity;
}


