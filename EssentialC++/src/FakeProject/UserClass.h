#ifndef USERCLASS_H
#define USERCLASS_H

#include<iostream>
#include<string>
#include<vector>



typedef struct UserInformation{

 enum SEX{MALE, FEMALE, UNKNOW}; 
	unsigned int age;
	std::string email;
	std::string PhoneNumber;
} UserInformation;


class User{

	public:
	
	User(const std::string& ID) : _ID(ID) { std::cout << "User(" << _ID << ") constructor!" << std::endl; } 

	virtual ~User() { std::cout << "User Destructor!" << std::endl;}

	virtual bool SetPassWord(std::string Password)  {
		
		if(Password.size() < 6 || Password.size() > 16)
		{
			return false;
		}

		_Password = Password;
		return true;

	}
	protected:
	std::string _ID;
	std::string _Password;
	std::string _Username;
	UserInformation _Information; 

};


class Student : public User{

	public:
	
	Student(const std::string& ID) : User(ID) 
	{std::cout << "Student(" << _ID << ") constructor!" << std:: endl;}
	virtual ~Student() {std::cout << "Student Destructor!" << std::endl;}
	virtual void SetSchool(std::string school) { _school = school; }
	private:
	std::string _school;
	std::string _classroom;


};



#endif
