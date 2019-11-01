#include<iostream>
#include<limits>
#include<ios>
#include<iomanip>
using namespace std;


void TestIOBuffer();
void TestIOBase();

int main(int argc, char **argv)
{
	//cout<<"Hello, World!"<<endl;
	
	//TestIOBuffer();
	
	TestIOBase();

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


void TestIOBase()
{
	int num = 100;

	//cout.setf(ios_base::hex,ios_base::basefield);
	//cout.setf(ios_base::showbase);
	cout << std::hex << num << 12 <<endl;
	cout << std::showbase << 123<< endl;
	cout << std::showbase <<198 << endl;
	cout.unsetf(ios_base::hex);
	//cout.setf(ios::dec);
	cout<< std::showbase <<199 << endl;


	//----------------
	

	cout.setf(ios_base::oct, ios_base::basefield);
	cout.setf(ios_base::showbase);

	cout << num << endl;

	cout.unsetf(ios_base::oct);

	//---------
	
	

	cout << oct << num << endl;



	cout << setw(10) << "Drafox" << endl;

	


}
