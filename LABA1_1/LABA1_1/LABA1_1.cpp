#include <iostream>
#include <cmath>

using namespace std;

int main() {

   double x, y, z;

   cout << "Input x: ";
   cin >> x;
   cout << "Input y: ";
   cin >> y ;
   cout << "Input z: ";
   cin >> z;


   double a = pow(cos(atan(z)), 2) + 4.2 * exp(-pow(x, 2) + 1.3)
      - sqrt(2 * pow(x, 2) + pow(y, 2) + 1)
      + log((2 + 3.3 * pow(x, 2) + pow(y, 2)) / (4 * pow(x, 2) + 5.5 * pow(y, 2) + 1));


   cout << "Result a = " << a << endl;

   return 0;
}
