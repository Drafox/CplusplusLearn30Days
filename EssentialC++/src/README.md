### Essential C++ 学习笔记

---

**0x00 Preface**

​	看C++Primer有一段时间了，对于那本巨作啃完它还是需要些时间，为了有效的读懂那本书，总结了之前8章学习的经验，慎重考虑了一下，还是先看一本简小的书，对C++整体有一个认识。那么Essential C++无疑是最佳的选择了。

**0x01 从书本前言中获取的信息**

​	这本书简略了很多东西，但是把跟多内容都浓缩了，舍弃掉了一些未涉及的东西，以及了解S.B.L一些创作。

**0x02 从书中GET到的点**

##### 第一组

- **point 1**

  语句是C++程序的最小独立单元。

- **point 2**

  `namespace`是一种将库名称封装起来的方法。t 

- **point 3**

  `vector`对象没有初始化时，是不能通过索引进行赋值，添加元素的。

- **point 4**

  将参数声明为`reference`

  ​	理由1：希望得以直接对传入的对象进行修改。

  ​	理由2：降低复制大型对象的额外负担。

- **point 5**

  指针可能会没有指向任何对象，但是引用必须指向对象。所以使用指针传递对象时，需要判断：

  `if(pointer == nullptr)`

- **point 6**

  定义在`file scope` 内的变量会被编译器初始化，但是定义在局部内的变量用户需要自己初始化，否则该变量的值是为定义的。

- **point 7**

  `form: int *p = new int; int *ptr = new int(2948);`

- **point 8**

  C++没有提供任何语法让我们从heap分配数组的同时初始值。

- **point 9**

  如果为某个参数提供默认值，那么其右侧所有变量都必须提供默认值，否则行为是非法的。

- **point 10**

  定义默认值的地方只允许是一处，要么是声明部分，要么是定义部分。最好是在声明部分，用户可见性高。

- **point 11**

  `inline function`常常被定义到头文件中。

- **point 12**

  ```c++
  form : 
  template<typename A, B ,C D>
  void printm(A ,B ,C, D); //declaration
  
  //definition
  template<typename A, B, C, D>
  void printm(A a, B b, C b, Dd)
  {
      cout << "1 : " << a << "\t2: " <<b << "\t3 : " << c << "\t 4: " <<d << endl;
  }
  ```

  

- **point 13**

  ​	函数传递数组时会转变成指针，所以难免有些操作不能实现，比如：`auto beg = begin(arr);`

  因为传入的参数arr被转换成指针，而`begin`的参数类型为数组类型。

  可以使用数组引用类型解决这一问题`const int (&a)[10];`

- **point 14**

  所有容器的共同操作：

  ​	

- **point 15**

  `list `并不支持`iterator`偏移运算:no match for ‘operator+’ (operand types are ‘std::_List_iterator<int>’ and ‘int’)	

- **point 16**

  `max_element`  Essential C++ :max_element() is passed an iterator pair marking the range of elements to traverse. It returns the largest element within the vector. 

  但是实际上是返回的该最大元素的迭代器。

- **point 17**

  `algorithm` 库中的函数的迭代器范围都是`[first, last)`

- **point 18**

  `STL（Standard Template Library）`有两种组件构成：容器、操作这些容器的`generic algorithm`

- **point 19**

  泛型算法通过`function template`,达到与操作对象的类型相互独立，实现与容器无关的技术，则是通过迭代器，进行操作。

- **point 20**

  `iterator(generic pointer) Iterators are used to point at the memory addresses of STL containers. `

  Operation: assign, compare , increment, dereference.

