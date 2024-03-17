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
    void SetPlanetName(char *planetNameToSet);

    void SetDiameter(unsigned int DiameterToSet);

    void SetHaveLife(bool haveLifeValue);
   
    void SetSatellites(unsigned int satellitesToSet);
   
    char *GetPlanetName();
   
    unsigned int GetDiameter();
  
    bool GetHaveLife();
    
    unsigned int GetSatellites();
  
    unsigned GetID();
   
    Planet();
   
    Planet(char *p, unsigned d = 0, bool h = 0, unsigned s = 0);
    
    ~Planet();
   
    Planet& operator=(Planet &planet_);
    
    bool operator==(Planet &planetForEqual);
   
    bool operator<(Planet &planetForCompare);
    
    Planet(Planet &planetToCopy);
   
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