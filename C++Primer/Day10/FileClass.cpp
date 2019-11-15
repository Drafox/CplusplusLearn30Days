#include"FileClass.h"


void FileClass:: GetMaxNameLength()
{

	std::cout << "the max length of name is :" <<  NAME_MAX << std::endl;

}



void FileClass::TestName(std::string name)
{
	auto flag = O_RDWR|O_CREAT|O_EXCL;
	auto file = open(name.c_str(), flag);

	std::cerr  << strerror(errno) << std::endl;


}
