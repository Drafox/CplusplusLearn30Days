#include"lambda.h"



using namespace std;


int main()
{


	vector<int> vec {2,222,11,33,44,55,12,11};
	Lambda lbd(23);
	lbd.Test();
	lbd.bubbleSort(vec);
	for(auto i : vec)
	{
	cout << i << "\t";
	}
	cout << endl;

	Lambda lbd1(22);
	Lambda lbd2(lbd1);
	lbd2.show();

	Lambda lbd3 = lbd2;

	lbd3.show();
	Lambda lbd5(100);
	lbd5 = lbd3;

return 0;
}
