#pragma once

#define CAPACITY 15

#include <iostream>
#include <fstream>
#include <cstring>

class Planet
{
private:
    char *planetName;
    unsigned int Diameter;
    bool haveLife;
    unsigned int satellites;

private:
    static unsigned total;
    unsigned id = 0;

public:
    void SetPlanetName(char *planetNameToSet)
    {
        delete[] planetName;
        planetName = new char[strlen(planetNameToSet) + 1];
        strcpy(planetName, planetNameToSet);
    }

    void SetDiameter(unsigned int DiameterToSet)
    {
        this->Diameter = DiameterToSet;
    }

    void SetHaveLife(bool haveLifeValue)
    {
        this->haveLife = haveLifeValue;
    }

    void SetSatellites(unsigned int satellitesToSet)
    {
        this->satellites = satellitesToSet;
    }

    char *GetPlanetName()
    {
        return this->planetName;
    }

    unsigned int GetDiameter()
    {
        return this->Diameter;
    }

    bool GetHaveLife()
    {
        return this->haveLife;
    }

    unsigned int GetSatellites()
    {
        return this->satellites;
    }

    unsigned GetID()
    {
        return this->id;
    }

    Planet()
    {
        planetName = new char[1];
        planetName[0] = '\0';
        total++;
        id = total;
        //std::cout << "created ID " << id << "\n";
    }

    Planet(char *p, unsigned d = 0, bool h = 0, unsigned s = 0)
    {
        planetName = new char[strlen(p) + 1];
        strcpy(planetName, p);
        total++;
        id = total;
        //std::cout << "created ID " << id << "\n";
    }

    ~Planet()
    {
        total--;
        //std::cout << "deleted ID " << id << "\n";
        delete[] planetName;
    }

    void operator=(Planet &planet_)
    {
        if (this == &planet_)
        {
            return;
        }
        char *newName = new char[30];
        strcpy(newName, planet_.GetPlanetName());
        this->SetPlanetName(newName);

        this->SetDiameter(planet_.GetDiameter());
        this->SetHaveLife(planet_.GetHaveLife());
        this->SetSatellites(planet_.GetSatellites());

        delete[] newName;
    }

    bool operator==(Planet &planetForEqual)
    {
        return this->Diameter == planetForEqual.GetDiameter();
    }

    bool operator<(Planet &planetForCompare)
    {
        return this->Diameter < planetForCompare.GetDiameter();
    }

    Planet(Planet &planetToCopy)
    {
        SetPlanetName(planetToCopy.GetPlanetName());
        SetDiameter(planetToCopy.GetDiameter());
        SetHaveLife(planetToCopy.GetHaveLife());
        SetSatellites(planetToCopy.GetSatellites());
    }

    static void AddPlanet(Planet *db, size_t &size, Planet &planetToAdd);
    static void PrintDB(Planet *mas, size_t size);
    static void DBtoFile(Planet *mas, size_t size, const char *file1);
    static void Sort(Planet *mas, size_t size);
    static unsigned FindID(char *planetToFind, Planet *mas, size_t size);
    static void DeletePlanet(Planet *mas, size_t &size, char *planetToDelete);
    static void EditPlanetValues(Planet *mas, size_t size);
};

std::istream &operator>>(std::istream &in, Planet &planet);
std::ostream &operator<<(std::ostream &out, Planet &planet);
unsigned menu();