#include"BinarySearch.h"

using namespace std;

int main()
{
	vector<int> data = {1,2,3,4,5,6,7,8};

	int a[] = {1,2,3,4,5,6,7};
	
	auto result = BinarySearchByIterator(data,2);

	auto n = BinarySearchByRecursion(a,0,6,4);
	cout << result << endl << n << endl;
	

}
