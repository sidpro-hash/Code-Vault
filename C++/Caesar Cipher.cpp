//============================================================================
// Name        : Caesar Cipher.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*
The Caesar cipher involves replacing each letter of the alphabet with the
letter standing three places further down the alphabet.

shift may be of any amount, so that the general Caesar algorithm is
C = E(k, p) = (p + k) mod 26 
where k takes on a value in the range 1 to 25. 
The decryption algorithm is simply
p = D(k, C) = (C - k) mod 26
*/
//============================================================================

#include <iostream>
#include <cctype>
#include <cmath>
#include <string>
using namespace std; 

string Caesar_Cipher_encryption(string message,int k){
	int l = message.length();
	string ency = "";
	for(int i=0;i<l;++i){
		if(message[i]==' '){
			ency+=' ';
			continue;			
		}
		if(isupper(message[i])){
			ency += 'A' + ((message[i] - 'A') + k) % 26;
		}
		else{
			ency += 'a' + ((message[i] - 'a') + k) % 26;
		}
	}
	return ency;
}
string Caesar_Cipher_decryption(string message,int k){
	int l = message.length();
	string ency = "";
	for(int i=0;i<l;++i){
		if(message[i]==' '){
			ency+=' ';
			continue;			
		}
		if(isupper(message[i])){
			int temp = (message[i] - 'A') - k;
			ency += 'A' +  (temp<0?(temp+26):temp)  % 26;
		}
		else{
			int temp = (message[i] - 'a') - k;
			ency += 'a' +  (temp<0?(temp+26):temp) % 26;
		}
	}
	return ency;
}

string Brute_Force_Caesar_Cipher_decryption(string message){
	string dcy="";
	for(int i=0;i<26;++i){
		dcy+="Message: "+Caesar_Cipher_decryption(message,i)+" Key: "+to_string(i)+"\n";
	}
	return dcy;
}

int main(){
	
	string s;
	int key = 19;
	cout<<"Enter Message: ";
	getline(cin,s);
	cout<<"Enter Key: ";
	cin>>key;
	string p = Caesar_Cipher_encryption(s,key);
	cout<<"Caesar_Cipher_encryption :"<<p<<"\n";
	cout<<"Caesar_Cipher_decryption :"<<Caesar_Cipher_decryption(p,key)<<"\n";
	cout<<"Brute_Force_Caesar_Cipher_decryption:\n"<<Brute_Force_Caesar_Cipher_decryption(p);
	system("pause");
	return 0;
}

