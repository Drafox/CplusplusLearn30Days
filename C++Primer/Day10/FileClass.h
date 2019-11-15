#ifndef FILECLASS_H
#define FILECLASS_H



#include<iostream>
#include<fcntl.h>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<errno.h>
#include<cstring>

class FileClass{

	public:
	
	void GetMaxNameLength();
	void TestName(std::string name );
	private:
	
	std::string TempName;
	const char *PathName = TempName.c_str();



};



#endif
