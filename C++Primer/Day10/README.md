### 第十天学习笔记

---

####0x00 Preface

学习计划：

- 第八章I/O库
- Linux下的文件

#### 0x01 概括

​	一个程序中，分为很多小的程序段，而这些程序段又分为：数据段，计算段，IO操作段。

​	我们期待把计算结果输出到屏幕，或者将某些记录输出到文件当中，比如日志，以及从键盘或者文件中读取数据，读入到程序中等等。

​	那么C++IO标准库定义了几种基本类型以及对象和操作符。

​	

#### 0x02 基本知识

- IO对象不能进行拷贝以及赋值

  IO对象是对输入输出设备以及文件的抽象，那么该对象不能有副本，而且不允许修改。

- 条件状态

  未清楚了解

- 管理输出缓冲区

  - 三种不同的显式刷新输出缓冲区

    ```c++
    std::cout << "Drafox, Google Code" << std::endl; //刷新缓冲区，并且加上换行符
    std::cout << "Drafox, Google Code" << std::flush; //只刷新缓冲区
    std::cout << "Drafox, Google COde" << std::ends; //刷新缓冲区， 并且加上空字符
    ```

  - 如果程序异常终止时，不会刷新输出缓冲区。

- 文件输入输出

  - 头文件：`fstream`

    类型：

    - `ifstream`:从一个给定文件读数据
    - `ofstream`:从一个给定文件写数据
    - `fstream`: 可以读写给定文件。

  - `fstream`特有的操作

    ```c++
    fstream file;
    fstream file(filename, mode);
    mode : in , out ,app , ate,truc, binary
    file.open(filename2);
    file.close();
    bool file.is_open();
    
    ```

    - **in: 以读取的方式打开，只能用于`ifstream`**
    - **out : 以写入的方式打开，默认截断文件，会清空文件原有的内容，只能用于`ofstream`**
    - **app: 只有写操作时，定位到文件末尾，进行添加操作 **
    - **ate: 无论什么方式直接定位到文件末尾**
    - **binary: 以二进制的方式打开**
    - **truc: 截断文件**

    示例：

    ```c++
    //iotest.cpp
    ```

    对于ofstream类型打开文件时，如果文件不存在则创建并打开，如果存在则打开。

    对于ifstream类型打开文件时，如果文件不存在返回flase;

    如果想重新定为可以使用seekg函数。

    ```c++
    #include<fstream>
    #include<iostream>
    #include<string>
    #include<limits.h>
    
    using namespace std;
    class FileClass{
        public:
      bool MyOpenF(string pathname,string filename,ios_base::openmode flag = ios_base::app) const {
            string t = (pathname + "/" + filename);
            const char *name = t.c_str();
            ofstream outfile(name,flag);
          	if(!outfile)
            {
                cerr << "Error: failed to open file" << endl;
                return false;
            }
          	cout << "opened!" << endl;
          return true;
        }
        private:
        string pathName;
        string fileName;
    };
    
    int main()
    {
        string name1(254,'h');
        string name2(13,'h');
        FileClass obj;
        if(MAX_NAME < 15)
        {
            obj.MyopenF(".", name2);
        }
        else
        {
            obj.MyopenF(".",name1);
        }
        
    }
    ```

    在Linux下，我把文件权限修改之后，open是无法打开的，所以检查是否打开是很有必要的。



####Linux文件

---

文件标识符

​	当一个进程打开文件时，系统内核将返回一个文件标识符引用，文件标识符是一个非负整数。

​	我们可以通过`open`和`create`打开文件返回的文件标识引用，传递给`read`和`write`进行操作。

`fuction: int open(const char *name, int flag,.../*mode*/)`

​	若成功返回文件描述符，若失败返回-1.

​	在`fcntl.h` 头文件定了flag常量。

```shell
cd /usr/include/asm-generic/
cat fcntl.h
define O_ACCMODE	00000003
#define O_RDONLY	00000000
#define O_WRONLY	00000001
#define O_RDWR		00000002
#ifndef O_CREAT
#define O_CREAT		00000100	/* not fcntl */
#endif
#ifndef O_EXCL
#define O_EXCL		00000200	/* not fcntl */
#endif
#ifndef O_NOCTTY
#define O_NOCTTY	00000400	/* not fcntl */
#endif
#ifndef O_TRUNC
#define O_TRUNC		00001000	/* not fcntl */
#endif
#ifndef O_APPEND
.....
```

- flag常量

`O_RDONLY` 只读打开

`O_WRONLY` 只写打开

`O_RDWR` 读写打开

以上三种只允许使用一个

`O_APPEND` 	每次写时都加到文件的尾端，与C++标准中的`ofstream::app`相同

`O_CREATE`	若文件不存在则创建它

`O_EXCL`		如果同时指定`O_CREATE`,文件若存在，则报错。检验文件是否存在。

`O_TRUNC`	如果文件存在，而且只读或者只写，长度截取为0

`O_SYNC`  	每次`write` 都需要等待物理设备完成 。

- 文件名以及路径名截断

  如果文件名或者路径名超过`NAME—MAX`，会报错将errno设置为36，可以通过strerro(errno)查看说明。