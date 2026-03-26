#define _CRT_SECURE_NO_WARNINGS 
#include "Car.h"
#include <iostream>
#include <cstring>
#include <sstream> 
#include <cstdlib>

Car::Car(const char* b, double p, double engPow) : engine(engPow) {
    brand = new char[std::strlen(b) + 1];
    std::strcpy(brand, b);
    if (!setPrice(p)) {
        std::cerr << "Error: Invalid car price! Terminating." << std::endl;
        std::exit(1);
    }
}

Car::~Car() {
    delete[] brand;
}

Car::Car(const Car& other) : engine(other.engine.getPower()), price(other.price) {
    brand = new char[std::strlen(other.brand) + 1];
    std::strcpy(brand, other.brand);
}

const char* Car::getBrand() const { return brand; }
double Car::getPrice() const { return price; }
double Car::getEnginePower() const { return engine.getPower(); }

void Car::setBrand(const char* b) {
    if (b) {
        delete[] brand;
        brand = new char[std::strlen(b) + 1];
        std::strcpy(brand, b);
    }
}

bool Car::setPrice(double p) {
    if (p >= 0) {
        price = p;
        return true;
    }
    return false;
}

Car::operator std::string() const {
    std::stringstream ss;
    ss << "Brand: " << brand << ", Price: " << price << ", Engine Power: " << engine.getPower();
    return ss.str();
}