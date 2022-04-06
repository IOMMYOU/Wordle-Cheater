#include "helper.h"
#include <iostream>
#include <vector>
#include <string>
#include "letter.h"


void helper::printArgs(int argc, char** argv) {
	//print out arguments
	std::cout << "You have entered " << argc
		<< " arguments:" << "\n";
	for (int i = 0; i < argc; ++i)
		std::cout << argv[i] << "\n";
	//end of printing arguments 
}
void helper::prepArgs(int argc, char** argv, std::vector<std::string>& args) {
    for (int i = 0; i < argc; ++i) {
        args.push_back(argv[i]);
    }
    while (args.size() < 7) {
        args.push_back(".");
    }
    for (auto tc : args) {
        std::cout << tc + " ";
    }
    std::cout << std::endl;
    
}

void helper::output(word_list* weighted_list, std::vector<std::string> list,
    alphabet* alpha, const char* msg) 
{
    for (std::string word : list) {
        weighted_list->addWord(alpha, word);
    }
    weighted_list->sortList();
    std::cout << "********************" << std::endl << msg << std::endl;
    for (int i = 0; i < std::min((size_t)5, weighted_list->size()); i++) {
        std::cout << weighted_list->list[i].word << ": " << weighted_list->list[i].weight << std::endl;
    }
}