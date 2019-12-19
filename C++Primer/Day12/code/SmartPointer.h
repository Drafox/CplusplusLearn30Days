#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H 


#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<memory>
#include<initializer_list>
#include<exception>
#include<typeinfo>
class SmartPointer{

	public:
		SmartPointer() = default;
		SmartPointer(std::vector<int> &data) : _Data(data) {
		
			//std::vector<int> *vvecptr  = new std::vector<int>;
			//vecptr->push_back(21);
			//
			vecptr = std::make_shared<std::vector<int> >();
		       vecptr->push_back(22);	
		}
		virtual ~SmartPointer() {}

		void GetElm() const { std::cout << (*vecptr)[0] << std::endl;}
	protected:
		std::vector<int> _Data;
		std::shared_ptr<std::vector<int> > vecptr;
};



class StrBlob{

	typedef std::vector<std::string>:: size_type size_type;
	public:
	std::shared_ptr<std::vector<std::string> > _data;
		StrBlob();
		StrBlob(std::initializer_list<std::string> il);
		bool empty() const {return _data->empty();}
	       	size_type size() const {return _data->size();}
		

		void push_back(const std::string elem){ _data->push_back(elem);}
		void pop_back();
		
	
		void Test( const std::shared_ptr<int> &st ) const{
		
			std::shared_ptr<int> sst = st;
			
			std::cout << "sst:" << sst.use_count() << std::endl;
		}
			
		std::vector<int> *  practice1() const 
		{
		
			return new std::vector<int>();
		}

		void practice2(std::vector<int> *rst) const 
		{
				
			rst->push_back(22);
		}
		
		void practice3(std::vector<int> *rst) const
		{
			std:: cout << rst->back() << std:: endl;
		
		}

		std::string & front() const;
		std::string & back() const;

		StrBlob & operator= (const StrBlob &Stbl1){
			if(this != &Stbl1)
			{
			_data = Stbl1._data;
			}
			return *this;
		}

	void display() const { for(auto i : *_data) std::cout << i << std::endl;}
	
		void process(std::shared_ptr<int>p)
		{
		
			std::cout << "p : "  << p.use_count() << std::endl;
		}
	
	
	void compute(std::unique_ptr<int> &p)
	{
			const int &a = 222;
			std::string && name = "as"; 
			name += "1111";


		std::cout << ++(*p) << std::endl;

	}

void SptrTest()
{
	std::shared_ptr<int []> sptr(new int[30]);
    sptr[0] = 202;
    SptrC(sptr);
    std::cout << sptr.use_count() << std::endl;
}
void SptrC(std::shared_ptr<int []> sptrE)
{
    //Copying a duplication, the count of pointer which object was pointed adds one 
    std::cout << sptrE[0] << std::endl;
    std::cout << sptrE.use_count() << std::endl;
}
	
	
	private:
	void check(size_type i, const std::string &msg) const;

};


StrBlob::StrBlob(): _data(std::make_shared<std::vector<std::string> >()){}
StrBlob::StrBlob(std::initializer_list<std::string> il): _data(std::make_shared<std::vector<std::string> >(il)){}
inline void StrBlob::check(size_type i, const std::string &msg ) const
{
	if(i > _data->size())
		throw std::out_of_range(msg);
	
}

void StrBlob:: pop_back()
{

	_data->pop_back();
}


std::string & StrBlob::front() const{

	check(0,"out_of_range");
	return _data->front();

}


std::string & StrBlob:: back() const{

	check(0,"out_of_range");
	return _data->back();

}


class ExConversion{

	public:
	
	void stCast()
	{
	float j = 3.1415926 , i = 2.71828;
	double dbM = static_cast<double> (j/i);
	int IntAverage = static_cast<int> (j+i);
	std::cout << dbM << "\t it: " << IntAverage << std::endl;

//Try to convert a low-level const to find out what will happen.

std::string corperation = "ByteDance";
void * target =  &corperation;
std:: cout << target << std::endl;
std::string *UltimateAim = static_cast<std::string *> (target);
std::cout << UltimateAim << std::endl;
	
//--------
const char * ttarget  = "ByteDance";
//char * aim = static_cast<char *>(ttarget);
//


	char a = 'a';
	std::string b= "ByteDance";
	int c =102;
	std::vector<std::string> d;
	std:: cout << typeid(a).name() <<typeid(a).hash_code() <<std::endl;
	std:: cout << typeid(b).name() << typeid(b).hash_code()<<std::endl;
	std:: cout << typeid(c).name() << typeid(c).hash_code() <<std::endl;
	std:: cout << typeid(d).name() <<typeid(d).hash_code() <<std::endl;

	}
};

#endif
