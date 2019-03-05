//creating an input file with a sample text
#include <iostream>
#include <fstream>
#include <random>

size_t randomGenerator(size_t min, size_t max);

int main(void) {
	//asking for a name of output file with matrix representation
	std::string inputFile = "D:/Studying/Programming/LABS/Labka_2.1_Second_Sem/";
	std::string inputFileTemp = "";
	do {
		std::cout << "Enter only the name of the output file: ";
		std::cin >> inputFileTemp;
	} while (inputFileTemp.empty());
	inputFile += inputFileTemp + ".txt";

	std::ofstream inFile;
	inFile.open(inputFile);
	if (inFile.fail()) {
		std::cerr << "Error Opening inputData.txt" << std::endl;
		inFile.close();
		system("pause");
		return -1;
	}

	size_t userSize = 0;
	while (true) {
		std::cout << "Enter the amount of elements: ";
		if (!(std::cin >> userSize)) {
			//reset the input
			std::cin.clear();
			//get rid of the bad input before return was pressed
			while (std::cin.get() != '\n');
		}
		else if (userSize <= 0)
			continue;
		else
			break;
	}

	for (size_t i = 0; i < userSize; ++i)
		inFile << ' ' << randomGenerator(0, 99);
	inFile.close();
}

size_t randomGenerator(size_t min, size_t max) {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	//rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
	return dist(rng);
}