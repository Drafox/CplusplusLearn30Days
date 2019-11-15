#include"FileClass.h"

using namespace std;

int main()
{
	FileClass obj;

	obj.GetMaxNameLength();
	
	string name(280,'h');
	obj.TestName(name);
	return 0;

}
