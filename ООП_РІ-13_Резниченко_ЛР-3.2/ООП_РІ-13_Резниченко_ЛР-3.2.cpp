#include "Lorry.h"
#include <iostream>

Car processCar(Car c) {
    std::cout << "Inside processCar function: " << (std::string)c << std::endl;
    return c;
}

int main() {
    Car car1("Ford", 15000, 120);
    Lorry lorry1("Volvo", 90000, 480, 25000);

    std::cout << "--- Substitution Principle (Passing Lorry to Car function) ---" << std::endl;
    processCar(lorry1);

    std::cout << "\n--- Lorry Display ---" << std::endl;
    lorry1.display();

    std::cout << "\n--- Array of Objects ---" << std::endl;
    Car* fleet[2];
    fleet[0] = new Car("Toyota", 25000, 160);
    fleet[1] = new Lorry("MAN", 125000, 520, 18000);

    for (int i = 0; i < 2; i++) {
        std::cout << "Fleet [" << i << "]: " << (std::string)*fleet[i] << std::endl;
        delete fleet[i];
    }

    std::cout << "\n--- Modifying object via methods ---" << std::endl;
    car1.setPrice(14500);
    std::cout << "Updated car price: " << car1.getPrice() << std::endl;

    return 0;
}