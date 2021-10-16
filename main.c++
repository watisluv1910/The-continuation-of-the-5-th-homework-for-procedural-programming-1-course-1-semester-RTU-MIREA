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

void runSubtaskTenth() { // refers to the task 'Processing of text files'
	
}

int runSubtaskTwentySeventh() { // refers to the task 'Processing of text files'
	ofstream fout; // object of ofstream class (writing)
	string filePath = "text_file_Subtask_TwentySeventh.txt";
	fout.open(filePath); 
	if (!fout.is_open()) { // checking for the successful opening
		cout << "\nFile opening error.\n";
		return 0;
	}
	else {
		srand(time(0));
		cout << "\nEnter the number of symbols in the file :\n";
		int symbolsNumber = inicializeNotNegativeInteger();
		switch (symbolsNumber) {
		case 0 : {
			cout << "\nThere are no symbols in the text file.\n";
		}
		default : {
			for (size_t i = 0; i < symbolsNumber; i++) {
				if (i == symbolsNumber - 1) {
					int symbolOutput = rand() % 128;
					fout << (char)symbolOutput;
					//cout << (char)symbolOutput << endl;
				}
				else {
					int symbolOutput = rand() % 128;
					fout << (char)symbolOutput << endl;
					//cout << (char)symbolOutput << endl;
				}
			}
		}
		}
	}
	fout.close(); // closing file
	//ifstream fin; // object of ifstream class (reading)
	//fin.open(filePath);
	//int allTextSymbols[1]; // array with all symbols in the text (only ASCII)
	//int allTextSymbolsCount[1]; // array that counts the number of symbols
	//allTextSymbols[0] = 0;
	//if (!fin.is_open()) { // checking for the successful opening
	//	cout << "\nFile opening error.\n";
	//	return 0;
	//}
	//else {
		//string symbolInput = "";
		//getline(fin, symbolInput);
		//allTextSymbols[0] = (int)symbolInput[0]; // reading the 1st symbol
		//allTextSymbolsCount[0] += 1;
		//while (!fin.eof()) {// true while not end of file
		//	symbolInput = "";
		//	getline(fin, symbolInput); // reading all symbols
		//	int *symbolIndex = find(begin(allTextSymbols), end(allTextSymbols), (int)symbolInput[0]);
		//	if (symbolIndex != end(allTextSymbols)) { // if symbol is already in allTextSymbols
		//		allTextSymbolsCount[distance(allTextSymbols, symbolIndex)]++;
		//	}
		//	else { // not found
		//		// extending of allTextSymbols:
		//		int allTextSymbolsExtended[sizeof(allTextSymbols) + 1];

		//		// copy elements from allTextSymbols to allTextSymbolsExtended:
		//		copy(allTextSymbols, allTextSymbols + sizeof(allTextSymbols),
		//			begin(allTextSymbolsExtended));
		//		/*for (size_t i = 0; i < sizeof(allTextSymbols); i++) {
		//			allTextSymbolsExtended[i] = allTextSymbols[i];
		//		}*/

		//		// deleting allTextSymbols:
		//		delete[] allTextSymbols; 

		//		// inicializing allTextSymbols with length of extended:
		//		int allTextSymbols[sizeof(allTextSymbolsExtended)];
		//		copy(allTextSymbolsExtended, allTextSymbolsExtended+sizeof(allTextSymbolsExtended),
		//			begin(allTextSymbols));
		//		/*for (size_t i = 0; i < sizeof(allTextSymbolsExtended); i++) {
		//			allTextSymbols[i] = allTextSymbolsExtended[i];
		//		}*/

		//		// deleting allTextSymbolsExtended:
		//		delete[] allTextSymbolsExtended; 


		//		// extending of allTextSymbolsCount:
		//		int allTextSymbolsCountExtended[sizeof(allTextSymbolsCount) + 1];

		//		// copy elements from allTextSymbols to allTextSymbolsExtended:
		//		copy(allTextSymbolsCount, allTextSymbolsCount + sizeof(allTextSymbolsCount),
		//			begin(allTextSymbolsCountExtended));
		//		/*for (size_t i = 0; i < sizeof(allTextSymbolsCount); i++) {
		//			allTextSymbolsCountExtended[i] = allTextSymbolsCount[i];
		//		}*/

		//		// deleting allTextSymbolsCount:
		//		delete[] allTextSymbolsCount;

		//		// inicializing allTextSymbols with length of extended:
		//		int allTextSymbolsCount[sizeof(allTextSymbolsCountExtended)];
		//		copy(allTextSymbolsCountExtended, allTextSymbolsCountExtended + sizeof(allTextSymbolsCountExtended),
		//			begin(allTextSymbolsCount));
		//		/*for (size_t i = 0; i < sizeof(allTextSymbolsCountExtended); i++) {
		//			allTextSymbolsCount[i] = allTextSymbolsCountExtended[i];
		//		}*/

		//		// deleting allTextSymbolsCountExtended:
		//		delete[] allTextSymbolsCountExtended;

		//		// adding new symbol in the new unit:
		//		allTextSymbols[sizeof(allTextSymbols) - 1] = (int)symbolInput[0];
		//		allTextSymbolsCount[sizeof(allTextSymbolsCount) - 1]++;
		//	}
		//}
		//for (size_t i = 0; i < sizeof(allTextSymbols); i++) {
		//	cout << "The number of " << allTextSymbols[i] << " symbols is " << allTextSymbolsCount[i] << ".\n";
		//}
		//cout << endl;
	/*}
	fin.close();*/
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
