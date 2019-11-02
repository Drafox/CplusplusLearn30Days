### C++Primer课后习题练习（1）

---

**0x00 系统如何处理程序返回错误的标识**

```c++
#include<iostream>

using namespace std;
int main()
{
    cout << "Hello, World!" << endl;
    return -1;  
}

/*
	output: Hello, World!
	在Linux（4.16）下正常输出，并且没有什么异常。
	查看环境变量记录上次程序所返回的值
	$ echi $?
	255
*/
```

首先需要了解的是return 到底return 到哪？

​	其实return的作用是，返回一个整型给父进程（在main函数中），其余如果函数return 则代表着函数返回值，其值类型与函数定义有关。那么我们接下来探讨的是，我们程序传递到父进程的值为什么会与传递的值不符。

​	我们看到这个值，第一反映，8位数。为什么是8位数？ 有符号转无符号？

执行`echo $？`为什么输出结果是255而不是-1，如果是因为整型类型问题，那也会是$2^{64}-1$ 。

探索之前了解一个命令：strace

 trace system calls and signals  追踪系统调用和信号

系统调用：用户程序需要通过内核执行相关程序段，比如I/O设备，进程管理，文件管理，内存管理等。

用法：

`man strace` 最简单的用法：strace  ./main(可执行程序)

那么我们看看上面的程序是如何调用那些系统调用（System call）

```shell
$strace ./main 
#内容好多 关键部分
exit_group(-2)                          = ?
+++ exited with 254 +++
```

我们看到上面的程序调用了exit_group();系统调用函数，其作用与exit相似，它会结束该进程所有线程。

​	wait()语句等待进程改变状态，比如子进程终止，那么它将从运行态转变成终止态，然后撤销资源，撤销PCB（程序控制块）。那么将wait语句传递的参数status仅仅保留低八位作为程序终止状态码。而且是无符号类型。（此处依旧有些不太清楚，学玩基础课程之后，Linux内核部分在详细了解）。

​	总结：程序返回值由系统调用传递给父进程，父进程通过返回值进行处理。目前，在一般的OS下（windows也是如此），程序返回错误码并不会有明显的错误。但是，OS会记录程序返回的那个值。

**对比for循环和while循环**

​	在对于循环次数已知的情况下，for循环的形式显然更加整洁，更好的理解。

​	在对于循环次数未知的情况下，但对特定情况终止循环的情况下，while循环更加友善。

**读取数量不定的输入数据**

```c++
//省略
///......
int num, sum = 0;
while(std::cin >> num )
    sum += num;
std::cout << sum << endl;
```

​		我如果执行上面的程序你会发现，结束不了，其实对于不同的操作系统，传递文件结束符不同，在Linux下，你可以 按下回车，然后`ctrl + d`, 完美解决。但是如果你不想这样做，其实还有很多种方式，比如：

```c++
int num, sum = 0;
char ch;
while(std :: cin >> num)
    sum += num;
while(ch = getchar() != '\n');

/------其它操作---------
```

​	这里就是你输入完你需要的数据后，按下非数字键（空格除外），即可。

**标准输入输出**

​	首先我们打开iostream头文件看看里面的声明。

​	extern istream cin;		/// Linked to standard input
 	extern ostream cout;		/// Linked to standard output
	extern ostream cerr;		/// Linked to standard error (unbuffered)
	extern ostream clog;		/// Linked to standard error (buffered)

```c++
std::cout <<  "This will print on the screen" << endl;
std::ceer << "This will print on the screen, too" << endl;

//but 若执行 
//$ ./main >> "log.txt"
```

以下是两种不同执行方式的结果

```shell
(base) xiandonghua@HappyDay:~/C++Learn30Days/C++PrimerPractices/Day1$ g++ main.cpp -o main &&./main
Hello, World!
This will print on the screen
This will print on the screen, too
(base) xiandonghua@HappyDay:~/C++Learn30Days/C++PrimerPractices/Day1$ g++ main.cpp -o main &&./main >> "log.txt"
This will print on the screen, too
```

我们紧接着打开`log.txt`

```shell
$cat log.txt
Hello, World!
This will print on the screen
```

我们会发现如果使用重定向的话，标准输出不会再被显示到屏幕上，但标准输出依旧会打印到屏幕上。

标准输出则是对键盘的字符流获取。

​	从上面的声明中我们可以看到 `clog` 是有缓冲区的，也就是说如果不显式刷新缓冲区，它是不会立刻打印到屏幕。





 



 

