#include<iostream>

using namespace std;

typedef int ArrayType[5];

void Test(int(&a)[5]);
ArrayType * Test1(int (&a)[5], int (&b)[5]);

int main(){


	int a[5] = {2,3,4,5,6};
	int b[5] = {1,2,3,1,3};
	Test(a);
	int (*c)[5];
	c = Test1(a, b);
	for(size_t index = 0; index < 5 ; ++index )
	{
	
		cout << (*c)[index] << endl;
	
	}
	
	cout << &a << endl;

 	for(auto i :a)
		cout << i << endl;

	return 0;
}




void Test(int(&a)[5])
{
	for(auto i: a)
	
		cout << i << endl;


}



ArrayType * Test1(int (&a)[5], int (&b)[5])
{

	auto beg = begin(b);
	int temp = 0;
	for(auto &i:a)
	{
		temp = i;
		i = *beg;
		*(beg++) = temp;
	}

	return &a;
}
