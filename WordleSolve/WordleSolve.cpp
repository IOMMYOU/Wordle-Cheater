#include <iostream>
#include <string>
#include <vector>
#include "letter.h"
#include "letterHandling.h"
#include "helper.h"

int main(int argc, char** argv){
	std::string oLine;
	int c = 0;
	char b;
	int pass = 0;
	std::vector<std::string> iList;
	iList.reserve(256);
	alphabet *alpha = new alphabet;
	std::vector<std::string> oList;	// does not have size reservation
	//DBprint("debugging output on");

	//helper::printArgs(argc, argv);
		//TODO class for input - read in list and add into alpha object

	while (std::cin.get(b)) {
		//oLine.erase(oLine.begin(), oLine.end());			//clears each line from working data
		if (b != '\n'){
			oLine.push_back(b);									//builds line into working data
			//alpha->raw[b - 97].frequency++;						//increases letter frequency when found in word TODO handling of more than lower case letters
			std::cout << oLine << std::endl;
		}
		else {
			if (DEBUG_M) { std::cout << "run '\\n'" << std::endl; }
			if (oLine == "exit") { return 0; }						//ends program when exit is typed in or blank line
			if (oLine.size() <= 0) {
				if (DEBUG_M) { std::cout << "oline size continue" << std::endl; }
				continue; 
			}
			else{
				for (int i = 0; i < oLine.size(); i++) {
					if (DEBUG_M) {std::cout << "i val: " << i << "oLine.size();" << oLine.size() << std::endl; }
					std::cout << oLine << argv[i + 1] << i;
					pass = letterHandling::findFunc(oLine, argv[i+1], i );
					if (DEBUG_M) { std::cout << "letterHandling" << std::endl; }
					if (!pass){
						if (DEBUG_M) { std::cout << "not pass" << std::endl; }
						oLine.erase(oLine.begin(), oLine.end());
						continue;
					}
				}
			}
			if (!pass) { 
				continue; 
				oLine.erase(oLine.begin(), oLine.end());
				}
			iList.push_back(oLine);	
			c++;
			oLine.erase(oLine.begin(), oLine.end());			//clears each line from working data
		}
		
	}
	for (int i = 0; i < iList.size(); i++) {
		std::cout << i + 1 << " : " << iList[i] << std::endl;
	}
	//std::cout << c << " words " << std::endl;
	//std::cout << c << " words " << std::endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

