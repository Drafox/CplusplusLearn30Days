### 第三天学习笔记

----

**0x00 前言**

**0x01 第二章**

- **初始化跟赋值**
  - 首先初始化跟赋值是完全不同的操作，只是在编写源程序的过程中，使用的操作符相似之外，其实现是不同的。
  - 初始化：在创建变量时就赋予一个初始值；赋值：将原有值抹去，然后赋予一个新有的值。
  - 未初始化的变量存在着一些不确定性，在程序执行过程中，由于对象没有初始化，经常会出现与我们预料的结果想违背。
  - 如果确定声明变量会在接下来被重新赋值，则可以一定需要初始化，但是养成一个初始化的习惯是十分有必要的。

- **extern key word**

  如果程序分开来定义，但是又需要共享某个变量，可以使用extern来实现这种状况。它的作用只声明，不定义。就是告诉编译器，这是个变量，但不需要为其分配空间，然后连接器，查找相应变量的精确定义的位置，然后使他指向那个精确的位置。

  **source 1**

  ```c++
  // header.h
  extern int global_x;
  void print();
  ```

  **source 2**

  ```c++
  #include"header.h"
  
  int global_x;
  
  int main()
  {
      global_X = 100;
      print();
      
      return 0;
  }
  ```

  **source 3**

  ```c++
  //test.cpp
  #include<iostream>
  #include"header.h"
  void print()
  {
      
      	std::cout << global_x << std::endl;
     
  }
  ```

  **RESULT**

  ```shell
  $ g++ main.cpp test.cpp -o main && ./main
  100
  ```

  分析上面程序与结果：

  ​	首先我们通过头文件声明了变量`global_x`以及函数`print`，然后我们通过第二个文件定义改变量以及调用该函数，通过第三个文件定义函数。但是第三个文件并没定义变量`global_x`但是连接器并没有报错，因为main.cpp有该变量精确的位置。