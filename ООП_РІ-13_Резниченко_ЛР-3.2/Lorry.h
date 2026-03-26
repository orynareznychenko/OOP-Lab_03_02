#ifndef LORRY_H
#define LORRY_H

#include "Car.h"

class Lorry : public Car { 
private:
    double loadCapacity;

public:
    Lorry(const char* b = "", double p = 0, double engPow = 0, double cap = 0);
    ~Lorry();

    double getLoadCapacity() const;
    bool setLoadCapacity(double cap);

    void display() const; 
};

#endif