#ifndef ASSC_H
#define ASSC_H 1

//  -------------------- preprocessor-- header file  --------------

#include<map> //map multimap
#include<set> //set multiset
#include<unordered_map>  //unordered map and unordered multimap
#include<unordered_set>  //unordered set and unordered multiset

#include<string> //string 
#include<cstdlib> //srand rand
#include<cstddef> //size_t 
#include<ctime> //time 
#include<iostream> //istream ostream 
#include<utility> //pair class  
#include<vector>
#include<typeinfo>
// ---------------------- end -------------------------------------


class ASSC_HTTP{

	public:

	ASSC_HTTP(const std::map<std::string, std::string> &Gram) : _httpData(Gram){}
		ASSC_HTTP(ASSC_HTTP& AH){
			this->_httpData = AH._httpData;
		}

	/*	ASSC_HTTP(const std::map<std::string, std::string>& Gram) {
		
			this->_httpDate = Gram._httpData;
	}

*/	

		void show()
		{
			auto element = _httpData.cbegin();
			while(element != _httpData.cend())
			{
	std::cout << element->first << " :\t" << element->second << std::endl;
			element++;
			}
		}



	void PairTest() const 
	{

/*
 *	Some operations of pair type 
 *
 *	pair<T1, T2> p;  p is a pair type, these data members are T1 and T2  
 *
 * 	pair<T1, T2> p(v1, v2);  the first member is initialized by v1, second member is initialized by v2
 *
 * 	pair<T1, T2> p = {v1, v2}  equal to p(v1, v2)
 *
 *	make_pair(v1, v2)  return a pair which is initialized by v1 and v2, and the type of this pair infered to v1 and v2 
 *
 *	p.first returns the public member first of p
 *
 *	p.second returns the public member second of p
 *
 *	p1 relop p2    
 *
 *	p1 == p2   if the value of first and second  of p1  is equal to p2 that will  return true 
 *
 *	p1 != p2  
 *
 * */
		
		std::pair<std::string, std::vector<int>> data; //default constructor

		std::pair<std::string, std::size_t> user = {"ByteDance", 100};

		std::pair<int, double> salary(23,18);
	
		std::pair<int, int> p = std::make_pair(100, 101);

	std::cout << user.first << ": " << user.second << std::endl;	

		std::pair<int, int> q(222, 223);


		if(q > p)
			std::cout << "q won this game!" << std::endl;

		std::cout << typeid(q).name() << std::endl;
		std::cout << typeid(q.first).name() << std::endl;
	
		std::map<std::string, std::string> data1 = {{"zs", "bytedance"}};


		std::cout << typeid(data1).name() << std::endl;
		std::cout << typeid(data1.cbegin()->first).name() << std::endl; 




	}

	
	void TestMap()
	{
	
	
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
	//mud->first = "yaHoo";
//error:
//
//


	std::set<int> pset {2,3,4,5,};
	auto re =  pset.insert(2);
	std::cout << *re.first << re.second << std::endl;

	}

		~ASSC_HTTP(){}
	private:
		std::map<std::string, std::string> _httpData;


};









#endif
