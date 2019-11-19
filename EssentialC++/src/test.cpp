#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void print_msg(const vector<T> data);

void test(const int (&a)[10]);
template<typename A,typename  B ,typename C, typename  D>
void printm(A  ,B  ,C , D ); //declaration
int main()
{


	vector<int> data1 = {1,2,3,4,5,6};
	vector<string> data2 ={"Heko","TujK","yuyu"};
	vector<char> data3{'a','b','c'};
	print_msg(data1);
	print_msg(data2);
	print_msg(data3);

	printm("123",4,4.098,'a');
	printm(4,4.098,'a',"123");
	printm('a',"123",4.08,4);



	int h[10] = {1,2,3,4,5,6,7,8,11,12};
       	test(h);	
	return 0;
}


template <typename T>
void print_msg(const vector<T> data)
{
	for(auto i : data)
	{
	
		cout << i << endl;
	}

}
//definition
template<typename A, typename B, typename C,typename D>
void printm(A a, B b, C c, D d)
{
    cout << "1 : " << a << "\t2: " <<b << "\t3 : " << c << "\t 4: " <<d << endl;
}





void test(const int (&a)[10])
{

		auto beg = begin(a);
		auto ed = end(a);
		for(beg; beg!=ed ; ++beg)
		{
			cout << *beg << endl;
		}
}
