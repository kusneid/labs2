#pragma once

#include <iostream>
#include <fstream>

class Planet{
    char* planetName;
    unsigned int Diameter;
    bool haveLife;
    unsigned int satellites;

    Planet(){
        planetName = new char[30];
    }
    ~Planet(){
        delete[] planetName;
    }
    Planet(const Planet &planetToCopy){
        planetName = planetToCopy.planetName;
        Diameter = planetToCopy.Diameter;
        haveLife = planetToCopy.haveLife;
        satellites = planetToCopy.satellites;
    }

};