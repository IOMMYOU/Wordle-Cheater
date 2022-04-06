#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "letter.h"
#include "letterHandling.h"
#include "..\ThreadPool.h"
#include <map>
#include "helper.h"



int main(int argc, char** argv)
{
    /*****************************************************************/
    /*variables used in main program**********************************/
    int c = 0;
    ThreadPool pool(1);
    alphabet* alpha = new alphabet;
    std::vector<std::future<int> > results;
    std::vector<std::string> args, full_list, partial_list;
    word_list* weighted_full_list = new word_list;
    word_list* weighted_partial_list = new word_list;
    std::ifstream myfile("c:/wordle/5list.txt");
//    std::ifstream myfile("../../WordleSolve/rsc/5list.txt");
    /*****************************************************************/
    /*****************************************************************/
    /*****************************************************************/
    /*fill in arguments and attemp to open list file******************/
    helper::prepArgs(argc, argv, args);
    if (!myfile.is_open()){
        std::cout << "Unable to open file";    
        std::cin.get();
        return 0;
    }
    /*****************************************************************/
    /*filter list and count unique letter appearances*****************/
    letterHandling::main(&myfile, args, &partial_list, &full_list, alpha, &c, &pool);
    myfile.close();         //close file so it can be accessed later
    for (auto&& result : results) //wait on thread pool
        std::cout << result.get() << ' ';
    std::cout << std::endl;
    /*****************************************************************/
    /*process and present data****************************************/
    alpha->sort();
    alpha->setWeight(c);
    alpha->outSortedUnique();
    helper::output(weighted_full_list, full_list, alpha, "Elimination Words");
    helper::output(weighted_partial_list, partial_list, alpha, "Guesses");
    /*****************************************************************/
    std::cin.get();
    return 0;
}

/*
* replaced with letterHandling::main
* 
    while (std::getline(myfile, line))
{
    if (line == "exit") { break; }						//ends program when exit is typed in or blank line
    if (line.size() <= 0) {continue;}
    else {
        if (!letterHandling::letterNotInWord(line, args[6])){continue;}
        for (int i = 0; i < 5; i++) {
            pass = letterHandling::findFunc(line, args[i + 1], i);
            if (!pass) {break;}
        }
        if (!pass) {
            full_list.push_back(line);
            continue;
        }
        c++;
        partial_list.push_back(line);
        pool.enqueue(&alphabet::inputLine, alpha, line);
    }
}
*/

/*
* replaced with helper::output
* 
for(std::string word : full_list){
    weighted_full_list->addWord(alpha, word);
}
weighted_full_list->sortList();
std::cout << "********************" << std::endl << "Elimination words" << std::endl;
for( int i =0; i < 5; i++){
    std::cout << weighted_full_list->list[i].word << ": " << weighted_full_list->list[i].weight << std::endl;
}
for (std::string word : partial_list) {
    weighted_partial_list->addWord(alpha, word);
}
weighted_partial_list->sortList();
std::cout << "********************" << std::endl << "Guesses" << std::endl;
for (unsigned int i =0; i< std::min((size_t)5,weighted_partial_list->size()); i++) {
    std::cout << weighted_partial_list->list[i].word << ": " << weighted_partial_list->list[i].weight << std::endl;
}
*/