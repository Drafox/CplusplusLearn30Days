### 第六天学习笔记

---

####  初涉模板

- 类模板实例一`vector`

  **定义`vector`**

  ```c++
  #include<vector>
  
  struct Sale{
    int *sequence;
    char *ID;
  };
  
  vector<int> ivec;
  vector<Sale> Books;
  vector<vector<string>> file;
  ```

  初始化`vector`对象

  ```c++
  vector<T> v1;
  vector<T> v2 = v1;
  vector<T> v2(v1);
  vector<T> v3(n,val);
  vector<T> v4(n);
  vector<T> v5{a,b,c...};
  vector<T> v6 = {a,b,c,d...}
  ```

  #### 添加元素

  `push_back` 向向量末尾添加元素

  ```c++
  vector<int> cve ;
  
  for(int i = 0; i < 100 ; i++)
      cve.push_back(i)
  for(auto i : cve)
      cout << i  << endl;
  ```

  **不能用下表进行添加元素**

  ```c++
  vector<int> s;
  for(decltype(s) index = 0; index != 10 ; ++index)
      s[index] = index; //error : s 内不含任何元素
  ```

  #### Iterator

  ​	遍历容器的作用，在C++中容器类型都拥有`begin,end`成员。

  **begin:表示容器第一个元素**

  **end:表示容器最后一个元素的下一个位置**

  ```c++
  vector<int>  vec{1,2,3,3};
  auto a = vec.begin();
  auto b = vec.end();
  ```

  #### 				如果目标容器为空，则begin,end返回同一个迭代器。

  ##### 迭代器运算符

  `begin and end`返回`const_iterator or iterator`

  如果对象是常量则返回`const_iterator`

  如果对象不是常量则返回`iterator`

  **example**

  ```c++
  vector<int> vec(18,98);
  const vector<int> cvec(18,99);
  vector<int> :: const_iterator a;
  vector<int> :: const_iterator b;
  vector<int> :: iterator c;
  vector<int> :: iterator d;
  
  a = vec.cbegin(); //cvec.begin() /
  b = vec.cend();  // cvec.end() /
  c = vec.begin();
  d = vec.end();
  
  for(a; a !=b ; a++)
      cout << *a << endl;
  for(c; c !=d ; c++)
      *c = 100;
  //try  to  modify the value by const_iterator
  
  for(a = cbegin(); a != b; a++)
      *a = 101;  
  //error: assignment of read-only location ‘a.__gnu_cxx::__normal_iterator<const int*, std::vector<int> >::operator*()’                               
  ```

  #### 迭代器运算

  `iter+n`  迭代器加上一个整数值仍得一个迭代器，所以加上n，迭代器移动n个元素位置

  `iter-n`迭代其向后移动n个位置

  `iter +=n`把移动之后的迭代器位置赋给`iter`

  `iter -=n`与前面类似，只是方向不同

  `iter1 - iter2`两个迭代器之间的位置

  `> < >= <=`

  如果两个迭代器相减，并且该容器有difference_type, 则两个容器相减后返回的类型为`difference_type`有符号整型。

  ```c++
  string name = "Hello, World!";
  decltype(name.begin()) a = name.begin();
  auto b = name.end();
  auto c = a + 3;
  
  auto d = a -c;
  
  string:: difference_type e = b -c;
  
  cout << d << endl << e << endl; 
  // -3 10
  
  ```

  ####  Binary Search

  ​	思路：

  ​	给定序列然后进行排序，按字典顺序排好后，通过定位中位值与所要查找元素做比较，如果所要查找元素在中位值之前，那么把序列缩小到原来的一半，开始为原来序列的开始位置，结束位置为原来序列中位值之前的一个元素。如果所要查找的元素在原先的序列中位值之后，开始位置变成原来中位值下一个元素的位置，而结束位置为原序列结束位置。

  ```c++
  #ifndef BINARYSEARCH_H
  #define BINARYSEARCH_H
  
  #include<string>
  #include<vector>
  #include<iostream>
  
  int BinarySearchByRecursion(int data[], int left, int right, int element)
  {
          if(right >= left )
          {
                  int mid = (right + left) /2 ;
          if(data[mid] == element)
                  return mid+1;
  
          if(data[mid] > element)
                  return BinarySearchByRecursion(data,left, mid-1, element);
  
          return BinarySearchByRecursion(data, mid+1 , right, element);
  
  }       
          return -1;
  }
  
  std::vector<int>::difference_type  BinarySearchByIterator(std::vector<int> data, int element)
  {
          auto left = data.cbegin();
          auto right = data.cend();
          auto mid = data.cbegin() + (right - left)/ 2 ;
  
          while(mid != right && *mid != element)
          {
                  if(*mid > element)
                          right = mid;
                  else
                          left = mid +1 ;
  
                  mid = left + (right - left) /2 ;
  
          }
  
          return mid - data.cbegin() + 1;
  }
  
  ```

  #### 数组元素的初始化

- **C中的数组初始化概念**

  初始化中必须是一个字符串或者用大括号围起来的元素的有限集合。

  ```c
  char a[] = "hello, world!"; //size: 14 contain '\0' character
  char b[3] ="hel"; //correct! if given the size of an array and the string literal size is more than the size of the array so that the initializer ignore the '\0'(null) character; 
  
  const int n = 99;
  int c[n]; //It is correct on the linux OS
  ```

- **在C++语言中的初始化与C类似**

  而且数组可以用范围`for`进行便利。

  ```c++
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  for(auto &i:a)
      i = i+1;
  for(auto i:a)
      cout << i << endl;
  
  int b[3][4] = {
      {2,3,4,1},
      {5,6,7,0},
      {8,9,10,-1}
  }
  
  for(auto &i:b)
      for(auto j:i)
          cout << j << endl;
  
  /*
  	探讨双重范围for遍历b，为什么第一个范围for中变量i必须是引用。
  	避免编译器将i视为指针类型，所以将其与行向量绑定在一起。
  
  */
  ```

  #### 指针和数组

  ​	编译器会将数组转变为指向该数组首元素的指针。所以当使用`auto`，编译器会返回指针类型，所以导致一些操作无法执行。但是使用`decltype（arr）arr1`不会出现转换为指针，而是数组类型。

- 指针也是迭代器

  ```c++
  #include<cstddef>
  
  int a[10] = {1,2,3,4,5,6,7,8,9,10};
  int *be = begin(a);
  int *en = end(a);  //标准库函数，不是成员函数
  
  ptrdiff_t size = en - be;
  
  ```

- 使用数组初始化`vector`

```c++
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int *be = begin(a);
int *en = end(a);  
vector<int> c(be+2, en-2);
```

