#ifndef ALLOCATOR_H
#define ALLOCATOR_H 1

#include<iostream>
#include<string>
#include<memory>
#include<typeinfo>
class uu{
  public:
    constexpr uu() noexcept;
    explicit uu(std::string& a)
    {
        	_str_uu = new std::string(a);
    }
    
    ~uu(){ delete _str_uu;}
    
    void show()
    {
        std::cout << *_str_uu << std::endl;
    }
    
    std::string operator*()
    {
        return *_str_uu;
    }
  private:
  	std::string *_str_uu;  
    
};


class AllocatorTest{
    public:
    void Test()
    {
        std::string ultimate = "ByteDance";
        std::allocator<::uu> uua;
        auto p = uua.allocate(10);
  		uua.construct(p,ultimate);
        p->show(); //ByteDance;
        std::cout << typeid(**p).name() << std::endl; //error
	std::cout << **p << std::endl;
    }
    
    
    
};




#endif
