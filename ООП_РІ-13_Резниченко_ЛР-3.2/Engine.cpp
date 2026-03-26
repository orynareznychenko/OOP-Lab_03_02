#include "Engine.h"
#include <iostream>
#include <cstdlib> 

Engine::Engine(double p) {
    if (!setPower(p)) {
        std::cerr << "Error: Invalid engine power! Terminating." << std::endl;
        std::exit(1);
    }
}

double Engine::getPower() const { return power; }

bool Engine::setPower(double p) {
    if (p >= 0) {
        power = p;
        return true;
    }
    return false;
}