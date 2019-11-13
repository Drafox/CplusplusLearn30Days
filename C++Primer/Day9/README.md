### 第九天学习笔记

---

### 类

#### this 

​	成员函数通过额外的隐式参数this访问调用它的对象，一个类可以有多个实体，那么如何确定我调用的是该实体？即通过this来确定，指向特定的类实体。

​	this 的值为该对象的地址。

#### const 成员函数

```c++
class Person{
  public:
    void print_m(const string msg) const{;};
    std::string Id() const{return this->Idnumber;} 
   private:
    std::string Idnumber; 
    bool CreateId() const {return true;}; 
};
```

`std::string Id() const {return Idnumber;};`语句表示，限定`this` 为指向常量的指针，即该函数为常量成员函数，所以其不能改变该对象的内容。

示例：

```c++
class Fruit{
    private:
    std::string species;
    unsigned double price;
    public:
    void ModifyPrice() const{ price++;} // error
}
```

**note:常量对象，以及常量对象的引用和指针都只能调用常量成员函数函数。**

#### 构造函数

​	构造函数的作用：初始化类对象的数据成员。

**构造函数没有返回类型**

​	如果用户没有定义构造函数，则编译器会自动隐式的插入一个默认构造函数，称其为合成的默认构造函数。

该合成的默认构造函数的特点是：如果用户定义了构造函数，则编译器不会插入该函数。

​	一个类可以有多个构造函数，类似于函数重载。

- 如果用户即想要自己定义的构造函数，又想拥有默认的构造函数，即可以使用`= default`。进行定义，该方法可以定义在类内部，也可以定义在内外部，定义在类内部会被隐式转换成内联函数。

```c++
struct Person{
    Person() = default;
    Person(std::string s):name(s){}//[1]
    std::string name;
}
```

[1]: 中冒号后面为初始化参数列表，如果没有出现在构造函数初始化列表中的数据成员，由默认构造函数的方式初始化。

- 在类的外部定义构造函数

  在类的外部定义构造函数需要指明该构造函数是哪一个类的成员。

  ```c++
  Person::Person(std::string s):name(s){}
  ```

#### 访问控制符

**public:**	定义在其后的数据成员，在整个程序的都可以被访问。

**private:**  定义在其后的数据成员，只能被其类内部访问。封装了很多实现细节，比如某些数据不能在运行过程中被修改，但是用户无意修改了，导致整个程序崩溃都是有可能的。

- `struct and class`区别

  - `struct`在第一个访问控制符之前定义的数据成员为`public`
  - `class`在第一个访问控制符之前定义的数据成员为`private`

- 示例

  ```c++
   #ifndef HEADER_H
   #define HEADER_H
    
    enum class Status{student, parent, teacher};
    
    class Person{
    
  		  Status StatusFlag = Status::student;
    
            public:
            Status GetStatus() const {return StatusFlag;}
      
    };
  
    struct AccountManager{
    
            std::string UserID = "0000000" ;
    
            public:
    
            std::string GetUserID() const{return UserID;}
    
    
    };
  
  ```

  ```c++
   		Person object1;
          AccountManager object2;
    
          object1.StatusFlag = Status::teacher;
  
  ```

  ​	程序会报错：‘Status Person::StatusFlag’ is private within this context            

  #### 可变数据成员

  ​	如果一个const成员函数想修改某个变量，可以定义成mutable类型。

  ```c++
  class Person{
      public:
      	mutable size_t size;b
      	void IncreateSize() const {return ++size} // 隐式inline
      
  };
  ```

  #### 类数据成员的初始值

  ​	如果一个类只是某种数据的元素类型，那么如何初始化呢？

  ```c++
  vector<Person> People{Person(/*initializer list*/)};
  vector<Person> People = Person(/*initializer list*/);
  ```

  **只有以上两种初始化方式**

    #### return *this

  ​	首先理解为什么要用到`return *this`:

  ​	如果当我们执行完类成员函数时，我们可能会再执行一条其它的语句。但是如果我们对于该对象用一条语句（紧接着执行），我们首先需要的就是对调用成员函数的返回值为该对象本身（左值），这样才能通过这个返回对象再次调用其它成员对象。

  ```c++
  class Position{
      public:
      Position(int x, int y): x(x), y(y){}
      int x ; int y;};
  class Person{
      public:
      Person& move_x(int x);
      Person& move_y(int y);
      void printPosition() const {
          std::cout << "x: " << position.x << "\ty: " << position.y << std::endl; 
      }
      
      private:
      	Position position{0,0};
      
  };
  
  Person& Person::move_x(int x)
  {
      position.x = x;
      return *this;
  }
  
  Person& Person::move_y(int y)
  {
      position.y = y;
      return *this;
  }
  
  
  ```

  ```c++
  //main.cpp
  
  Person object;
  object.move_x(10);
  object.move_y(10);
  object.printPosition();
  
  //x: 10 	y:10
  
  object.move_x(100).move_y(100);
  object.printPosition();
  //x: 100	y: 100
  ```

  3333