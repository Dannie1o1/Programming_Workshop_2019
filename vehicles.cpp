#include <iostream>
#include <string>

using namespace std;

class vehicle //Parent
{
    protected:
        int seatingCapacity;
        string engine;
        int fuelCapacity;
        int currentFuel;
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
        cout << "Fuel Cap = " << fuelCapacity << endl;
        cout << "Num of Wheels = " << numOfWheels << endl;
        cout << "Vehicle Name = " << name << endl;

    }

    void travel(int fuelCapacity)
    {
        if(currentFuel >= fuelCapacity)
        {
            currentFuel = currentFuel-fuelCapacity;
        }
        else
        {
            cout << "Cannot make the journey" << endl;
        }

        cout << "Current fuel is now...." << currentFuel << endl;
    }

    void fillTank(int fuelAmt)
    {
        //Check if more than fuelAmt
        currentFuel = currentFuel + fuelAmt;
        if (currentFuel > fuelCapacity)
        {
            currentFuel = fuelCapacity;
        }
        cout << "Current Fuel = " << currentFuel << endl;
    }
    ~vehicle(){}
};

class car: public vehicle
{
    private:
        
    public:

    car (int NumOfSeats, int FeulCapacity, int NumOfWheels, string Name)
    {
        seatingCapacity =  NumOfSeats;
        fuelCapacity = FeulCapacity;
        numOfWheels = NumOfWheels;
        name = Name;
        currentFuel = 0;
    }
};

int main()
{
    car carObj1 (5, 120, 4, "Tiida");
    //carObj1.printVehicleDetails();
    carObj1.fillTank(100);
    carObj1.travel(100);
    carObj1.fillTank(100);
    carObj1.travel(100);

    return 0;
}
