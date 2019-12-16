#include "OOP.h"

using namespace std;

void print(const LibMat &mat);
int main()
{
  

	
	//LibMat libm;

	//print(libm);
//	cout << endl << endl << endl;
//	Book book("Operating System : Three Easy Piece", "S.S.A");
//	print(book);

	AudioBook ab("yark","S.n.m","N.s");
	print(ab);	


	return 0;
}



void print(const LibMat &mat)
{

	
	cout << "in global print(): about to print mat.print" << endl;

	mat.print();
}
