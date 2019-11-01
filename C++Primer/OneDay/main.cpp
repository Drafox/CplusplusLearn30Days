#include<iostream>
#include<limits>
using namespace std;


void TestIOBuffer();

int main(int argc, char **argv)
{
	//cout<<"Hello, World!"<<endl;
	
	TestIOBuffer();

	return 0;
}


void TestIOBuffer()
{
	int a;
	char ch[50];
	
	int b;
	
	cin >> a;
	
	//cin.ignore(numeric_limits<streamsize>::max(),'\n');
	

	//cin >> b; 	
	
	cin.getline(ch,50);


	cout << a << endl;


	cout << ch << endl;
	




}
