#include "LotteryMachine.h"
#include <algorithm>
#include <fstream>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



LotteryMachine::LotteryMachine(list<string> &nat1, list<string> &nat2, list<string> &nat3, list<string> &nat4): n1(nat1), n2(nat2), n3(nat3), n4(nat4) {
srand((unsigned int)time(NULL));
}

LotteryMachine::LotteryMachine(list<string> &nat1, list<string> &nat2, list<string> &nat3, list<string> &nat4, string host_country): n1(nat1), n2(nat2), n3(nat3), n4(nat4), host(host_country) {
srand((unsigned int)time(NULL));
}

LotteryMachine::LotteryMachine(const LotteryMachine& r) : n1(r.n1), n2(r.n2), n3(r.n3), n4(r.n4), host(r.host) {}

LotteryMachine& LotteryMachine::operator=(const LotteryMachine& r){
n1=r.n1;
n2=r.n2;
n3=r.n3;
n4=r.n4;
host=r.host;
return *this;
}

LotteryMachine::LotteryMachine(LotteryMachine&& m) : n1(m.n1), n2(m.n2), n3(m.n3),n4(m.n4) {
host=m.host;
m.host = "";
}

LotteryMachine& LotteryMachine::operator=(LotteryMachine&& m){
n1=m.n1;
n2=m.n2;
n3=m.n3;
n4=m.n4;
host=m.host;
m.host="";
return *this;
}


void LoadData(string fp,list<string>& n1, list<string>& n2, list<string>& n3, list<string>& n4)
{
	string line;
	int linenr;
	fstream file;
	file.open(fp);
	list<string>* nptr[4]={&n1,&n2,&n3,&n4};
	while(getline(file,line)){
		if (line.rfind("Basket",0)==0) { linenr = line[line.length()-2] - '1';
		} else if (!line.empty()) (*nptr[linenr]).push_back(line);
	}
	file.close();
}

string LotteryMachine::GetNRemoveRandomCountry(list<string>& n)
{
	list<string>::iterator it = n.begin();
	string country;
	advance(it,rand()%(n.size()));
	country = *it;
	n.erase(it);
	return country;
}

list<list<string> > LotteryMachine::RandomCountries()
{
	list<string> group;
	list<list<string> > result;
	list<string>::iterator gr;
	char groupLetter = 'A';
	list<string>* nptr[4]={&n1, &n2, &n3, &n4};

	while(!n1.empty()){
		for(list<string>* v : nptr) group.push_back(GetNRemoveRandomCountry(*v));
		gr = find(group.begin(), group.end(),host);
		if(host.size() && *gr == host){
			group.erase(gr);
			group.push_front(host);
			result.push_front(group);
		} else result.push_back(group);
		group.clear();
	}

	for (list<list<string> >::iterator it=result.begin();it!=result.end();++it){
		cout << endl << "Group " << groupLetter++ << ":" << endl;
		list<string>& ptr = *it;
		for (gr=ptr.begin();gr!=ptr.end();gr++) cout << *gr << endl;
	}
	return result;
}

LotteryMachine::~LotteryMachine(){}
