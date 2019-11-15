#ifndef IOTEST_H
#define IOTEST_H

#include<iostream>
#include<ostream>
#include<istream>
#include<fstream>




class IOtest{

	public:

	IOtest() = default;
	
	void Test();	
	void FileTest();	

	void FileModein();
	void FileModeout();
	void FileModeApp();
	private:
	std::string data;

};


#endif