- **point 21**

  对于不同容器有着不同的操作，所以`iterator`也有不同的类型，比如： [LegacyInputIterator](https://en.cppreference.com/w/cpp/named_req/InputIterator), [LegacyOutputIterator](https://en.cppreference.com/w/cpp/named_req/OutputIterator), [LegacyForwardIterator](https://en.cppreference.com/w/cpp/named_req/ForwardIterator), [LegacyBidirectionalIterator](https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator), [LegacyRandomAccessIterator](https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator), and [LegacyContiguousIterator](https://en.cppreference.com/w/cpp/named_req/ContiguousIterator) ［from cppreference.com］

- **point 22**

  `erase return the iterator which points the position after the deleted element`

- **point 23**

  `destructor并不是绝对需要的。`

- **point 24**

  `mutable` 不会破坏`const object`的常量性质。

- **point 25**

  静态类成员，不允许定义在类内部，可以在类的外部进行定义，通过范围解析运算符。

- **point 26**

  静态类成员，相同类的实体共享该成员。

- **point 27**

  静态成员函数与普通成员函数的区别是：静态函数没有`this`指针，只能访问静态成员数据及静态成员函数。

- **point 28**

  静态成员函数可以在对象实体创建之前通过范围解析运算符进行访问。

- **point 29**

  运算符重载规则：不可以引入新的运算符。而且`. .* :: ?:`四个运算符不允许重载。运算优先级以及运算符的操作对象数量不可变。

- **point 30**

  `OOP：（Object-Oriented Programming）面向对象编程，万事皆对象。 `

- **point 31**

- **point 32**

- **point 33**

- **point 34**

- **point 35**

- **point 36**

- **point 37**

- **point 38**

- **point 39**

- **point 40**

##### 动手练习

**Sample 1: Fibonacci(Get the given position result )**

```c++
bool FibonacciGame(int position, int &element)
{
    //2^31 46: 1836311903 45:1134903170
    if(position <= 0 || position > 46){
        element = 0;
        return false;
    }
    
    int num1 = 1, num2 =1;
    for(int index = 3; index <= position; ++index)
    {
        element = num1 + num2;
        num1 = num2; 
        num2 =element;
    }
    return true;
}
```

**Sample 2: Bubble Sort**

- which is the  simplest sorting algorithm that works by  repeatedly swapping the adjacent element if they are in wrong order. 

  ![]()

- 我们分析上面的图，然后设计程序

  1：相邻两个元素进行对比，按照我们需要的顺序进行对比，比如从小到大的顺序，如果左边元素大于右边元素，则互换位置，然后指针指向右边元素，即右边元素变为下一次对比的左边对象。重复这样的操作直到最后一个元素的位置。

  2：再次迭代，重复1的操作，但是我们可以注意到由于每一次迭代都使最大值放到合适的位置。所以之后每次迭代的次数是数组的长度减一再减去之前迭代的总次数。

- 程序设计

```c++
void BubbleSort(int data[], int size)
{
    for(int index_x = 0; index_x < size; ++index_x )
    {
        for(int index_y = 0; index_y < size - index_x -1; ++index_y)
        {
            if(data[index_y] > data[index_y+1])
                swap(data[index_y],data[index_y + 1]);
        }
    }
}

void BubbleSort(vector<int> data)
{
    for(decltype(data.size()) index_x = 0; index_x < data.size(); ++index_x)
    {
        for(decltype(index_x) index_y = 0; index_y < data.size() - index_x -1; ++index_y)
            if(data[index_y] > data[index_y + 1])
                swap(data[index_y],data[index_y + 1]);
    }
}

void swap(int &num1, int &num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
```

分析程序：

时间复杂度：$\Omicron(n^2)$

​	1：外层循环必然为n

​	2：原子语句依次$n-1, n-2 ,n-3\cdots1,0 $

​	所以原子语句频度为（${n(n-1)}/2$）

空间复杂度：$\Omicron(1)$

​	所以说冒泡排序是最简单的排序方法，只用与教学目的了解算法，实际上几乎用不到。因为有更高效率的算法：快速排序，归并排序等等。	

但是上面程序有个很严重的问题，没有最优情况，如果是应经排好顺序的序列依旧需要没一项进行检查。所以上面程序可以优化一下：

```c++
void BubbleSort(vecot<int> data)
{
    bool isOrder;
    for(decltype(data.size()) index_x = 0 ;index_x < data.size() ; ++index_x )
    {
        isOrder = true;
        for(decltype(data.size() index_y = 0 ; index_y < data.size() -1 -index_x ; ++index_y))
        {
            if(data[index_y] > data[index_y +1])
            { 
                swap(data[index_y], data[index+1]);
            	isOrder = false;
            }
   			if(isOrder == true)
                break;
        }
    }
}
```

分析程序：

​	如果第一次迭代并没有任何交换，可以说明该序列是有序的，所以就不用之后的迭代。也就是说时间复杂度为$\Omega(n)$

#### 课后习题

- 1.7 	输入文字并存盘。将文本文件读取内容存取到`vector<string>`对象中。遍历该对象，将内容显示到`cout`，然后利用泛型算法`sort`对文字进行排序。

  ```c++
   void FileTest() const {
            
                  ifstream file("main.cpp");
                  vector<string> data;
                  string str;
                  while(getline(file,str))
                  {
                          sort(str.begin(),str.end());
                          data.push_back(str);
                  }
                  for(auto i : data)  
                  {
                          cout << i << endl;
                  }
                  
                  cout << data.size() << endl;
          
          }
  ```

- 1.8 根据用户答错次数显示不同的安慰语句。

  ```c++
  
  ```

  