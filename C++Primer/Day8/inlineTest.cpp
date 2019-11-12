#include"header.h"
#include<cassert>

void myAssert();

void Test(decltype(sum) *fpprt);
int main()
{

	print();


	std::cout << sum(22,22) << std:: endl;
	
	std::string words = "affirm";

	//assert(words.size() > 8);
	if(words.size() < 8)
	{
		myAssert();
	}


	Test(sum);




	return 0;	



}

void myAssert()
{
    #ifndef NDEBUG

    	std::cerr << __FILE__ << ": function:\t" << __func__<< "\t:" << __LINE__ <<std::endl;

    #endif
}


void Test(decltype(sum) *fpprt)
{
    int result = fpprt(100,100);
    std::cout << result << std::endl;
}
