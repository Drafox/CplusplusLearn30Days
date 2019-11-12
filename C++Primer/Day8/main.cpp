#include<iostream>
#include<cstddef>
#include<vector>
#include<string>
#include<exception>
#include<iterator>
using namespace std;


typedef int aat[10];
using arrT = int[10];

const int  GetElement(const int n, const char ch, const char* (&target) );
bool Judge(int a, char ch, double b);
bool InitialString(size_t &size, char *c);
void print(char *name);
void Get(int (&b)[10]);
void print(const string greet);
void Condition( int a,  int b);
auto FunPlusVsG2(int (&a)[5], int (&b)[5]) -> int (*)[5];
int (*	Test(int (&a)[10], int (&b)[10]))[10];
int add(int a, int b);
//int add(const int a, const int b);
//int add(const int a, int b);
//int add(int a, const int b);

bool moveLeft(const int a, const int b);




















int main()
{
	
	int a = 33;
	double b = 66;
	char ch = 'c';
	cout << Judge(22,'a',75.98) << endl;
	cout << Judge(a, ch, b) << endl;
	char name[10]= "jp";
       	print(name);	
	
	int d[10];
	int (&dd)[10] = d;
	
	dd[2] = 251;
	cout << d[2] << endl;

	int aa[10] = {1,2,3,4,5,6};
	Get(aa);
	cout << aa[0] << endl;

	Condition(22,2);



	int aaa[10] = {1,3,5,7,9};
	int bbb[10] = {2,4,6,8,10};

	int (*ccc)[10] ;
	  ccc=	Test(aaa, bbb);
	return 0;
}



//int , char ,double

bool Judge(int a, char ch, double b)
{
	try{
	
		if(int(a+b) == (int)ch)
			throw runtime_error("error");
	
	}catch(runtime_error err)
	{
		return true;
	}

	return false;
}

//pointer, reference

bool InitialString(size_t &size, char *c)
{

	size_t index = 0;
	for(; index < size ; ++index)
	{
	
		*(c+index) = 'z';
	}

	if(index < size)
	{
		return false;
	}

	return true;
}


//const int, const char

const int  GetElement(const int n, const char ch, const char* (&target) )
{
	int result;
	for(int index = 0; index < n; ++index)
	{
		if(*(target) == ch)
		{
			
			++result;
		}
	
	
	}

	return result;
}



//
void print(char *name)
{
    while(*(name))
          {
              cout << *(name++) << endl;
          }
    
}

void Get(int (&b)[10])
{
    cout << b[0]++ << endl;
}

void print(const string greet)
{
    cout << greet << endl;
}

//不严谨的函数
void Condition( int a,  int b)
{
    string greet("Hello, World!");
    if(a == b)
        return print(greet);
    a -= b;
    return Condition(a,b); 
}


arrT * Test(int (&a)[10], int (&b)[10])
{

	int temp;

	auto bbe = begin(b);
	for(auto be = begin(a);begin(a) != end(a);++be,++bbe)
	{
		temp = *be;
		*be = *bbe;
		*bbe = temp;
	}

	return &a;


	
}

auto FunPlusVsG2(int (&a)[5], int (&b)[5]) -> int (*)[5]
{
	return &a;
}

int add(int a, int b)
{
	
	bool moveLeft(const int a);

	bool flag = moveLeft(a,b);
	return a+b;

}

/*

int add(const int a, const int b)
{
	return a+b;

}


int add(const int a, int b)
{

	return a+b;
}


*/
bool moveLeft(int a, const int b)
{
	if(++a < b)
	{
		return true;
	}
	return false;
}

bool moveLeft(const int a)
{

	return true;
}
