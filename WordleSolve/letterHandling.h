#pragma once
#include <vector>
#include <string>

#ifndef DEBUG_M 
#define DEBUG_M true
#endif 

class letterHandling
{
public:
	static int findFunc(std::string string, std::string pattern, int pos);	//not sure on data type
	static int findFunc(std::string string, std::string pattern);	//not sure on data type
	static int letterInPosition(std::string string, std::string pattern, int pos);
	static int  letterNotInPosition(std::string string, std::string pattern, int pos);
	static int  letterNotInWord(std::string string, std::string pattern);
};
	
class wordList {
public:
	void giveMeLine(const char* input, const char* pointer);

private:
	std::vector<std::string> list;
};