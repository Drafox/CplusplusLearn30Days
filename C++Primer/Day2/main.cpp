#include<iostream>

using namespace std;
void TestInputC();
int main()
{
 	unsigned  a = 198;
	int b = -72;
	
	TestInputC();


	cout << (unsigned)b + a  << endl;



	cout << hex << a << endl;
	cout << b << endl;
	
	cout << (unsigned)b << endl;

	cout << a+b << endl;	



	cout.unsetf(ios_base::hex);

	
	cout << a+a << endl;
	cout << a+b << endl;
	cout << b+b << endl;

	return 0;
}

void TestInputC()
{
	//char ch;
	wchar_t ch;

	cin >> ch ; 

	cout << ch << endl;



}
