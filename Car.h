#ifndef CAR_H_
#define CAR_H_

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car();
    Car(const string& n, const string& b, const string& m, const string& c);
    ~Car();

    string getType() const;
    double getCostPerHour() const;
};

#endif // CAR_H
