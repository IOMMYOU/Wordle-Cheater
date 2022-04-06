#pragma once
#include <vector>
#include <string>
#include "Debug.h"
#include "letter.h"
#include "..\ThreadPool.h"
using vstring = std::vector<std::string>;

class letterHandling
{
public:
	static int findFunc(std::string string, std::string pattern, int pos);	
	static int findFunc(std::string string, std::string pattern);	
	static int letterInPosition(std::string string, std::string pattern, int pos);
	static int letterNotInPosition(std::string string, std::string pattern, int pos);
	static int letterNotInWord(std::string string, std::string pattern);
	static int letterInWord(std::string string, std::string pattern);
	static void main(std::ifstream* myfile, vstring args,
		vstring* partial_list, vstring* full_list, alphabet* alpha, int* c, ThreadPool* pool);
};
	