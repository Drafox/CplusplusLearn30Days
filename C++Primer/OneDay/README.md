### 						第一天学习

#### C++基本语法以及语言特性

----

**0x00 前言**

​	C++ 程序设计语言属于高级程序语言，与其同属于高级语言的有C，JAVA，Python，PHP，Javascript，Golang。低级语言：汇编语言。再往底层看待就属机器语言了，顾名思义其是机器可识别的语言。其实汇编语言可以认为其是方便程序员记住以及操作的机器语言助记符。而C++等高级语言则是对于底层语言的抽象。

​	从另一个角度看待C++，其归属静态编译程序语言。与之相反的有动态编译程序设计语言（JAVA），还有其它解释型语言，也可以称其写的程序为脚本，换言之，可以称其为，脚本语言。比如现在比较热门的python，无论是在哪个领域都看可以用到的语言，也是较为“简单”的语言。在黑客的世界里，python真的就像是屠龙宝刀一样的存在。

​	那么何为编译，通俗的将就是将我们书写的程序（文本存在）源代码，翻译成机器可以识别的指令。在Linux下十分著名的编译程序，gcc/g++，以及 Clang，都是编译软件，它是属于系统软件之上的软件。

​	我们在计算机上安装编译软件，然后通过其软件特有的运行方式，把我们的源文件，编译成机器可以识别的二进制文件。在不同的OS之上，其可运行软件有着不一样的结构。但是对于机器可以识别的指令大多都是根据CPU的指令集所翻译的。

```shell
#比如在windows 下的可执行文件是以后缀所区分
main.exe
后缀的目的主要是用来让操作系统知道使用什么样的软件去执行这个文件。
比如 .txt文件，用来表示文本文件，OS 通过默认打开txt文件的软件打开此文件
	.com, .pdf, .doc ... 都是根据其默认程序打开该文件

但是每一个可执行文件的头信息是os可以识别，也就是说OS或者说某个特定的软件规定其可以识别的软件所必须的头部信息。
比如把Windows下的.exe文件放到Linux 下 是不可被运行，尽管在相同的CPU下，而且其内部的指令没有涉及对应的os所特有的程序段，还是不可以执行的，因为其头部信息不可被识别。

#在Linux 下，OS是通过其属性来鉴别目标文件是不是可执行程序，比如 执行
ls -l #命令查看部分信息。
```

**0x01 Gcc and G++**

​	gcc 全称：the GNU Compiler Collection。

