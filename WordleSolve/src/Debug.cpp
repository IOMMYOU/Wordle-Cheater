#pragma once
#include <iostream>
#include "Debug.h"


void dbMsg(const char* input) {
	if(!DEBUG_M){return;}
	std::cout << input << std::endl;
}
