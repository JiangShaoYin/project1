 /// @date    2018-07-09 23:47:17
 
#include "DictProducer.h"
#include "Configuration.h"
#include <fstream>
using namespace std;

DictProducer::DictProducer(const string &dir)	//将文件输出至dir
	:_dir(dir) {
	//	cout << "DictProducer(string)" << endl;
	}
DictProducer::DictProducer()	//将文件输出至dir
	:_dir("/home/xubo/jiang/project1/data/") {
	//	cout << "DictProducer(string)" << endl;
	}

void DictProducer::get_file() {
	cout << "get_file" << endl;
	Configuration config("/home/xubo/jiang/project1/data/conf.txt");
		_files = config.getConfigMap();
}

void DictProducer::show_file() {
	for(auto& it : _files) {
		cout << it.second << endl;
	}
}

void DictProducer::build_dict() {
	get_file();
	for(auto &it : _files){
		string fileName = it.first;
		ifstream ifs(it.second);
		while(ifs){
			string word;
			ifs >> word;
			if(isalpha(word[0])){
			if(_dict.find(word)==_dict.end()) 
				_dict.insert(make_pair(word, 1));	
			else 
				++ _dict[word];
			}
		}
	}
		store_dict("enDict.dat");
}

void DictProducer::show_dict() {
	for(auto& it : _dict) {
		cout << it.first << " "
			 << it.second << endl;
	}
}

void DictProducer::store_dict(const string & fileName) {
	stringstream reFileName;
	reFileName << _dir << fileName; //cout << reFileName.str() << endl
	ofstream ofs(reFileName.str());
		for(auto & it : _dict) {
			ofs << it.first << " "
				<< it.second << endl;
		}
}

