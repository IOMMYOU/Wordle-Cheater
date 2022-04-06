#pragma once
#include <iostream>
#include "Debug.h"
#include <vector>
#include <string>
#include <fstream>
#include "alphabet.h"

class helper
{
public:
	static void printArgs(int argc, char** argv);
	static int prepArgs(int argc, char** argv, std::vector<std::string>& args);
	static void output(word_list* weighted_list, std::vector<std::string> list, alphabet* alpha, const char* msg);
};