#ifndef BASETMP_H
#define BASETMP_H

#include<iostream>
#include<string>
#include<vector>
#include<stddef.h>
#include<ctime>
#include<cmath>




class BaseTmp{
	public:

	

	BaseTmp() = default;


	template <typename T1, typename T2, typename RT>
	RT MAX(T1 const& a, T2 const& b)
	{
	
		return a > b ? a:b;
	}
	

	private:

	protected:

};



template <typename T>
class Stack{
	public:
		T top() const;
		bool empty() const { return elems.empty();}
		T pop();
		void push(T const&);
	private:
		std::vector<T> elems;



};






#endif
