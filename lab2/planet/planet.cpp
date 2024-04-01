#include "planet.h"

unsigned Planet::total = 0;

void Planet::AddPlanet(Planet *db, size_t &size, Planet &planetToAdd)
{
    if (size == CAPACITY)
    {
        std::cout << "FULL OF CAPACITY";
        return;
    }
    db[size++] = planetToAdd;
}

void Planet::PrintDB(Planet *mas, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << mas[i];
    }
}

void Planet::DBtoFile(Planet *mas, size_t size, const char *file1)
{
    std::fstream file(file1);
    for (size_t i = 0; i < size; i++)
    {
        file << mas[i];
    }
    file.close();
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

void Planet::DeletePlanet(Planet *mas, size_t &size, char *planetToDelete)
{
    int curIndex = -1;

    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(planetToDelete, mas[i].GetPlanetName()) == 0)
        {
            curIndex = i;
            break;
        }
    }

    if (curIndex == -1)
    {
        std::cout << "Planet not found";
        return;
    }

    size--;
    for (size_t i = curIndex; i < size; i++)
    {
        mas[i] = mas[i + 1];
    }
    std::cout << "planet deleted";

    return;
}

void Planet::EditPlanetValues(Planet *mas, size_t size)
{
    char planetName[30];
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

    std::cout << "which one of the values you want to edit: Name of the planet(press 1), Diameter(press 2), Having of life(press 3), Number of satellites(press 4)";
    int ans;
    std::cin >> ans;
    switch (ans)
    {
    case 1:
        std::cout << "enter new name of the planet:";
        char ansName[30];
        std::cin >> ansName;
        mas[curIndex].SetPlanetName(ansName);
        std::cout << "\n";
        break;
    case 2:
        std::cout << "enter new diameter:";
        unsigned newDiameter;
        std::cin >> newDiameter;
        mas[curIndex].SetDiameter(newDiameter);
        std::cout << "\n";
        break;
    case 3:
        std::cout << "New 'having of life' value?(1/0)";
        bool newValue;
        std::cin >> newValue;
        mas[curIndex].SetHaveLife(newValue);
        std::cout << "\n";
        break;
    case 4:
        std::cout << "set new number of satellites:";
        unsigned satellites;
        std::cin >> satellites;
        mas[curIndex].SetSatellites(satellites);
        std::cout << "\n";
        break;
    default:
        break;
    }

    
    return;
}

unsigned menu()
{
    unsigned ans;
    std::cout << "\nPress 1 to read Database\n";
    std::cout << "Press 2 to write to Database\n";
    std::cout << "Press 3 to edit planet values\n";
    std::cout << "Press 4 to print Database\n";
    std::cout << "Press 5 to sort Database\n";
    std::cout << "Press 6 to add planet\n";
    std::cout << "Press 7 to delete planet\n";
    std::cout << "Press 8 to exit\n";
    std::cin >> ans;
    return ans;
}

void Planet::SetPlanetName(char *planetNameToSet)
{
    if (planetName!=nullptr)
    {
        delete[] planetName;
    }
    
    
    planetName = new char[strlen(planetNameToSet) + 1];
    strcpy(planetName, planetNameToSet);
}

void Planet::SetDiameter(unsigned int DiameterToSet)
{
    Diameter = DiameterToSet;
}

void Planet::SetHaveLife(bool haveLifeValue)
{
    haveLife = haveLifeValue;
}

void Planet::SetSatellites(unsigned int satellitesToSet)
{
    satellites = satellitesToSet;
}

char* Planet::GetPlanetName()
{
    return planetName;
}

unsigned int Planet::GetDiameter()
{
    return Diameter;
}

bool Planet::GetHaveLife()
{
    return haveLife;
}

unsigned int Planet::GetSatellites()
{
    return satellites;
}

unsigned Planet::GetID()
{
    return id;
}

Planet::Planet()
{
    planetName = new char[1];
    planetName[0] = '\0';
    total++;
    id = total;
    // std::cout << "created ID " << id << "\n";
}

Planet::Planet(char *p, unsigned d, bool h, unsigned s)
{
    planetName = new char[strlen(p) + 1];
    strcpy(planetName, p);
    total++;
    id = total;
    // std::cout << "created ID " << id << "\n";
}

Planet::~Planet()
{
    total--;
    // std::cout << "deleted ID " << id << "\n";
    delete[] planetName;
}

Planet& Planet::operator=(Planet &planet_)
{
    if (this == &planet_)
    {
        return *this;
    }
    char newName[30];
    strcpy(newName, planet_.GetPlanetName());
    SetPlanetName(newName);
    Diameter = planet_.Diameter;
    haveLife = planet_.haveLife;
    satellites = planet_.satellites;
    
    return *this;
}

bool Planet::operator==(Planet &planetForEqual)
{
    return Diameter == planetForEqual.Diameter;
}

bool Planet::operator<(Planet &planetForCompare)
{
    return Diameter < planetForCompare.Diameter;
}

Planet::Planet(Planet &planetToCopy)
{
    Diameter = planetToCopy.Diameter;
    haveLife = planetToCopy.haveLife;
    satellites = planetToCopy.satellites;
    SetPlanetName(planetToCopy.GetPlanetName());
}