### 第四天学习笔记

---

#### 引用

​	引用并不是对象，只是一个已经存在的对象的另一个名字，所以不能引用一个引用变量。

​	引用类型必须与绑定类型严格匹配。

```c++
int var = 0;
double &value = var ; //Can be generated an error by compiler
int &TrueValue = var; //correct!
int &reference = 3.1415926; //can not refer to a constant value(object);
```

​	思考:可以更改一个引用类型指引的对象吗?

```c++
int var = 33;
int &refer = var;
int var2 = 32;
std::cout << refer << endl; //output: 33
refer = var2 ;
std::cout << refer << endl; //output:32
std::cout << var << endl; //output:32
```

​	分析上述程序段，首先定义一个引用变量`refer`，然后将其与`var`变量绑定（初始化），之后打印`refer`的值，其至等同于`var`，但是当`refer = var2`该语句并不是表示将`var2`变量帮定到`refer`上，而是将值赋值给`refer`绑定的对象。所以后面两条输出语句的结果与`var2`相同。

#### 空指针

​	不指向任何对象的指针为空指针，有时候我们需要用指针变量指向某个对象时，但是由于没有达到某种特定的条件以至于，该指针并未指向该对象，但是我们没有检查该指针类型，导致程序错误。所以首先我们对指针对象进行操作时，先检查其是否是有效对象。

​	定义一个指针变量时，将其初始化成空指针。

```c++
//#include<cstdlib>

int *ptr = NULL;

int *jtr = nullptr;
```

`nullptr`是一个特殊类型的字面值，它可以被转换成任意其它指针类型。

#### 指针与引用

​	首先，引用不是一个对象，而指针是，所以不能定义一个指向引用的指针，而可以定义一个绑定指针的引用类型。

```c++
int var = 99;
int *ptr = &var;
int *&r = ptr;
```

​	对第三行语句进行分析，首先一元操作符位置：（＆r）代表引用类型变量，`*var`则代表指针变量`var`。那么`*(&r)`则代表r是一个引用类型，然后是绑定对象为`int`型指针。从右往左进行分析，离变量名最近的则为其根本属性。

```c++
const int *(&(*r); //首先这个定义就是错误的，*r 代表指针变量，指向绑定int型指针变量的引用类型。由于引用并不是一个对象，所以这条语句无法执行。
//程序运行结果
cannot declare pointer to ‘const int*&’

int &(*r);
cannot declare pointer to ‘int&’

```

​	综上：引用对象一定要初始化，而且后面不会被修改绑定对象（即：既然结婚了就不会再离婚了，除了GG）

#### const 限定符

​	针对定义对象的操作，不能对其进行修改。

​	首先`const`对象必须要初始化。其次，其仅在文件内部有效。

​	文件内部有效？

**main.cpp**

```c++

#include "header.h"

int var = 89;

int main()
{
    std::cout << var << std::endl;
    print();
    return 0;
}

```

**test.cpp**

```c++
#include"header.h"

int var = 999;
void print()
{
    std::cout << var << std::endl;
}
```

**header.h**

```c++
#include<iostream>

void print();
```

**Reasult**

```shell
$g++ main.cpp test.cpp -o main && ./main
/tmp/ccJXcIVk.o:(.data+0x0): multiple definition of `var'
/tmp/ccrehAW6.o:(.data+0x0): first defined here
collect2: error: ld returned 1 exit status
```

分析：

- 由于main中定义全局变量var之后，test.cpp也定义了全局变量var所以变量冲突。

```c++
//main.cpp
const int var = 99;
//test.cpp
const int var =999;
```

**Reasult**

```shell
$g++ main.cpp test.cpp -o main && ./main
89
999
```

分析：

- 首先编译器在编译过程中，把遇到该（const ）变量时，将其替换成对应的值，当多个文件出现同名const变量时，其实等同于在不同文件分别定义了独立的变量。
- 如果想在多个文件中共享一个const类型变量，则需要在其前加入`extern`。
  - 首先要清楚：`extern const int var = 99;`其实就是定义而不是声明，所以在其它文件中可以`extern const int var;`那么多个文件就可以共享一个`const`变量。

```c++
//main.cpp
extern const int var = 99;
//test.cpp
extern const int var ;
```

```shell
$g++ main.cpp test.cpp -o main && ./main
99
99
```

#### const 的引用

`const int var;`首先其是一个对象，那么我们可以通过一个引用类型变量与其绑定。

`const int &refer = var; `

​	其实如何辨别一个变量到底是什么类型，则可以通过就近原则，距离其最近的操作符决定其根本类型，然后其它都是它指向的对象类型。

​	例如：

`const int var `  首先const 是修饰符，其修饰int var，所以其是”常量变量“。

`const int &var;`首先其是引用变量，其绑定对象为：`const int`

**初始化对const的引用**

```c++
int var = 22;
const int &rvar = var;
const int &rvar1 = 42; 
const int &rvar2 = r1*2;
```

*note:  如果定义变量`const int ID` 编译器会报错：uninitialized const ‘ID’* 

正如前面所述：定义const类型必须要初始化。

如果`rvar = 2` 编译器：assignment of read-only reference ‘r1’；

**Addition: linux tips**

删除某个多余内核

`sudo update-grub`  更新grub, 生成 grub2 config file.

`sudo apt-get purge ` purge与remove相同，删除并清理软件包，所有配置文件也被删除了

`sudo dpkg --get-selections |grep linux` 获取文件包列表 

​		