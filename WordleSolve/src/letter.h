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
		float weight;
		std::string word;
	};

	bool compareWordWeight(weighted_word w1, weighted_word w2);

	class word_list {
	private:
		weighted_word temp_word;
//		bool compareWordWeight(weighted_word w1, weighted_word w2);
	public:
		int size(){return list.size();}
		std::vector<weighted_word> list;
		void addWord(alphabet* alpha, std::string input) {
			float val = 0;
			bool repeat = 0;
			//embed
			for (int ia=0; ia < input.size(); ia++) {
				for (int ib = 0; ib < ia; ib++) {
					if(input[ia] == input[ib]){
						repeat = 1;
						break;
					}
				}
				if (!repeat){val += alpha->sorted[input[ia] - 'a'].weight;}
			}
				
			
			temp_word.weight = val;
			temp_word.word = input;
			list.push_back(temp_word);
		}
		void sortList() {
			std::sort(list.begin(), list.end(), compareWordWeight);
		}


	};




#endif // !_LETTER_H