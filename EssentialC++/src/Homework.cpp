#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstdlib>
#include<time.h>


using namespace std;

class Chapter1{

	public:
	
	void FileTest() const {
		
		ifstream file("main.cpp");
		
		vector<string> data;
		string str;
		while(getline(file,str))
		{
			sort(str.begin(),str.end());
			data.push_back(str);
		}
		

		for(auto i : data)
		{
			cout << i << endl;
		}
		
		cout << data.size() << endl;
	
	}

	
	void GreetDiff()
	{
		srand(time(nullptr));
		int err_time = 0;
		int n = rand() % 10;
		
		int m;
		cout << "Guess the number of the candy in my hand (tips: less than 10)" << endl;


		const char *comfort[6] = {"Less Than 4!! You are stupid!!", "You are right!!", "Oh, are you ok?", "Come on! Get it!", "OH MY GOD!!","Finally!!!"};

		while(cin >> m)
		{
			if( m == n)
			{
				cout << comfort[1] << endl;
				break;
			}
			else if(m >10 || m < 0)
				cout << comfort[0] << endl;
			else 
			{
					if(++err_time > 4)
						break;
				cout << comfort[err_time + 1] << endl;
			
			}
		}
	
	
	
	}

};














int main()
{
	Chapter1 ch1;
//	ch1.FileTest();
	ch1.GreetDiff();
	return 0;
}
