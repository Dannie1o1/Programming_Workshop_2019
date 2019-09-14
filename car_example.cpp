#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
public:
	//Constructors
	Car() {};
	Car(string name, int miles) {
		setCarName(name);
		setMilesDriven(miles);		
	};

	//Setters
	void setCarName(string name) {
		carName = name;
	}
	void setMilesDriven(int miles) {
		milesDriven = miles;
	}

	//Getters
	string getCarName() {
		return carName;
	}
	int getMilesDriven() {
		return milesDriven;
	}

	//Method (Member Function)
	void checkServiceNeeds() {
		if (milesDriven >= 5000) {
			cout << "Your " << getCarName() << " needs servicing as soon as possible.\n\n";
		}
		else {
			cout << "Your " << getCarName() << " does not need servicing. Hit the road!\n\n";
		}
	}

private:
	//Car variables

	string carName = "XXXXXX";
	int milesDriven = 0;
};

int main() {
	vector <Car> carList;
	//Object Instantiations
	Car car1("Nissan 120Y", 9500);
	Car car2("Subaru Impreza STI", 4000);
	Car car3("Toyota Supra", 2600);

	carList.push_back(car1);
	carList.push_back(car2);
	carList.push_back(car3);
	

	char serviceChoice;
	cout << "There are " << carList.size() << " cars in your garage. Would you like to check if they need servicing? [Y]es or [N}o?\n";
	cin >> serviceChoice;

	if (serviceChoice == 'Y') {
		for (int i = 0; i < carList.size(); i++) {
			carList[i].checkServiceNeeds();
		}
	}
	else {
		cout << "Uhhh so why are you here?\n\n";
	}

	return 0;
}