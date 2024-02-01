#pragma once
#include <iostream>
#include <iomanip>
#include "Engine.h"
#include "Exception.h"

using namespace std;

class Car
{
protected:
	int id;
	string brand;
	string model;
	int productionYear;
	int pricePerDay;
	bool available;
	Engine engine;
public:
	Car();
	Car(int id, string brand, string model, int productionYear, int pricePerDay, bool available/*, Engine& engine*/);
	virtual int getID() const;
	virtual string getBrand() const;
	virtual string getModel() const;
	virtual int getProductionYear() const;
	virtual int getPricePerDay() const;
	virtual bool isAvailable() const;
	virtual void markAvailable();
	virtual void markUnavailable();
	virtual int getCapacity() const = 0;
	virtual int getHorsePower() const = 0;
	virtual string getFuelType() = 0;

	virtual void displayCar() = 0;
	virtual void saveCar(ofstream& file) = 0;
	virtual void loadCar(const string& line) = 0;
	//virtual ~Car();
};

class PetrolCar : public Car
{
private:
	PetrolEngine engine;

public:
	PetrolCar();
	PetrolCar(int id, string brand, string model, int productionYear, int capacity, int horsePower, int pricePerDay, bool available/*, PetrolEngine& engine*/);
	friend ostream& operator<<(ostream& os,  PetrolCar& car);
	int getCapacity() const override;
	int getHorsePower() const override;
	string getFuelType() override;
	void displayCar() override;
	void saveCar(ofstream& file) override;
	void loadCar(const string& line) override;
};


class DieselCar : public Car
{
private:
	DieselEngine engine;

public:
	DieselCar();
	DieselCar(int id, string brand, string model, int productionYear, int capacity, int horsePower, int pricePerDay, bool available/*, DieselEngine& engine*/);
	friend ostream& operator<<(ostream& os,  DieselCar& car);
	int getCapacity() const override;
	int getHorsePower() const override;
	string getFuelType() override;
	void displayCar() override;
	void saveCar(ofstream& file) override;
	void loadCar(const string& line) override;

};

class ElectricCar : public Car
{
private:
	ElectricEngine engine;

public:
	ElectricCar();
	ElectricCar(int id, string brand, string model, int productionYear, int horsePower, int pricePerDay, bool availabl/*, ElectricEngine& engine*/);
	friend ostream& operator<<(ostream& os,  ElectricCar& car);
	void displayCar() override;
	int getHorsePower() const override;
	int getCapacity() const override;
	string getFuelType() override;
	void saveCar(ofstream& file) override;
	void loadCar(const string& line) override;
};

