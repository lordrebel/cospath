// cospath.cpp: 定义应用程序的入口点。
//
#include<iostream>
#include "cospath.hpp"

using namespace std;

namespace os = cospath;
int main()
{

	cout << "start test:" << endl;
	string current_path;
	os::cwd(current_path);
	std::cout << "current dir:" << current_path << endl;
	std::string dirname,filename,filename_stem,extension_str;
	os::dirname(current_path, dirname);
	os::filename(current_path, filename);
	os::stem(current_path, filename_stem);
	std::cout << "current dir parent:" <<dirname  << endl;
	std::cout << "current filename:" << filename << endl;
	std::cout << "current filename_stem:" << filename_stem << endl;
	std::cin.get();
	return 0;
}
