#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;


int main()
{

	map<string, int> words;

	set<string> keywords3;
	words["apple"]  = 100;
	
	auto beg = words.begin();
	cout << beg->first<< endl;
	cout << beg->second << endl;

	auto it = words.find("banana");
	if(it != words.end())
		cout << "find it " << endl;
	else
		cout << "no words" << endl;
	
	return 0;
}
