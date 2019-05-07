#include "Car.h"

Car::Car() {}

Car::Car(const string& n, const string& b, const string& m, const string& c)
: Vehicle(n, b, m, c)
{}

Car::~Car() {}

string Car::getType() const
{
    return "Car";
}

double Car::getCostPerHour() const
{
    return 2;
}
