#include<iostream>
#include<string>
#include<vector>


template<typename T>
class BinaryTree{};


template<typename T>
class BTnode{
	friend class BinaryTree<T>;

};
