#include "Car.h"
#include <fstream>
#include <string>
#include <sstream>

Car::Car()
{

}

PetrolCar::PetrolCar()
{

}

DieselCar::DieselCar()
{

}

ElectricCar::ElectricCar()
{
}

Car::Car(int id, string brand, string model, int productionYear, int pricePerDay,bool available)
{
	this->id = id;
	this->brand = brand;
	this->model = model;
	this->productionYear = productionYear;
	this->pricePerDay = pricePerDay;
	this->available = available;
}


PetrolCar::PetrolCar(int id, string brand, string model, int productionYear, int capacity, int horsePower, int pricePerDay, bool available)
	: Car(id, brand, model, productionYear, pricePerDay, available), engine(horsePower, capacity)
{
}

int PetrolCar::getCapacity() const
{
	return this->engine.getCapacity();
}

int PetrolCar::getHorsePower() const
{
	return this->engine.getHorsePower();
}

string PetrolCar::getFuelType()
{
	
	return "petrol";
}

string DieselCar::getFuelType()
{
	
	return "diesel";
}

string ElectricCar::getFuelType()
{
	
	return "electric";
}

int DieselCar::getCapacity() const
{
	return this->engine.getCapacity();
}

int DieselCar::getHorsePower() const
{
	return this->engine.getHorsePower();
}

int ElectricCar::getHorsePower() const
{
	return this->engine.getHorsePower();
}
int ElectricCar::getCapacity() const
{
	return 0;
}


DieselCar::DieselCar(int id, string brand, string model, int productionYear, int capacity, int horsePower, int pricePerDay, bool available)
	: Car(id, brand, model, productionYear, pricePerDay, available), engine(horsePower, capacity)
{
}




ElectricCar::ElectricCar(int id, string brand, string model, int productionYear, int horsePower, int pricePerDay, bool available)
	: Car(id, brand, model, productionYear, pricePerDay, available), engine(horsePower) 
{
}



int Car::getID() const
{
	return this->id;
}

string Car::getBrand() const
{
	return this->brand;
}

string Car::getModel() const
{
	return this->model;
}

int Car::getProductionYear() const
{
	return this->productionYear;
}

int Car::getPricePerDay() const
{
	return this->pricePerDay;
}

bool Car::isAvailable() const
{
	return this->available;
}

void Car::markAvailable() 
{
	this->available = true;
}

void Car::markUnavailable() 
{
	this->available = false;
}







//bez const przy car bo nei dostane sie do engine
ostream& operator<<(ostream& os, PetrolCar& car) 
{
	os << setw(20) << left << car.getID()
		<< setw(20) << left << car.getBrand()
		<< setw(20) << left << car.getModel()
		<< setw(20) << left << car.getProductionYear()
		<< setw(20) << left << car.engine.getCapacity()
		<< setw(20) << left << car.engine.getHorsePower()
		<< setw(20) << left << "petrol"
		<< setw(20) << left << car.getPricePerDay();
	if (car.isAvailable()) 
	{
		os << setw(20) << left << "yes" << endl << endl;
	}
	else
	{
		os << setw(20) << left << "no"<< endl << endl;
	}


	return os;
}


ostream& operator<<(ostream& os, DieselCar& car) 
{
	os << setw(20) << left << car.getID()
		<< setw(20) << left << car.getBrand()
		<< setw(20) << left << car.getModel()
		<< setw(20) << left << car.getProductionYear()
		<< setw(20) << left << car.engine.getCapacity()
		<< setw(20) << left << car.engine.getHorsePower()
		<< setw(20) << left << "diesel"
		<< setw(20) << left << car.getPricePerDay();
	if (car.isAvailable()) 
	{
		os << setw(20) << left << "yes" << endl << endl;
	}
	else
	{
		os << setw(20) << left << "no"<< endl << endl;
	}


	return os;
}


ostream& operator<<(ostream& os, ElectricCar& car) 
{
	os << setw(20) << left << car.getID()
		<< setw(20) << left << car.getBrand()
		<< setw(20) << left << car.getModel()
		<< setw(20) << left << car.getProductionYear()
		<< setw(20) << left << "none"
		<< setw(20) << left << car.engine.getHorsePower()
		<< setw(20) << left << "electric"
		<< setw(20) << left << car.getPricePerDay();
	if (car.isAvailable()) 
	{
		os << setw(20) << left << "yes" << endl << endl;
	}
	else
	{
		os << setw(20) << left << "no"<< endl << endl;
	}


	return os;
}

void PetrolCar::displayCar() 
{
	cout << *this;
}

void DieselCar::displayCar() 
{
	cout << *this;
}

