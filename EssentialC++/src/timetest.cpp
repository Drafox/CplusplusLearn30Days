#include<iostream>
#include<ctime>
#include<vector>

using namespace std;



int main()
{


	double start_t = 0, end_t = 0;

	start_t = clock();


	vector<double> V(1000000000);

	end_t = clock();

	cout << (end_t - start_t) /(CLOCKS_PER_SEC) << endl;	



	return 0;
}
