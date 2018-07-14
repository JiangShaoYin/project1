 /// @date    2018-07-10 14:20:35

#include "Index.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void Index::store_index() {	
	read_dict();
	vectorToMap();
	
	string File = "/home/jiang/project1/data/en_index.dat"; //cout << reFileName.str() << end
	ofstream ofs(File);
		for(auto & itMap : _index) {//遍历map内的每一个pair
			ofs << itMap.first << " ";
			for(auto &iterSet : itMap.second) {//遍历pair里的第二个成员set内的每一个int
				ofs << iterSet << " ";
			}
			ofs << endl;
		}
}

void Index::vectorToMap() {
	int lineNum = 0;
//	cout << "before vectorToMap" << endl;
	for(auto &iterVector : _readIn) {//读vector的每一个元素
		string word = iterVector.first;
//cout << word <<endl;
		for(auto & iterString : word) {//解析单词的每一个字符
			if(isalpha(iterString)){
			string charString(1,iterString);
//cout << "charString :" << charString <<endl;

			auto exist = _index.find(charString);
//if(exist==_index.end()) cout << "not exist " << endl;
			if(exist == _index.end()){
				set<int> newSet{lineNum};
			_index.insert(make_pair(charString, newSet));
			}
			else{
//cout << "exist->first: " << exist->first << endl; 
				(exist->second).insert(lineNum);
			}
			}
		}//end of nearest for
		++lineNum;
	}//end of for	
//	cout << "after vectorToMap" << endl;
}


void Index::show_readIn() {
	for(auto &it:_readIn) {
		cout << it.first << " "
			 << it.second << endl;
	}
}

void Index::read_dict() { //读数据到_readIn
	stringstream ss;
	ss << "/home/jiang/project1/data/" << _fileName;
	ifstream ifs(ss.str());//打开dict_*文件(将ifs与这个文件关联)	
	string line;
	while(ifs) {//从文件中读数据
		getline(ifs, line);
			istringstream iss(line);
			string word1,word2;
			iss >> word1 >> word2;
				int freq = atoi(word2.c_str());
			pair<string, int> tmp(word1,freq);
			_readIn.push_back(tmp);
		}
}