void ElectricCar::displayCar() 
{
	cout << setw(20) << left << this->getID()
		 << setw(20) << left << this->getBrand()
		 << setw(20) << left << this->getModel()
		 << setw(20) << left << this->getProductionYear()
		 << setw(20) << left << "none"
		 << setw(20) << left << this->engine.getHorsePower()
		 << setw(20) << left << "electric"
		 << setw(20) << left << this->getPricePerDay();
		 if (this->isAvailable())
	{
		cout << setw(20) << left << "yes" << endl << endl;
	}
	else
	{
		cout << setw(20) << left << "no" << endl << endl;
	}
}



void PetrolCar::saveCar(ofstream& file) 
{
	file << "Petrol,";
	file << getID() << ","
		<< this->getBrand() << ","
		<< this->getModel() << ","
		<< this->getProductionYear() << ","
		<< this->getPricePerDay() << ","
		<< this->engine.getCapacity() << ","
		<< this->engine.getHorsePower() << ",";
		if (isAvailable())
		{
			file << "yes";
		}
		else
		{
			file << "no";
		}

	file << endl;

	if (file.fail())
	{
		throw FileSaveErrException();
	}
}

void DieselCar::saveCar(ofstream& file) 
{
	file << "Diesel,";
	file << this->getID() << ","
		<< this->getBrand() << ","
		<< this->getModel() << ","
		<< this->getProductionYear() << ","
		<< this->getPricePerDay() << ","
		<< this->engine.getCapacity() << ","
		<< this->engine.getHorsePower() << ",";

	if (this->isAvailable())
	{
		file << "yes";
	}
	else
	{
		file << "no";
	}

	file << endl;

	if (file.fail())
	{
		throw FileSaveErrException();
	}
}

void ElectricCar::saveCar(ofstream& file) 
{
	file << "Electric,";
	file << this->getID() << ","
		<< this->getBrand() << ","
		<< this->getModel() << ","
		<< this->getProductionYear() << ","
		<< this->getPricePerDay() << ","
		<< "none,"  
		<< this->engine.getHorsePower() << ",";

	if (this->isAvailable())
	{
		file << "yes";
	}
	else
	{
		file << "no";
	}

	file << endl;

	if (file.fail())
	{
		throw FileSaveErrException();
	}
}



void PetrolCar::loadCar(const string& line)
{
	try
	{
		istringstream ss(line);

		string carType;
		getline(ss, carType, ',');

		string temp;
		getline(ss, temp, ',');
		this->id = stoi(temp);

		getline(ss, this->brand, ',');
		getline(ss, this->model, ',');

		getline(ss, temp, ',');
		this->productionYear = stoi(temp);

		getline(ss, temp, ',');
		this->pricePerDay = stoi(temp);

		getline(ss, temp, ',');
		this->engine.setCapacity(stoi(temp));

		getline(ss, temp, ',');
		this->engine.setHorsePower(stoi(temp));

		getline(ss, temp, ',');
		if (temp == "yes")
		{
			this->available = true;
		}
		else
		{
			this->available = false;
		}
	}
	catch (exception& ex)
	{
		throw FileLoadErrException();
	}
}

void DieselCar::loadCar(const string& line)
{
	try
	{
		istringstream ss(line);

		string carType;
		getline(ss, carType, ',');

		string temp;
		getline(ss, temp, ',');
		this->id = stoi(temp);

		getline(ss, this->brand, ',');
		getline(ss, this->model, ',');

		getline(ss, temp, ',');
		this->productionYear = stoi(temp);

		getline(ss, temp, ',');
		this->pricePerDay = stoi(temp);

		getline(ss, temp, ',');
		this->engine.setCapacity(stoi(temp));

		getline(ss, temp, ',');
		this->engine.setHorsePower(stoi(temp));

		getline(ss, temp, ',');
		if (temp == "yes")
		{
			this->available = true;
		}
		else
		{
			this->available = false;
		}
	}
	catch (exception& ex)
	{
		throw FileLoadErrException();
	}
}


void ElectricCar::loadCar(const string& line)
{
	try
	{
		istringstream ss(line);

		string carType;
		getline(ss, carType, ',');

		string temp;
		getline(ss, temp, ',');
		this->id = stoi(temp);

		getline(ss, this->brand, ',');
		getline(ss, this->model, ',');

		getline(ss, temp, ',');
		this->productionYear = stoi(temp);

		getline(ss, temp, ',');
		this->pricePerDay = stoi(temp);

		getline(ss, temp, ','); //none z capacity trzeba odczytac nie uzyc

		getline(ss, temp, ',');
		this->engine.setHorsePower(stoi(temp));


		getline(ss, temp, ',');
		if (temp == "yes")
		{
			this->available = true;
		}
		else
		{
			this->available = false;
		}
	}
	catch (exception& ex)
	{
		throw FileLoadErrException();
	}

}