#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

double inicializeNotNegativeDouble() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream
		// as it is in the wrong format
	}
	return temp_var;
}

double inicializeDouble() { // function that check type error
	double temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream
		// as it is in the wrong format
	}
	return temp_var;
}

int inicializeNotNegativeInteger() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var) || temp_var < 0)
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream 
		// as it is in the wrong format
	}
	return temp_var;
}

int inicializeInteger() { // function that check type error
	int temp_var; // inicialization of temporary variable 
	while (!(cin >> temp_var))
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream as 
		// it is in the wrong format
	}
	return temp_var;
}

void f1() {
	
}

void f2() {

}

int main() {
	int chooseTask;
	setlocale(LC_ALL, "Russian");
	cout << "Hello!\nTask number can't be more than 9.\n"
		"Enter 0 to end the programm.\n"
		"Enter the task number: \n";
	chooseTask = inicializeNotNegativeInteger();
	while (chooseTask > 0) {
		switch (chooseTask) {
		case 1:
			f1();
			break;
		case 2:
			f2();
			break;
		default:
			cout << "Entered task number is incorrect, try again.\n"
				"Task number can't be more than 2.\n"
				"Enter 0 to end the programm.\n";
			break;
		}
		cout << "Enter the next task number:\n";
		chooseTask = inicializeNotNegativeInteger();;
	}
}