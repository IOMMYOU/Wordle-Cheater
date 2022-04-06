#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "letter.h"
#include "letterHandling.h"
#include "..\ThreadPool.h"
#include <map>

int func(int &input) {
    input *= 2;
    input += 2;
    return input;
}

int main(int argc, char** argv)
{
    int c = 0, thing = 2;
    ThreadPool pool(1);
    alphabet* alpha = new alphabet;
    std::vector<std::future<int> > results;
    std::vector<std::string> args, full_list, partial_list;
    word_list* weighted_full_list = new word_list;
    word_list* weighted_partial_list = new word_list;
    int pass = 0;
    int ins = 0;
    std::string line;
    std::ifstream myfile("c:/wordle/5list.txt");
    std::map<std::string,float> weighted_map;


    for (int i = 0; i < argc; ++i) {
        args.push_back(argv[i]);
    }
    while (args.size() < 7) {
        args.push_back(".");
    }
    for (std::string tc : args) {
        std::cout << tc + " ";
    }
    std::cout << std::endl;
    if (!myfile.is_open())
    {   
    std::cout << "Unable to open file";    
    }
    else {
        while (std::getline(myfile, line))
        {
//            full_list.push_back(line);
            if (line == "exit") { break; }						//ends program when exit is typed in or blank line
            if (line.size() <= 0) {
                continue;
            }
            else {
                if (!letterHandling::letterNotInWord(line, args[6])){
                continue;
                }
                else{
                    //full_list.push_back(line);
                }
            for (size_t i = 0; i < line.size(); i++) {
                pass = letterHandling::findFunc(line, args[i + 1], i);
                if (!pass) {
                    break;
                }
            }
            if (!pass) {
                full_list.push_back(line);
                continue;
            }
            c++;
            partial_list.push_back(line);
            //pool.enqueue([alpha, line] {alpha->inputLine(line); });
            pool.enqueue(&alphabet::inputLine, alpha, line);
            }
        }
        myfile.close();
    }
    for (int i = 0; i < 8; ++i) {
    //    results.emplace_back(pool.enqueue(&func,std::ref(thing)));
    }   
    for (int i = 0; i < 8; ++i) {
    //    results.emplace_back(pool.enqueue(&func, thing));
    }
//    for (auto&& result : results)
//        std::cout << result.get() << ' ';
//    std::cout << std::endl;
    alpha->sort();
    alpha->setWeight(c);
    alpha->outSortedUnique();
//    std::cin.get();

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
    
//    std::cin.get();
    std::cout << "********************" << std::endl << "Guesses" << std::endl;

    for (int i =0; i< std::min(5,weighted_partial_list->size()); i++) {
        std::cout << weighted_partial_list->list[i].word << ": " << weighted_partial_list->list[i].weight << std::endl;
    }

    return 0;
}