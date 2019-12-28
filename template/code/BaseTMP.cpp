#include"BaseTMP.h"

using namespace std;



int main()
{
	
	BaseTmp entity;

	//cout << entity.MAX(22, 23) << endl;
	cout << entity.MAX<double , int, double>(22, 23) << endl;
		

	Stack<string> st_string;

	cout << st_string.empty() << endl;
	

	st_string.push("Hello, Word!");

	cout << st_string.top() << endl;
	return 0;

}

template <typename T>
void Stack<T>::push(T const &elem)
{
	elems.push_back(elem);
}


template <typename T>
T Stack<T> :: pop()
{
	if(empty())
	{
		std::cout << "Exception: no element in the container " << std::endl;
	}
	T result = elems.back();
	elems.pop_back();

	return result;
}

template <typename T>
T Stack<T>::top() const
{

	if(empty())
	std::cout << "Exception: no element in the container " << std::endl;

	return elems.back();
}

