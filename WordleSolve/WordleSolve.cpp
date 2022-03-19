#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "letter.h"
#include "letterHandling.h"
#include "helper.h"
#include "Debug.h"



#define THREADS_NUM 2

int main(int argc, char** argv){
	std::string oLine;
	int c = 0;
	char b;
	int pass = 0;
	std::vector<std::string> args;
	std::vector<std::string> iList;
	iList.reserve(256);
	alphabet *alpha = new alphabet;
	std::vector<std::string> oList;	// does not have size reservation

	std::vector<std::thread> threads;


	dbMsg("Debugging output enabled");



	for (int i = 0; i < argc; ++i){
		args.push_back(argv[i]);
	}

	//helper::printArgs(argc, argv);
	//TODO class for input - read in list and add into alpha object
	//TODO sanitize the command line arguments into an array for use

	while (std::cin.get(b)) {
		if (b != '\n'){
			oLine.push_back(b);									//builds line into working data
			dbMsg(oLine.c_str());
		}
		else {
			dbMsg("run '\\n'");
			if (oLine == "exit") { return 0; }						//ends program when exit is typed in or blank line
			if (oLine.size() <= 0) {
				dbMsg("oline size continue");
				continue; 
			}
			else{
				if (!letterHandling::letterNotInWord(oLine, argv[6])) {
					dbMsg("not in word");
					oLine.erase(oLine.begin(), oLine.end());
					continue;
				}
				for (int i = 0; i < oLine.size(); i++) {
					if (DEBUG_M) {std::cout << "i val: " << i << " oLine.size(); " << oLine.size() << std::endl; }
					if (DEBUG_M) {std::cout << oLine << argv[i + 1] << i << std::endl; }		//TODO use sanitized input
					pass = letterHandling::findFunc(oLine, argv[i+1], i );
					if (DEBUG_M) { std::cout << "letterHandling: " << pass << std::endl; }		//TODO use sanitized input
					if (!pass){
						dbMsg("not pass");
						oLine.erase(oLine.begin(), oLine.end());
						continue;
					}
				}
			}
			if (!pass) { 
				oLine.erase(oLine.begin(), oLine.end());
				continue;
			}
			//alpha->inputLine(oLine);
			 

			threads.push_back(std::thread(&alphabet::inputLine, alpha, oLine));

			iList.push_back(oLine);	
			c++;
			oLine.erase(oLine.begin(), oLine.end());			//clears each line from working data
		}
		
	}
	for (int i = 0; i < iList.size(); i++) {
		std::cout << i + 1 << " : " << iList[i] << std::endl;
	}

	for (auto& th : threads) {
		th.join();
	}
	
	alpha->sort();
	alpha->setWeight(c);
	alpha->outSortedUnique();
	std::cout << std::endl << c << " words " << threads.size() << std::endl;
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

