#include<iostream>
#include<list>
#include<deque>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

template<typename T>
const T * MyFind(const vector<T> &vec, const T &element);
void ListTest();
int main()
{
	


	deque<int> data(100,98);
	data.pop_back();
	data.push_back(22);
	auto en = data.end() - 1;
	cout << *en << endl;
	ListTest();


	vector<int> nec{11,12,13,14,15,16,141,132,112,332};
	const int *ptr;
	ptr = MyFind(nec, 14);
	cout << *ptr << endl;


}


//双向链表
void ListTest()
{
	

	list<int> data = {1,2,3,44,33,22,11};

	auto it1 = find(data.begin(),data.end(), 3);
	auto it2 = find(data.begin(), data.end(), 22);

	auto  max = max_element(data.begin(), data.end());
	cout << *it1 << endl << *it2 << endl;
	

	vector<int> data1 = {2,44,11,223,24,4,89,90};
       sort(data1.begin(),data1.end(),greater<int>());
       for(auto i : data1)
	       cout <<    i   << "i : \t";
	cout << endl;
	auto re = data.erase(it1, it2);

	cout << endl << *re << endl << endl;
	
	for(auto i : data)
		cout << i << endl;
	

       cout << *max << endl;	

	
	cout << data.back() << endl;
	data.pop_back();
	cout << data.back() << endl;
	cout <<data.front() << endl;
	data.pop_front();
	cout << data.front() << endl;
	
	for(auto i : data)
		cout <<  "i:" << i << endl;

	cout << *(data.erase(data.begin())) << endl;

}







template<typename T>
const T * MyFind(const vector<T> &vec, const T &element)
{
	for(int ix = 0; ix < vec.size(); ++ix)
		if(vec[ix] == element)
			return &vec[ix];

		return nullptr;


}
