#include<iostream>

#include"header.h"


using namespace std;

int main()
{

	Person object1;
	AccountManager object2;

	//object1.StatusFlag = Status::teacher;
	
	object2.UserID = "03163071";



	object1.move_x(22);
	object1.move_y(33);

	object1.printPositon();


	object1.move_x(100).move_y(200);

	object1.printPositon();

	object1.move_x(101).move_y(103).printPositon();

	return 0;
}
