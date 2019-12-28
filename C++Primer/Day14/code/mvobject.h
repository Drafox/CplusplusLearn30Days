#ifndef MVOBJECT_H
#define MVOBJECT_H 

#include<iostream>

#include<string>
#include<utility>
#include<vector>
#include<map>




template<typename T>
class MvClass{

	public:
	//five different constructor
	// default constructor
	
	
	MvClass(T *ptr, T data) : _ptr(new T(*ptr)), _data(data) {}

	//copy constructor
	
	MvClass(const MvClass& mvc)
	{
		_ptr = new T(*(mvc._ptr));
		_data = mvc._data; //copy 
	}


	//copy assignment operator
	//
	

	MvClass& operator= (const MvClass &mvc)
	{
		_ptr = new T(*(mvc._ptr));
		_data = mvc._data;
	}

	//move constructor 
	//
	MvClass(MvClass<T> &&mvc) noexcept : _ptr(mvc._ptr), _data(mvc._data){
		mvc._ptr = nullptr;
	} 


	//move assignment
	//
	MvClass<T>& operator= (MvClass<T> &&mvc)
	{
		
		_ptr = mvc._ptr;
		_data = mvc._data;  //move mvc._data to _data , the original resource of _data from mvc had moved to _data. 
	}

	void show() const 
	{
		std::cout << _ptr  << std::endl << _data << std::endl;
	}
	~MvClass() {delete _ptr;}
	private:
	
	T *_ptr;
	T _data;
	



};



#endif

