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

void runSubtaskTenth() { // refers to the task 'Processing of text files'
	cout << "";

	int choosepath = inicializeInteger();
}

void runSubtaskTwentySeventh() { // refers to the task 'Processing of text files'

}

void runSubtaskNineteenth() { // refers to the task 'Ranks'

}

void runSubtaskSixtySeventh() { // refers to the task 'Ranks'

}

void runSubtaskSeventh() { // refers to the task 'Files'

}

void runSubtaskTwentySixth() { // refers to the task 'Files'

}

int main() {
	int chooseTask;
	setlocale(LC_ALL, "Russian");
	cout << "Hello!\nTask number can't be more than 3.\n"
		"Enter 1 to run the task 'Processing of text files', "
		"2 to run the task 'Ranks', "
		"3 to run the tusk 'Files'.\n"
		"Enter 0 to end the programm.\nEnter the task number :\n";
	chooseTask = inicializeNotNegativeInteger();
	while (chooseTask > 0) {
		switch (chooseTask) {
		case 1 : {
			cout << "Enter the number of subtask :\n";
			int chooseSubtask = inicializeNotNegativeInteger();
			while (chooseSubtask > 0) {
				switch (chooseSubtask) {
				case 10 :
					runSubtaskTenth();
					break;
				case 27 :
					runSubtaskTwentySeventh();
					break;
				default :
					cout << "Entered task number is incorrect, try again.\n"
						"Task number can't be anything except 10 or 27.\n"
						"Enter 0 to end the choosing of the subtask.\n";
					break;
				}
				cout << "Enter the next subtask number:\n";
				chooseSubtask = inicializeNotNegativeInteger();
			}
			break;
		}
		case 2 : {
			cout << "Enter the number of subtask :\n";
			int chooseSubtask = inicializeNotNegativeInteger();
			while (chooseSubtask > 0) {
				switch (chooseSubtask) {
				case 19 :
					runSubtaskNineteenth();
					break;
				case 67 :
					runSubtaskSixtySeventh();
					break;
				default:
					cout << "Entered task number is incorrect, try again.\n"
						"Task number can't be anything except 19 or 67.\n"
						"Enter 0 to end the choosing of the subtask.\n";
					break;
				}
				cout << "Enter the next subtask number:\n";
				chooseSubtask = inicializeNotNegativeInteger();
			}
			break;
		}
		case 3 : {
			cout << "Enter the number of subtask :\n";
			int chooseSubtask = inicializeNotNegativeInteger();
			while (chooseSubtask > 0) {
				switch (chooseSubtask) {
				case 7 :
					runSubtaskSeventh();
					break;
				case 26 :
					runSubtaskTwentySixth();
					break;
				default:
					cout << "Entered task number is incorrect, try again.\n"
						"Task number can't be anything except 7 or 26.\n"
						"Enter 0 to end the choosing of the subtask.\n";
					break;
				}
				cout << "Enter the next subtask number:\n";
				chooseSubtask = inicializeNotNegativeInteger();
			}
			break;
		}
		default:
			cout << "Entered task number is incorrect, try again.\n"
				"Task number can't be more than 3.\n"
				"Enter 0 to end the programm.\n";
			break;
		}
		cout << "Enter the next task number:\n";
		chooseTask = inicializeNotNegativeInteger();;
	}
}