#include "letterHandling.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "letter.h"
#include "..\ThreadPool.h"
using vstring = std::vector<std::string>;

// call this from within a loop for each letter to increment the position
int letterHandling::findFunc(std::string string, std::string pattern, int pos) {
	unsigned int val;
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

}
int letterHandling::letterNotInWord(std::string string, std::string pattern) {
	int i = 0;
//	for (int ia = 0; std::min(string.size(), pattern.size()) < 5; ia++) {						//TODO make length dynamic
	for (int ia = 0; ia < std::min(string.size(), pattern.size()); ia++) {						//TODO make length dynamic
		while ((pattern[i]) != '\0') {
			if (string[ia] == pattern[i]) { return 0; }
			i++;
		}
		i=0;
	}
	return 1;
}

int letterHandling::letterInWord(std::string string, std::string pattern) {
	int i = 0;
	//	for (int ia = 0; std::min(string.size(), pattern.size()) < 5; ia++) {						//TODO make length dynamic
	for (int ia = 0; ia < std::min(string.size(), pattern.size()); ia++) {						//TODO make length dynamic
		while ((pattern[i]) != '\0') {
			if (string[ia] == pattern[i]) { return 1; }
			i++;
		}
		i = 0;
	}
	return 0;
}


void letterHandling::main(std::ifstream* myfile, vstring args, 
vstring* partial_list, vstring* full_list, alphabet* alpha, int* c, ThreadPool* pool) 
{
	std::string line;
	int pass = 0;
	while (std::getline(*myfile, line))
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
				full_list->push_back(line);
				continue;
			}
			*c = *c + 1;
			partial_list->push_back(line);
			pool->enqueue(&alphabet::inputLine, alpha, line);
		}
		
	}

}