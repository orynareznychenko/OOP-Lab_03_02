#include "Engine.h"
#include <cstdlib>

using namespace std;

Engine::Engine() {
    setPower(1.0);
}

Engine::Engine(double p) {
    setPower(p);
}

double Engine::getPower() const {
    return power;
}

void Engine::setPower(double p) {
    if (p <= 0) {
        cout << "Error: Invalid engine power." << endl;
        exit(1);
    }
    power = p;
}

Engine::operator string() const {
    return "Engine Power: " + to_string(power);
}

istream& operator>>(istream& is, Engine& e) {
    double p;
    is >> p;
    e.setPower(p);
    return is;
}

ostream& operator<<(ostream& os, const Engine& e) {
    os << string(e);
    return os;
}