#include "Lorry.h"
#include <cstdlib>

using namespace std;

Lorry::Lorry() : Car() {
    setCapacity(1.0);
}

Lorry::Lorry(double p, const char* b, double pr, double cap) : Car(p, b, pr) {
    setCapacity(cap);
}

Lorry::Lorry(const Lorry& other) : Car(other), capacity(other.capacity) {}

Lorry& Lorry::operator=(const Lorry& other) {
    if (this != &other) {
        Car::operator=(other);
        setCapacity(other.capacity);
    }
    return *this;
}

Lorry::~Lorry() {}

double Lorry::getCapacity() const {
    return capacity;
}

void Lorry::setCapacity(double cap) {
    if (cap <= 0) {
        cout << "Error: Invalid lorry capacity." << endl;
        exit(1);
    }
    capacity = cap;
}

void Lorry::print() const {
    cout << string(*this) << endl;
}

Lorry::operator string() const {
    return Car::operator string() + ", Capacity: " + to_string(capacity);
}

istream& operator>>(istream& is, Lorry& l) {
    double p, pr, cap;
    string b;
    is >> p >> b >> pr >> cap;
    l.setEngine(Engine(p));
    l.setBrand(b.c_str());
    l.setPrice(pr);
    l.setCapacity(cap);
    return is;
}

ostream& operator<<(ostream& os, const Lorry& l) {
    os << string(l);
    return os;
}