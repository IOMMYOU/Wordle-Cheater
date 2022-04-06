#include "letterHandling.h"
#include <string>
#include <iostream>
#include <algorithm>


// call this from within a loop for each letter to increment the position
int letterHandling::findFunc(std::string string, std::string pattern, int pos) {
	int val;
	int i = 0;
	val = pattern.find('.');
	if (val != -1) {																//has info
		return 1;
	}
	val = pattern.find('+');
	if(val==-1){																//out position
		return letterHandling::letterNotInPosition(string, pattern, pos);
	}
	else{																	//in position
		pattern.erase(pattern.begin()+val);
		return letterHandling::letterInPosition(string, pattern, pos);
	}
	return 0;
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