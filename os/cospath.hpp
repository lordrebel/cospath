#ifndef COSPATH
#define COSPATH
#include<string>
#include<vector>

namespace cospath {
	typedef enum class __cos_status {
		SUCCESS = 0,
		NOT_EX,
		FAIL,
		IS_EX,
		IS_FILE,
		IS_DIR,

	} COS_STATUS;
	//list current dir
	COS_STATUS list_dir(const std::string& path,std::vector<std::string>&path_list);
	//list only file in current dir
	COS_STATUS list_dir_subfile(const std::string& path, std::vector<std::string>& path_list);
	//list only folder in current dir
	COS_STATUS list_dir_subdir(const std::string& path, std::vector<std::string>& path_list);
	//list current dir recursively
	COS_STATUS list_dir_recursive(const std::string& path, std::vector<std::string>& path_list);
	//find thefilename cantain the partten in current dir
	COS_STATUS glob(const std::string& path, const std::string& pattern, std::vector<std::string>& res);
	//find thefilename cantain the partten in current dir
	COS_STATUS glob_recursive(const std::string& path, const std::string& extension, std::vector<std::string>& res);
	
	//move file or path
	COS_STATUS mv(const std::string& src, const std::string& dst);
	//copy file or path
	COS_STATUS cp(const std::string& src, const std::string& dst);
	//rm current file or path
	COS_STATUS rm(const std::string& path);
	COS_STATUS fileSize(const std::string& path,size_t &size);


	bool is_file(const std::string& path);
	bool is_dir(const std::string& path);
	bool is_exist(const std::string& path);
	

	COS_STATUS get_sep(std::string& res);
	COS_STATUS mkdir(const std::string& path);
	COS_STATUS cwd(std::string& res);
	COS_STATUS dirname(const std::string& src, std::string& res);
	COS_STATUS filename(const std::string& src, std::string& res);
	COS_STATUS stem(const std::string& src, std::string& res);
	COS_STATUS extension(const std::string& src, std::string& res);

	template<class T>
	std::string join(std::initializer_list<T> alist)
	{
		std::string res("");
		std::string sep;
		cospath::get_sep(sep);
		for (auto a : alist) {
			res += (sep + a);
		}
		return res;
	};
	

}
#endif