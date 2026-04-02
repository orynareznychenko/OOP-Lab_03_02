#pragma once
#include "Car.h"

using namespace std;

class Lorry : public Car {
    double capacity;
public:
    Lorry();
    Lorry(double p, const char* b, double pr, double cap);
    Lorry(const Lorry& other);
    Lorry& operator=(const Lorry& other);
    ~Lorry() override;

    double getCapacity() const;
    void setCapacity(double cap);

    void print() const;

    operator string() const override;

    friend istream& operator>>(istream& is, Lorry& l);
    friend ostream& operator<<(ostream& os, const Lorry& l);
};