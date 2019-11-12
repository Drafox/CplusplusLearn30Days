#include<iostream>
#include<cstddef>
#include<vector>
#include<string>
#include<exception>

using namespace std;


const int  GetElement(const int n, const char ch, const char* (&target) );
bool Judge(int a, char ch, double b);
bool InitialString(size_t &size, char *c);
void print(char *name);
void Get(int (&b)[10]);
void print(const string greet);
void Condition( int a,  int b);
int main()
{
	
	int a = 33;
	double b = 66;
	char ch = 'c';
	cout << Judge(22,'a',75.98) << endl;
	cout << Judge(a, ch, b) << endl;
	char *name = "jp";
       	print(name);	
	
	int d[10];
	int (&dd)[10] = d;
	
	dd[2] = 251;
	cout << d[2] << endl;

	int aa[10] = {1,2,3,4,5,6};
	Get(aa);
	cout << aa[0] << endl;

	Condition(22,2);

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

