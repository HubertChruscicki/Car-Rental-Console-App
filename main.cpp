#include <iostream>
#include "Menu.h"

using namespace std;



int main()
{
	Admin admin("123");
	CarRental rental(admin);
	mainMenu(rental);

	//header();
	//PetrolCar car(1, "madzia", "elo", 2002, 2000, 140,50,true);
	//DieselCar car1(2, "vw", "passat", 2007, 1999,110,70,false);
	//ElectricCar car3(3, "tesla", "x", 2022, 400, 202, false);
	//rental.addCar(&car);
	//rental.addCar(&car1);
	//rental.addCar(&car3);



	//rental.displayCars(0);
	//cout << endl << endl;

	//searchMenu(rental);


	//rental.displayCars(1);
	//rental.removeCar(2);
	//rental.displayCars(1);
	//rental.saveCars("rental_cars.csv");


	//rental.loadCars("rental_cars.csv");
	//rental.displayCars(1);
	//header();	
	//rental.displayCars(0);
	//header();
	//rental.removeCar(2);
	//rental.displayCars(0);
	//rental.saveCars("rental_cars.csv");


















	//ofstream file("rental_cars.csv");
	//if (file.is_open()) {
	//	rental.saveCarsData(file);
	//	file.close();
	//	cout << "Dane zapisano do pliku." << endl;
	//}
	//else {
	//	cout << "Blad otwarcia pliku!" << endl;
	//}


	//ofstream file("rental_cars.csv");
	//if (file.is_open()) {
	//	rental.saveCars(file);
	//	file.close();
	//	cout << "Dane zapisano do pliku." << endl;
	//}
	//else {
	//	cout << "B³¹d otwarcia pliku!" << endl;
	//}

	return 0;
}

