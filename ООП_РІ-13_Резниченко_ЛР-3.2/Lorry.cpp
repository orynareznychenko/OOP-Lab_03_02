#include "Lorry.h"
#include <iostream>
#include <cstdlib>

Lorry::Lorry(const char* b, double p, double engPow, double cap)
    : Car(b, p, engPow) {
    if (!setLoadCapacity(cap)) {
        std::cerr << "Error: Invalid load capacity! Terminating." << std::endl;
        std::exit(1);
    }
}

Lorry::~Lorry() {}

double Lorry::getLoadCapacity() const { return loadCapacity; }

bool Lorry::setLoadCapacity(double cap) {
    if (cap >= 0) {
        loadCapacity = cap;
        return true;
    }
    return false;
}

void Lorry::display() const {
    std::cout << (std::string)*this << ", Load Capacity: " << loadCapacity << " kg" << std::endl;
}