### 第五天学习笔记

---

#### const reference

​	由于在传递参数的过程中，会重新分配内存空间给局部变量，这样会额外消耗系统资源，所以使用引用则会减少资源不必要浪费，提高效率。由于对于不可变变量，则通过const引用会更好。

#### pointer and  const

​	指向常量的指针不能通过改变量改变其所指向对象的值，但是可以通过其它方式改变该对象的值。

```c++
int var = 99;
int *ptr = &var;
const int *cptr = &ptr;
```

​	常量指针，很明显，其意思是该指针不可变，其指向的内容在初始化之后是不可变的。

```c++
int var2 = 100;
int *const ptrc = &var;

ptrc = &var2; //error:assignment of read-only variable ‘ptrc’ 
```

​	但是其可以改变其指向对象的内容

#### top-level const and low-level const

- **top-level const**

  表示指针本身是个常量

- **low-level const**

  表示指向对象是常量

```c++
int i = 0;
const int var = 0; //top-level const
int *const cpt = &i;//top-level const 其本身是常量
const int *ptr = &var; //low-level const 只想内容为不可变。
```

赋值过程中可能出现的问题：

- 对于`top-level const`来说无妨，因为其本身就是常量，无论赋值给任何对象都是可以的。但是由于初始化完成之后，`top-level const`变量是不允许被赋值的。
- 但对于`low-level const`来说，其指向的内容是常量，所以如过将一个非常量赋值给它，则会产生错误。

#### constexpr

**full-name**:const expression

其右值是常量表达式，则其每个操作符左右都应该常量或者常量表达式。

```c++
const int max = 100;
const int min = 9;
constexpr avg = (max + min)/2;
```

#### typedef and using

​	两种不同的方式给类型去别名。

```C++
typedef const int *const  Avg;
Avg minus;// const int *const minus
using Avga = const int * const ;

Avg pct = &max;
Avga ppct = &min;
cout << *pct << endl << ppct << endl;//100  9
```

#### auto and decltype

​	如果想通过某中变量的类型判定一个新变量的类型可以使用`auto` `decltype`

```c++
int var = 0;
auto m = var; // int m;
const int var1 = 99;
auto n = var1;//
const int *const var2 = &var1;
const int var3 = 100;
var2 = &var3; //correct , ignore the top-level const 
```

```c++
int num = 989;
decltype(num) mun ; // int mun;

decltype((num)) mun = num ; //int &mun, 所以必须初始化
int *p = &num;
decltype(*p) q = num; //int &., 必须初始化
```

### 向着远方前进-----String and Vector

- **初始化**

  C++中很多对象都是通过类定义，这些类中定义了一些对于该对象所允许的操作。没一个类都会定义一个或多个初始化方式，所以遇见某个对象时，根据其类的定义有多种不同的初始化方式。

  ```C++
  string greet1 ; // blank string object
  string greet2 = "Hello, World!";
  string greet3(greet2);
  string greet4 = greet2;
  string greet5(27,'-');
  ```

- **输入输出String object**

   ```c++
  cin >> greet1;
  cout << greet1 << endl;;
  
  getline(cin,greet1);//丢弃掉换行符
  greet1 += "\n";
  cout << greet1; //由于没有加上endl，则不会主动刷新输出缓冲区
   ```

- **string类的成员函数**

  - empty 判断字符串是否为空

    ```c++
    string line = "Hello, World!";
    string nonline;
    
    if(!line.empty())
        if(nonline.empty())
            return true;
    ```

  - size 返回该字符串对象长度，即字符个数

    - 判定该对想是否会自动加'\0'字符

      ```c++
      string test;
      cin >> test;
      cout << test.size() <<endl;
      //shell
      $input : zhang   //input length is 5
      //ouput : 5
      ```

      ​	首先C++中的字符串与C中的字符串一定的区别，最大的区别就是不会在字符串后面加上'\0'标识字符串结尾。

      ​	我觉得比较舒服的一个解释有：<https://www.prismnet.com/~mcmahon/Notes/strings.html>

      - size 返回的类型

        `string::size_type`类型：它是String类中定义的类型，它与 `unsigned`类型一样，但是具体的实现细节目前（本人）不太清楚。

        ```c++
        auto len = line.size(); //的到size返回的字符串长度
        or 
        decltype(line.size()) len;
        ```

        ​	由于`size`返回的是一个无符号类型，所以 它与`int`类型进行比较以及运算过程中，可能出现不必要的麻烦，所以在编程 过程中尽可能声明一个`string::size_type`类型的变量与其做比较以及运算。

        