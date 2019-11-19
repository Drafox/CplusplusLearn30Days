#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;



bool FibonacciGame(int position, int &element);
void BubbleSort(int data[], int size);
void BubbleSort(vector<int> data);
void swap(int &num1, int &num2);
int main()
{
	vector<int> object(18);
	cout << object[0] << endl;
	object[0] = 1;

	//vector<int> object2;

	//object2[0] = 11;
	
	int result = 0;
	int pos;
	cin >> pos;
	if(!FibonacciGame(pos, result))
	{
		cerr << "the value is exceed the scope!" << endl;
	
	}

	else
	{
		cout << "result : " << result << endl;
	
	}


	srand(time(NULL));
	const int n = rand() % 100;
	int a[n] ;  
	for(int i = 0; i < n; ++i)
	{
		int m = rand() % 1000;
		a[i] = m;
		cout << a[i] << endl;
	}

	BubbleSort(a, n);
	
	for(int i = 0 ; i < n ; i++)
	{
		cout << a[i] << ( (i + 1 %10 == 0) ? "\n" : "\t");
	}


return 0;
}

bool FibonacciGame(int position, int &element)
{
    if(position <= 0 || position > 46){
        element = 0;
        return false;
    }
    
    int num1 = 1, num2 =1;
    for(int index = 3; index <= position; ++index)
    {
        element = num1 + num2;
        num1 = num2; 
        num2 =element;
	//cout <<element <<( ((index-3)%10 == 0)?"\n":"\t");

    }
    return true;
}


void BubbleSort(int data[], int size)
{
    for(int index_x = 0; index_x < size; ++index_x )
    {
        for(int index_y = 0; index_y < size - index_x -1; ++index_y)
        {
            if(data[index_y] > data[index_y+1])
                swap(data[index_y],data[index_y + 1]);
        }
    }
}

void BubbleSort(vector<int> data)
{
    for(decltype(data.size()) index_x = 0; index_x < data.size(); ++index_x)
    {
        for(decltype(index_x) index_y = 0; index_y < data.size() - index_x -1; ++index_y)
            if(data[index_y] > data[index_y + 1])
                swap(data[index_y],data[index_y + 1]);
    }
}

void swap(int &num1, int &num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;

  //  cout << "num 1: " << num1 << "\n num2: " << num2 << endl; 
}

