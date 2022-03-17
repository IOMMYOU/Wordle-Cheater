#pragma once
#include "letter.h"
#include <iostream>
#include <algorithm>
/**/



alphabet::alphabet() {
	for (int i = 0; i < 26; ++i) {							//initialize the alpha array of letter structures
		raw[i].letter = (char)(i + 97);
		raw[i].frequency = 0;
		sorted[i]=raw[i];
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
		std::cout << sorted[i].letter << "\t : " << sorted[i].frequency << std::endl;
	}
}

int alphabet::sort() {
	if (DEBUG_M) { std::cout << "run sort()" << std::endl; }
	letter swapLetter = {0};
	for (int i = 0; i < 26; ++i) {							
		sorted[i] = raw[i];
	}
	for (int ib = 0; ib < 26 - 1; ++ib) {
		for (int i = 0; i < 26 - 1; ++i) {
			if (sorted[i].frequency < sorted[i + 1].frequency) {
				swapLetter = sorted[i]; 
				sorted[i] = sorted[i+1];
				sorted[i+1] = swapLetter;
			}
		}
	}
	return 0;
}

