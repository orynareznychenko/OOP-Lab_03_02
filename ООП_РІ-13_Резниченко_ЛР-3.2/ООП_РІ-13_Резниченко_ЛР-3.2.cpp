#include <iostream>
#include "Engine.h"
#include "Car.h"
#include "Lorry.h"

using namespace std;

Car modifyCarPrice(Car c) {
    c.setPrice(c.getPrice() + 1000);
    return c;
}

void printCarInfo(const Car* c) {
    cout << "Polymorphic substitution: " << string(*c) << endl;
}

int main() {
    Car baseCar(150.5, "Toyota", 25000);
    cout << "Base Car: " << string(baseCar) << endl;

    baseCar.setPrice(26000);
    baseCar.setBrand("Honda");
    baseCar.setEngine(Engine(160));
    cout << "Modified Car: " << baseCar << endl;

    cout << "\n--- Testing Getters ---" << endl;
    cout << "Brand: " << baseCar.getBrand() << endl;
    cout << "Price: " << baseCar.getPrice() << endl;
    cout << "Engine Power: " << baseCar.getEngine().getPower() << endl;

    cout << "\n--- Testing Derived Class (Lorry) ---" << endl;
    Lorry baseLorry(450.0, "Volvo", 85000, 20000);
    baseLorry.print();
    cout << "Lorry capacity via getter: " << baseLorry.getCapacity() << endl;

    cout << "\n--- Testing Substitution Principle ---" << endl;
    Car substitutedCar = modifyCarPrice(baseLorry);
    cout << "Returned Car (sliced from Lorry): " << substitutedCar << endl;
    printCarInfo(&baseLorry);

    cout << "\n--- Testing Input/Output ---" << endl;
    Car userCar;
    cout << "Enter Engine power, Car brand, and Car price (e.g., 120 Fiat 15000):" << endl;
    cin >> userCar;
    cout << "User input result: " << userCar << endl;

    cout << "\n--- Testing Dynamic Object ---" << endl;
    Car* dynamicCar = new Car(200, "Ford", 30000);
    cout << *dynamicCar << endl;
    delete dynamicCar;

    cout << "\n--- Testing Static Array of Objects ---" << endl;
    Lorry lorryArray[2];
    lorryArray[0] = Lorry(300, "MAN", 60000, 15000);
    lorryArray[1] = Lorry(400, "Scania", 75000, 18000);
    for (int i = 0; i < 2; i++) {
        lorryArray[i].print();
    }

    cout << "\n--- Testing Dynamic Array of Objects ---" << endl;
    Car* carPointerArray = new Car[2];
    carPointerArray[0].setBrand("Mazda");
    carPointerArray[1] = Lorry(500, "DAF", 90000, 22000);
    for (int i = 0; i < 2; i++) {
        cout << carPointerArray[i] << endl;
    }
    delete[] carPointerArray;

    return 0;
}