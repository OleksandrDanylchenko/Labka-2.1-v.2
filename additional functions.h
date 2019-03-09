#pragma once
#include "dynamicArray.h"

void putAboutA(); // information about laboratory work
size_t getOption(); // get the option if the menu is called
bool fillByFile(dynamicArray& a, const string& inputFilePath) noexcept;
bool fillByKbd(dynamicArray& a);
bool isNumber(const string& s); // checks if number consists of numeric elements
bool isPrimeNum(const int& k); // checks if the number is prime or not
void outputArray(const dynamicArray& a, const string& outputFilePath);
