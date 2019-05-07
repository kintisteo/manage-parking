#include "ParkingLot.h"

#include <iomanip>
#include <iostream>

int printMenu();

int main()
{
    ParkingLot parking;

    for (;;){
        switch (printMenu())
        {
        case 1:
        {
            string number, brand, model, color;
            bool temp, isCar;
            char answer;

            cout << "Dose ton arithmo kykloforias: ";
            getline(cin, number, '\n');
            cout << "Dose ti marka: ";
            getline(cin, brand, '\n');
            cout << "Dose to modello: ";
            getline(cin, model, '\n');
            cout << "Dose to xroma: ";
            getline(cin, color, '\n');

            for (;;){
                cout << "Prokeitai gia vraxiprothesmi stathmeysi?( ligotero tis mias oras )(Y/N): ";
                cin >> answer;
                if (answer == 'Y' || answer == 'y')
                {
                    temp = true;
                    break;
                }
                else if (answer == 'N' || answer == 'n')
                {
                    temp = false;
                    break;
                }
            }

            for (;;){
                cout << "Einai amaksi h mixani?( A/M ): ";
                cin >> answer;

                if (answer == 'A' || answer == 'a')
                {
                    isCar = true;
                    break;
                }
                else if (answer == 'M' || answer == 'm')
                {
                    isCar = false;
                    break;
                }
            }

            Vehicle* newPtr;

            if (isCar == true)
                newPtr = new Car(number, brand, model, color);
            else
                newPtr = new Moto(number, brand, model, color);

            int result = parking.addVehicle(newPtr, temp);
            if (result)
            {
                if (result == 2)
                    cout << "Exoun desmeytei oi kanonikes theseis, na parkarete to oxima se xorous metaksi ton theseon." << endl;
                else
                {
                    if (isCar == true)
                        cout << "To amaksi na parkarei sti proti eleytheri thesi.\n" << endl;
                    else
                        cout << "O odigos na parkarei th mixani sti thesi poy tha tou ypodeixtei.\n" << endl;
                }
            }
            else
            {
                cout << "Den yparxe	i eleytheri thesi sto parking.\n" << endl;
            }
        }
        break;
        case 2:
            string number;
            double cost;

            cout << "Dose ton arithmo kykloforias: ";
            getline(cin, number, '\n');

            if (parking.remVehicle(number, cost))
            {
                cout << "Epitixis evresi tou oximatos." << endl;
                cout << "To kostos einai: " << fixed << setprecision(2) << cost << " euro.\n" << endl;
            }
            else
            {
                cout << "To oxima me ayton ton arithmo kykloforias den vrethike.\n" << endl;
            }
        break;
        }
    }

    return 0;
}

int printMenu()
{
    int choice;

    for (;;){
        cout << "Gia nea kataxorisi oximatos pieste 1" << endl;
        cout << "Gia eyresi yparxon oximatos pieste 2" << endl;
        cin >> choice;

        if (choice == 1 || choice == 2)
            break;

        cout << "Ayti h epilogh den yparxei, ksanaprospathise." << endl;
    }

    while (cin.get() != '\n')
        continue;

    return choice;
}

