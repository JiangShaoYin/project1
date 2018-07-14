 /// @date    2018-07-09 19:53:57
 
#ifndef __DICTPRODUCER_H__
#define __DICTPRODUCER_H__
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class DictProducer {
	public:
		DictProducer(const string &dir);
		DictProducer();
		void build_dict();//建字典的时候，顺带store_dict(filePath)
		void show_file();
		void show_dict();
	private:
		void store_dict(const string & fileName);
		void get_file();
	private:
		string _dir;
		map<string, string> _files;
		map<string,int> _dict;
};
#endif
