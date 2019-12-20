### 关联容器大法

----

### 八绝技

- **map**

  键值结构，不允许存在相同的键（key），且关键字有序排列。

- **set**

  关键字即值，只保存关键字的容器，有序

- **multimap**

  允许有相同关键字map，且有序

- **multiset**

  允许与相同关键字的set, 且有序

- **unordered_map**

  关键字无序的map

- **unordered_set**

  关键字无序的set

- **unordered_multimap**

  关键字无序的multimap

- **unordered_multiset**

  关键字无序的multiset

#### a pair of 

#### pair

*defined in utility*

```c++
#include<utility>
#include<string>
std::pair<int, std::string> RP(const vector<int> &a, const pair<int, int>& b)
{
    
    	if(find(a.cbegin(),a.cend(),b.first) != a.cend())
            return std::pair<int, std::string>(b.first, "find");
 		return std::pair<int, std::string>(b.first, "not-found");
}

int main()
{:
   //test
  std::vector<int> vec{1,2,3,4,5,6,7};
  std::pair<int, int> pai = {1,21};
  std::pair<int, std::string> p = RP(vec,pai);
  if(p == std::pair<int, std::string> q(pai.first, "find"))
    	std::cout << "the data was found in vec" << std::endl;
}

```

​	\`pair<T1,T2>\`类模板有两个成员变量`first , second`分别指向T1元素，以及T2元素

### map

声明 ： `std::map<T1, T2> mp;`

​	一个map对象保存数据类型为一个pair类型，其中有三种类型：

```c++
value_type //pair类型
mapped_type //关键字所映射的值
key_type //关键字
```

- #### 初始化map对象

``` c++
//c++
std::map<std::string, std::string> smap = {{"key","value"}}; 
std::map<std::string, int> suser;
suer["Alibaba"] = 1000;
suer["ByteDance"] = 100000000;
suer["MeiTuan"] = 12;
suer["JingDong"] = 1200;
```

```python
#python
smap = {"key":value, "key1":value1}
for key, value in smap.items():
    print(key,"->",value)
```

- #### 遍历map对象， 迭代器

#### 

```c++
std::map<std::string, int> pmap = {{"alibaba",1000},{"ByteDance",100000000}};

auto beg = pmap.begin();
auto end = pmap.end();
auto mud = beg;
while(beg != end)
{
    	std::cout << beg->first << std::endl;
    	std::cout << beg->second << std::endl;
    	beg++;
}

//try to modify the key of the pmap;
	mud->first = "yaHoo";
//error:passing ‘const std::__cxx11::basic_string<char>’ as ‘this’ argument discards qualifiers

```

​	我们看到上面程序试图修改其`key`值，然后编译器报错内容为：

​	由于迭代器返回一个`value_type`类型，该类型为`pair`类型，而其中的`first`为`const`类型。

- #### 插入insert

  ```c++
  std::map<std::string, std::size_t > pmap;
  std::set<int> pset;
  std::multimap<std::string, std::string> mmap;
  
  auto pm =  pmap.insert(std::pair<std::string, std::size>v{"ByteDance",9090});
  // pm : std::pair<const std::iterator&, bool>
  pm.first; //the value of inserting that is a pair type
  pm.first->first;
  pm.first->second;
  pm.second; //if it successfully insert, it will return true, otherwise, return false
  
  auto ps = pset.insert(101);
  ps.first //a constant iterator which is a reference of the element of pset 
  ```

  

  ​	





 	

