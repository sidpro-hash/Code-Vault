//============================================================================
// Name        : Diffie_Hellman.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*
this is public-key cryptography and is generally
referred to as Diffie-Hellman key exchange

The purpose of the algorithm is to enable two users to securely exchange a
key that can then be used for subsequent symmetric encryption of messages. The
algorithm itself is limited to the exchange of secret values

For any integer b and a primitive root a of prime number p, we can find a
unique exponent i such that
b = a^i (mod p) where 0 <=i<=(p - 1)
The exponent i is referred to as the discrete logarithm of b for the base a, mod p.
We express this value as dloga,p(b).

*/
//============================================================================
#include <iostream>
#include <cmath>
using namespace std;


// Power function to return value of a^b(mod q)
long long int power(long long int a, long long int b,long long int q){
    if (b == 1)return a;
    else return (((long long int)pow(a, b)) % q);
}

int main() {
    //there are two publicly known numbers: a prime number q and an integer a that is a primitive root of q. 
	//Suppose the users A and B wish to create a shared key.
    long long int a=2,q=11;
    
	// Alice generates a private key XA such that XA<q
	long long int XA=8,YA,KA;
	//Alice calculates a public key YA = a^XA mod q
	YA = power(a,XA,q);
	
	
	// Bob generates a private key XB such that XB<q
	long long int XB=4,YB,KB;
	// Bob calculates a public key YB = a^XB mod q
	YB = power(a,XB,q);
	
	// Alice receives Bob’s public key YB in plaintext
	// Alice calculates shared secret key K = YB^XA mod q
	KA = power(YB,XA,q);
	
	// Bob receives Alice’spublic key YA in plaintext
	// Bob calculates shared secret key K = YA^XB mod q
	KB = power(YA,XB,q);
	
	/*
	above two calculations produce identical results:
    K = (YB)^XA mod q
      = (a^XB mod q)^XA mod q
      = (a^XB)^XA mod q by the rules of modular arithmetic
      = a^(XB*XA) mod q
      = (a^XA)^XB mod q
      = (a^XA mod q)^XB mod q
      = (YA)^XB mod q
     The result is that the two sides have exchanged a secret value
	
	*/
	cout<<"Secret key for the Alice is : "<<KA<<"\n";
    cout<<"Secret Key for the Bob is : "<<KB<<"\n";
    cout<<"Two sides have exchanged a secret key";
    
	return 0;
}