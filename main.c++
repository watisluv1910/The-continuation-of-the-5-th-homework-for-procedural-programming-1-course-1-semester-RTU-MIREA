#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream> // for if/ofstream
#include <time.h> // for srand
#include <vector> // for vector
#include <stdio.h> // for printf

using namespace std;

double initializeNotNegativeDouble() { // function that check type error
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

double initializeDouble() { // function that check type error
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

int initializeNotNegativeInteger() { // function that check type error
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

int initializeInteger() { // function that check type error
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

// for the 'Processing of text files' subtask 10th:
// vector<string> is for returning the list:
vector<string> findPrefix(string startWord) {
	string word = startWord;
	string prefixesList[24] = { "Anti", "De", "Un", "Dis", "Im", "Mid", "Mis", "Over", "Pre", "Re", "Super", "Under",
						  "anti", "de", "un", "dis", "im", "mid", "mis", "over", "pre", "re", "super", "under" };
	size_t prefixLength = 5; // max length of prefix
	string prefix = "";
	// if length of the word is less than minimal (3):
	if (word.length() < 3) {
		// for returning 2 strings:
		vector<string> prefixAndWord = { prefix, word };
		return prefixAndWord;
	}
	bool isPrefix = false;
	// finding max possible length of prefix for the word:
	while (word.length() < prefixLength) {
		prefixLength--;
	}
	while (word.length() >= prefixLength && prefixLength >= 2) {
		// searching coincidence in prefixesList:
		for (size_t i = 0; i < 24; i++) {
			if (prefixesList[i] == word.substr(0, prefixLength)) {
				isPrefix = true;
			}
		}
		if (isPrefix) {
			prefix = word.substr(0, prefixLength);
			word = word.substr(prefixLength, word.length() - prefixLength);
			break; // if we already have prefix - leaving from while
		}
		else {
			prefixLength--;
		}
	}
	// for returning 2 strings:
	vector<string> prefixAndWord = { prefix, word };
	return prefixAndWord;
}

// for the 'Processing of text files' subtask 10th:
// vector<string> is for returning the list:
vector<string> findSuffix(string startWord) {
	string word = startWord;
	string suffixesList[35] = { "acy", "ance", "ence", "dom", "er", "or", "ism", "ist", "ity", "ty", "ment", "ness", "sion", "tion", "ed", "ing", "y",
						  "ate", "en", "ify", "fy", "ize", "ly", "al", "able", "ible", "esque", "ful", "ic", "ical", "ious", "ous", "ish", "ive", "less" };
	size_t suffixLength = 5; // max length of suffix
	string suffix = "";
	// if length of the word is less than minimal (3):
	if (word.length() < 3) {
		// for returning 2 strings:
		vector<string> suffixAndWord = { suffix, word };
		return suffixAndWord;
	}
	bool isSuffix = false;
	// finding max possible length of suffix for the word:
	while (word.length() < suffixLength) {
		suffixLength--; 
	}
	while (word.length() >= suffixLength && suffixLength >= 1) {
		// searching coincidence in suffixesList:
		for (size_t i = 0; i < 33; i++) {
			if (suffixesList[i] == word.substr(word.length() - suffixLength, suffixLength)) {
				isSuffix = true;
			}
		}
		if (isSuffix) {
			suffix = word.substr(word.length() - suffixLength, suffixLength);
			word = word.substr(0, word.length() - suffixLength);
			break; // if we already have suffix - leaving from while
		}
		else {
			suffixLength--;
		}
	}
	// for returning 2 strings:
	vector<string> suffixAndWord = { suffix, word };
	return suffixAndWord; 
}

//antisocial
//performance
//overcooked
//Two roads diverged in a yellow wood,

// for the 'Processing of text files' subtask 10th:
string insertSpaces(string startWord, string allVowels, 
					string allConsinats, string allSpecialCharacters) {
	// fixed startWord without first prefix and/or last suffix:
	string word = startWord;
	string wordWithSpaces = "", letterAffiliation;
	// if letter is consinat - "c"
	// if letter is vowel - "v"
	// if letter is a special character - "s" (anyway is indicated by spaces)
	// if character is unacceptable - "u"
	for (size_t i = 0; i < word.length(); i++) {
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
		// if character is unacceptable (ex. 1984):
		else {
			return word;
		}
	}
	// if length = 3 or more - searching for the syllables:
	if (word.length() >= 3) {
		size_t i = 0;
		// consonants that convey a sound that is syllable:
		string syllabicConsonats = "mnlMNL";
		while (i < word.length()) {
			if (letterAffiliation[i] == 's') {
				// if 2 special symbols in a row:
				if ((word.substr(i, word.length() - i)).length() >= 2 
					&& letterAffiliation[i + 1] == 's') {
					wordWithSpaces = wordWithSpaces + " " + word[i];
					i++;
				}
				// if 1 (or last) special symbol in a row:
				else {
					wordWithSpaces = wordWithSpaces + " " + word[i] + " ";
					i++;
				}
			}
			else if (letterAffiliation[i] == 'v') {
				// if more than 5 consonats in a row - the word is compound 
				if ((word.substr(i, word.length() - i)).length() >= 7 
					&& letterAffiliation.substr(i + 1, 6) == "cccccc") {
					return word;
				}
				else if ((word.substr(i, word.length() - i)).length() >= 3 && letterAffiliation[i + 1] == 'c' && letterAffiliation[i + 2] == 'v') {
					// e in the end of the word doesn't define a syllable:
					if (word[word.length() - 1] == 'e' 
						&& i + 2 == word.length() - 1) {
						wordWithSpaces = wordWithSpaces + word.substr(i, 3);
						i += 3;
					}
					else {
						// 1st rule:
						wordWithSpaces = wordWithSpaces + word[i] + 
										 + " " + word[i + 1];
						i += 2;
					}
				}
				else if ((word.substr(i, word.length() - i)).length() >= 4 && letterAffiliation.substr(i + 1, 2) == "cc" && letterAffiliation[i + 3] == 'v') {
					// e in the end of the word doesn't define a syllable:
					if (word[word.length() - 1] == 'e' && i + 3 == word.length() - 1) {
						wordWithSpaces = wordWithSpaces + word.substr(i, 4);
						i += 4;
					}
					// 3rd rule:
					else if (syllabicConsonats.find(word[i + 2]) != string::npos) {
						wordWithSpaces = wordWithSpaces + word[i] + " " + word[i + 1] + word[i + 2];
					}
					// 2nd (4th) rule:
					else {
						wordWithSpaces = wordWithSpaces + word[i] + word[i + 1] + " " + word[i + 2];
					}
					i += 3;
				}
				else if ((word.substr(i, word.length() - i)).length() >= 5 && letterAffiliation.substr(i + 1, 3) == "ccc" && letterAffiliation[i + 4] == 'v') {
					// 5th rule:
					if (syllabicConsonats.find(word[i + 3]) != string::npos) {
						wordWithSpaces = wordWithSpaces + word[i] + word[i + 1] + " " + word[i + 2] + word[i + 3];
					}
					// 2nd rule (for 3 consinats):
					else {
						wordWithSpaces = wordWithSpaces + word[i] + word[i + 1] + word[i + 2] + " " + word[i + 3];
					}
					i += 4;
				}
				else { // if vowel isn't syllabic:
					wordWithSpaces = wordWithSpaces + word[i];
					i++;
				}
			}
			else { // if symbol isn't a vowel or special
				wordWithSpaces = wordWithSpaces + word[i];
				i++;
			}
		}
	}
	// if length = 2 or lower - output unchanged word:
	else {
		wordWithSpaces = word;
	}
	return wordWithSpaces;
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
			// rules of entering text:
			cout << "\nAttention! For correct work of the programm:\n"
				"It's desireable that the text consists of meaningful "
				"words and doesn't contain any characters other than "
				"punctuation marks, standart special symbols and numbers.\n"
				"It's also desireable NOT to use abbreviations of ordinals, "
				"(ex. 1st, 3rd) or compound words (ex. sightscreen). "
				"Such words in any case won't be changed.\n"
				"\nEnter your text:\n";
			// reading all symbols before a new line:
			getline(cin, allTextSymbols);
			break;
		case 2:
			// prearranged text:
			allTextSymbols = "Down the river drifts an axe."
							 "From the town of Byron."
							 "Let it float by itself - "
							 "Fucking piece of iron!";
			break;
		default: 
			cout << "\nThe subtask was interrapted by user.\n";
			return 0;
			break;
		}
	}
	cout << "\nThe file text is:\n";
	for (size_t i = 0; i < allTextSymbols.length(); i++) {
		fout << allTextSymbols[i]; // writing to the file
		cout << allTextSymbols[i]; // writing to the console
	}
	cout << endl;
	fout.close(); // closing file
	// searching for the " " (space) symbol:
	size_t spaceIndex = allTextSymbols.find(" ");
	// "alphabet" strings:
	string allVowels = "aeioquyAEIOQUY",
		allConsinats = "bcdfghjklmnprstvwxzBCDFGHJKLMNPRSTVWXZ",
		allSpecialCharacters = ",@_.+-*/=#¹%^(){}[]!?':;",
		indivisibleSuffixesList = "al, ed";
	// if there is only one symbol or word in the file (no space symbol):
	if (spaceIndex == string::npos) {
		cout << "\nThe result is:\n";
		// result of findPrefix (prefix, rest part of word):
		vector<string> withPrefix = findPrefix(allTextSymbols);
		// result of findSuffix (rest part of word, suffix):
		vector<string> withSuffix = findSuffix(withPrefix[1]);

		// withPrefix[0] - prefix
		// withSuffix[0] - suffix
		// withSuffix[1] - rest part of word (from findPrefix and findSuffix)
		
		// inicializing prefix and suffix with spaces:
		string prefix = insertSpaces(withPrefix[0], allVowels, 
									 allConsinats, allSpecialCharacters),
			   suffix = insertSpaces(withSuffix[0], allVowels, 
								     allConsinats, allSpecialCharacters),
			   // inicializing word without prefixes (suffixes) and with spaces:
			   fixedWord = insertSpaces(withSuffix[1], allVowels, 
										allConsinats, allSpecialCharacters);
		if (prefix.length() != 0 && suffix.length() != 0) {
			// if suffix isn't indivisible:
			if (indivisibleSuffixesList.find(suffix) == string::npos) {
				cout << prefix + " " + fixedWord + " " + suffix << endl;
			}
			// if suffix is indivisible:
			else {
				cout << prefix + " " + fixedWord + suffix << endl;
			}
		}
		else if (prefix.length() != 0 && suffix.length() == 0) {
			cout << prefix + " " + fixedWord + suffix << endl;
		}
		else if (suffix.length() != 0) {
			if (indivisibleSuffixesList.find(suffix) == string::npos) {
				cout << prefix + fixedWord + " " + suffix << endl;
			}
			else {
				cout << prefix + " " + fixedWord + suffix << endl;
			}
		}
		else {
			cout << prefix + fixedWord + suffix << endl;
		}
	}
	// if there is more than one word (space symbol exists):
	else {
		// for the same conditions of splitting a sentence into words is
		// necessary to insert space symbol to the begining:
		allTextSymbols = " " + allTextSymbols;
		cout << "\nThe result is:\n";
		spaceIndex = 0; // index of first space
		while (spaceIndex != string::npos) { 
			string nWord = allTextSymbols.substr(spaceIndex + 1, allTextSymbols.find(" ", spaceIndex + 1) - (spaceIndex + 1));
			// result of findPrefix (prefix, rest part of word):
			vector<string> withPrefix = findPrefix(nWord);
			// result of findSuffix (rest part of word, suffix):
			vector<string> withSuffix = findSuffix(withPrefix[1]);
			// inicializing prefix and suffix with spaces:
			string prefix = insertSpaces(withPrefix[0], allVowels,
				allConsinats, allSpecialCharacters),
				suffix = insertSpaces(withSuffix[0], allVowels,
					allConsinats, allSpecialCharacters),
				// inicializing word without prefixes (suffixes) and with spaces:
				fixedWord = insertSpaces(withSuffix[1], allVowels,
					allConsinats, allSpecialCharacters);
			if (prefix.length() != 0 && suffix.length() != 0) {
				// if suffix isn't indivisible:
				if (indivisibleSuffixesList.find(suffix) == string::npos) {
					cout << prefix + " " + fixedWord + " " + suffix + " ";
				}
				// if suffix is indivisible:
				else {
					cout << prefix + " " + fixedWord + suffix + " ";
				}
			}
			else if (prefix.length() != 0 && suffix.length() == 0) {
				cout << prefix + " " + fixedWord + suffix + " ";
			}
			else if (suffix.length() != 0) {
				if (indivisibleSuffixesList.find(suffix) == string::npos) {
					cout << prefix + fixedWord + " " + suffix + " ";
				}
				else {
					cout << prefix + " " + fixedWord + suffix + " ";
				}
			}
			else {
				cout << prefix + fixedWord + suffix + " ";
			}
			spaceIndex = allTextSymbols.find(" ", spaceIndex + 1);
		}
		cout << endl;
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
		int symbolsNumber = initializeNotNegativeInteger();
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

// for the 'Ranks' subtask 19th:
double initializeHeight() { // function that check type error
	double temporaryVariable; // inicialization of temporary variable
	cout << "-> ";
	while (!(cin >> temporaryVariable) 
		|| temporaryVariable < 0.0 
		|| temporaryVariable > 244.0)
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream
		// as it is in the wrong format
		cout << "-> ";
	}
	return temporaryVariable;
}

int runSubtaskNineteenth() { // refers to the 'Ranks'
	cout << "\nStudent height analysis.\n"
		"To exit from the program enter 0 and push <Enter> bottom:\n"
		"Enter height in centimeters and push <Enter> bottom:\n";
	double studentHeight = initializeHeight(), summaryHeight = 0;
	// if user interrupted the programm:
	if (studentHeight == 0.0) {
		cout << "\nPremature exit from the subtask.\n"
			"Programm doesn't have enough data for correct functioning.\n";
		return 0;
	}
	// list with height of each student:
	double* studentsHeightsList = new double[1]{studentHeight};
	size_t studentsNumber = 0;
	while (studentHeight != 0.0) {
		summaryHeight += studentHeight;
		studentsNumber++;
		// each iteration except 1st it's necessary to extend the list:
		if (studentsNumber > 1) {
			// initializing new list longer than the old one:
			double* studentsHeightsListExtended = new double[studentsNumber];
			// copying elements from old list to the new one:
			for (size_t i = 0; i < studentsNumber; i++) {
				studentsHeightsListExtended[i] = studentsHeightsList[i];
			}
			// deleting old list:
			delete[] studentsHeightsList;
			studentsHeightsListExtended[studentsNumber - 1] = studentHeight;
			// "renaming" new list as a the old one:
			studentsHeightsList = studentsHeightsListExtended;
		}
		// initializing new height value:
		studentHeight = initializeHeight();
	}
	printf("\nAverage height is: %.1lf cm.\n", summaryHeight / studentsNumber);
	size_t upperHeightCount = 0, lowerHeightCount = 0, equalHeightCount = 0;
	// comparing each height with average:
	for (size_t i = 0; i < studentsNumber; i++) {
		if (*(studentsHeightsList + i) > summaryHeight / studentsNumber) {
			upperHeightCount++;
		}
		else if (*(studentsHeightsList + i) < summaryHeight / studentsNumber) {
			lowerHeightCount++;
		}
		else {
			equalHeightCount++;
		}
	}
	cout << upperHeightCount << " student(s) have"
		"a height upper than average\n"
		<< lowerHeightCount << " student(s) have"
		"a height lower than average\n"
		<< equalHeightCount << " student(s) have"
		"a height equal to average\n";
	return 1;
}

// for the 'Ranks' subtask 67th:
int initializeFinalNumberSystem() { // function that check type error
	int temporaryVariable; // inicialization of temporary variable 
	while (!(cin >> temporaryVariable)
		|| temporaryVariable < 3
		|| temporaryVariable > 6)
	{
		cout << "Inicialization error.\nEnter correct value:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// operator >> will no longer fetch data from the stream as 
		// it is in the wrong format
	}
	return temporaryVariable;
}

void runSubtaskSixtySeventh() { // refers to the 'Ranks'
	cout << "\nEnter the value of n variable (length of the array):\n";
	size_t numbersCount = initializeNotNegativeInteger();
	cout << "\nEnter the final number system (from 3 to 6):\n";
	int finalNumberSystem = initializeFinalNumberSystem();
	cout << "\nEnter the numbers in double system (using enter).\n"
		"If the number is fractal, use (,).\n";
	// list of entered numbers:
	string* originalNumbersList = new string[numbersCount];
	// list of entered numbers in final number system:
	string* finalNumbersList = new string[numbersCount];
	for (size_t i = 0; i < numbersCount; i++) {
		string originalNumber, finalNumber;
		if (i == 0) {
			cout << "\nEnter the 1st number:\n";
		}
		else if (i != numbersCount - 1) {
			cout << "Enter the next number:\n";
		}
		else {
			cout << "Enter the last number:\n";
		}
		cin >> originalNumber;
		// filling the list with original numbers:
		originalNumbersList[i] = originalNumber;
		long numberInteger = 0;
		float numberFloat = 0.0f;
		int pointIndex = originalNumber.find(",");
		if (pointIndex == string::npos) { // if there is no , in a number
			// reversed iteration for transfer to decimal system:
			for (int i = originalNumber.length() - 1; i >= 0; i--) {
				char rankChar = originalNumber[i];
				numberInteger += (static_cast<long>(rankChar) - 48) * pow(2, (originalNumber.length() - 1 - i));
			}
			while (numberInteger > 0) { // transfer to final number system
				finalNumber = to_string(numberInteger % finalNumberSystem) + finalNumber;
				numberInteger /= finalNumberSystem; // <= rank
			}
			finalNumbersList[i] = finalNumber;
		}
		else { // if , is in a number
			// reversed iteration for transfer to decimal system before point:
			for (int i = pointIndex - 1; i >= 0; i--) {
				char rankChar = originalNumber[i];
				numberInteger += (static_cast<long>(rankChar) - 48) * pow(2, (pointIndex - 1 - i));
			}
			// reversed iteration for transfer to decimal system after point:
			for (int i = originalNumber.length() - 1; i > pointIndex; i--) {
				char rankChar = originalNumber[i];
				numberFloat += (static_cast<long>(rankChar) - 48) * pow(2, (-1 * (i - pointIndex)));
			}
			// fractional number in decimal system:
			float numberDecimal = numberInteger + numberFloat;
			// transfer integer part to final number system:
			while (numberInteger > 0) { 
				finalNumber = to_string(numberInteger % finalNumberSystem) + finalNumber;
				numberInteger /= finalNumberSystem; // <= rank
			}
			finalNumber += ","; // adding the point to integer
			string numberFloatString = to_string(numberFloat);
			pointIndex = numberFloatString.find(",");
			float transferAccuracy = 1.0f / pow(finalNumberSystem, numberFloatString.length() - 1 - pointIndex);
			// transfer fractional part to ss2:
			int counterOfRanks = 0;
			cout << "Enter needful number of ranks after (,):\n";
			int maxCountOfRanks = initializeNotNegativeInteger();
			while (stof(numberFloatString.substr(numberFloatString.find(",") + 1, numberFloatString.length() - 1 - numberFloatString.find(","))) > transferAccuracy) {
				numberFloatString = to_string(numberFloat *= finalNumberSystem);
				// the integer part of numberFloat
				string integerPart = numberFloatString.substr(0, numberFloatString.find(","));
				if (counterOfRanks >= maxCountOfRanks) {
					break;
				}
				else {
					finalNumber = finalNumber + to_string(stoi(integerPart) % finalNumberSystem);
					counterOfRanks++;
				}
			}
			finalNumbersList[i] = finalNumber;
		}
	}
	cout << endl;
	for (size_t i = 0; i < numbersCount; i++) {
		cout << "Original number is: " << originalNumbersList[i]
			<< "\t\tFinal number is: " << finalNumbersList[i] << ".\n";
	}
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
	chooseTask = initializeNotNegativeInteger();
	while (chooseTask > 0) {
		switch (chooseTask) {
		case 1: {
			cout << "\nEnter 0 to end the choosing of the subtask.\n"
				"Enter the number of subtask :\n";
			int chooseSubtask = initializeNotNegativeInteger();
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
				chooseSubtask = initializeNotNegativeInteger();
			}
			break;
		}
		case 2: {
			cout << "\nEnter 0 to end the choosing of the subtask.\n"
				"Enter the number of subtask :\n";
			int chooseSubtask = initializeNotNegativeInteger();
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
				chooseSubtask = initializeNotNegativeInteger();
			}
			break;
		}
		case 3: {
			cout << "\nEnter 0 to end the choosing of the subtask.\n"
				"Enter the number of subtask :\n";
			int chooseSubtask = initializeNotNegativeInteger();
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
				chooseSubtask = initializeNotNegativeInteger();
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
		chooseTask = initializeNotNegativeInteger();
	}
}
