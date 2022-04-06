#pragma once
#include "alphabet.h"
#include <iostream>
#include <algorithm>
#include <string>

void s_letter::operator = (s_letter& l) {
	this->frequency = l.frequency;
	this->letter = l.letter;
	this->uniqueFrequency = l.uniqueFrequency;
	this->weight = l.weight;
}

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
	delete[] raw;
	delete raw;
	delete[] sorted;
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
	s_letter swapLetter = {0};
	for (int i = 0; i < 26; ++i) {		
		sorted[i] = raw[i];
	}
	for (int ib = 0; ib < 26 - 1; ++ib) {
		for (int i = 0; i < 26 - 1; ++i) {
			if (sorted[i].uniqueFrequency < sorted[i + 1].uniqueFrequency) {
				swapLetter = sorted[i];
				sorted[i] = sorted[i+1];
				sorted[i+1] = swapLetter;
			}
		}
	}
	return 0;
}

void alphabet::inputLine(std::string input) {
	if (0) { std::cout << "run inputLine()" << std::endl; }
	int i = 0;
	char c = input[i];
	int test = 0;
	std::string tempString; 
	while (c != '\0') {
		if (0) { std::cout << c; }
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
	float halfWordCount = 1.0f + ((float)wordCount / 2.0f);
	for (int i=0; i<26; i++) {
		alphabet::sorted[i].weight = halfWordCount - abs(halfWordCount - alphabet::sorted[i].uniqueFrequency);
	}
}

bool compareWordWeight(weighted_word w1, weighted_word w2)
{
	return (w1.weight > w2.weight);
}


void word_list::addWord(alphabet* alpha, std::string input) {
	float val = 0;
	bool repeat = 0;
	for (int ia = 0; ia < input.size(); ia++) {
		for (int ib = 0; ib < ia; ib++) {
			if (input[ia] == input[ib]) {
				repeat = 1;
				break;
			}
		}
		if (!repeat) { val += alpha->sorted[input[ia] - 'a'].weight; }
	}
	temp_word.weight = val;
	temp_word.word = input;
	list.push_back(temp_word);
}


