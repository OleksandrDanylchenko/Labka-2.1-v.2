#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "additional functions.h"

//CONSTRUCTORS
dynamicArray::dynamicArray() : Size(0), Capacity(N), arr(new int[N]) {}

//DESTRUCTOR
dynamicArray::~dynamicArray() {
	delete[]arr;
	arr = nullptr;
}

//OPERATORS OVERLOADING
// gets the character from a dynamic array
int& dynamicArray::operator[](size_t i) {
	if (i >= Size)
		throw out_of_range("Invalid cell number!");
	return arr[i];
}

// insert an element to the current position in the dynamic array
bool operator>>(istream & is, dynamicArray& a) {
	return a.in(is);
}

// output an element from the current position in the dynamic array
ostream& operator<<(ostream& os, const dynamicArray& a) {
	a.out(os);
	return os;
}

//METHODS
// insert an element to the array if it has numeric value, else return false
// if the array is full, doubles its size
bool dynamicArray::in(istream& is) {
	while (true) {
		string checkVal = "";
		if (Size < Capacity) {
			is >> checkVal;
			if (isNumber(checkVal)) {
				arr[Size] = stoi(checkVal);
				++Size;
				return true;
			}
			else
				return false;
		}
		else
			Resize();
	}
}

// output the array to the file with formatting
void dynamicArray::out(ostream& os) const {
	for (size_t i = 0, f = 0; i < Size; ++i) {
		os << setw(6) << arr[i];
		f += 1;
		if (f == 4 && i + 1 < Size) {
			f = 0;
			os << endl;
		}
	}
}

size_t dynamicArray::getSize() const { return Size; }

size_t dynamicArray::getCapacity() const { return Capacity; }

// doubles the size of the array
void dynamicArray::Resize() {
	Capacity *= 2;
	int* newArray = new int[Capacity];
	cout << "\n=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%" << endl;
	cout << "\tMEMORY ALLOC" << "\n\tCapacity: " << Capacity << "\n\tSize in bytes: " << Size * sizeof(int) << endl;
	cout << "=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%=%" << endl << endl;
	for (size_t i = 0; i < Size; ++i)
		newArray[i] = arr[i];
	delete[] arr;
	arr = newArray;
}

// process the array due to the task
void processArray(dynamicArray& a) {
	cout << "\n Enter a new value:";
	int newValue = 0;
	while (true) {
		cout << "\n>> ";
		if (cin >> newValue)
			break;
		else {
			cout << "Invalid Input! Please input a numerical value." << endl;
			cin.clear();
			while (cin.get() != '\n'); // empty loop
		}
	}
	if (a.Size + 1 >= a.Capacity)
		a.Resize();

	// find the last prime number in the array
	size_t lastPrimeNum = 10;
	for (size_t l = 0; l < a.Size; ++l)
		if (isPrimeNum(a.arr[l]))
			lastPrimeNum = l;

	// add the newElement after last prime number if it  occured, else insert in the beginning
	if (lastPrimeNum != 10) {
		for (size_t k = a.Size; k > lastPrimeNum + 1; --k)
			a.arr[k] = a.arr[k - 1];
		a.arr[lastPrimeNum + 1] = newValue;
		++a.Size;
		return;
	} 
	else
		for (size_t i = a.Size; i > 0; --i) {
			a.arr[i] = a.arr[i - 1];
		}
	a.arr[0] = newValue;
	++a.Size;
}
