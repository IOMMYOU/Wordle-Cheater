#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include "Debug.h"
#include <mutex>



//namespace myClass{

	struct letter {                                                                                         //structure chosen for combining data

	public:
		char letter;
		int frequency;
		int uniqueFrequency;
		float weight;
		std::mutex mut;
	};

	class alphabet {
	public:
		int sort();
		alphabet();
		~alphabet();
		void outRaw();
		void outSorted();
		void outSortedUnique();
		void setWeight(int wordCount);
		letter raw[26] = {0};
		letter sorted[26] = {0} ;
		void inputLine(std::string input);
	};
//}