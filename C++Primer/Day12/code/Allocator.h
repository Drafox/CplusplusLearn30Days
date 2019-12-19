#ifndef ALLOCATOR_H
#define ALLOCATOR_H 1

#include<memory>
#include<iostream>
#include<string>
#include<vector>

/*
 * 	some opoeration of an allocator object 
 *
 *
 *	allocator<T> a   to define an named a allocator object which can allocate memory for a type T
 *
 *	a.allocate(n)  an member function of a; to allocate an original and un-constructed memory for storing n of type T object
 *
 *	a.deallocate(p, n)  释放p指向的内存，n为allocate所分配的大小，调用deallocate之前需要先调用a.destroy。
 *
 *	a.construct(p, args)   p必须为类型T*的指针，指向一块原始内存：arg被传递给类型为T的构造函数，用来在p指向的内存中构造一个对象
 *
 *	a.destroy(p)  p为T*类型的指针，对p指向的对象执行析够函数
 * */


class uu{
	public:
	uu(std::string a){
		
	_str_uu = new std::string(a);
	}

	~uu(){
		delete _str_uu;
	}

	void show()
	{
		std::cout << *_str_uu << std:: endl;
	}


	std::string operator*()
	{
		return *_str_uu;
	}
	private:
	std::string *_str_uu;
};



template<class T >
class Allocator{

	public:
	
	void Test1()
	{
		std::allocator<std::string> aobj;
		
		auto p =  aobj.allocate(12);
		
		auto q = p;
		auto s = p;


		std::cout << q << "\t" << s << "\t" << p << std::endl;
		for(std::size_t index = 0; index < 8; ++index)
		{
			aobj.construct(q++,13,'-');
		}

		//std::cout << *(p) << std::endl;

		// allocated 12 space which can store type string object, and then, construct 8 string object, other space does not construct, we saved time.


		aobj.destroy(--q);
		
		std::cout <<"flag1:" << *q << std::endl; 
		for(std::size_t index = 0;index < 5 ; ++index)
		{
		
			aobj.construct(q++, 22,'*');
		}
			

		std::cout << q << "\t" << s << "\t" << p << std::endl;
		 q = p;
		for(std::size_t index = 0; index < 12;++index)
		{
			std::cout << *(q++) << std::endl;
		
		}

			
	
		std::cout << q << "\t" << s << "\t" << p << std::endl;

		while( s != q)
		{
			std::cout << * s << std::endl;
			aobj.destroy(s++);
		}
		std::cout << q << "\t" << s << "\t" << p << std::endl;
		aobj.deallocate(p,12);
		aobj.construct(p,10,'a');

		std::cout << q << "\t" << s << "\t" << p << std::endl;

		std:: cout << *p<< std::endl;


	}

		void Test2()
		{
		
			std::allocator<::uu> auu;
			auto p = auu.allocate(2);
			auu.construct(p,"heloo");

			p->show();

			auu.destroy(p);
			
			//p->show();
		
		}


	private:

		std::shared_ptr<T> _sptr;
		




};




#endif
