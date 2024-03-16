#include "bus.h"

unsigned Bus::total = 0;

void Bus::AddBus(Bus *db, size_t &size)
{
    if (size == CAPACITY)
    {
        std::cout << "FULL OF CAPACITY\n";
        return;
    }
    std::cout << "enter values of new bus:\n";
    Bus newBus;
    std::cin >> newBus;

    db[size++] = newBus;
}

void Bus::PrintDB(Bus *mas, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << mas[i];
    }
}

void Bus::DBtoFile(Bus *mas, size_t size, const char *file1)
{
    std::ofstream file(file1);
    for (size_t i = 0; i < size; i++)
    {
        file << mas[i];
    }
    file.close();
}

void Bus::Sort(Bus *mas, size_t size)
{

    Bus k;
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

std::istream &operator>>(std::istream &in, Bus &bus)
{

    char model[30];
    in >> model;
    bus.SetBusModel(model);

    unsigned year;
    unsigned mileage;
    bool availability;
    in >> year >> mileage >> availability;

    bus.SetYearOfIssue(year);
    bus.SetMileage(mileage);
    bus.SetAvailability(availability);

    return in;
}

std::ostream &operator<<(std::ostream &out, Bus &bus)
{
    out << bus.GetBusModel() << " " << bus.GetYearOfIssue() << " " << bus.GetMileage() << " " << bus.GetAvailability() << "\n";
    return out;
}

unsigned Bus::FindID(char *modelToFind, Bus *mas, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(mas[i].GetBusModel(), modelToFind) == 0)
        {
            return mas[i].id;
        }
    }
    std::cout << "CAN'T FIND BUS";
    return 0;
}

void Bus::DeleteBus(Bus *mas, size_t &size)
{
    char modelName[30];
    std::cout << "\nEnter bus model to delete:\n";
    std::cin >> modelName;
    int curIndex = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(modelName, mas[i].GetBusModel()) == 0)
        {
            curIndex = i;
            break;
        }
    }
    if (curIndex == -1)
    {
        std::cout << "Bus not found.";
        return;
    }
    size--;
    for (size_t i = curIndex; i < size; i++)
    {
        mas[i] = mas[i + 1];
    }

    return;
}

void Bus::EditBusValues(Bus *mas, size_t size)
{
    char *modelName = new char[30];
    std::cout << "\nEnter bus model to edit:\n";
    std::cin >> modelName;
    int curIndex = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(modelName, mas[i].GetBusModel()) == 0)
        {
            curIndex = i;
            break;
        }
    }
    if (curIndex == -1)
    {
        std::cout << "Bus not found.\n";
        return;
    }

    std::cout << "which value do you want to edit: Model (press 1), Year of issue (press 2), Mileage (press 3), Availability (press 4)";
    int ans;
    std::cin >> ans;
    switch (ans)
    {
    case 1:
        std::cout << "enter new model name:";
        char newModel[30];
        std::cin >> newModel;
        mas[curIndex].SetBusModel(newModel);
        std::cout << "\n";
        break;
    case 2:
        std::cout << "enter new year of issue:";
        unsigned newYear;
        std::cin >> newYear;
        mas[curIndex].SetYearOfIssue(newYear);
        std::cout << "\n";
        break;
    case 3:
        std::cout << "enter new mileage:";
        unsigned newMileage;
        std::cin >> newMileage;
        mas[curIndex].SetMileage(newMileage);
        std::cout << "\n";
        break;
    case 4:
        std::cout << "New availability value? (1/0):";
        bool newAvailability;
        std::cin >> newAvailability;
        mas[curIndex].SetAvailability(newAvailability);
        std::cout << "\n";
        break;
    default:
        break;
    }
    delete[] modelName;
    return;
}

unsigned menuBus()
{
    unsigned ans;
    std::cout << "\nPress 1 to read Database\n";
    std::cout << "Press 2 to write to Database\n";
    std::cout << "Press 3 to edit bus values\n";
    std::cout << "Press 4 to print Database\n";
    std::cout << "Press 5 to sort Database\n";
    std::cout << "Press 6 to add bus\n";
    std::cout << "Press 7 to delete bus\n";
    std::cout << "Press 8 to exit\n";
    std::cin >> ans;
    return ans;
}