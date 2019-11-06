#include<iostream>
#include<string>
#include<cctype>

using namespace std;

void Test();
void Test2();

void Test3();
void TestString();
void TestStringO();
typedef const int *const Avg;
using Avga = const int *const; 





int main()
{
//	Test();
//	Test2();
//	Test3();
//	TestString();
	TestStringO();
	return 0;
}


void Test()
{

	int var = 99;
	int var2 = 100; 
	int *ptr = &var;
	const int *cptr = &var;


	cout << var << endl;
	cout << *ptr << endl;
	cout << *cptr << endl;

	cptr = &var2;

	cout << *cptr << endl;


}

void Test2()
{
	int var = 101;
	int var2 = 102;
	
	int * const ptrc = &var;
	cout << *ptrc << endl;
	//ptrc = &var2;

	*ptrc = 999;

	cout << *ptrc << endl;
	cout << var << endl;
	
	const int max = 100;
	const int min = 9;

	constexpr int  avg = (max + min)/ 2;
	cout << avg << endl;

	Avg pct = &max;
	Avga ppct =&min;

	cout << *pct << endl << *ppct << endl;

}	//int i = -1, &r = 0;error 

void Test3()
{
	int var = 0;
	auto m = var;

	const int var1 = 99; //top-level const  
	auto n =var1; //ignore top-level const return int type 
	
	const int *const q = &var1;

	auto p = q;
	
	const int var2 = 100;
	p = &var2;
	cout <<* p << endl;
	n = 991;
		

	decltype(var) num =989;
        cout << num << endl;
	
	decltype((var)) mun =num ;
	cout << mun << endl;

}

void TestString()
{
	//initiate string object
	
	string greet1; //default: blank string 
	string greet2 = "Hello, World!"; //字面值副本
        string greet3 = greet2;//copy the value of the greets variable to greet3; 
	
	string headline(37,'-');

	cout << headline << endl << endl << endl << endl << headline << endl;	


	cin >> greet1;
	greet1 += "\n";
	cout << greet1;

	string test;
	cin >> test;
	cout << test.size() << endl;
	cout << greet1.size() <<endl;


}

void TestStringO()
{
	string word;
	cin >> word;

	for(auto &i: word)
		i=toupper(i);
	cout << word <<endl;


}
