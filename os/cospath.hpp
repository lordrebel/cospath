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

	COS_STATUS list_dir(const std::string& path,std::vector<std::string>&path_list);
	COS_STATUS list_dir_subfile(const std::string& path, std::vector<std::string>& path_list);
	COS_STATUS list_dir_subdir(const std::string& path, std::vector<std::string>& path_list);
	COS_STATUS list_dir_recursive(const std::string& path, std::vector<std::string>& path_list);

	bool is_file(const std::string& path);
	bool is_dir(const std::string& path);
	bool is_exist(const std::string& path);

	COS_STATUS mkdir(const std::string& path);
	COS_STATUS cwd(std::string& res);
	COS_STATUS dirname(const std::string& src, std::string& res);
	COS_STATUS stem(const std::string& src, std::string& res);
	COS_STATUS extension(const std::string& src, std::string& res);
	COS_STATUS mv(const std::string& src, const std::string dst);
	COS_STATUS cp(const std::string& src, const std::string dst);

}
#endif