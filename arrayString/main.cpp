#include <iostream>
#include <string>
#include <array>

using namespace std;

typedef array<string, 5> StringArray;

StringArray readStringArray(StringArray strings) {

	for (int i = 1; i < strings.size(); i++) {
		cout << "Enter a string: ";
		getline(cin, strings[i]);
	}
	return strings;
}

StringArray sortStringArray(StringArray strings) {

	//bubble sort

	bool sorted = false;

	while (!sorted) {
		sorted = true;
		for (int i = 1; i < strings.size() - 1; i++) {
			if (strings[i] > strings[i + 1]) {
				swap(strings[i], strings[i + 1]);
				sorted = false;
			}
		}
	}
	return strings;
}

void printArrayString(StringArray strings) {
	cout << "\n--- Strings ---";

	for (StringArray::iterator p = strings.begin(); p != strings.end(); ++p) {
		cout << *p << endl;
	}
}

int main() {
	StringArray scentences = {};
	
	scentences = readStringArray(scentences);
	scentences = sortStringArray(scentences);
	printArrayString(scentences);

	return 0;
}
