#include "Menu.h"

void header()
{
	cout << setw(20) << left << "ID"
		<< setw(20) << left << "Brand"
		<< setw(20) << left << "Model"
		<< setw(20) << left << "Year"
		<< setw(20) << left << "Capacity"
		<< setw(20) << left << "Horse power"
		<< setw(20) << left << "Fuel Type"
		<< setw(20) << left << "Cost/day"
		<< setw(20) << left << "Aviable" << endl
		<< "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl << endl;
}


void mainMenu(CarRental& rental)
{
	int choice=0;
	while (choice!=5)
	{

	    system("cls");
		cout << "CAR RENTAL " << endl;
		cout << "--------------------------- " << endl;
		cout << "1. Display all cars " << endl;
		cout << "2. Display available cars " << endl;
		cout << "3. Search car " << endl;
		cout << "4. Admin panel" << endl;
		cout << "5. Exit " << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				system("cls");
				header();
				rental.displayCars(0);
				system("pause");
				system("cls");
			}
			break;
			case 2:
			{
				system("cls");
				header();
				rental.displayCars(1);
				system("pause");
				system("cls");
			}
			break;

			case 3:
			{
				system("cls");
				searchMenu(rental);

			}
			break;
			case 4:
			{
				system("cls");
				adminMenu(rental);

			}
			break;

			case 5:
			{
				break;
				system("cls");

			}
			break;

			default:
			{
				cout << "Invalid input" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	}
}

void searchMenu(CarRental &rental)
{
	int choice;
	cout << "Search by: " << endl;
	cout << "1. Brand " << endl;
	cout << "2. Fuel type " << endl;
	cout << "3. Capacity range " << endl;
	cout << "4. Minimum horse power " << endl;
	cout << "5. Year of production range " << endl;
	cout << "6. Price per day " << endl;
	cout << "choice: ";
	cin >> choice;

	switch (choice)
	{
		case 1:
		{
			string brand;
			cout << "Input brand: ";
			cin >> brand;
			system("cls");
			header();
			rental.displayCarsByBrand(brand);
			system("pause");
			system("cls");
		}
		break;

		case 2:
		{
			int cchoice;
			cout << "1 - Petrol | 2 - Diesel | 3 - Electric" << endl;
			cin >> cchoice;
			switch (cchoice)
			{
			case 1:
			{
				system("cls");
				header();
				rental.displayCarsByFuelType("petrol");
				system("pause");
				system("cls");

			}
			break;
			case 2:
			{
				system("cls");
				header();
				rental.displayCarsByFuelType("diesel");
				system("pause");
				system("cls");
			}
			break;
			case 3:
			{
				system("cls");
				header();
				rental.displayCarsByFuelType("electric");
				system("pause");
				system("cls");
			}
			break;
			default:
				//cout << "Invalid input" << endl;
				//system("pause");
				//system("cls");
				break;
			}

		}
		break;

		case 3:
		{
			int minCapacity, maxCapacity;
			cout << "Input min capacity of cars engine: ";
			cin >> minCapacity;
			cout << "Input max capacity of cars engine:";
			cin >> maxCapacity;
			system("cls");
			header();
			rental.displayCarsByCapacityRange(minCapacity, maxCapacity);
			system("pause");
			system("cls");
		}
		break;

		case 4:
		{
			int minPower;
			cout << "Input min horse power: ";
			cin >> minPower;
			system("cls");
			header();
			rental.displayCarsByMinPower(minPower);
			system("pause");
			system("cls");
		}
		break;

		case 5:
		{
			int minYear, maxYear;
			cout << "Input min year of production: ";
			cin >> minYear;
			cout << "Input max year of production: ";
			cin >> maxYear;
			system("cls");
			header();
			rental.displayCarsByYearRange(minYear, maxYear);
			system("pause");
			system("cls");
		}
		break;

		case 6:
		{
			int minPrice, maxPrcie;
			cout << "Input min price: ";
			cin >> minPrice;
			cout << "Input max price: ";
			cin >> maxPrcie;
			system("cls");
			header();
			rental.displayCarsByYearRange(minPrice, maxPrcie);
			system("pause");
			system("cls");
		}
		break;

		default:
		{
			cout << "Invalid input" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void adminMenu(CarRental& rental)
{
	rental.loggAdmin();
	if(rental.isAdminLogged())
	{
		int choice;
		cout << "1. Add car " << endl;
		cout << "2. Remove car " << endl;
		cout << "3. Mark as rented " << endl;
		cout << "4. Mark as available " << endl;
		cout << "choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int id, productionYear, capacity, horsePower, pricePerDay, fuelType;
			string brand, model;

			system("cls");

			cout << "Fuel type: (1 - petrol | 2 - diesel | 3 - electric): ";
			cin >> fuelType;															//TO DO wyjatek????

			cout << "Input id: ";
			cin >> id;

			cout << "Input brand: ";
			cin >> brand;

			cout << "Input model: ";
			cin >> model;

			cout << "Input production year: ";
			cin >> productionYear;

			switch (fuelType)
			{
			case 1:
			{
				cout << "Input capacity: ";
				cin >> capacity;

				cout << "Input horse power: ";
				cin >> horsePower;

				cout << "Input price per day: ";
				cin >> pricePerDay;

				PetrolCar* car1 = new PetrolCar(id, brand, model, productionYear, capacity, horsePower, pricePerDay, true);
				rental.addCar(car1);
			}
			break;

			case 2:
			{

				cout << "Input capacity: ";
				cin >> capacity;

				cout << "Input horse power: ";
				cin >> horsePower;

				cout << "Input price per day: ";
				cin >> pricePerDay;

				Car* car = new DieselCar();

				DieselCar* car2 = new DieselCar(id, brand, model, productionYear, capacity, horsePower, pricePerDay, true);
				rental.addCar(car2);
			}
			break;

			case 3:
			{
				cout << "Input horse power: ";
				cin >> horsePower;

				cout << "Input price per day: ";
				cin >> pricePerDay;

				ElectricCar* car3 = new ElectricCar(id, brand, model, productionYear, horsePower, pricePerDay, true);
				rental.addCar(car3);

			}
			break;

			default:
				break;
			}



		}
		break;
		case 2:
		{
			system("cls");
			int id;
			cout << "Input id of car you want remove: ";
			cin >> id;
			rental.removeCar(id);

		}
		break;

		case 3:
		{
			int carId;
			cout << "Input car ID to mark it rented: ";
			cin >> carId;

			rental.markCarAsRented(carId);
		}
		break;

		case 4:
		{
			system("cls");
			int carId;
			cout << "Input car ID to mark it available: ";
			cin >> carId;
			rental.markCarAsAvailable(carId);

		}
		break;
		default:
		{
			cout << "Invalid input" << endl;
			system("pause");
			system("cls");
			break;
		}

		}
		rental.logoutAdmin();
	}
}

//}

	