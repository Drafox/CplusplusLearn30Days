###第七天学习笔记

---

#### 表达式

- **terms**

  presedence  : 优先级

  associativity  : 结合律

  promoted   	: 提升

  overload operator : 重载运算符。 通过重新定义一个内置操作符号的功能的符号称为重载运算符。

  C++表达式有： `rvalue:are-value` and `lvalue:ell-value` 

#### 位运算

​	位运算过程中会把“小整型”的值提升，比如：

```c++
unsigned char a = 0xf; // 8bits
unsigned char b = 0xa; // 8bits

std::cout << std::hex << ~a << std::endl; // fffffff0  32 bits
```

#### switch

分析代码

```c++
int digit =0;
unsigned evenCnt = 0, oddCnt = 0;
cin >> digit;                
digit %= 10;
switch(digit)
{
        
    case (1,3,5,7,9):
        ++oddCnt;
        break;
    case (0,2,4,6,8):
        ++evenCnt;
        break;    
}
cout << oddCnt << endl << evenCnt << endl;
```

```shell
input : 22
output:	0 0
input : 23
output: 0 0
input : 28
output: 0 1
input : 29
output: 1 0
```

由于`case`标签必须是整型常量表达式， 所以通过逗号运算符运算结果位9 or 8。

#### 异常处理

​	当程序运行到某个程序段时，程序发生异常中断，可能会崩溃，导致后面程序无法正常执行，在这个过程中，我们可以对于可能会出现异常的程序段进行异常处理。

首先应该尝试（try）执行某段程序，如果得到了可能会引发错误的结果，抛出异常，然后进行捕捉异常，之后对异常进行处理。

##### throw

​	抛出异常，用户设定异常类型，等待异常处理程序进行处理。

**try**

​	执行用户想要执行的代码

**catch**

​	捕捉抛出的异常，然后进行处理。

```c++
	try {
		if (a / 0)
			throw runtime_error("error");
	}
	catch (runtime_error err)
	{
		cout << " zero cannot be divided by other number" << endl;
	}
```

这里程序不会执行我们抛出异常的程序，因为程序执行if语句时，已经由OS抛出异常。

**改进：**

```c++
double a =0 ,b = 0;
cin >> a >> b;
try{
    if(b == 0)
        throw range_error("error");
}
catch(range_error err)
{
    cout << "Please input divided number agagin" << endl;
    cin >> b;
}

cout << a/b << endl;
```

由于块内定义的变量，使局部变量，所以在try中定义的变量无法在其外部使用。

​	比如在之后，编写一个爬虫项目时，访问某个网站失效，有可能导致系统异常，所以在这一方面我们可以自定这种异常。

**常识学习小插曲**

​	鲁棒是Robust的音译，也就是健壮和强壮的意思。它也是在异常和危险情况下系统生存的能力。比如说，计算机[软件](https://baike.baidu.com/item/%E8%BD%AF%E4%BB%B6)在输入错误、磁盘故障、网络过载或有意攻击情况下，能否不死机、不崩溃，就是该软件的鲁棒性。

### 后面的内容要十分仔细的学习了

#### 函数

- 函数的形参初始化机理与实参初始化机理一样

```c++
void print(int a, int b);
void print_s(char *a);
void print_ss(string a);
void print_a(int a[]);
void print_v(vector<int> a);
void modify_p(int &p);

int main{
    
    string  name= "ss";
    int a = 98;
    print(2,2);
    print_s("name");
    print_ss(name);
    modify_p(a);  
}
```

- **const 形参和实参**

  初始化时，顶层`const`被忽略。也就是说，可以被正常赋值。

  ```c++
  const unsigned int abss(const int a)
  {
      if(a < 0)
          return -a;
      else
          return a;
  }
  
  main:
  b = abss(-99); // return 99
  ```

