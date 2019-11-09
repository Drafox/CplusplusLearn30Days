#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include<string>
#include<vector>
#include<iostream>

int BinarySearchByRecursion(int data[], int left, int right, int element)
{
	if(right >= left )
	{
		int mid = (right + left) /2 ;
	if(data[mid] == element)
		return mid+1;

	if(data[mid] > element)
		return BinarySearchByRecursion(data,left, mid-1, element);

	return BinarySearchByRecursion(data, mid+1 , right, element);

}
	return -1;
}

std::vector<int>::difference_type  BinarySearchByIterator(std::vector<int> data, int element)
{
	auto left = data.cbegin();
	auto right = data.cend();
	auto mid = data.cbegin() + (right - left)/ 2 ;

	while(mid != right && *mid != element)
	{
		if(*mid > element)
			right = mid;
		else
			left = mid +1 ;

		mid = left + (right - left) /2 ;
	
	}

	return mid - data.cbegin() + 1;
}









#endif
