#include <iostream>

using namespace std;

class Opponent {

protected:
	int attackPower;
public:
	void setAttackPower(int a) {
		attackPower = a;
	}
};


class Troll : public Opponent {
public:
	void attack()      // each Opponent attacks but each attack is specific to the opponent
	{
		cout << "I am the bridge Troll, You shall not pass, Troll SMASH!! - " << attackPower << endl;
	}
};

class Zombies : public Opponent { //Zombies class inherits from Opponent class 
public:
	void attack()
	{
		cout << "mrrrr, Brains!! ----Zombie BITE - " << attackPower << endl;
	}
};


int main() {
	Troll Fluffy;
	Zombies Ben;

	Opponent* Opponent1 = &Fluffy; // fluffy is a Troll which is a type of opponent
	Opponent* Opponent2 = &Ben;    // Ben is also an opponen, anything an opponent can do "Ben the ZOMBIE can do"

	Opponent1->setAttackPower(70);  //each opponent has a set attack power 
	Opponent2->setAttackPower(40);

	Fluffy.attack();
	Ben.attack();
	return 0;
}