/*=================================================================================+
|ECNG 2007                                                                         |
|REMEDIAL LAB                                                                      |
|                                                                                  |
|Description                                                                       |
|The game can have multiple players and multiple food objects. The developer (you) |
|decides when to end the game (maybe a certain number of points).                  |
+================================================================================*/

///////////////////////////////////////////////////////////////////////
////////////////   Declaring libraries/definitions/global variables////
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>

#define MAX 10 //Set the size of the playing area
#define SPEED 1 //Set the amount of spaces for a player to move.

using namespace std;

char a[MAX][MAX];//This is the 2D char array on which the game is played.

bool stopgame = false; //Used to store the state of the game.


/////////////////////////////////////////////////////////////////////////
/////               CLASS/FUNCTION DEFINITIONS                      /////
/////////////////////////////////////////////////////////////////////////

//printMap clears the console window before printing everything
//in the 2D char array.
void printMap(){
	system("cls");
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}

/*
THIS FUNCTION IS INCOMPLETE.
PLEASE EDIT TO SUIT.
*/
//Initialise the boundary for the level
void initBoundary(){
	for(int i=0;i<MAX; i++){
		a[i][0]='#'; //sets left boundary
		a[0][i]='#'; //sets upper boundary
		a[i][MAX-1]='#';
		a[MAX-1][i]='#';
	}
}


//Player class handles the positioning, movement,
//and score of a player.
class Player {
	private:
		int x,y;
		int score;
		char name;

	public:
		Player(){};//Default constructor
		
		//Overidden constructor which initialises the player's position
		//(x and y coordinates) and score.
		Player(int xPos, int yPos, int s, char n){
			x=xPos;
			y=yPos;
			score=s;
			name=n;
			a[x][y]= name;
		}
		
		//Accessors
		int getX(){return x;}
		int getY(){return y;}
		void printScore(){
			cout<<name<<"'s score = "<<score<<endl;
		}
		int getScore(){
			return score;
		}

		//Mutators
		void updateScore(int s){
			score+=s;
		}
		
		void resetScore(){
			score = 0;
		}

		void playerCollide(Player p){
			if((p.getX()==x)&&(p.getY()==y)){ //if players collide take the score of the other player
			   updateScore(p.getScore());
			   resetScore(); //investigate this, to reset the eaten player's score

			   stopgame=true;
			}
		}

		//This function handles the movement of the player
		void updatePlayer(int n){
			if(n==1){//UP
				if(x-SPEED<1)return; //if player goes out of bounds, don't do anything.
				a[x][y]=' '; //reset old position
				x-=SPEED;    //update x position
				a[x][y]=name; //update new position in 2D char array
			}
			if(n==2){//DOWN
				if(x+SPEED>MAX-2)return;//if player goes out of bounds, don't do anything.
				a[x][y]=' ';
				x+=SPEED;
				a[x][y]=name;
			}
			if(n==3){//LEFT
				if(y-SPEED<1)return; //if player goes out of bounds, don't do anything.
				a[x][y]=' '; //reset old position
				y-=SPEED;    //update y position
				a[x][y]=name; //update new position in 2D char array
			}
			if(n==4){//RIGHT
				if(y+SPEED>MAX-2)return;
				a[x][y]=' ';
				y+=SPEED;
				a[x][y]=name;
			}
		}

};

//Food class handles the position of food on the map,
//and the points associated with eating each food object.
//NB. points can be negative.
class Food{
	private:
		char name; //Symbol used to represent object on map.
		int x,y,points;//coordinates and points for eating food.

	public:
		Food(){};//Default constructor
		
		//Overidden constructor used to set position of food,
		//char representation, and amount of points.
		Food(int xPos, int yPos, char n,int p){
			name=n;
			points = p;
			x = xPos;
			y = yPos;
			a[x][y]=n;
		}
		
		/*INCOMPLETE FUNCTION*/
		//This function checks if a player has collided with
		//this food. If yes,then return the number of points to
		//update player's score. Else, return 0.
		int collide(Player p){
			if((p.getX()==x) && (p.getY()==y))
				return points;
			return 0;
		}
};

/////////////////////////////////////////////////////////////////////////
/////               MAIN FUNCTION                                   /////
/////////////////////////////////////////////////////////////////////////
int main(){

	//Initialise map's boundary.
	initBoundary();
	
	//Create player 1
	Player p(1,1,0, 1);

	//Create player 2
	Player q(MAX-2,MAX-2,0, 3);

	//Food objects
	vector<Food>foods;
	foods.push_back(Food(3,3,'&',-5));
	foods.push_back(Food(2,6,'@',10));
	/*CREATE MORE FOOD OBJECTS FOR THE MAP*/

	//Update loop for gameplay
	while(!stopgame){
		printMap();
		
		/*INCOMPLETE CODE*/
		//Update player 1's movement.
		if(GetAsyncKeyState(VK_UP)!=0){//UP Arrow
			p.updatePlayer(1);
			p.playerCollide(q);  //if player one collides with player 'eat' p2 and take its score
		}
		if(GetAsyncKeyState('W')!=0){
			q.updatePlayer(1);
			q.playerCollide(p);
		}
		if(GetAsyncKeyState(VK_DOWN)!=0){//DOWN Arrow
			p.updatePlayer(2);
			p.playerCollide(q);
		}
		if(GetAsyncKeyState('S')!=0){
			q.updatePlayer(2);
			q.playerCollide(p);
		}
		if(GetAsyncKeyState(VK_LEFT)!=0){//LEFT Arrow
			p.updatePlayer(3);
			p.playerCollide(q);
		}
		if(GetAsyncKeyState('A')!=0){
			q.updatePlayer(3);
			q.playerCollide(p);
		}
		if(GetAsyncKeyState(VK_RIGHT)!=0){//RIGHT Arrow
			p.updatePlayer(4);
			p.playerCollide(q);
		}
		if(GetAsyncKeyState('D')!=0){
			q.updatePlayer(4);
			q.playerCollide(p);
		}
		if(GetAsyncKeyState('Q')!=0){
			stopgame=true;
		}
		
		//Keep player1's score on the screen.
		p.printScore();
		q.printScore();

		//Need all food objects to check
		//collision with player1
		for(int i=0; i<foods.size(); i++){
			int s = foods[i].collide(p);
			//if a collision occured, delete food object from vector
			if(s!=0) {
				foods.erase(foods.begin()+i);
				//Update Player 1's score
			    p.updateScore(s);
				break;
			}
			s = foods[i].collide(q);
			if(s!=0){
				foods.erase(foods.begin()+i); 
				q.updateScore(s);
				break;
			}
		}
		if((p.getX()==q.getX())&&(p.getY()==q.getY())){
			//stopgame=true;
		}

		//Tell thread to sleep for 0.1 seconds between updates.
		Sleep(100);

	}//end while
	
}//end main