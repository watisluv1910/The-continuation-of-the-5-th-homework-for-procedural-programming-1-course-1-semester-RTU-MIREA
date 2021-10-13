#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

double inicializeNotNegativeDouble() { // function that check type error
	double temporaryVariable; // inicialization of temporary variable 
	while (!(cin >> temporaryVariable) || temporaryVariable < 0)
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream
		// as it is in the wrong format
	}
	return temporaryVariable;
}

double inicializeDouble() { // function that check type error
	double temporaryVariable; // inicialization of temporary variable 
	while (!(cin >> temporaryVariable))
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream
		// as it is in the wrong format
	}
	return temporaryVariable;
}

int inicializeNotNegativeInteger() { // function that check type error
	int temporaryVariable; // inicialization of temporary variable 
	while (!(cin >> temporaryVariable) || temporaryVariable < 0)
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream 
		// as it is in the wrong format
	}
	return temporaryVariable;
}

int inicializeInteger() { // function that check type error
	int temporaryVariable; // inicialization of temporary variable 
	while (!(cin >> temporaryVariable))
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream as 
		// it is in the wrong format
	}
	return temporaryVariable;
}

void f1() {
	cout << "";

	int choosepath = inicializeInteger();
}

void f2() {

}

void f3() {

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
		case 3:
			f3();
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