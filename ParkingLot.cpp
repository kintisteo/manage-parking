#include "ParkingLot.h"

ParkingLot::ParkingLot()
{}

ParkingLot::~ParkingLot()
{}

int ParkingLot::addVehicle(Vehicle* ptr, bool temp)
{
    int result;

    if (temp)//!an einai barxyprouesmh stathmefsi tote
    {
        //! Elegxetai an yparxoun kenes theseis
        if (parkingSlots.size() < maxSlots)
        {
            ptr->setEnterTime(time(0));
            extraSlots.push_back(ptr);
            result = 1;
        }
        //! Elegxetai an yparxoun kenes theseis sto vraxiprothesmo
        else if (extraSlots.size() < maxExtraSlots)
        {
            ptr->setEnterTime(time(0));
            parkingSlots.push_back(ptr);
            result = 2;
        }
        else
            return 0; //! Den yparxoun kenes theseis pouthena
    }
    else
    {
        //! Elegxw an yparxoun kenes thesis
        if (parkingSlots.size() < maxSlots)
        {
            ptr->setEnterTime(time(0));
            parkingSlots.push_back(ptr);
            result = 1;
        }
        else
            return 0; //! Den yparxoun kenes theseis sto kuriws parking.
    }

    return true;
}

bool ParkingLot::remVehicle(const string& number, double& cost)
{
    vector<Vehicle*>::iterator i;

    //! Elegxetai an vrisketai stis theseis tou kuriws parking
    for (i = parkingSlots.begin(); i < parkingSlots.end(); i++)
        {
        if ((*i)->getNumber() == number) //! elegxos uparkshs arithmoy kukloforias
            break;
        }

    //! An den einai sto kuriws parking
    if (i == parkingSlots.end())
    {
        //! elegxetai an vrisketai stis vraxiprothesmes theseis
        for (i = extraSlots.begin(); i < extraSlots.end(); i++)
            {
            if ((*i)->getNumber() == number)
                break;
            }

        //! An einai stis vraxiprothesmes
        if (i != extraSlots.end())
        {
            Vehicle* ptr = *i; //! Apothikevetai o deiktis
            time_t curTime = time(0); //! Pairno tin torini ora

            //! Ipoligizetai to kostos tis stathmeysis
            cost = ptr->getCostPerHour()*(curTime - ptr->getEnterTime())/3600;
            //! An den exei perasei toylaxiston mia ora, isxiei elaxisti xreosi ths mias oras
            if (cost < ptr->getCostPerHour())
                cost = ptr->getCostPerHour();

            //! Apodeysmevetai h thesi apo to vraxiprothesmo parking
            extraSlots.erase(i);
        }
        else
            return false; //! Den vrethike oxima me ayton ton arithmo kykloforias
    }
    else
    {
        if (i != parkingSlots.end())
        {
            Vehicle* ptr = *i; //! Apothikeyo ton deikti
            time_t curTime = time(0); //! Pairno tin torini ora

            //! Ipologizetai to kostos tis stathmeysis
            cost = ptr->getCostPerHour()*(curTime - ptr->getEnterTime())/3600;
            //! An den exei perasei toylaxiston mia ora, bazo elaxisti xreosi thn mia ora
            if (cost < ptr->getCostPerHour())
                cost = ptr->getCostPerHour();

            //! Apodeysmevetai thn thesi apo to parking
            parkingSlots.erase(i);
        }
        else
            return false; //! Den vrethike oxima me ayton ton arithmo kykloforias
    }

    return true;
}

