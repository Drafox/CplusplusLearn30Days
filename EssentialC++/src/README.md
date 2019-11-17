### Essential C++ 学习笔记

---

**0x00 Preface**

​	看C++Primer有一段时间了，对于那本巨作啃完它还是需要些时间，为了有效的读懂那本书，总结了之前8章学习的经验，慎重考虑了一下，还是先看一本简小的书，对C++整体有一个认识。那么Essential C++无疑是最佳的选择了。

​	计划：三天时间刷完整本书。

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

  

- **point 5**

- **point 6**

- **point 7**

- **point 8**

- **point 9**

- **point 10**

- **point 11**

- **point 12**

- **point 13**

- **point 14**

- **point 15**

- **point 16**

- **point 17**

- **point 18**

- **point 19**

- **point 20**

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

  ![](<https://github.com/Drafox/C-Learn30Days/blob/master/EssentialC%2B%2B/img/bubble%20_sort.jpg>)

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

