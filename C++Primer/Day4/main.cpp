#include"header.h"

using namespace std;

void Test();
void Test2();

void Test3();
extern const int var = 89;
//int var = 89;
int main()
{

	//cout << var << endl;
	//print();
	//Test();
//	Test2();
	Test3();
	return 0;
}

void Test()
{
	int var = 33;
	int &refer =var;
	cout << refer << endl;

	int var2=32;
	refer = var2;
	cout << refer << endl;
	
	cout << var << endl;
}

void Test2()
{
	int var = 98;
	int *ptr = &var;

	int * &r = ptr;

	cout << *r << endl;
	
	//const int * (&(*d));
	//int &(*e);



}




void Test3()
{

	const long int ID = 0xffff;
	
	const long int &r1 = ID;
	long int r3= 0x123;

	const long int &r2 = r3 * 2;
	cout << r1 << endl;
	cout << hex << ID << endl;
	cout << r1 << dec << ID << endl;

	r3 = 0x234;
	cout << r2 << endl;
	
	cout << r2 << endl;	


}
