#pragma once

#ifndef _LETTER_H
#define _LETTER_H



#include <vector>
#include <algorithm>
#include <string>
#include "Debug.h"
#include <mutex>
#include <algorithm>
#include <map>



//namespace myClass{

	struct letter {                                                                                         //structure chosen for combining data

	public:
		char letter;
		int frequency;
		int uniqueFrequency;
		float weight;
		int pad[256];
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
		//int pad2[256];
		letter sorted[26] = {0} ;
		void inputLine(std::string input);
	};
//}

	struct weighted_word {
		float weight = 0;
		std::string word;
	};

	bool compareWordWeight(weighted_word w1, weighted_word w2);

	class word_list {
	private:
		weighted_word temp_word;
	public:
		size_t size(){return list.size();}
		std::vector<weighted_word> list;
		void addWord(alphabet* alpha, std::string input);
		void sortList() {
			std::sort(list.begin(), list.end(), compareWordWeight);
		}
	};
#endif // !_LETTER_H