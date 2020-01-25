#include "LotteryMachine.h"
#include <string>
#include <list>

int main(){
list<string> n1,n2,n3,n4;
LoadData("Nations.txt",n1,n2,n3,n4);
LotteryMachine L(n1,n2,n3,n4,"Polska");
LotteryMachine R(L);
L=R;
L.RandomCountries();

return 0;
}
