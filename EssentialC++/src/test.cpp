#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Test{
	public:	
	
	Test() = default;
	Test(int a, double b) : height(a), area(b){}
	Test  operator+ (const Test &b) ;
	const size_t  GetElemSize() const {return _elem.size();}
	void AddElem(int elem)
	{
		_elem.push_back(elem);
	}
	
	void display()
	{
	
		
	cout << height << "\t" << area << endl;
	}

	private:
		static vector<int> _elem;
		int height;
	       	double area;	


};


Test  Test::
operator+ (const Test &b)
{
	Test result;
	result.height = height + b.height;
	result.area = area + b.area;

	return result;

}



vector<int>Test::_elem;

template<typename T>
void print_msg(const vector<T> data);

void test(const int (&a)[10]);
template<typename A,typename  B ,typename C, typename  D>
void printm(A  ,B  ,C , D ); //declaration
template <typename T >
int count_occurs(const vector<T> &vec,  T elem);
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



	vector<int> var1 {1,2,3,4,1,1,2,3,1,4};
	vector<string> var2{"facebook","alibaba","meituan","alibaba","alibaba"};

	int var1_c = 0 , var2_c = 0;

	string str = "alibaba";
	int s = 1;
	var1_c = count_occurs(var1, s);
	var2_c = count_occurs(var2, str);

	cout << "time1: \t" << var1_c << "\ttime2: \t" << var2_c << endl; 



	//static class data memeber
	//
	Test test1{1,2.333};
	Test test2{11,3.333};
	test1.AddElem(100);
	cout << "size:" <<test1.GetElemSize() << endl;
	test2.AddElem(111);

	cout << "size:" <<test2.GetElemSize() << endl;
	


	Test test3 = test1 + test2;
	test3.display();

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




template <typename T>
int count_occurs(const vector<T> &vec,  T elem)
{
	auto beg = vec.begin();
	int count_occur = 0;
	while((beg = find(beg, vec.end(), elem)) != vec.end())
	{
		++count_occur;
		++beg;
	
	}

	return count_occur;
}






