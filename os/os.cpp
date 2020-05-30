#include"cospath.hpp"
#include<boost/filesystem.hpp>
namespace cospath {
	using namespace std;
	namespace bfs = boost::filesystem;
	bool is_file(const std::string& path){

		return bfs::is_regular_file(bfs::path(path));
	
	}

	bool is_dir(const std::string& path){

		return bfs::is_directory(path);
	}

	bool is_exist(const std::string& path){

		return bfs::exists(path);
	}
	COS_STATUS cwd(std::string& res){
		auto path = bfs::current_path();
		res = path.string();
		return COS_STATUS::SUCCESS;
	}
}