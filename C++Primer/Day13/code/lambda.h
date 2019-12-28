#ifndef LAMBDA_H
#define LAMBDA_H 1

#include<iostream>
#include<string>
#include<vector>




class Lambda{

	public:
		//Lambda() = default;

		Lambda(int num) {
			_ptr = new int(num);
		}

		Lambda(const Lambda& lb )
		{
			_ptr = new int(*lb._ptr);
		}

		void Test() const 
		{
			auto f = [](int a, int b) -> bool {return a > b;};
			std::cout << f(12, 13) << std::endl; 
		}

		template<typename T>
		void swap(T& a, T& b)
		{
			std:: cout << a << "\t" << b << std::endl; 
			T temp;
			temp = a ;
			a = b;
			b = temp;
		}
		


		Lambda& operator= (const Lambda& des)
		{
			_ptr = new int(*(des._ptr));
			return *this;
		}

		template<class T>
		void bubbleSort(std::vector<T> &data)
		{
			auto f = [](const T a, const T b ) ->bool {return a > b;};
			for(auto index_i = 0; index_i < data.size(); ++index_i)
				for(auto index_j = 0; index_j <data.size() - index_i -1 ; ++index_j)
					if(f(*(data.begin()+index_j), *(data.begin()+index_j+1)))
						swap(*(data.begin()+index_j),*(data.begin()+index_j +1));
		
		
		}

		void show() const { std::cout << *_ptr << std::endl;}
		~Lambda() { delete _ptr;}
		
	private:
	
		int *_ptr;

};





#endif
