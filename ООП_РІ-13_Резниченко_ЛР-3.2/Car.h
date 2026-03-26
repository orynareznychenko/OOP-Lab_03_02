#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include <string>

class Car {
private:
    Engine engine;
    char* brand;   
    double price;

public:
    Car(const char* b = "", double p = 0, double engPow = 0);
    virtual ~Car();
    Car(const Car& other); 

    const char* getBrand() const;
    double getPrice() const;
    double getEnginePower() const;

    void setBrand(const char* b);
    bool setPrice(double p);

    operator std::string() const; 
};

#endif