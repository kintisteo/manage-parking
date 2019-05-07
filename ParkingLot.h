#ifndef PARKING_LOT_H_
#define PARKING_LOT_H_

#include "Car.h"
#include "Moto.h"

#include <vector>

class ParkingLot
{
    public:
        ParkingLot();
        ~ParkingLot();

        int addVehicle(Vehicle* ptr, bool temp);
        bool remVehicle(const string& number, double& cost);

    private:
        const static int maxSlots = 50;
        const static int maxExtraSlots = 10;

        vector<Vehicle*> parkingSlots;
        vector<Vehicle*> extraSlots;
};

#endif // PARKING_LOT_H_
