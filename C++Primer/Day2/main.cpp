#include<iostream>

using namespace std;
int main()
{
 	unsigned  a = 198;
	int b = -72;
	

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