*The GNU Compiler Collection includes front ends for [C](https://gcc.gnu.org/c99status.html), [C++](https://gcc.gnu.org/projects/cxx-status.html), Objective-C, [Fortran](https://gcc.gnu.org/fortran/), Ada, Go, and D, as well as libraries for these languages (libstdc++,...). GCC was originally written as the compiler for the [GNU operating system](http://www.gnu.org/gnu/thegnuproject.html). The GNU system was developed to be 100% free software, free in the sense that it [respects the user's freedom](http://www.gnu.org/philosophy/free-sw.html).*

*g++ command is a GNU c++ compiler invocation command, which is used for preprocessing, compilation, assembly and linking of source code to generate an executable file. The different “options” of g++ command allow us to stop this process at the intermediate stage.*

通过上面我们可以了解到gcc是GUN编译器的集合，而g++ 则是用来编译c++程序。

​	其实在使用这个软件的过程中，我们可以分开进行处理，编译，汇编，以及链接这四个步骤。其实这也是我为什么喜欢Linux的原因，其可以看到一些一体化程序的运行过程。

- 预处理

  其作用就是我们在源文件开始喜欢定义一些宏，还有调用一些库函数头文件，该过程将宏替换，和把库函数中API，复制到我们的源文件中，以及我们自己定义的头文件，还有执行一些预处理指令。

- 编译

  经过前一个阶段的处理，紧接着对于中间文件（处理过程中会产生新的中间文件obeject.i），首先进行语法检验，通过语法检验之后进行编译成汇编文件。

- 汇编

  经过前两个步骤之后，把中间文件object.s编译成二进制文件object.o文件。

- 链接

  对于多个文件中含有不同的功能，其有不同的.o文件，链接器将这些所需要的.o文件链接成为最终二进制文件。

之后的练习中，均使用g++编译器

```shell
g++ main.cpp -o  main   	#指定输出文件名
g++ main.cpp -E -o main.i 	#生成预处理之后的文件
g++ main.cpp -S -o main.s 	#只编译
g++ main.cpp -c -o main.o 	#生成二进制文件，但不链接

#还可以如下
g++ main.cpp -E main.i && g++ main.i -S main.s && g++ main.i -c main.o && g++ main.o #生成a.out

最常用的是
g++ main.cpp -o main && ./main #编译并且执行

```

详细实例：

```c++
//main.cpp
 #include<iostream>
   
using namespace std;       
int main(int argc, char **argv)
   {
           cout<<"Hello, World!"<<endl;
           return 0;          
   }                     
```



```shell
g++ main.cpp -E  main.i && head main.i
#部分内容显示
# 1 "main.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main.cpp"
# 1 "/usr/include/c++/7/iostream" 1 3
# 36 "/usr/include/c++/7/iostream" 3
       
# 37 "/usr/include/c++/7/iostream" 3
tail main.i
# 3 "main.cpp"
using namespace std;


int main(int argc, char **argv)
{
 cout<<"Hello, World!"<<endl;
 return 0;
}

g++ main.i -S -o main.s && head main.s &&tail main.s
###output
	.file	"main.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
.LC0:
	ret
	.cfi_endproc
.LFE1983:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
	
	至于g++ -c 命令产生的文件是二进制文件，打开后若用文本显示会是乱码此处不在显示

```

​	以上内容只是编译器g++最基础的命令，很多参数都可以通过g++ --help可查看。之后还需要用到的是g++  xxxxx -std=xxx 选择C++标准。

还有makefile，以及gdb的练习放到基础书籍学习完之后在去学习。

**0x02 正式启航**

- C++的基础学习

  输出运算符`<<`以及输入运算符`>>`

  ```c++
  int variable ;
  cin >> variable; //可以认为将cin输入流存储的内容流向>>variable
  cout << variable << endl; //与输入相反，将变量的内容流向<<输出流
  ```

  这里必须要明确一点：

  ​	运算符的左侧必须是输入输出流对象，并且输入输出符左侧必须是与其对应的流。换言之，不能把流出的目的地换成流入的目的地。

  **comment: endl  (end line) ** 其作用结束当前行，将光标下移到下一行的开始，并且刷新缓冲区。缓冲区机制：设置缓冲区大小，当缓冲区满时或者遇到换行符刷新缓冲区。

  ​	Extend :  I/O buffer , 用于良好的输入输出。如果不设置一个缓冲区的话，用户输入输出直接操作与程序。体验不是很理想，所以当用户想要删除或者修改时，并不经过程序，而是修改的是缓冲区内的内容。 

  - **I/O库基础**

    C++ 包含了两种I/O库，一种是基于流的库，另一种是C风格的I/O函数集合。

  **Stream-base I/O**

  这个库主要是围绕抽象I/O设备来实现的，可以使用相同的代码实现对内存，文件，以及自定义适配器设备的输入输出。

  这里所定义的很多类都是基于模块化的。

  ​	由于这里涉及到了很多类的继承，以及模块部分的内容。所以绝大多数内容，在以后的学习过程中深入研究，在这里只是片面的理解一部分内容。

  - - **设置输出字符格式**

      **fmtflags 类型的常量有：**

    | constan         | Explanation                                                  |
    | --------------- | ------------------------------------------------------------ |
    | **dec**         | use decimal base for integer I/O: see [std::dec](https://en.cppreference.com/w/cpp/io/manip/hex) |
    | **oct**         | use octal base for integer I/O: see [std::oct](https://en.cppreference.com/w/cpp/io/manip/hex) |
    | **hex**         | use hexadecimal base for integer I/O: see [std::hex](https://en.cppreference.com/w/cpp/io/manip/hex) |
    | **basefield**   | dec\|oct\|hex. Useful for masking operations                 |
    | **left**        | left adjustment (adds fill characters to the right): see [std::left](https://en.cppreference.com/w/cpp/io/manip/left) |
    | **right**       | right adjustment (adds fill characters to the left): see [std::right](https://en.cppreference.com/w/cpp/io/manip/left) |
    | **internal**    | internal adjustment (adds fill characters to the internal designated point): see [std::internal](https://en.cppreference.com/w/cpp/io/manip/left) |
    | **adjustfield** | left\|right\|internal. Useful for masking operations         |
    | **scientific**  | generate floating point types using scientific notation, or hex notation if combined with fixed: see [std::scientific](https://en.cppreference.com/w/cpp/io/manip/fixed) |
    | **fixed**       | generate floating point types using fixed notation, or hex notation if combined with scientific: see [std::fixed](https://en.cppreference.com/w/cpp/io/manip/fixed) |
    | **floatfield**  | scientific\|fixed. Useful for masking operations             |
    | **boolalpha**   | insert and extract bool type in alphanumeric format: see [std::boolalpha](https://en.cppreference.com/w/cpp/io/manip/boolalpha) |
    | **showbase**    | generate a prefix indicating the numeric base for integer output, require the currency indicator in monetary I/O: see [std::showbase](https://en.cppreference.com/w/cpp/io/manip/showbase) |
    | **showpoint**   | generate a decimal-point character unconditionally for floating-point number output: see [std::showpoint](https://en.cppreference.com/w/cpp/io/manip/showpoint) |
    | **showpos**     | generate a + character for non-negative numeric output: see [std::showpos](https://en.cppreference.com/w/cpp/io/manip/showpos) |
    | **skipws**      | skip leading whitespace before certain input operations: see [std::skipws](https://en.cppreference.com/w/cpp/io/manip/skipws) |
    | **unitbuf**     | flush the output after each output operation: see [std::unitbuf](https://en.cppreference.com/w/cpp/io/manip/unitbuf) |
    | **uppercase**   | replace certain lowercase letters with their uppercase equivalents in certain output operations: see [std::uppercase](https://en.cppreference.com/w/cpp/io/manip/uppercase) |
    |                 |                                                              |

    在对输入输出有相应的要求的话可以使用一下方法：

    ```c++
    //头文件
    #include<ios> 
    #include<iomanip>  //调用setw 设置输出长度，不足是补充空格
    
    //8进制输出
    
    cout.setf(std::ios_base::oct, std::ios_base::basefield); //设置格式
    cout.setf(std::ios_base::showbase); //显示前缀 例如 O12 
    cout << 100 << endl; // output  0144
    //------
    cout.unsetf(std::ios_base::oct); //撤销之前设置的格式
    // 另一种方式
    cout << std::oct << num << endl; // output 0144
    
    //左对齐
    cout.setf(std::ios_base::left);
    cout << setw(20) << "Drafox" << endl; // output :$      Drafox
    ```

  ​	

  