#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <cstring>
#include <cstdlib>

using namespace std;

Car::Car() : engine(1.0), price(1.0) {
    brand = nullptr;
    setBrand("Unknown");
}

Car::Car(double p, const char* b, double pr) : engine(p) {
    brand = nullptr;
    setBrand(b);
    setPrice(pr);
}

Car::Car(const Car& other) : engine(other.engine), price(other.price) {
    brand = new char[strlen(other.brand) + 1];
    strcpy(brand, other.brand);
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        engine = other.engine;
        setPrice(other.price);
        setBrand(other.brand);
    }
    return *this;
}

Car::~Car() {
    delete[] brand;
}

Engine Car::getEngine() const {
    return engine;
}

void Car::setEngine(const Engine& e) {
    engine = e;
}

const char* Car::getBrand() const {
    return brand;
}

void Car::setBrand(const char* b) {
    if (!b || strlen(b) == 0) {
        cout << "Error: Invalid car brand." << endl;
        exit(1);
    }
    if (brand != nullptr) {
        delete[] brand;
    }
    brand = new char[strlen(b) + 1];
    strcpy(brand, b);
}

double Car::getPrice() const {
    return price;
}

void Car::setPrice(double pr) {
    if (pr <= 0) {
        cout << "Error: Invalid car price." << endl;
        exit(1);
    }
    price = pr;
}

Car::operator string() const {
    return string(engine) + ", Brand: " + string(brand) + ", Price: " + to_string(price);
}

istream& operator>>(istream& is, Car& c) {
    double p, pr;
    string b;
    is >> p >> b >> pr;
    c.setEngine(Engine(p));
    c.setBrand(b.c_str());
    c.setPrice(pr);
    return is;
}

ostream& operator<<(ostream& os, const Car& c) {
    os << string(c);
    return os;
}