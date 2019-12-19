### 12

---

#### DYNAMIC MEMORY

#### Smart Pointer

​	动态内存的释放行为往往影响着程序的执行效率，C++中动态内存的释放是由程序设计者来进行管理而不是编译器，所以有可能会导致内存泄漏等问题的出现。C++中出现了两种类型的“特殊指针”，它的行为与常规指针类似，但是其会**自动释放所指对象**。

- ##### `shared_ptr` 类模板

  - `shared_ptr`通过构造一种对动态内存进行管理的类进行模拟指针行为。该类型智能指针可以**共享同一个对象**，每当该类型指针指向一个对象，该指针对象中的计数值加一（e.g, _count++）。

  -  每当该类型对象生命周期结束时，其会调用构造函数来进行相应释放空间操作。

     ```c++
     template<class T>
     class shared_prt{
         
         ~shared_ptr(){
             if(--_count == 0)
                 delete _ptr;
         }
     }
     ```

     如果`shared_ptr`满足以下两个条件之一即会释放所指对象：

     - 最后一个拥有对象的`shared_ptr`被销毁
     - 最后一个拥有对象的`shared_ptr`被赋予其它对象

  ##### shared_ptr 特有的操作

  ```c++
  make_shared<T> (args) // return a shared_ptr pointing to a dynamically allocated object of type T, and, use the parament of args to initialize the object
  shared_ptr<T> p(q) // copy the the object of q, and, the count of pointing to the object adds one, the type of q must be converted to  T*. 
  ```

  

  例子：

  ```c++
  void SptrTest()
  {
      std::shared_ptr<int []> sptr(new int[30]);
      sptr[0] = 202;
      SptrC(sptr);
      std::cout << sptr.use_count() << std::endl;
  }
  void SptrC(std::shared_ptr<int []> sptrE)
  {
      //Copying a duplication, the count of pointer which object was pointed adds one 
      std::cout << sptrE[0] << std::endl;
      std::cout << sptrE.use_count() << std::endl;
  }
  
  /*output:
  202
  2
  1
  */
  ```

  两种不同方式，指定`shared_ptr`只想某个对象。

  - 与`new`搭配

    `shared_ptr<int []> sptr(new int[101]);`

    `shared_ptr<string []> sptrC(new (nothrow)string[1024]);`

  - 比上述更加安全的方式`make_shared<int>();`

    `shared_ptr<int> sppr = make_shared<int>(22);`

    `make_shared<T>函数并不是shared_ptr的成员函数，而是公共函数，其声明在memory头文件中。`

  

  ----

  ［confused part］

  - `shared_ptr<int> p(new int(2)); 与shared_ptr<int> sppr = make_shared<int>(2);有什么不同`

    前者首先需要执行`new int(2)`分配空间并初始化对象，然后再继续进行堆分配管理对象，进行两次堆分配。

    而`make_shared`则是只进行一次堆分配。

    

- ##### `unique_ptr`类模板

  `unique_ptr`“独占”对象，不可被复制。即，当其被销毁时，其指对象也会被释放掉。

  ```c++
  unique_ptr<T> p;
  p.release();  
  p.reset(q.release());
  ```

  `make_unique<T>`**c++14**  可以分配数组，而`make_shared` 不可以。

  ```c++
  std::unique_ptr<int []> uptr = std::make_unique<int[]>(22); //allocate an array containted 22 element;
  ```

  `make_unique<T>`重载

  ``` c++
  template<class T, class Args...>
  unique_ptr<T> make_unique(Args&&...arg);
  
  template<class T>
  unique_ptr<T> make_unique(std::size_t size) //T is only array type
  
  template<class T, class Args...>
  unique_ptr<T> make_unique(Args&&...arg) = delete;
  ```

  

- ##### unique_ptr 与 shared_ptr 共有的操作

  ```c++
  shared_ptr<T> sptr;
  unique_ptr<T> uptr;
  //both can point the object of type T, meanwhile, both are null smart pointer.
  sptr or uptr  // can use in condition, if a sptr pointer points an objejct, it will be true
  *sptr or *uptr  // dereference sptr or uptr to get the object to which it points
  sptr->member()  or uptr->member() //equal (*sptr).member()
  sptr.get() // return the address of the object which it points, if the object is released, the value of the sptr.get() function returning will be invalid and generated a unknown error. 
  sptr.swap(sqtr) // swap the pointer sptr and sqtr
  ```

  

- ##### `weak_ptr`类模板

  只想`shared_ptr`所指的对象，但不会增加该对象计数值。

  **Operation**

  ```c++
  //constructor
  
  constexpr weak_ptr() noexcept;
  
  template<class T>
  weak_ptr (const shared_ptr<T>& q) noexcept;
  
  template<class T>
  weak_ptr(const weak_ptr& q ) noexcept;
  
  template<class T>
  weak_ptr(const weak_ptr<T> &q) noexcept;
  
  template<class T>
  weak_ptr(const weak_ptr&& q) noexcept;
  
  template<class T>
  weak_ptr(const weak_ptr<T>&& q) noexcept;
  
  
  //destrctor
  
  ~weak_ptr();
  
  
  weak_ptr<T> p; //null pointer
  weak_ptr<T> p(sp); // point an object which shared_ptr sp pointed
  
  p = q; // q is weak_ptr or shared_ptr
  
  p.reset() //make null
      
  p.lock(); //if expired return true, it returns a null pointer, otherwise, return a shared_ptr to the object to which p ponits
  p.expired(); //return true if p.use_count is return zero, false otherwise
  p.use_count(); //the count of shared_ptr pointed 
  ```

#### allocator

​	使用`new/delete`operator 进行动态分配时，会进行两部分内容：

 	［1］ 分配空间

​	［2］ 对对象进行初始化

​	有时，我们不需要对部分空间进行初始化，使用上述操作反而效率很低。而，`allocator class`帮助我们把内存分配，以及对象初始化分开，这样程序会更加高效。（memory 头文件中定义）

```c++
//auto p = allocator::allocate(n) 
allocator<T> allocType;  //define an alloctor object, it can allocate memory for type T
allocType.allocate((size_t)n);  //allocate memory but not initialize
allocType.construct(p, args); //given allocted object, to construct the object, now, equal to new an object  
allocType.destroy(p) //execute the desctruct function of an object p
allocType.deallocate(p,n);  //n is must equal to allocte function allocated size
```

**Sample**

```c++
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
        std::cout << **p << std::endl;  // equal to p->show()
        std::cout << typeid(*p).name() << std::endl; //p2uu
     	std::cout << typeid(**p).name() << std::endl; //xxxxbasic_stringxxxxxxxx
    }
    
    
    
};




#endif
```





