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

