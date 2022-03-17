#include "helper.h"
#include <iostream>
void helper::printArgs(int argc, char** argv) {
	//print out arguments
	std::cout << "You have entered " << argc
		<< " arguments:" << "\n";
	for (int i = 0; i < argc; ++i)
		std::cout << argv[i] << "\n";
	//end of printing arguments 
}