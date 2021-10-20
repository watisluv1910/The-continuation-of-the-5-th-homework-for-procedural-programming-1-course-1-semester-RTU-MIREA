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

int insertSpaces(string word, string allVowels, string allConsinats, string allSpecialCharacters) {
	string wordWithSpaces = "", letterAffiliation;
	// if letter is consinat - "c"
	// if letter is vowel - "v"
	// if letter is a special character - "s" (anyway is indicated by spaces)
	// if character is unacceptable - "u"
	for (size_t i = 0; i < word.length(); i++) {
		cout << endl << word[i] << endl;
		// if letter is consinat:
		if (allConsinats.find(word[i]) != string::npos) {
			letterAffiliation += "c";
		}
		// if letter is vowel:
		else if (allVowels.find(word[i]) != string::npos) {
			letterAffiliation += "v";
		}
		// if letter is a special character:
		else if (allSpecialCharacters.find(word[i]) != string::npos) {
			letterAffiliation += "s";
		}
		// if character is unacceptable:
		else {
			cout << "\nIncorrect text entered.\nTry again later.\n";
			return 0;
		}
	}
	if (word.length() >= 3) {
		size_t i = 0;
		// consonants that convey a sound that is syllable:
		string syllabicConsonats = "mnlMNL";
		while (i < word.length()) {
			if (letterAffiliation[i] == 's') {
				if ((word.substr(i, word.length() - i)).length() >= 2 && letterAffiliation[i + 1] == 's') {
					wordWithSpaces = wordWithSpaces + " " + word[i];
					cout << i << " 1\n";
					i++;
				}
				else {
					wordWithSpaces = wordWithSpaces + " " + word[i] + " ";
					cout << i << " 2\n";
					i++;
				}
			}
			else if (letterAffiliation[i] == 'v') {
				if ((word.substr(i, word.length() - i)).length() >= 3 && letterAffiliation[i + 1] == 'c' && letterAffiliation[i + 2] == 'v') {
					// 1st rule:
					wordWithSpaces = wordWithSpaces + word[i] + " " + word[i + 1];
					cout << i << " 3\n";
					i += 2;
				}
				else if ((word.substr(i, word.length() - i)).length() >= 4 && letterAffiliation.substr(i + 1, 2) == "cc" && letterAffiliation[i + 3] == 'v') {
					// 3rd rule:
					if (syllabicConsonats.find(word[i + 2]) != string::npos) {
						wordWithSpaces = wordWithSpaces + word[i] + " " + word[i + 1] + word[i + 2];
						cout << i << " 4\n";
					}
					// 2nd (4th) rule:
					else {
						wordWithSpaces = wordWithSpaces + word[i] + word[i + 1] + " " + word[i + 2];
						cout << i << " 5\n";
					}
					i += 3;
				}
				else if ((word.substr(i, word.length() - i)).length() >= 5 && letterAffiliation.substr(i + 1, 3) == "ccc" && letterAffiliation[i + 4] == 'v') {
					// 5th rule:
					if (syllabicConsonats.find(word[i + 3]) != string::npos) {
						wordWithSpaces = wordWithSpaces + word[i] + word[i + 1] + " " + word[i + 2] + word[i + 3];
						cout << i << " 6\n";
					}
					// 2nd rule (for 3 consinats):
					else {
						wordWithSpaces = wordWithSpaces + word[i] + word[i + 1] + word[i + 2] + " " + word[i + 3];
						cout << i << " 7\n";
					}
					i += 4;
				}
				else {
					wordWithSpaces = wordWithSpaces + word[i];
					cout << i << " 8\n";
					i++;
				}
			}
			else {
				wordWithSpaces = wordWithSpaces + word[i];
				cout << i << " 9\n";
				i++;
			}
		}
	}
	// if length = 2 or lower - output unchanged word:
	else {
		wordWithSpaces = word; 
		cout << "9\n";
	}
	cout << wordWithSpaces;
}

int runSubtaskTenth() { // refers to the 'Processing of text files'
	ofstream fout; // object of ofstream class (writing)
	string filePath = "text_file_Subtask_Tenth.txt";
	string allTextSymbols;
	fout.open(filePath);
	if (!fout.is_open()) { // checking for the successful opening
		cout << "\nFile opening error.\n";
		return 0;
	}
	else {
		cout << "\nEnter 1 to continue with your own text.\n"
			"Enter 2 to continue with preset of words (recommended).\n"
			"Enter other number to exit from the subtask.\n";
		int choosePath;
		cin >> choosePath;
		// ignoring new row symbol for correct work of getline:
		cin.ignore(32767, '\n'); 
		switch (choosePath) {
		case 1:
			cout << "\nAttention! For correct work of the programm:\n"
				"It's desireable that the text consists of meaningful "
				"words and doesn't contain any characters other than "
				"punctuation marks and numbers.\n"
				"It's also desireable NOT to use abbreviations of ordinals, "
				"(ex. 1st, 3rd) or compound words (ex. sightscreen).\n"
				"\nEnter your text:\n";
			getline(cin, allTextSymbols);
			break;
		case 2:
			allTextSymbols = "Down the river drifts an axe. "
							 "From the town of Byron. "
							 "Let it float by itself - "
							 "Fucking piece of iron!";
			break;
		default: 
			cout << "\nThe subtask was interrapted by user.\n";
			return 0;
			break;
		}
	}
	cout << "\nFile text:\n";
	for (size_t i = 0; i < allTextSymbols.length(); i++) {
		fout << allTextSymbols[i]; // writing to the file
		cout << allTextSymbols[i]; // writing to the console
	}
	cout << endl;
	fout.close(); // closing file
	// searching for the ' ' (space) symbol:
	size_t spaceIndex = allTextSymbols.find((char)32); 
	string allVowels = "aeioquyAEIOQUY",
		allConsinats = "bcdfghjklmnprstvwxzBCDFGHJKLMNPRSTVWXZ", 
		allSpecialCharacters = "@_.+-*/=#¹()!?':;";
	// if there is only one symbol or word in the file:
	if (spaceIndex == string::npos) {
		cout << "\nFile text with spaces:\n";
		insertSpaces(allTextSymbols, allVowels, allConsinats, allSpecialCharacters);
	}
	// if there is more than one word:
	else {
		cout << "\nFile text with spaces:\n";
	}
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
		string symbolInput, allTextSymbols;
		cout << "\nThe file text is:\n";
		while (!fin.eof()) { // true while not end of file
			fin >> symbolInput;
			cout << symbolInput << endl; // printing all symbols in the file
			allTextSymbols += symbolInput; // reading all symbols here
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
