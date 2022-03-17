#pragma once
#include <vector>
#include <algorithm>
#ifndef DEBUG_M 
#define DEBUG_M true
#endif 



//namespace myClass{

	struct letter {                                                                                         //structure chosen for combining data

	public:
		char letter;
		int frequency;
	};

	class alphabet {
	public:
		int sort();
		alphabet();
		~alphabet();
		void outRaw();
		void outSorted();
		letter raw[26] = {0};
		letter sorted[26] = {0} ;
	};
//}