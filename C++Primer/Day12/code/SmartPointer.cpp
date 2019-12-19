#include"SmartPointer.h"

using namespace std;

int main()
{
	vector<int> test{1,2,3,4,5};
	SmartPointer sp(test);
	sp.GetElm();
	
	
	StrBlob st;
	{
	StrBlob sbtl={"an","guo","peng"};
		st = sbtl;
		sbtl.pop_back();
		cout << st._data.use_count() << endl;
		cout << st._data.unique() << endl;
		//sbtl.push_back("dengdeng");
	}
	//sbtl.display();
	
		cout << st._data.unique() << endl;
	st.display();

	shared_ptr<int> sn = make_shared<int>(22);
      	st.Test(sn);	
	cout << "sn:" << sn.use_count() << endl;
	

	vector<int> *a;
	a= st.practice1();
	st.practice2(a);
	st.practice3(a);
	delete a;
	a = nullptr;


	shared_ptr<int> np(new int(2048));
	st.process(shared_ptr<int>(np));
	cout << np.use_count() << endl;

	st.process(shared_ptr<int> (np.get()));
	cout << np.use_count() << endl;

	shared_ptr<int []> p(new int [20]);	
	//shared_ptr<int []> pp = make_shared<int []>(50);
	unique_ptr<int []> ppp = make_unique<int []>(1024);
	
	unique_ptr<int> pr = make_unique<int>(23);
	st.compute(pr);


	StrBlob sptrA;
	sptrA.SptrTest();	

	ExConversion ec;
	ec.stCast();
	return 0;
}
