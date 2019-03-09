#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "dynamicArray.h"

void putAboutA() {
	cout << "Laboratory work 1 - 2  Changing of the array VAR: 62" << endl;
	cout << "Group: K-14" << ' ' << "Danilchenko Alexander" << endl;
}

size_t getOption() {
	cout << endl;
	cout << "#################################################" << endl;
	cout << "#                      MENU:                    #" << endl;
	cout << "# 1 - FILL THE ARRAY FROM AN INPUT FILE         #" << endl;
	cout << "# 2 - FILL THE ARRAY MANUALLY FROM THE KEYBOARD #" << endl;
	cout << "# 9 - STOP THE EXECUTION                        #" << endl;
	cout << "#################################################" << endl;

	size_t userChoice = 0;
	while (true) {
		cout << ">> ";
		if (!(cin >> userChoice)) {
			cin.clear();	//reset the input
			while (cin.get() != '\n');	//get rid of the bad input before return was pressed
		}
		else if (!(userChoice == 1 || userChoice == 2 || userChoice == 9))
			continue;
		else
			return userChoice;
	}
}

bool fillByFile(dynamicArray& a, const string& inputFilePath) noexcept {
	ifstream inputFile;
	inputFile.open(inputFilePath);
	while (!inputFile.eof())
		if (!(inputFile >> a))
			return false;
	inputFile.close();
	return true;
}

bool fillByKbd(dynamicArray& a) {
	cout << endl;
	while (true) {
		cout << "array[" << a.getSize() << "] = ";
		if (!(cin >> a))
			break;
	}
	if (a.getSize() == 0) // indicates that array was not filled
		return false;
	else
		return true;
}


bool isNumber(const string& s) {
	if (s.length() == 0)
		return false;
	else
		for (size_t i = 0; i < s.length(); i++)
			if (s[i] == '-' && i == 0)
				continue;
			else if (!(s[i] >= '0' && s[i] <= '9'))
				return false;
	return true;
}

bool isPrimeNum(const int& k) {
	//handle only natural numbers higher than 1
	if (k <= 1)
		return false;
	for (int i = 2; i <= sqrt(k); ++i)
		if (k % i == 0)
			return false;
	return true;
}

void outputArray(const dynamicArray& a, const string& outputFilePath) {
	ofstream outputFile;
	outputFile.open(outputFilePath);
	if (outputFile.fail()) 
		throw logic_error("Error in opening of output file!");
	outputFile << a; 
	outputFile.close();
}
