#include "Vehicle.h"

Vehicle::Vehicle()
{}

Vehicle::Vehicle(const string& n, const string& b, const string& m, const string& c)
{
    number = n;
    brand = b;
    model = m;
    color = c;
}

const string& Vehicle::getNumber() const
{
    return number;
}

void Vehicle::setNumber(const string& n)
{
    number = n;
}

const string& Vehicle::getBrand() const
{
    return brand;
}

void Vehicle::setBrand(const string& b)
{
    brand = b;
}

const string& Vehicle::getModel() const
{
    return model;
}

void Vehicle::setModel(const string& m)
{
    model = m;
}

const string& Vehicle::getColor() const
{
    return color;
}

void Vehicle::setColor(const string& c)
{
    color = c;
}

time_t Vehicle::getEnterTime() const
{
    return enterTime;
}

void Vehicle::setEnterTime(time_t eT)
{
    enterTime = eT;
}

