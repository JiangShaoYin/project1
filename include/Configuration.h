 /// @date    2018-07-09 18:55:19
 
#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
using std::string;
using std::map;
using namespace std;

class Configuration {
	public:
		Configuration(const string & filePath) 
			 :_filePath(filePath) {
		//	 cout << "Configuration(filePath)" << endl;
			 } 
		Configuration() 
			 :_filePath("/home/xubo/jiang/project1/data/conf.txt") {
		//	 cout << "Configuration(filePath)" << endl;
			 } 
		map<string, string>& getConfigMap();
	private:
		string _filePath;//读文件的路径
		map<string,string> _configMap;
};//end of Configuration
#endif
