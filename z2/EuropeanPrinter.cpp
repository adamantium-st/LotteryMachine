#include "EuropeanPrinter.h"
#include <iostream>
using namespace std;

void printDegrees(float c)
{
if (c>40.0) cout << "It's hot!!!"<<endl;
else if (c< 0.0) cout << "It's cold!"<<endl;
else cout << "The temperature is optimal. Good to go!"<<endl;
}
