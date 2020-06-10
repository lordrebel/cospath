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
	std::string dirname,filename,filename_stem,extension_str,sep;
	os::dirname(current_path, dirname);
	os::filename(current_path, filename);
	os::stem(current_path, filename_stem);
	os::extension(current_path + ".bbt", extension_str);
	os::get_sep(sep);
	std::cout << "current dir parent:" <<dirname  << endl;
	std::cout << "current filename:" << filename << endl;
	std::cout << "current sep:" <<  sep<< endl;
	std::cout << "current filename_stem:" << filename_stem << endl;
	vector<string> list;
	cospath::list_dir(current_path, list);
	std::cout << "listdir:" << endl;
	for (auto a : list) {
		cout << a << endl;
	}
	std::cout << "current extension:" << extension_str << endl;
	auto status=os::mkdir(current_path + "/test/aaa/bsc");
	bool flag = (status == os::COS_STATUS::SUCCESS) ? true : false;
	std::cout << "mkdir:" << current_path + "/test/aaa/bsc"<<" status:"<<flag<< endl;
	std::cout <<"join:"<< cospath::join({ "aa", "ert", "dedee"});
	std::cin.get();
	return 0;
}
