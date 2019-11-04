#include<iostream>
#include<locale>

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
	locale loc("chs");
	wcout.imbue(loc);
	wchar_t ch[]=L"中文";
	wcout << ch << endl;



}
