### 移动对象

---

#### 前言

 - **学习目标**

   - 了解什么是移动对象
   - 了解右值引用
   - 了解移动构造函数 
   - 了解移动赋值运算
   - 了解`std::move`

- **知识点引入**

  如果拷贝一个即将销毁的对象，使用移动操作会更加高效。copy可以使用与任何定义它的对象之中，一个对象的默认构造函数为：默认构造函数，复制构造函数，移动构造函数，复制赋值运算符，移动赋值运算符，析构函数。而有的对象却将复制够咱函数以及复制赋值运算符制定为`delete`。所以 我们只能使用移动构造以及移动赋值运算符。移动赋值以及移动运算符的操作对象都是即将销毁的对象。

#### 知识点整理

- **`rvalue reference`**

  An `rvalue` reference is a reference that must be bounded by a `rvalue.`

  - `lvalue` which stand on the left-hand side of an assignment , but, `rvalue` not.
  - `rvalue`which does not be mortified.(personal idea) and, it always represents the value of an `rvalue`.

  **we can not bind an `lvalue ` to an `rvalue reference`**

上面这句话很好理解，只有一个`rvalue`的对象才可以绑定到`rvalue reference`上，由于`rvalue reference`所绑定的对象是一个即将要“销毁的对象” 或者是一个字面值。

```c++
int i = 0;
int &&rvr = 1010; //corect
int &&rv = i; //error an rvalue reference can not bind an lvalue

//we try another way
int &&rvr = std::move(i); //correct, but now, a is null ### std::move (c++11)


int &&rrvr = rvr; //error  for the rvr is a variable that is an lvalue type
```

​	其实我们可以说`std::move` 操作其实就是将对象拉过来（或者“剪切”）。

- `std::move`

  ```c++
  #include<utility>
  
  template<class T>  //since c++11 untill c++14
  typename std::remove_reference<T>::type&& move(T &&t) noexcept;
  
  template<class T>
  constexpr typename std::remove_reference<T>::type&& move(T &&t) noexcept; //(since c++14)
  
  
  return static_cast<typename std::remove_reference<T>::type &&>(t);
  ```

  通过上面的声明以及函数的返回，可以看到该函数的作用是将原有的类型转换为某种类型的右值引用。

  **try**

  ```c++
  string a = "asd";
  string b(static_cast<typename std::remove_reverence<string>::type &&>(a));
  //equal to b(std::move(a));
  ```

- `move constructor` and `move assignment`

  `general move constructor and move assignment sample`

  **move constructor**

  ```c++
  //--class definition
  class A{
      private:
      	int _x;
      	int _y;
      	int _z;
      public:
      A(A && a) noexcept: _x(std::move(a._x)), _y(std::move(a._y), _z(std::move(a._z))){
          //some operations
      }  
  };
  ```

  **move assignment**

  ```c++
  inline
  A& A::operator=(A && a) noexcept
  {
      _x =  std::move(a._x);
      _y =  std::move(a._y);
      _z =  std::move(a._z);
      return *this;
  }
  ```

- 容器中的函数重载（move）版本

  我们可以查看`bits/stl_vector.h`关于`vector`相关的定义中`push_back`有一个关于move操作的重载

  ```c++
  void                                                                               push_back(value_type&& __x)                                                          { emplace_back(std::move(__x)); }                                              
  ```

  所以在操作`push_back`过程中我们可以进行右值引用转换操作，将某个对象的`resource`“剪切到”容器当中。