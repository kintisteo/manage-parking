#include "Moto.h"

Moto::Moto() {}

Moto::Moto(const string& n, const string& b, const string& m, const string& c)
: Vehicle(n, b, m, c)
{}

Moto::~Moto() {}

string Moto::getType() const
{
    return "Moto";
}

double Moto::getCostPerHour() const
{
    return 0.5;
}
