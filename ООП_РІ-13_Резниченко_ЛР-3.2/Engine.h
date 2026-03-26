#ifndef ENGINE_H
#define ENGINE_H

class Engine {
private:
    double power;
public:
    Engine(double p = 0);
    double getPower() const;
    bool setPower(double p);
};

#endif