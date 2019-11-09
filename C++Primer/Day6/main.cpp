#include<iostream>
#include<vector>
#include<string>
#include<cstddef>

using namespace std;

typedef vector<int>::size_type vsize_t;
typedef string::size_type st_size;

void Test2();
typedef struct  Lnode{
	int data;
	struct Lnode *next;
}Lnode, *LinkList;

void Test();
void Test3();
void Test4();
int main()
{

	 //Test();
	 //Test2();
	//Test3();

	Test4();
}


void Test()
{

	vector<int> price;
	vector<int> &prfer = price;
	vector<string> BookName;
	vector<Lnode> LinkArray;
	vector<vector<int> > D;
	
	for(int i = 0; i < 19 ; i++)
	{
	
		price.push_back(i);
	}

	for(auto i : price)
		cout << i << "\t" << endl;

	vsize_t plen = price.size();

	cout << endl << plen << endl;


	auto e = price.begin();
	auto f = price.end();


	if(e != f)
	{
	
		cout << "unempty" << endl;
	}

	for(e ; e != f; e++)
	{
	
		cout << *e << endl;
	}


vector<int> vec(18,98);
const vector<int> cvec(18,99);
vector<int> :: const_iterator a;
vector<int> :: const_iterator b;
vector<int> :: iterator c;
vector<int> :: iterator d;

a = vec.cbegin();
b = vec.cend();
c = vec.begin();
d = vec.end();

for(a; a !=b ; a++)
    cout << *a << endl;
for(c; c !=d ; c++)
    *c = 100;

//for(auto i : vec)
//	cout << i << endl;

for(c = vec.begin(); c != d; c++ )
	cout << *c << endl;

//for(a = vec.cbegin(); a != b; a++)
  //  *a = 101;
}

void Test2()
{
	string name = "Hello, World!";
decltype(name.begin()) a = name.begin();
auto b = name.end();
auto c = a + 3;

auto d = a -c;

string:: difference_type e = b -c;

cout << d << endl << e << endl; 

}


void Test3()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for(auto &i:a)
    	    i = i+1;
	for(auto i:a)
    		cout << i << endl;
int b[3][4] = {
    {2,3,4},
    {5,6,7},
    {8,9,10}
};

for(auto &i:b)
    for(auto j:i)
        cout << j << endl;

}

void Test4()
{

	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	int *be = begin(a);
	int *en = end(a);

	ptrdiff_t size = en - be ;
	cout << size << endl;

	vector<int> c(be+2, en-2);
	for(auto i : c)
		cout << i << endl;


}

