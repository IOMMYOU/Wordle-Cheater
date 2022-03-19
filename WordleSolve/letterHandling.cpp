#include "letterHandling.h"
#include <string>
#include <iostream>
#include <algorithm>

/*
public:
	static int findFunc(const char&);	//not sure on data type
	static void letterInPosition();
	static void letterNotInPosition();
	static void letterNotInWord();
*/

// call this from within a loop for each letter to increment the position
int letterHandling::findFunc(std::string string, std::string pattern, int pos) {
	if (DEBUG_M) { std::cout << "run findFunc()" << std::endl; }

	int val;
	int i = 0;
	val = pattern.find('.');
	if (val != -1) {																//has info
		if (DEBUG_M) { std::cout << "no info val: " << val << std::endl; }
		return 1;
	}
	if (DEBUG_M) { std::cout << "has info" << std::endl; }
	val = pattern.find('+');
	if(val==-1){																//out position
		if (DEBUG_M) { std::cout << "not in position" << std::endl; }
		return letterHandling::letterNotInPosition(string, pattern, pos);
	}
	else{																	//in position
		pattern.erase(pattern.begin()+val);
		if (DEBUG_M) { std::cout << "in position" << std::endl; }
		return letterHandling::letterInPosition(string, pattern, pos);
	}
	//return letterHandling::letterNotInPosition(string, pattern, pos);

	return -1;
}

int letterHandling::findFunc(std::string string, std::string pattern) {
	return letterHandling::letterNotInWord(string, pattern);
}


int letterHandling::letterInPosition(std::string string, std::string pattern, int pos) {
	if (DEBUG_M) { std::cout << "run letterInPosition()" << std::endl; }
	if (string.find(pattern) == (pos)) {
		return 1;
	}
	return 0;
}
int  letterHandling::letterNotInPosition(std::string string, std::string pattern, int pos) {
	if (DEBUG_M) { std::cout << "run letterNotInPosition()" << std::endl; }
	int i = 0;
	while ((pattern[i]) != '\0') {
		if (string[pos] == pattern[i]) { return 0; }
		i++;
	}
	i = 0;
	while ((pattern[i]) != '\0') {
		if (string.find(pattern[i]) == -1) { return 0; }
		i++;
	}
	return 1;
	// for each letter in pattern scan through the position

	/*for (char letter : pattern) {
		if (string.find(pattern) != -1 && string.find(letter) != (pos - 1)) {
			return 1;
		}
	}*/

}
int letterHandling::letterNotInWord(std::string string, std::string pattern) {
	if (DEBUG_M) { std::cout << "run letterNotInWord()" << std::endl; }
	int i = 0;
	for (int ia = 0; ia < 5; ia++) {						//TODO make length dynamic
		while ((pattern[i]) != '\0') {
			if (string[ia] == pattern[i]) { return 0; }
			//std::cout << "not in word" << i << pattern[i] << std::endl;
			i++;
		}
		i=0;
	}
	return 1;
}

void wordList::giveMeLine(const char* input, const char* pattern) {
	if (DEBUG_M) { std::cout << "run giveMeLine()" << std::endl; }
	int i = 0;
	char c = *(input );
	while ( c != '\0') {
		std::cout << c;
		i++;
	}
	return;
}