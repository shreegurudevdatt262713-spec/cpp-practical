#include <iostream>
using namespace std;
int main()
{
 // Name displayed first
 cout << "Name: Anushka Mohite" << endl;
 // Data types and variables
 int a, b;
 float average;
 char grade = 'A';
 // Constant
 const int bonus = 10;
 // Input
 cout << "Enter two numbers: ";
 cin >> a >> b;
 // Operators
 int sum = a + b;
 int difference = a - b;
 int product = a * b;
 int division = a / b;
 // Output
 cout << "\n----- RESULT -----" << endl;
 cout << "Sum = " << sum << endl;
cout << "Difference = " << difference << endl;
 cout << "Product = " << product << endl;
 cout << "Division = " << division << endl;
 cout << "Bonus = " << bonus << endl;
 cout << "Grade = " << grade << endl;
 return 0;
}