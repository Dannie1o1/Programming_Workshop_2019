#include "bits/stdc++.h"
using namespace std;
class House
{
    private:
    //Only properties inside of the house can be access by those who are inside of the class
    vector < string > listOfOwners;
    vector <string> listOfRooms;
    bool anyOneHome;
    string nameOfHouse;

    protected:
    //What other properties of your house is shared with other things (Garage, Insurance, Garden, Pool, etc.)

    public:
    //What Everyone Sees and can interact with a superficial level 
    House(string nameOfHouse, string originalOwner)
    {
        cout << "The House Constructor is being called" << endl;

        //Initialize variables 
        listOfOwners.clear();
        listOfRooms.clear();
        anyOneHome = false;
        this->nameOfHouse = nameOfHouse;

        //Add originalOwner
       // listOfOwners.push_back(make_pair(originalOwner,true));
       listOfOwners.push_back("Jason Gordon");
    }
    
    void getListOfOwners()
    {
        cout << "There is/are " << listOfOwners.size() << " owner(s) to the house: " << nameOfHouse << endl;
        cout << "List of Owners:" << endl;

        for(int i = 0; i < listOfOwners.size(); i++)
        {
            cout << i+1 << ") " << listOfOwners[i] << endl;
        } 
        return; 
    }

    void addOwner(string requestor, string newOwner)
    {	
        // Check if requester is already an owner
        vector<string>::iterator it = find(listOfOwners.begin(), listOfOwners.end(), requestor);
        if (it != listOfOwners.end())
        {
            cout << "Requester: " << requestor << " RECOGNIZED!" << endl;
            cout << "Adding " << newOwner << " as an owner to the house" << endl;

            listOfOwners.push_back(newOwner);
        }
        else
        {
            cout << "Requester: " << requestor << " NOT RECOGNIZED" << endl;
            cout << "New Owner: " << newOwner <<" could not be added!" << endl;
        }
        
        return;
    }

    void addRoom(string owner, int floor)
    {

    }

    void addFloor()
    {
        
    }



    ~House ()
    {
        cout << "House Deconstructor is being called" << endl;
    }
};

void solDriver()
{
    House myHouse("GFAM","Jason Gordon");
    myHouse.getListOfOwners();
    myHouse.addOwner("Jason Gordon","Daniel Gordon");
    myHouse.getListOfOwners();
    myHouse.addOwner("Bob","Jane");
}

int main()
{
    cout << "The Program is Running" << endl;
    solDriver();
    return 0;
}