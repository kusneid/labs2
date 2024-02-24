#include "planet.h"

unsigned Planet::total = 0;

void Planet::AddPlanet(Planet *db, size_t &size)
{
    if (size == CAPACITY)
    {
        std::cout << "FULL OF CAPACITY";
        return;
    }
    std::cout << "enter values of new planet:";
    Planet newPlanet;
    std::cin >> newPlanet;

    db[size++] = newPlanet;
}

void Planet::PrintDB(Planet *mas, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << mas[i];
    }
}

void Planet::DBtoFile(Planet *mas, size_t size, std::fstream &file)
{

    for (size_t i = 0; i < size; i++)
    {
        file << mas[i];
    }
}

void Planet::Sort(Planet *mas, size_t size)
{
    Planet k;
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (mas[j] < mas[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            k = mas[i];
            mas[i] = mas[min];
            mas[min] = k;
        }
    }
}

std::istream &operator>>(std::istream &in, Planet &planet)
{
    char buf[30];
    in >> buf;
    planet.SetPlanetName(buf);

    unsigned Diameter_;
    bool haveLife_;
    unsigned satellites_;
    in >> Diameter_ >> haveLife_ >> satellites_;

    planet.SetDiameter(Diameter_);

    planet.SetHaveLife(haveLife_);

    planet.SetSatellites(satellites_);

    return in;
}

std::ostream &operator<<(std::ostream &out, Planet &planet)
{
    out << planet.GetPlanetName() << " " << planet.GetDiameter() << " " << planet.GetHaveLife() << " " << planet.GetSatellites() << "\n";
    return out;
}

unsigned Planet::FindID(char *planetToFind, Planet *mas, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(mas[i].planetName, planetToFind) == 0)
        {
            return mas[i].id;
        }
    }
    std::cout << "CAN'T FIND PLANET";
    return 0;
}

void Planet::DeletePlanet(Planet *mas, size_t &size)
{
    char planetName[30];
    std::cout << "\nEnter planet name to delete:\n";
    std::cin >> planetName;
    int curIndex = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(planetName, mas[i].GetPlanetName()) == 0)
        {
            curIndex = i;
            break;
        }
    }
    if (curIndex == -1) {
        std::cout << "Planet not found";
        return;
    }
    delete[] mas[curIndex].GetPlanetName();
    size--;
    for (size_t i = curIndex; i < size; i++)
    {
        mas[i] = mas[i + 1];
    }

    return;
}

void Planet::EditPlanetValues(Planet *mas, size_t size)
{
    char *planetName = new char[30];
    std::cout << "\nEnter planet name to edit:\n";
    std::cin >> planetName;
    int curIndex = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(planetName, mas[i].GetPlanetName()) == 0)
        {
            curIndex = i;
            break;
        }
    }
    if (curIndex == -1)
    {
        std::cout << "Planet not found.\n";
        return;
    }
    
    
    std::cout<<"which one of the values you want to edit: Name of the planet(press 1), Diameter(press 2), Having of life(press 3), Number of satellites(press 4)";
    int ans;
    std::cin>>ans;
    switch (ans)
    {
    case 1:
        std::cout<<"enter new name of the planet:";
        char ansName[30];
        std::cin>>ansName;
        delete[] mas[curIndex].GetPlanetName();
        mas[curIndex].SetPlanetName(ansName);
        std::cout<<"\n";
        break;
    case 2:
        std::cout<<"enter new diameter:";
        unsigned newDiameter;
        std::cin>>newDiameter;
        mas[curIndex].SetDiameter(newDiameter);
        std::cout<<"\n";
        break;
    case 3:
        std::cout<<"New 'having of life' value?(1/0)";
        bool newValue;
        std::cin>>newValue;
        mas[curIndex].SetHaveLife(newValue);
        std::cout<<"\n";
        break;
    case 4:
        std::cout<<"set new number of satellites:";
        unsigned satellites;
        std::cin>>satellites;
        mas[curIndex].SetSatellites(satellites);
        std::cout<<"\n";
        break;
    default:
        break;
    }

    delete[] planetName;
    return;
}

unsigned MenuForBus(){
    unsigned ans;
    std::cout<<"\nPress 1 to read Database\n";
    std::cout<<"Press 2 to write to Database\n";
    std::cout<<"Press 3 to edit planet values\n";
    std::cout<<"Press 4 to print Database\n";
    std::cout<<"Press 5 to sort Database\n";
    std::cout<<"Press 6 to add planet\n";
    std::cout<<"Press 7 to delete planet\n";
    std::cout<<"Press 8 to exit\n";
    std::cin>>ans;
    return ans;
}