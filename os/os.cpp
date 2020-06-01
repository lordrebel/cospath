#include"cospath.hpp"
#include<boost/filesystem.hpp>
#include<iostream>

#ifdef OUT_ERRORS
const bool OUT_ERRORS = true;
#else
const bool OUT_ERRORS = false;
#endif // OUT_ERRORS

namespace cospath {
	using namespace std;
	namespace bfs = boost::filesystem;
	bool is_file(const std::string& path){

		return bfs::is_regular_file(bfs::path(path));
	
	}
	template<class T>
	std::string join(std::initializer_list<T> alist)
	{
		return std::string();
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
	COS_STATUS mkdir(const std::string& path)
	{
		if (is_exist(path)) {
			return COS_STATUS::IS_EX;
		}
		boost::system::error_code code;
		bool flag = bfs::create_directories(path,code);
		
		if (!flag) {
			if (OUT_ERRORS) {
				cerr << "error when creating: " << path << " " << code.message() << std::endl;
			}
			bool flag = bfs::create_directory(path,code);
			
			if (!flag) {
				if (OUT_ERRORS) {
					cerr << "error when creating: " << path << " " << code.message() << std::endl;
				}
				return COS_STATUS::FAIL;
			}
			else {
				return COS_STATUS::SUCCESS;
			}
		}
		else {
			return COS_STATUS::SUCCESS;
		}
	}
	COS_STATUS dirname(const std::string& src, std::string& res)
	{
		res.clear();
		res = bfs::path(src).parent_path().string();
		return COS_STATUS::SUCCESS;
	}
	COS_STATUS filename(const std::string& src, std::string& res)
	{
		res.clear();
		res = bfs::path(src).filename().string();
		return COS_STATUS::SUCCESS;
	}
	COS_STATUS stem(const std::string& src, std::string& res)
	{
		res.clear();
		res = bfs::path(src).stem().string();
		return COS_STATUS::SUCCESS;
	}
	COS_STATUS extension(const std::string& src, std::string& res)
	{
		auto start = src.find_last_of(".");
		if (start != src.size()) {
			res = src.substr(start+1);
		}else{
			res = "";
			}
		return COS_STATUS::SUCCESS;
	}
	COS_STATUS mv(const std::string& src, const std::string& dst)
	{
		
		try {
			bfs::rename(src, dst);
			return COS_STATUS::SUCCESS;
		}
		catch (exception err) {
			if (OUT_ERRORS) {
				cerr << err.what()<<endl;
			}
			return COS_STATUS::FAIL;
		};
	}
	COS_STATUS cp(const std::string& src, const std::string& dst)
	{
		if (!boost::filesystem::exists(dst))
		{
			boost::filesystem::create_directories(dst);
		}
		bfs::path src_p(src);
		bfs::path dst_p(dst);
		for (boost::filesystem::directory_iterator it(src_p); it != boost::filesystem::directory_iterator(); ++it)
		{
			const boost::filesystem::path newSrc = it->path();
			const boost::filesystem::path newDst = dst_p / it->path().filename().string();
			if (boost::filesystem::is_directory(newSrc))
			{
				auto flags=cp(src, dst);
				if (flags == COS_STATUS::FAIL) return COS_STATUS::FAIL;
				else continue;
			}
			else if (boost::filesystem::is_regular_file(newSrc))
			{
				boost::filesystem::copy_file(newSrc, newDst, boost::filesystem::copy_option::overwrite_if_exists);
			}
			else
			{	if(OUT_ERRORS)
					cerr<< "Error: unrecognized file - " << newSrc.string() << endl;
					return COS_STATUS::FAIL;
			}
		}
		return COS_STATUS::SUCCESS;
	}
	COS_STATUS get_sep(std::string& res)
	{
		res = bfs::path::preferred_separator;
		return COS_STATUS::SUCCESS;
	}



}