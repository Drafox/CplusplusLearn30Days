#include"mvobject.h"

using namespace std; // using 指示


int main()
{


	string a ="asd";
	string b(static_cast<typename std::remove_reference<string>::type &&>(a));


	cout << a << "\n"<< b << endl;

	string spr = "ByteDance";
	MvClass<string> mv(&spr, "abc");

	mv.show();
	MvClass<string> smv(std::move(mv));
	smv.show();

	cout << "----------" << endl;

	mv.show();




	return 0;
}
