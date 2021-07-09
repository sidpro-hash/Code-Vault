//============================================================================
// Name        : Vigenère Cipher.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*

polyalphabetic ciphers
is the Vigenère cipher. In this scheme, the set of related monoalphabetic substitution
rules consists of the 26 Caesar ciphers with shifts of 0 through 25. Each cipher is
denoted by a key letter, which is the ciphertext letter that substitutes for the plaintext
letter a.

Thus, the first letter of the key is added to the first letter of the plaintext, mod 26,
the second letters are added, and so on through the first m letters of the plaintext.
For the next m letters of the plaintext, the key letters are repeated. This process
continues until all of the plaintext sequence is encrypted. A general equation of the
encryption process is
						
						C[i] = (p[i] + k[i mod m]) mod 26
						
Similarly, decryption is a generalization of above,
						
						p[i] = (C[i] - k[i mod m]) mod 26

key : deceptive

key    : deceptivedeceptivedeceptive
Message: wearediscoveredsaveyourself
Cipher : zicvtwqngrzgvtwavzhcqyglmgj
*/
//============================================================================

#include<iostream>
#include <cctype>
using namespace std;

string Vigenere_Cipher_encryption(string message,string key){
	int n = message.length(),m = key.length();
	int k=0;
	string ency="";
	for(int i=0;i<n;++i,++k){
		if(message[i]==' '){
			ency+=' ';
			--k;
			continue;			
		}
		ency += 'a' + ( (message[i] -'a') + (key[(k%m)] - 'a') ) % 26;
	}
	return ency;
}

string Vigenere_Cipher_decryption(string message,string key){
	int n = message.length(),m = key.length();
	int k=0,temp;
	string ency="";
	for(int i=0;i<n;++i,++k){
		if(message[i]==' '){
			ency+=' ';
			--k;
			continue;			
		}
		temp = (message[i] -'a') - (key[(k%m)] - 'a');
		ency += 'a' + (temp<0?(temp+26):temp) % 26;
	}
	return ency;
}

int main(){
	//the quick brown fox jumps over the lazy dog
	string s;
	string key="deceptive";
	cout<<"Enter Message: ";
	getline(cin,s);
	string p = Vigenere_Cipher_encryption(s,key);
	cout<<"Vigenere_Cipher_encryption :"<<p<<"\n";
	cout<<"Vigenere_Cipher_decryption: "<<Vigenere_Cipher_decryption(p,key)<<"\n";
	system("pause");
	return 0;
}