#include "planet.h"

int main()
{
    system("chcp 1251");

    Planet *db = new Planet[CAPACITY];
    std::fstream file("data.txt");
    size_t size = 0;
    
    
    //int ans;
    // while (true)
    // {
    //     switch (menu())
    //     {
    //     case 1:
    //         while (file)
    //         {
    //             file >> db[size++];
    //         }
    //         break;
    //     case 2:
    //         Planet::DBtoFile(db,size,file);
    //         break;
    //     case 3:
    //         Planet::EditPlanetValues(db,size);
    //         break;
    //     case 4:
    //         Planet::PrintDB(db,size);
    //         break;
    //     case 5:
    //         Planet::Sort(db,size);
    //         break;
    //     case 6:
    //         Planet::AddPlanet(db,size);
    //         break;
    //     case 7:
    //         Planet::DeletePlanet(db,size);
    //         break;
    //     case 8:
    //         return 0;
    //         delete[] db;
    //         break;
    //     default:
    //         std::cout<<"\nWrong input, try again)\n";
    //         break;
    //     }
    // }
    

    
}