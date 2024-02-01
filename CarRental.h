#pragma once
#include <iostream>
#include <vector>
#include "Car.h"
#include "Admin.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Exception.h"

using namespace std;

class CarRental
{
private:
    Admin& admin;
    vector<Car*> cars;

public:
    CarRental(Admin &admin);
    void loggAdmin();
    bool isAdminLogged();
    void logoutAdmin();
    
    void addCar(Car* car);
    void displayCars(bool displayOnlyAvailable);
    void removeCar(int id);
    //void saveCars(ofstream& file);
    void saveCars(const string& filename);
    void loadCars(const string& filename);


    void displayCarsByMinPower(int minPower);
    void displayCarsByYearRange(int minYear, int maxYear);
    void displayCarsByCapacityRange(int minCapacity, int maxCapacity);
    void displayCarsByFuelType(const string& fuelType);
    void displayCarsByBrand(const string& brand);
    void displayCarsByPriceRange(int minPrice, int maxPrice);
    void markCarAsAvailable(int id);
    void markCarAsRented(int id);

    ~CarRental();

};
