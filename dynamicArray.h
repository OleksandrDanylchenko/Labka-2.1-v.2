#pragma once
class dynamicArray {
public:
	//CONSTRUCTORS
	dynamicArray(); // empty constructor

	//DESTRUCTOR
	~dynamicArray();

	//OPERATORS OVERLOADING
	int &operator[](size_t i); // return the value in the certain cell of dynamic array

	//METHODS
	bool in(istream& in); // inserts an element from istream, called by the operator >>
	void out(ostream& out) const; // output an element to the ostream, called by the operator <<
	size_t getSize() const;
	size_t getCapacity() const;
	friend void processArray(dynamicArray& a); // process the array due to the task
private:
	size_t Size; // work length
	size_t Capacity; // absolute length
	int* arr = nullptr; // pointer to a dynamic array
	void Resize(); // changes the length of a dynamic array
	static const size_t N = 100;  
};

bool operator>>(istream& is, dynamicArray& a);
ostream& operator<<(ostream& os, const dynamicArray& a);
