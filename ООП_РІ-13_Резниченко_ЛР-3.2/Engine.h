#pragma once
#include <iostream>
#include <string>

using namespace std;

class Engine {
    double power;
public:
    Engine();
    Engine(double p);

    double getPower() const;
    void setPower(double p);

    operator string() const;

    friend istream& operator>>(istream& is, Engine& e);
    friend ostream& operator<<(ostream& os, const Engine& e);
};