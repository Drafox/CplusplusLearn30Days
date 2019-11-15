#include"iotest.h"
void IOtest::Test()
{  
	int input;

	std::cout << "Drafox, Google Code" << std::endl; //刷新缓冲区，并且加上换行符
	std::cout << "Drafox, Google Code" << std::flush; //只刷新缓冲区
	std::cout << "Drafox, Google COde" << std::ends; //刷新缓冲区， 并且加上空格



	std::cout << "Noo";
		//cin.tie(&cout);
	std::cin >> input ;



	

}



void IOtest::FileTest()
{
	
	//ifstream practices
	//
	
	std::ifstream file("test.txt");

	if(!file.is_open())
	{
	
		std::cout << "did not open!" << std::endl;
	}	
	
	std::string data;
       //file >> data;

	getline(file,data);
	std::cout << data << std::endl;       
}

void IOtest::FileModein()
{
	
	std::ifstream in;
	in.open("test.txt");
	if(in.is_open())	
	{
		std::cout << "opened" << std::endl;
	}

	std::string word;
	in >> word;
	std::cout << word << std::endl;

	in.close();
}


void IOtest::FileModeout()
{
	std::cout << "original file:" << std::endl;
	system("cat test.txt");
	std::ofstream out("test.txt");
	//default mode out | trunc
	
	if(!out)
	{
		std::cout << "failed" << std::endl << std::endl; 
	}
	out << "Hello, HongKong" << std::endl  << "One China!" << std::endl;

	out.close();
	std::cout << "current file:" << std::endl;
	system("cat test.txt");

}


void IOtest::FileModeApp()
{
	std::cout << "original file: " << std::endl;
	std::ofstream out("test.txt",std::ofstream::out | std::ofstream::app);
	if(!out)
	{
		std::cerr << "open failed" << std::endl; 
	}

	out << "HongKong, Taiwan" << std::endl;

	out.close();	

	std::cout << "current file: " << std::endl;
	system("cat test.txt");
}

/*
void IOtest::FileModeAte()
{
	
	

}


void IOtest::FileModeBinary()
{}
*/
