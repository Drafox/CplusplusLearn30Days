#ifndef HEADER_H
#define HEADER_H

enum class Status{student, parent, teacher};

class Positon{
	public:
	Positon(int x, int y) : x(x), y(y){}
	int x;
	int y;
};


class Person{
	
	Status StatusFlag = Status::student;

	public:
	Status GetStatus() const {return StatusFlag;}
	
	Person& move_x(int x);
	Person& move_y(int y);	

	void printPositon() const{
		std::cout << "x: "<<position.x << "\ty: "<< position.y << std::endl; 
	};
	private:
	Positon position{0,0};


	
};


struct AccountManager{

	std::string UserID = "0000000" ;

	public:

	std::string GetUserID() const{return UserID;}


};


Person& Person::move_x(int x){
	position.x = x;
	return *this;

}


Person& Person::move_y(int y)
{
	position.y = y;

	return *this;
}



#endif
