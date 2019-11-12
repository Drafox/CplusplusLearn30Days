### 第八天学习

---

#### 0x00 数组形参

- 三种传入形参的方法

  - 标有结束符

    在设计数组内容过程中我们可以向数组中最后一个元素下一个位置放置一个标志结束符号的元素，该元素不会在正常数据中出现，比如字符数组中可以使用`'\0'`作为结束符，但是对于`int`数组来说就不一定有数据可以作为结束符号。

    ```c++
    void print(char *name)
    {
        while(*(name))
              {
                  cout << *(name++);
              }
        cout << endl;
        
    }
    ```

  - 使用标准库函数（begin, end）

    可以使用`begin and end`向函数传递指向数组第一个元素指针和最后一个元素下一个位置的指针。

    ```c++
    const size_t GetSize(const int *beg, const int *end)
    {
        size_t size = 0;
        while(beg != end){
            size++;
        }
        
        return size;
    }
    ```

  - 传递数组大小，这也是C语言最常用的方法。

#### 数组形参

```c++
int a[10];
int (&b)[10] = a ;

void Get(int (&b)[])
{
    cout << b[0]++ << endl;
}

Get(a);
cout << a[0] << endl;
```

#### 传递多为数组

```c++
void find(int (*ptr)[10]);
```

​	ptr两边的括号必不可少，首先我们来分析，（*ptr）意味着ptr为指针，之后又有数组类型被解析为指针类型，int **。

#### 传递不定量参数

- 引入`initializer_list `模板。

  `initializer_list`:用于表示某种类型值的数组。

  这部分内容学习完模板之后再来回顾。

### return

`return 语句用于终止当前函数，返回给调用对象，不能返回数组。`

```C++
void print(const string greet)
{
    cout << greet << endl;
}

//不严谨的函数
void Condition(const int a, const int b)
{
    string greet("Hello, World!");
    if(a == b)
        return print(greet);
    a -= b;
    return Condition(a,b); 
}

```

<font color = “red”>不要返回局部指针对象以及引用类型</font>

- 返回数组指针

  由于数组不能直接被拷贝，所以无法返回数组类型，我们可以通过数组指针进行返回。

  ```C++
  typedef int aaT[10];
  using arrT = int[10];
  
  arrt *test(int (&a)[10], int (&b)[10]); 
  ```

  - 尾置返回类型

  ```c++
  auto FunPlusVsG2(int (&a)[5], int (&b)[5]) -> int (*)[5];
  ```

### 重载函数

​	声明多个函数名相同的函数，但要求其函数形参是不能一样（包括可转换类型）。

```c++
void print_m(string msg);
void print_m(string msg1, string msg2);
void print_m();
```

​	note: 顶层`const`在初始化过程中被忽略，所以如下的声明是错误的：

```c++
int add(int a, int b);
int add(const int a, const int b);
int add(const int a, int b);
int add(int a, const int b);

//error| note: ‘int add(int, int)’ previously defined here

main.cpp|203 col 5 error| redefinition of ‘int add(int, int)                         main.cpp|195 col 5 error| note: ‘int add(int, int)’ previously defined here
main.cpp|210 col 5 error| redefinition of ‘int add(int, int)
main.cpp|195 col 5 error| note: ‘int add(int, int)’ previously defined he
```

​	重载遵守作用域规则，我们在局部声明函数时，会将上层声明隐藏掉。

```c++
bool moveLeft(const int a, const int b);
bool GetString(string elem);

void Test()
{
    bool moveLeft(const int a);
    moveLeft(22);
    moveLeft(22,23); //ERROR  too many arguments to function ‘bool moveLeft(int)’   
}
```



### `inline and constexpr`

​	目前理解（后面会继续深入理解）：

​           编译器将`inline`函数展开在其调用的地方，因此该类函数通常执行的内容很少。

​	第一次尝试

```c++
#ifndef HEADER_H
#define HEADER_H

#include<iostream>
inline const int sum(const int a, const int b)
{
    
    return a+b;
    
}

inline void print()
{
    
    std::cout << "This is an inline function!" << std::endl;
}

#endif
```

```c++
//main.cpp

#included"header.h"

int main()
{
    print();
    std::cout << sum(99,98) << std::endl; 
}

//This is an inline function!
//197
```

**Advantages of inline functions **

- Spend lesser time  than normal functions 
- Can repeatedly use somewhere.
- more efficient

**constexpr**

​		隐式转换成`inline`, 且其参数以及返回值必须是字面值类型。

#### assert and NDEBUG

​           `assert(expr)`宏用于判断表达式是否为假，如果为假输出信息，如果为真则什么也不做。

```c++
//source file name :inlineTest.cpp program name: in
string words = "affirm";

assert(words.size() >8);

//output:
//in: inlineTest.cpp:15: int main(): Assertion `words.size() > 8' failed.
//Aborted (core dumped)

```

​	定义宏 `NDEBUG` ，assert不再起任何作用，实践中第一在源文件第三行，没有任何作用，只能定义在第一行，或者说定义在任何操作之前。

#### 编译器定义的局部静态变量

```c++
__func__ 函数名
__FILE__ 文件名
__LINE__ 当前行号
__TIME__ 编译时间
__DATE__ 编译日期
```

```c++
void myAssert()
{
    #ifndef NDEBUG
    
    	cerr << __FILE__ << ": In" << __func__<< ":" << __LINE__ <<endl;
    
    #endif
}
```

#### 函数指针

​	表达式：`returnType (*function_pointer_name) (parameter_list)`

​	示例：

```c++

int sum(const int a, const int b)
{
    return a+b;
}

int (*fptr)(const int a, const int b) = nullptr;
	fptr = sum; 
	fptr = &sum; //等价上一条语句

decltype(sum) *fpptr = nullptr;
decltype(sum) *fpptr = sum;
int result = fpptr(22,22);


void Test(decltype(sum) *fpprt)
{
    int ressult = fpprt(100,100);
    cout << result << endl;
}

```









