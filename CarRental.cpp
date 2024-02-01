#include "CarRental.h"
#include "Car.h"


using namespace std; 



CarRental::CarRental(Admin& admin) : admin(admin) 
{
    try
    {
        this->loadCars("rental_cars.csv");
    }
    catch (FileOpenErrException& fileOpenEx)
    {
        cout << fileOpenEx.what() <<" (LOAD)" << endl;
    }
    catch (FileCloseErrException& fileCloseEx)
    {
        cout << fileCloseEx.what() << "(LOAD)" << endl;
    }

}

void CarRental::loggAdmin()
{
    this->admin.login();
}

bool CarRental::isAdminLogged()
{
    return this->admin.isLogged();
}

void CarRental::logoutAdmin()
{
    this->admin.logout();
}

void CarRental::addCar(Car* car)
{
    cars.push_back(car);
}


void CarRental::displayCars(bool displayOnlyAvailable)
{

    if (displayOnlyAvailable == 1)
    {
        for (Car* car : cars)
        {
            if (car->isAvailable() == 1)
            {
                car->displayCar();
                cout << endl << endl;
            }
        }
    }
    else
    {
        for (Car* car : cars)
        {
            car->displayCar();
            cout << endl << endl;
        }
    }
}



void CarRental::removeCar(int id)
{
    for (auto i = cars.begin(); i != cars.end(); ++i)
    {
        if ((*i)->getID() == id)
        {
            cars.erase(i);
            cars.shrink_to_fit();  
            break;
        }
    }
}


void CarRental::saveCars(const string& filename)
{
    ofstream file(filename);

    if (file.is_open()) 
    {
        try
        {
            for (Car* car : cars)
            {
                car->saveCar(file);
            }

            file.close();

            if (file.fail())
            {
                throw FileCloseErrException();
            }

            //int k=1;
            for (Car* car : cars)  
            {
                delete car;
                //cout << "delate " << k<<endl ;
                //k++;
            }

        }
        catch (FileSaveErrException& fileSaveEx)
        {
            cout << fileSaveEx.what() << endl;
        }


    }
    else 
    {
        throw FileOpenErrException();
    }
    
}

void CarRental::loadCars(const string& filename)
{
    ifstream file(filename);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            {
                istringstream ss(line);

                string carType;
                getline(ss, carType, ',');
                try
                {
                    Car* car = nullptr;
                    if (carType == "Petrol")
                    {
                        car = new PetrolCar();
                    }
                    else if (carType == "Diesel")
                    {
                        car = new DieselCar();
                    }
                    else if (carType == "Electric")
                    {
                        car = new ElectricCar();
                    }

                    if (car)
                    {
                        car->loadCar(line);
                        addCar(car);
                    }

                }
                catch (bad_alloc& allocEx)
                {
                    cout << allocEx.what() << "(LOADING CAR)" << endl;
                }
                catch (FileLoadErrException& fileLoadEx)
                {
                    cout << fileLoadEx.what() << endl;
                }
            }
        }

        file.close();

        if (file.fail())
        {
            throw FileCloseErrException();
        }

    }
    else
    {
        throw FileOpenErrException();
    }
}


void CarRental::displayCarsByMinPower(int minPower)
{
    for (Car* car : cars) 
    {
        if (car->getHorsePower() >= minPower)
        {
            car->displayCar();
            cout << endl << endl;
        }
    }
}

void CarRental::displayCarsByYearRange(int minYear, int maxYear)
{
    for (Car* car : cars) 
    {
        if (car->getProductionYear() >= minYear && car->getProductionYear() <= maxYear)
        {
            car->displayCar();
            cout << endl << endl;
        }
    }
}

void CarRental::displayCarsByCapacityRange(int minCapacity, int maxCapacity)
{
    for (Car* car : cars)
    {
        if (car->getCapacity() >= minCapacity && car->getCapacity() <= maxCapacity)
        {
            car->displayCar();
            cout << endl << endl;
        }
    }
}

void CarRental::displayCarsByFuelType(const string& fuelType)
{
    for (Car* car : cars)
    {
        if (car->getFuelType() == fuelType)
        {
            car->displayCar();
            cout << endl << endl;
        }
    }
}

void CarRental::displayCarsByBrand(const string& brand)
{
    for (Car* car : cars)
    {
        if (car->getBrand() == brand)
        {
            car->displayCar();
            cout << endl << endl;
        }
    }
}

void CarRental::displayCarsByPriceRange(int minPrice, int maxPrice)
{
    for (Car* car : cars)
    {
        if (car->getPricePerDay() >= minPrice && car->getPricePerDay() <= maxPrice)
        {
            car->displayCar();
            cout << endl << endl;
        }
    }
}


void CarRental::markCarAsAvailable(int id)
{
    for (Car* car : cars)
    {
        if (car->getID() == id)
        {
            car->markAvailable();
            break;
        }
    }
}

void CarRental::markCarAsRented(int id)
{
    for (Car* car : cars) {
        if (car->getID() == id)
        {
            car->markUnavailable();
            break;
        }
    }
}

CarRental::~CarRental()
{
    try
    {
        this->saveCars("rental_cars.csv");
        cout << "Program has succesfully ended" << endl;
    }
    catch (FileOpenErrException& fileOpenEx)
    {
        cout << fileOpenEx.what() << " (SAVE)" << endl;
    }
    catch (FileCloseErrException& fileCloseEx)
    {
        cout << fileCloseEx.what() << "(SAVE)" << endl;
    }

}
