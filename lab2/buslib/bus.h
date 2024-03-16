#pragma once

#ifndef CAPACITY
#define CAPACITY 12
#endif

#include <iostream>
#include <fstream>
#include <cstring>

class Bus
{
    char *busModel;
    unsigned yearOfIssue = 0;
    unsigned mileage = 0;
    bool availability = 0;

    static unsigned total;
    unsigned id = 0;

public:
    void SetBusModel(char *busModelToSet)
    {
        delete[] busModel;
        busModel = new char[strlen(busModelToSet) + 1];
        strcpy(busModel, busModelToSet);
    }

    void SetYearOfIssue(unsigned yearOfIssueToSet)
    {
        this->yearOfIssue = yearOfIssueToSet;
    }

    void SetMileage(unsigned mileageToSet)
    {
        this->mileage = mileageToSet;
    }

    void SetAvailability(bool availabilityValue)
    {
        this->availability = availabilityValue;
    }

    char *GetBusModel()
    {
        return this->busModel;
    }

    unsigned GetYearOfIssue()
    {
        return this->yearOfIssue;
    }

    unsigned GetMileage()
    {
        return this->mileage;
    }

    bool GetAvailability()
    {
        return this->availability;
    }

    Bus()
    {
        busModel = new char[1];
        busModel[0] = '\0';
        total++;
        id = total;
        //std::cout << "created ID " << id << "\n";
    }

    Bus(char *m, unsigned y, unsigned mile, bool av)
    {
        busModel = new char[strlen(m) + 1];
        strcpy(busModel, m);
        total++;
        id = total;
        //std::cout << "created ID " << id << "\n";
    }

    ~Bus()
    {
        total--;
        //std::cout << "deleted ID " << id << "\n";
        delete[] busModel;
    }

    void operator=(Bus &bus_)
    {
        if (this == &bus_)
        {
            return;
        }

        char *newModel = new char[15];
        strcpy(newModel, bus_.GetBusModel());
        this->SetBusModel(newModel);

        this->SetYearOfIssue(bus_.GetYearOfIssue());
        this->SetMileage(bus_.GetMileage());
        this->SetAvailability(bus_.GetAvailability());

        delete[] newModel;
    }

    bool operator==(Bus &busForEqual)
    {
        return this->GetMileage() == busForEqual.GetMileage();
    }

    bool operator<(Bus &busForCompare)
    {
        return this->GetMileage() < busForCompare.GetMileage();
    }

    Bus(Bus &busToCopy)
    {
        SetBusModel(busToCopy.GetBusModel());
        SetYearOfIssue(busToCopy.GetYearOfIssue());
        SetMileage(busToCopy.GetMileage());
        SetAvailability(busToCopy.GetAvailability());
    }

    static void AddBus(Bus *db, size_t &size);
    static void PrintDB(Bus *mas, size_t size);
    static void DBtoFile(Bus *mas, size_t size, const char *file1);
    static void Sort(Bus *mas, size_t size);
    static unsigned FindID(char *busModelToFind, Bus *mas, size_t size);
    static void DeleteBus(Bus *mas, size_t &size);
    static void EditBusValues(Bus *mas, size_t size);
};

std::istream &operator>>(std::istream &in, Bus &bus);
std::ostream &operator<<(std::ostream &out, Bus &bus);
unsigned menuBus();