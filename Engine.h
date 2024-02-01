#pragma once

class Engine
{
protected:
	int horsePower;
public:
	Engine();
	Engine(int horsePower);
	virtual void setHorsePower(int horsePower);
	virtual int getHorsePower() const;
};

class CombustionEngine : public Engine
{
protected:
	int capacity;
public:
	CombustionEngine();
	CombustionEngine(int horsePower, int capacity);
	virtual void setCapacity(int capacity);
	virtual int getCapacity() const;

};


class PetrolEngine : public CombustionEngine
{
public:
	using CombustionEngine::CombustionEngine;
};

class DieselEngine : public CombustionEngine
{
public:
	using CombustionEngine::CombustionEngine;
};


class ElectricEngine : public Engine
{
public:
	using Engine::Engine;
};



