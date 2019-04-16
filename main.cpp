// Labka 2.1 v.1
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;

#include "dynamicArray.h"
#include "additional functions.h"

int main() {
	//opens terminal in fullscreen mode
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	putAboutA();
	dynamicArray array; // creates a dynamic array as a class
	size_t option = getOption(); // how the user wants to fill up a dynamic array
	try {
		if (option == 1) {	//from file
			string inputFilePath = "";
			ifstream inputFile;
			cin.ignore(); // gets rid of \n before getline()
			while (true) {
				cout << "\nEnter the path to the input file: ";
				cin.clear(); //clears the stream if ^z is pushed
				getline(cin, inputFilePath);
				inputFile.open(inputFilePath);
				if (inputFile.fail()) {
					inputFilePath.clear();
					continue;
				}
				else
					break;
			}
			inputFile.close();
			if (!fillByFile(array, inputFilePath))
				throw logic_error("Array was not filled from file! Reupload the file!");
		}
		else if (option == 2) {//fill from the keyboard
			if (!fillByKbd(array))
				throw logic_error("Array was not filled by the keyboard!");
		}
		else if (option == 9)
			return -9;
	}
	catch (std::bad_alloc&) {
		cerr << "\n=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%" << endl;
		cerr << "\t	MEMORY ALLOC" << "\n\tCapacity: " << array.getCapacity() << "\n\tSize in bytes: " << array.getSize() * sizeof(int) << "\nERROR!" << endl;
		cerr << "=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%" << endl << endl;
		system("pause");
		return -1;
	}
	// handles all the other exceptions
	catch (exception& ex) {
		cerr << '\t' << ex.what() << endl << endl;
		system("pause");
		return -2;
	}

	processArray(array);

	string outputFilePath = "";
	ofstream outputFile;
	while (true) {
		cout << "\nEnter the path to the output file: ";
		cin.ignore();
		getline(cin, outputFilePath);
		if (outputFilePath.find('\\') == std::string::npos and outputFilePath.find('/') == std::string::npos) { //if user didn't provided full adress -> create a new file in the root folder
			outputFilePath += ".txt";
			cout << "\nYour file will be stored at: D:" << '\\' << "Studying" << '\\' << "Programming" << '\\' << "LABS" << '\\' << "Labka_2.1_Second_Sem" << '\\' << "Labka_2.1_Second_Sem" << '\\' << outputFilePath << endl;
		}
		outputFile.open(outputFilePath);
		if (outputFile.fail())
			continue;
		else
			break;
	}
	outputFile.close();
	outputArray(array, outputFilePath);
	
	array.~dynamicArray();
	system("pause");
	return 0;
}
