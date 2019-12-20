#include"AssContainer.h"

using namespace std;


int main()
{


	map<string, string> gram;

	//
	gram["Request URL"] = "https://www.gstatic.com/images/branding/googlelogo/svg/googlelogo_clr_74x24px.svg";
	gram["Request Method"] = "GET";
	gram["Status Code"] = "200 (from disk cache)";
	gram["Remote Address"] = "127.0.0.1:1080";
	gram["Referrer Policy:"] = "strict-origin";
	//
	ASSC_HTTP ash(gram);

	ash.show();
	
	ash.PairTest();

	ash.TestMap();
	return 0;
}
