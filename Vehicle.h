#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>
#include <ctime>

using namespace std;

class Vehicle
{
public:
    Vehicle();
    Vehicle(const string& n, const string& b, const string& m, const string& c);
    virtual ~Vehicle() { }

    const string& getNumber() const;
    void setNumber(const string& n);

    const string& getBrand() const;
    void setBrand(const string& b);

    const string& getModel() const;
    void setModel(const string& m);

    const string& getColor() const;
    void setColor(const string& c);

    time_t getEnterTime() const;
    void setEnterTime(time_t eT);

    virtual string getType() const = 0;
    virtual double getCostPerHour() const = 0;

private:
    string number;
    string brand;
    string model;
    string color;
    time_t enterTime;
};

#endif // VEHICLE_H
