#include "planet.h"
#include "bus.h"

int interactive()
{
    Bus db[15];
    size_t size = 0;
    std::fstream file("busdata.txt");
    while (true)
    {
        switch (menuBus())
        {
        case 1:
            while (file)
            {
                file >> db[size++];
            }
            size--;
            break;
        case 2:
            Bus::DBtoFile(db, size, "busdata.txt");
            break;
        case 3:
            Bus::EditBusValues(db, size);
            break;
        case 4:
            Bus::PrintDB(db, size);
            break;
        case 5:
            Bus::Sort(db, size);
            break;
        case 6:
            Bus::AddBus(db, size);
            break;
        case 7:
            Bus::DeleteBus(db, size);
            break;
        case 8:
            return 0;
            break;
        default:
            std::cout << "\nWrong input, try again)\n";
            break;
        }
    }
    return 0;
}

int demo()
{
    Planet db[15];
    size_t size = 0;

    std::fstream file("data.txt");
    while (file)
    {
        file >> db[size++];
    }
    size--;

    std::cout << "\nprinting database:\n";
    Planet::PrintDB(db, size);
    std::cout << "\nsorting database:\n";
    Planet::Sort(db, size);
    std::cout << "\nprinting database:\n";
    Planet::PrintDB(db, size);
    std::cout << "\nDeleting mercury...\n";
    char planetName[30];
    strcpy(planetName, "Mercury");
    Planet::DeletePlanet(db, size, planetName);
    std::cout << "\nprinting database:\n";
    Planet::PrintDB(db, size);
    std::cout << "\nadding moon with 780 as diameter, false value of having life and 10 satellites :) :\n";
    Planet moon;
    strcpy(planetName, "Moon");
    moon.SetPlanetName(planetName);
    moon.SetDiameter(780);
    moon.SetHaveLife(0);
    moon.SetSatellites(10);
    Planet::AddPlanet(db, size, moon);
    std::cout << "\nprinting database:\n";
    Planet::PrintDB(db, size);
    std::cout << "\nmerging to file:\n";
    Planet::DBtoFile(db, size, "data.txt");
    return 0;
}

int main(int argc, char *argv[])
{
    system("chcp 1251");
    bool isInteractive = false;
    if ((argc == 2) && strcmp(argv[1], "i") == 0)
    {
        isInteractive = true;
    }

    if (isInteractive)
    {
        return interactive();
    }
    else
    {
        return demo();
    }
    return 0;
}