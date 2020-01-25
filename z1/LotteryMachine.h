#ifndef __LotteryMachine_H_
#define __LotteryMachine_H_

#include <string>
#include <list>
using namespace std;

//reading data from fp file to four lists passed by refrences
void LoadData(string fp, list<string> &n1, list<string> &n2, list<string> &n3, list<string> &n4);

class LotteryMachine{
//four baskets
	list<string> &n1, &n2, &n3, &n4;
//string with the name of the host country
	string host;
//privat method taking as refence one of the baskets, drawing a country, removing it from the list and returning the country as string
	string GetNRemoveRandomCountry(list<string>& n);
	
	public:
//main constructor, taking by referene four list-type baskets, setting a random seed when called
	LotteryMachine(list<string> &nat1, list<string> &nat2, list<string> &nat3, list<string> &nat4);
//second constructor, where you can specify a host country, setting a random seed when called
	LotteryMachine(list<string> &nat1, list<string> &nat2, list<string> &nat3, list<string> &nat4, string host_country);
//copy constructor
	LotteryMachine(const LotteryMachine& r);
//assignment operator
	LotteryMachine& operator=(const LotteryMachine& r);
//move constructor
	LotteryMachine(LotteryMachine&& m);
//move assignment operator
	LotteryMachine& operator=(LotteryMachine&& m);
//method using the baskets to return list of lists (groups), host country is on the first place of group A (if specified)
	list<list<string> > RandomCountries();
//default destructor
	~LotteryMachine();
};

#endif
