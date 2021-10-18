#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream> // for if/ofstream
#include <time.h> // for srand

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

void runSubtaskTenth() { // refers to the 'Processing of text files'
	
}

int runSubtaskTwentySeventh() { // refers to the 'Processing of text files'
	ofstream fout; // object of ofstream class (writing)
	string filePath = "text_file_Subtask_TwentySeventh.txt";
	fout.open(filePath);
	if (!fout.is_open()) { // checking for the successful opening
		cout << "\nFile opening error.\n";
		return 0;
	}
	else {
		srand(time(0)); // randomizing depends on system time
		cout << "\nEnter the number of symbols in the file :\n";
		int symbolsNumber = inicializeNotNegativeInteger();
		switch (symbolsNumber) {
		case 0: {
			cout << "\nThere are no symbols in the text file.\n";
		}
		default: { // {} because of inicializing symbolOutput variable
			for (size_t i = 0; i < symbolsNumber; i++) {
				if (i == symbolsNumber - 1) { // if symbol is the last
					int symbolOutput = rand() % 128;
					fout << (char)symbolOutput; // without endl
				}
				else { // if symbol isn't the last
					int symbolOutput = rand() % 128;
					fout << (char)symbolOutput << endl; // with endl
				}
			}
		}
		}
	}
	fout.close(); // closing file
	ifstream fin; // object of ifstream class (reading)
	fin.open(filePath);
	if (!fin.is_open()) { // checking for the successful opening
		cout << "\nFile opening error.\n";
		return 0;
	}
	else {
		string symbol, allTextSymbols;
		cout << "\nThe file text is:\n";
		while (!fin.eof()) { // true while not end of file
			fin >> symbol;
			cout << symbol << endl; // printing all symbols in the file
			allTextSymbols += symbol; // reading all symbols here
		}
		for (size_t i = 0; i < 128; i++) { // iteration of all ASCII symbols
			// searching for the index of first (char)i symbol in the file:
			size_t symbolIndex = allTextSymbols.find((char)i), symbolCount = 0;
			// if there is (char)i symbol in the file
			while (symbolIndex != string::npos) {
				symbolCount += 1;
				// searching for the index of next i symbol beginning with
				// the index of the next symbol to one found earlier:
				symbolIndex = allTextSymbols.find((char)i, symbolIndex + 1);
			}
			// if there is at least one (char)i symbol in the file:
			if (symbolCount > 0) {
				cout << "\nThe number of " << (char)i
					<< " symbols is " << symbolCount << ".\n";
			}
		}
		cout << endl;
	}
	fin.close(); // closing file
}

void runSubtaskNineteenth() { // refers to the 'Ranks'

}

void runSubtaskSixtySeventh() { // refers to the 'Ranks'

}

void runSubtaskSeventh() { // refers to the 'Files'

}

void runSubtaskTwentySixth() { // refers to the 'Files'

}

int main() {
	int chooseTask;
	setlocale(LC_ALL, "Russian");
	cout << "Hello!\nTask number can't be more than 3.\n"
		"Enter 1 to run the task 'Processing of text files', "
		"2 to run the task 'Ranks', "
		"3 to run the task 'Files'.\n"
		"Enter 0 to end the programm.\nEnter the task number :\n";
	chooseTask = inicializeNotNegativeInteger();
	while (chooseTask > 0) {
		switch (chooseTask) {
		case 1: {
			cout << "\nEnter 0 to end the choosing of the subtask.\n"
				"Enter the number of subtask :\n";
			int chooseSubtask = inicializeNotNegativeInteger();
			while (chooseSubtask > 0) {
				switch (chooseSubtask) {
				case 10:
					runSubtaskTenth();
					break;
				case 27:
					runSubtaskTwentySeventh();
					break;
				default:
					cout << "\nEntered task number is incorrect, try again.\n"
						"Task number can't be anything except 10 or 27.\n"
						"Enter 0 to end the choosing of the subtask.\n";
					break;
				}
				cout << "\nEnter the next subtask number:\n";
				chooseSubtask = inicializeNotNegativeInteger();
			}
			break;
		}
		case 2: {
			cout << "\nEnter 0 to end the choosing of the subtask.\n"
				"Enter the number of subtask :\n";
			int chooseSubtask = inicializeNotNegativeInteger();
			while (chooseSubtask > 0) {
				switch (chooseSubtask) {
				case 19:
					runSubtaskNineteenth();
					break;
				case 67:
					runSubtaskSixtySeventh();
					break;
				default:
					cout << "\nEntered task number is incorrect, try again.\n"
						"Task number can't be anything except 19 or 67.\n"
						"Enter 0 to end the choosing of the subtask.\n";
					break;
				}
				cout << "\nEnter the next subtask number:\n";
				chooseSubtask = inicializeNotNegativeInteger();
			}
			break;
		}
		case 3: {
			cout << "\nEnter 0 to end the choosing of the subtask.\n"
				"Enter the number of subtask :\n";
			int chooseSubtask = inicializeNotNegativeInteger();
			while (chooseSubtask > 0) {
				switch (chooseSubtask) {
				case 7:
					runSubtaskSeventh();
					break;
				case 26:
					runSubtaskTwentySixth();
					break;
				default:
					cout << "\nEntered task number is incorrect, try again.\n"
						"Task number can't be anything except 7 or 26.\n"
						"Enter 0 to end the choosing of the subtask.\n";
					break;
				}
				cout << "\nEnter the next subtask number:\n";
				chooseSubtask = inicializeNotNegativeInteger();
			}
			break;
		}
		default:
			cout << "\nEntered task number is incorrect, try again.\n"
				"Task number can't be more than 3.\n"
				"Enter 0 to end the programm.\n";
			break;
		}
		cout << "\nEnter the next task number:\n";
		chooseTask = inicializeNotNegativeInteger();
	}
}
