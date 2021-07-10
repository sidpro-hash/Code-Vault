//============================================================================
// Name        : GCD.cpp
// Author      : SidPro
// Version     : 1.0
// Date        : 10/07/2021
// Description : 
/*

unsigned long long int 	8bytes 	0 to 18,446,744,073,709,551,615 ~ 10^19


// built-in functions in GCC compiler

__builtin_ctz(x): This function is used to count the trailing zeros of the given integer.

    Note : ctz = count trailing zeros.Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
    
    @Reference : http://gcc.gnu.org/onlinedocs/gcc-4.5.0/gcc/Other-Builtins.html
    @Reference : https://cp-algorithms.com/algebra/euclid-algorithm.html

Example: Count no of zeros from last to first occurrence of one(set bit).
a = 16
Binary form of 16 is 00000000 00000000 00000000 00010000
Output: ctz = 4

*/
//============================================================================

#include <iostream>
#define ulli unsigned long long int

using namespace std;
int gcd(int a, int b) {
    
    if (!a || !b)
        return a | b;
     
      
    int shift = __builtin_ctz(a | b);

    a >>= __builtin_ctz(a);
 
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    
    return a << shift;
}

int main() {
	int num1,num2;
	cin >> num1>>num2;			// Reading input from STDIN
	cout << "Input number is " << num1  <<" "<<num2<< endl;	// Writing output to STDOUT
    cout<<"GCD: "<<gcd(num1,num2);
    return 0;
}