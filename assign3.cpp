/*********************************************************************
** Program Filename: assign3.cpp
** Author: Carlos Lopez Molina
** Date: January 31st, 2016
** Description: Program that will output and guide the rover to its destination.
** Input: Starting and destination coordinates for rover
** Output: Rover path from user given start and end points
*********************************************************************/
#include <iostream>
#include <string>
#include <limits> //for errorchecking

using namespace std;

void print_Blank();
void print_Grid(int, int, int, int);
void find_path(int xStart, int yStart, int xEnd, int yEnd);
int error_check(int point);

int main(){
	
	int xStart, yStart, xEnd, yEnd, again;
	
	do{
	cout << "Lets guide the rover. Here is our starting grid: " << endl;

	print_Blank();
	
	cout << "What is the rovers starting position? Insert the coordinate x followed by y (x,y): " << endl;
	//cin >> xStart >> yStart; dont need this because of error checking function
	
	//function to check if number between 0 and 3 then prompt for new number
	xStart = error_check(xStart);
	yStart = error_check(yStart);
	
	cout << "What is the destination? Insert the coordinate x followed by y (x,y): " << endl;
	//cin >> xEnd >> yEnd; dont need
	
	//Destination error checking for numbers too big or small
	xEnd = error_check(xEnd);
	yEnd = error_check(yEnd);

	cout << "The grid showing your starting (" << xStart << "," << yStart << ") and ending (" << xEnd << "," << yEnd << ") coordinates. " << endl;
	
	print_Grid(xStart, yStart, xEnd, yEnd);
	
	cout << endl;
	cout << "Moving rover to destination: " << endl;
	cout << "--------------------------------------" << endl;
	
	find_path(xStart, yStart, xEnd, yEnd);
	
	cout << "Insert 0 if you would like to end the program, else insert 1 to run again. ";
	cin >> again;
	cout << endl;
	while ((again!=0) && (again!=1)){
		cout << "Insert 0 or 1!" << endl;
		cin >> again;
	}
	}while (again != 0); //loops for how many times want to re-do
	
	return 0;
}
/*********************************************************************
**Function: find_path
**Description: finds the path from the starting positon to the ending position as well as prints the path to the screen
**Parameters: xStart, yStart, xEnd, yEnd
**Return: None
**Pre-Conditions: all parameters are valid integers
**Post-Conditions: no change to the parameters and the path will have been printed to the screen
*********************************************************************/
void find_path(int xStart, int yStart, int xEnd, int yEnd){
	//checking and comparing coordinates 
	if ((xStart == xEnd) && (yStart < yEnd)){ //same coordinate and yStart smaller than yEnd
		do {
			yStart=yStart++;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (yStart != yEnd);
	}
	else if ((xStart < xEnd) && (yStart == yEnd)){ //xStart smaller than xEnd and y's are equal
		do{
			xStart=xStart++;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (xStart != xEnd);
	}
	else if ((xStart == xEnd) && (yStart > yEnd)){ //both x's equal and yStart greater than yEnd
		do{
			yStart=yStart--;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (yStart != yEnd);
	}
	else if ((xStart < xEnd) && (yStart > yEnd)){ //xStart less than xEnd and yStart greater than yEnd (inc & dec starts)
		do{
			xStart=xStart++;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (xStart != xEnd);
		do{
			yStart=yStart--;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (yStart != yEnd);
	}
	else if ((xStart > xEnd) && (yStart == yEnd)){ //xStart greater than and both ys are equal
		do{
			xStart=xStart--;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (xStart != xEnd);
	}
	else if ((xStart > xEnd) && (yStart < yEnd)){ //xStart greater than xEnd and yStart less than yEnd (dec and inc)
		do{
			xStart=xStart--;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (xStart != xEnd);
		do{
			yStart=yStart++;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (yStart != yEnd);
	}
	else if ((xStart < xEnd) && (yStart < yEnd)){ //xStart less than xEnd and yStart less than yEnd (inc and inc)
		do{
			xStart=xStart++;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (xStart != xEnd);
		do{
			yStart=yStart++;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (yStart != yEnd);
	}
	else if ((xStart > xEnd) && (yStart > yEnd)){ //xStart greater than xEnd and yStart greater than yEnd (dec and dec)
		do{
			xStart=xStart--;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (xStart != xEnd);
		do{
			yStart=yStart--;
			print_Grid(xStart, yStart, xEnd, yEnd);
			cout << "--------------------------------------" << endl;
		}while (yStart != yEnd);
	}
}
/*********************************************************************
** Function: print_Blank
** Description: outputs the 4x4 grid
** Parameters: none
** Return: none
** Pre-Conditions: each line of the grid made as string
** Post-Conditions: Will output strings to show grid with start to end points
*********************************************************************/
void print_Blank(){
	string top =    "----------";
	string three =  "3| | | | |" ;
	string two =    "2| | | | |";
	string one  =   "1| | | | |" ;
	string zero =   "0| | | | |";
	string bottom = " |0|1|2|3|";
	//each line of grid outputed as strings
	cout << top << endl;
	cout << three << endl;
	cout << top << endl;
	cout << two << endl;
	cout << top << endl;
	cout << one << endl;
	cout << top << endl;
	cout << zero << endl;
	cout << top << endl;
	cout << bottom << endl;
}

/*********************************************************************
** Function: print_Grid
** Description: Outputs the grid with starting and ending destination
** Parameters: xStart, yStart, xEnd, yEnd
** Return: none
** Pre-Conditions: all parameters are positive integers and defined
** Post-Conditions: no change in parameters and grid will be printed with starting and ending coordinates marked with x.
*********************************************************************/
void print_Grid(int xStart, int yStart, int xEnd, int yEnd){
	
	string top =    "----------";
	string three =  "3| | | | |" ;
	string two =    "2| | | | |";
	string one  =   "1| | | | |" ;
	string zero =   "0| | | | |";
	string bottom = " |0|1|2|3|";

/****************Starting point!*********************/
//for the zero column
	if (xStart == 0 && yStart == 0){
		zero[2] = 'x';
	}
	else if (xStart == 1 && yStart == 0){
		zero[4] = 'x';
	}
	else if (xStart == 2 && yStart == 0){
		zero[6] = 'x';
	}
	else if (xStart == 3 && yStart == 0){
		zero[8] = 'x';
	}

//for ones column	
	if (xStart == 0 && yStart == 1){
		one[2] = 'x';
	}
	else if (xStart == 1 && yStart == 1){
		one[4] = 'x';
	}
	else if (xStart == 2 && yStart == 1){
		one[6] = 'x';
	}
	else if (xStart == 3 && yStart == 1){
		one[8] = 'x';
	}

//for twos column
	if (xStart == 0 && yStart == 2){
		two[2] = 'x';
	}
	else if (xStart == 1 && yStart == 2){
		two[4] = 'x';
	}
	else if (xStart == 2 && yStart == 2){
		two[6] = 'x';
	}
	else if (xStart == 3 && yStart == 2){
		two[8] = 'x';
	}
	
//for 3s column	
	if (xStart == 0 && yStart == 3){
		three[2] = 'x';
	}
	else if (xStart == 1 && yStart == 3){
		three[4] = 'x';
	}
	else if (xStart == 2 && yStart == 3){
		three[6] = 'x';
	}
	else if (xStart == 3 && yStart == 3){
		three[8] = 'x';
	}	

/****************Destination point!*********************/
//for the zero column
	if (xEnd == 0 && yEnd == 0){
		zero[2] = 'x';
	}
	else if (xEnd == 1 && yEnd == 0){
		zero[4] = 'x';
	}
	else if (xEnd == 2 && yEnd == 0){
		zero[6] = 'x';
	}
	else if (xEnd == 3 && yEnd == 0){
		zero[8] = 'x';
	}
//ones collumn
	if (xEnd == 0 && yEnd == 1){
		one[2] = 'x';
	}
	else if (xEnd == 1 && yEnd == 1){
		one[4] = 'x';
	}
	else if (xEnd == 2 && yEnd == 1){
		one[6] = 'x';
	}
	else if (xEnd == 3 && yEnd == 1){
		one[8] = 'x';
	}
//two collumn
	if (xEnd == 0 && yEnd == 2){
		two[2] = 'x';
	}
	else if (xEnd == 1 && yEnd == 2){
		two[4] = 'x';
	}
	else if (xEnd == 2 && yEnd == 2){
		two[6] = 'x';
	}
	else if (xEnd == 3 && yEnd == 2){
		two[8] = 'x';
	}
//three collumn	
	if (xEnd == 0 && yEnd == 3){
		three[2] = 'x';
	}
	else if (xEnd == 1 && yEnd == 3){
		three[4] = 'x';
	}
	else if (xEnd == 2 && yEnd == 3){
		three[6] = 'x';
	}
	else if (xEnd == 3 && yEnd == 3){
		three[8] = 'x';
	}	
	
	cout << top << endl;	//Print the grid with starting and ending positions
	cout << three << endl;
	cout << top << endl;
	cout << two << endl;
	cout << top << endl;
	cout << one << endl;
	cout << top << endl;
	cout << zero << endl;
	cout << top << endl;
	cout << bottom << endl;
}

/*********************************************************************
** Function: errorcheck
** Description: checks the coordinate for invalid input
** Parameters: point
** Return: new coordinate if not the int wanted
** Pre-Conditions: called when an input is needed to be inserted and checked
** Post-Conditions: value will always be an whole number int between the numbers 0 and 3.
*********************************************************************/
int error_check(int point){
	
	while (!(cin >> point)){ //while point has not been received
		cin.clear(); //clear whats in cin (fail state)
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); //checks the input and replaces with new value
		cout << "I will only take the whole number! Try again." << endl;
	}
	while (point < 0 || point > 3){ //check if number != to 0-3
		cout << "Please enter a number between 0 and 3." << endl;
		while(!(cin >> point)){ //fail state
			cin.clear(); //removes fail state
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); //checking if good integer then replaces
			cout << "You entered an invalid input, try again." << endl;
		}
	}
	return point;
}
