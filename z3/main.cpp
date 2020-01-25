#include <iostream>
using namespace std;

class Person{
string name;
string surname;

public:
Person(string name, string surname)
{
this->name=name;
this->surname=surname;
}

Person(Person& r){
name=r.name;
surname=r.surname;
}

Person& operator=(Person& r){
name=r.name;
surname=r.surname;
return *this;
}

void prtname()
{
cout << "Name: " << name << ", " << "Surname: " << surname << endl;
}

~Person(){}

};


int main(){
Person A("Jan", "Kowalski");
Person B("Stefan","Nowak");
Person C(A);
A.prtname();
B.prtname();
C.prtname();
cout <<endl;
C=B;
B.prtname();
C.prtname();

return 0;
}
