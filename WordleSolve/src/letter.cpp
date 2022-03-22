#pragma once
#include "letter.h"
#include <iostream>
#include <algorithm>
#include <string>

/**/



alphabet::alphabet() {
	for (int i = 0; i < 26; ++i) {							//initialize the alpha array of letter structures
		raw[i].letter = (char)(i + 'a');
		raw[i].frequency = 0;
		sorted[i].letter = (char)(i + 'a');
		sorted[i].frequency = 0;
		//sorted[i] = raw[i];
	}//
}

alphabet::~alphabet() {
	delete raw;
	delete sorted;
}

/**/
void alphabet::outRaw() {
	if (DEBUG_M) { std::cout << "run outRaw()" << std::endl;  }
	for (int i = 0; i < 26; i++) {
		std::cout << raw[i].letter << "\t : " << raw[i].frequency << std::endl;
	}
}

void alphabet::outSorted() {
	if(DEBUG_M){std::cout << "run outSorted()" << std::endl; }
	for (int i = 0; i < 26; i++) {
		std::cout << sorted[i].letter << "\t : " << sorted[i].frequency << "\t weight : " << sorted[i].weight << std::endl;
	}
}

void alphabet::outSortedUnique() {
	if (DEBUG_M) { std::cout << "run outSorted()" << std::endl; }
	for (int i = 0; i < 26; i++) {
		std::cout << sorted[i].letter << "\t : " << sorted[i].uniqueFrequency << "\t weight : " << sorted[i].weight << std::endl;
	}
}

int alphabet::sort() {
	if (DEBUG_M) { std::cout << "run sort()" << std::endl; }
	letter swapLetter = {0};
	for (int i = 0; i < 26; ++i) {							
		sorted[i].letter = raw[i].letter;
		sorted[i].frequency = raw[i].frequency;
		sorted[i].uniqueFrequency = raw[i].uniqueFrequency;
	}
	for (int ib = 0; ib < 26 - 1; ++ib) {
		for (int i = 0; i < 26 - 1; ++i) {
			if (sorted[i].uniqueFrequency < sorted[i + 1].uniqueFrequency) {
				swapLetter.letter = sorted[i].letter;
				swapLetter.frequency = sorted[i].frequency;
				swapLetter.uniqueFrequency = sorted[i].uniqueFrequency;
				sorted[i].letter = sorted[i+1].letter;
				sorted[i].frequency= sorted[i + 1].frequency;
				sorted[i].uniqueFrequency = sorted[i + 1].uniqueFrequency;
				sorted[i + 1].letter = swapLetter.letter;
				sorted[i + 1].frequency = swapLetter.frequency;
				sorted[i+1].uniqueFrequency = swapLetter.uniqueFrequency;
			}
		}
	}
	return 0;
}

void alphabet::inputLine(std::string input) {
	if (DEBUG_M) { std::cout << "run inputLine()" << std::endl; }
	int i = 0;
	char c = input[i];
	int test = 0;
	std::string tempString; 
	while (c != '\0') {
		if (DEBUG_M) { std::cout << c; }
		alphabet::raw[c - 'a'].mut.lock();
		raw[c - 'a'].frequency++;
		test = tempString.find(c);
		if (test == -1) {
			raw[c - 'a'].uniqueFrequency++;
		}
		alphabet::raw[c - 'a'].mut.unlock();
		tempString.push_back(c);
		i++;
		c = input[i];
	}
	return;
}

void alphabet::setWeight(int wordCount) {
	int halfWordCount = wordCount / 2;
	for (int i=0; i<26; i++) {
		alphabet::sorted[i].weight = halfWordCount - ( abs(halfWordCount - alphabet::sorted[i].uniqueFrequency)) ;
	}

	//TODO need another scan through remaining words to try to find the highest elimination available from given weights
	//TODO also possibly read in the original list for these weights to maximize letter removals
}