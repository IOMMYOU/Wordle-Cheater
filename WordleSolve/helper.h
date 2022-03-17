#pragma once
#include <iostream>

#ifndef DEBUG_M 
#define DEBUG_M false
#endif 

class helper
{
public:
	static void printArgs(int argc, char** argv);
};