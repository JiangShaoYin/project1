 /// @date    2018-07-10 14:09:05
 
#ifndef __INDEX_H__
#define __INDEX_H__
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Index {
	public:
		Index(string fileName) : _fileName(fileName) {}
		Index() : _fileName("en_dict.dat") {}
	void store_index();
	void show_readIn();
//	private:
		void read_dict();//read to vector
		void vectorToMap();//_readIn to _index
	private:
		string _fileName;//打开文件的名字
		unordered_map<string, set<int>> _index;
		vector<pair<string, int>> _readIn;
};//end of Index
#endif 
