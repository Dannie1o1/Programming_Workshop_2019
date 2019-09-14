#include <iostream>
#include <string>

using namespace std;

class vehicle //Parent
{
    protected:
        int seatingCapacity;
        string engine;
        int feulCapacity;
        string colour;
        int numOfWheels;
        string name;

    public:
    //Constructor
    vehicle(){}
    void printVehicleDetails()
    {
        cout << "# of Seats = " << seatingCapacity << endl;
        cout << "Eng Name = " << engine << endl;
        cout << "Feul Cap = " << feulCapacity << endl;
        cout << "Num of Wheels = " << numOfWheels << endl;
        cout << "Vehicle Name = " << name << endl;

    }
    ~vehicle(){}
};

class car: public vehicle
{
    private:
        
    public:

    car (int NumOfSeats, int FuelCapacity, int NumOfWheels, string Name)
    {
        seatingCapacity =  NumOfSeats;
        feulCapacity = FuelCapacity;
        numOfWheels = NumOfWheels;
        name = Name;
    }
};

int main()
{
    car carObj1 (5, 120, 4, "Tiida");
    carObj1.printVehicleDetails();
    return 0;
}
