#pragma once
#include "Engine.h"

using namespace std;

class Car {
protected:
    Engine engine;
    char* brand;
    double price;
public:
    Car();
    Car(double p, const char* b, double pr);
    Car(const Car& other);
    Car& operator=(const Car& other);
    virtual ~Car();

    Engine getEngine() const;
    void setEngine(const Engine& e);
    const char* getBrand() const;
    void setBrand(const char* b);
    double getPrice() const;
    void setPrice(double pr);

    virtual operator string() const;

    friend istream& operator>>(istream& is, Car& c);
    friend ostream& operator<<(ostream& os, const Car& c);
};