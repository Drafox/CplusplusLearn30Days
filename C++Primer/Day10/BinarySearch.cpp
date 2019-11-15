#include"BinarySearch.h"

using namespace std;
int BinarySearch::search(const vector<int>nums, int target){

		auto beg = nums.begin(), end = nums.end();
		auto mid = nums.begin() + (end -beg)/2;
		cout  << *mid << endl;
		while(*mid != target )
		{
			//cout << *mid << endl;
			if(*mid > target)
				end = mid;
			else
				beg = mid + 1; 


			mid = beg +(end - beg)/2;
			cout << *mid << endl;
		
		}

		if(beg == end)
		{
			return -1;
		}
		else
			return (mid - nums.begin())+1;



}
