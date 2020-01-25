#include "MathematicalCalculations.h"
#include "EuropeanPrinter.h"
#include <iostream>
using namespace std;

int main(){
float tempf;
cout << "Enter the temperature (Fahrenheit deg)" << endl;
cin >> tempf;

printDegrees(calculate(tempf));

return 0;
}
