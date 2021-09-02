//============================================================================
// Name        : Euclidean algorithm.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*

Given two non-negative integers a and b, we have to find their GCD 
(greatest common divisor), i.e. the largest number which is a divisor 
of both a and b.

When one of the numbers is zero, while the other is non-zero, their greatest 
common divisor, by definition, is the second number. When both numbers are zero, 
their greatest common divisor is undefined (it can be any arbitrarily large number), 
but we can define it to be zero. Which gives us a simple rule: if one of the 
numbers is zero, the greatest common divisor is the other number.

The Euclidean algorithm, discussed below, allows to find the greatest common divisor 
of two numbers a and b in O(logmin(a,b)).

While the Euclidean algorithm calculates only the greatest common divisor (GCD) of two 
integers a and b, the extended version also finds a way to represent GCD in terms 
of a and b, i.e. coefficients x and y

for which:
a*x+b*y=gcd(a,b)

It's important to note, that we can always find such a representation, for instance gcd(55,80)=5
therefore we can represent 5 as a linear combination with the terms 55 and 80: 55*3+80*(−2)=5
*/
//============================================================================
#include <iostream>
#include <tuple>
using namespace std;

int gcd (int a, int b) {
    int temp;
    while (b) {
        a %= b;
        temp = a;
        a = b;
        b = temp;
    }
    return a;
}

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main() {
	int num1,num2;
	int x,y;
	cout<<"Enter two number: ";
    cin>>num1>>num2;
    cout<<"Euclidean GCD: "<<gcd(num1,num2)<<"\n";
    cout<<"Extended Euclidean GCD: "<<gcd(num1,num2,x,y)<<" coefficients x: "<<x<<" and y: "<<y;
}