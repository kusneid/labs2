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
    void SetBusModel(char *busModelToSet);

    void SetYearOfIssue(unsigned yearOfIssueToSet);

    void SetMileage(unsigned mileageToSet);

    void SetAvailability(bool availabilityValue);

    char *GetBusModel();

    unsigned GetYearOfIssue();

    unsigned GetMileage();

    bool GetAvailability();

    Bus();

    Bus(char *m, unsigned y, unsigned mile, bool av);

    ~Bus();

    Bus& operator=(Bus &bus_);

    bool operator==(Bus &busForEqual);

    bool operator<(Bus &busForCompare);

    Bus(Bus &busToCopy);
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