#include "BubbleSortClass.h"



void BubbleSortClass::swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


void BubbleSortClass::BubbleSort(int data[], size_t size)
{
	bool isorder;
	for(size_t index_x = 0; index_x < size ; ++index_x )
	{
		isorder = true;
		for(size_t index_y = 0 ; index_y < size - 1 - index_x; ++index_y)
		{
			if(data[index_y] > data[index_y + 1])
			{
			
				swap(data[index_y], data[index_y + 1]);
				isorder = false;
			}
		}

		if(isorder == true)
			break;
	}
}


