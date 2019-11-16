#include<fstream>
#include<iostream>
#include<string>
#include<limits.h>

using namespace std;
class FileClass{
    public:
  bool MyOpenF(string pathname,string filename,ios_base::openmode flag = ios_base::app) const {
     	
        //const char *name = (pathname + "/" + filename).c_str();
	string temp = pathname + "/" + filename;
	const char * name = temp.c_str();
	cout << name << endl;
        ofstream outfile(name,flag);
      	if(!outfile)
        {
            cerr << "Error: failed to open file" << endl;
	    return false;
        }
     
	cout << "opened!" << endl;

	return true;
    }
    private:
    string pathName;
    string fileName;
};

int main()
{
    string name1(254,'h');
    string name2(13,'h');
    FileClass obj;
    if(NAME_MAX < 15)
    {
        obj.MyOpenF(".", name2);
    }
    else
    {
        obj.MyOpenF(".",name1);
    }
    
}
