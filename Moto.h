#ifndef MOTO_H_
#define MOTO_H_

#include "Vehicle.h"

class Moto : public Vehicle
{
public:
    Moto();
    Moto(const string& n, const string& b, const string& m, const string& c);
    ~Moto();

    string getType() const;
    double getCostPerHour() const;
};

#endif // MOTO_H
