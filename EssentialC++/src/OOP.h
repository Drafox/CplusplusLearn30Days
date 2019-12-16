#ifndef OOP_H
#define OOP_H

#include<iostream>
#include<vector>
#include<string>

class LibMat{

	public:
	LibMat(){std::cout << "LibMat::LibMat() default constructor !\n";}

	virtual ~LibMat(){std::cout <<"LibMat::~LibMat() destructor!\n";}

	virtual void print() const {
	
		std::cout << "LibMat::print() -- I am a LibMat Object!\n";
	} 
};


class Book : public LibMat{

	public:
	Book(const std::string &title, const std::string &author): _title(title), _author(author) {std::cout << "Book::Book (" << _title << "," << _author << ") constructor\n";}


	virtual ~Book(){std::cout << "Book::~Book() destructor\n";}

	virtual void print() const { std::cout << "Book::print()----I am a book object \n " << "My titile is : " << _title << "\n My author is : " << _author <<  std::endl;}

const std::string& title() const { return _title;}
const std::string& author() const {return _author;}


	protected:
	std::string _title;
	std::string _author;	
};


class AudioBook : public Book{

	public:
	AudioBook(const std::string&  title, const std::string& author, const std::string& player  ):
	Book(title, author), _player(player)
	{
		std::cout << "AudioBook::AudioBook(" << _title << ", " << _author << ", " << _player << ") constructor\n ";}

	virtual ~AudioBook() {std::cout << "AudioBook::~AudioBook() destructor!\n";}

	virtual void print() const {
	
		std::cout << "I am an AudioBook object! \n " << "My title  is  " << _title << "\n My author is " << _author << "\n My player is " << _player << std::endl;



	}
	protected:
		std::string _player;


};



//MY OWN OOP TEST
//
//Base: Person Derive: Student, Teacher, Parent
//

/*
struct PersonalInformation;


class Person{
	public:
	

	private:

	std::string ID;
	std::string Password;




}


*/

#endif
