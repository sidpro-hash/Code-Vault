//============================================================================
// Name        : HammingCode.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*
=> 	Hamming code is a block code that is capable of detecting up to 
	two simultaneous bit errors and correcting single-bit errors.

=>	In this coding method, the source encodes the message by inserting redundant bits within the message.
	These redundant bits are extra bits that are generated and inserted at specific positions in the message 
	itself to enable error detection and correction. When the destination receives this message, it performs 
	recalculations to detect errors and find the bit position that has error.

=> 	https://www.geeksforgeeks.org/hamming-code-in-computer-network/
=> 	https://en.wikipedia.org/wiki/Hamming_code
=> 	https://www.tutorialspoint.com/error-correcting-codes-hamming-codes

*/
//============================================================================

/* input - output format
 *
 * Enter Your message here: 10101010100
   Which parity is in even or odd [ e / d ]? e

Bit calculation:
1010101R010R0RR

R1 = 1111000 = 0
R2 = 1010010 = 1
R4 = 1010010 = 1
R8 = 1010101 = 0

Hamming Code: 101010100101010

Reciver Side decoding: 0000
 */


#include <iostream>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<string,int> Sender(string ,char);
void Reciver(string,int, char);

int main() {
	string mesg;
	char parity;
	int r;
	cout<<"Enter Your message here: ";
	cin>>mesg;
	cout<<"Which parity is in even or odd [ e / d ]? ";
	cin>>parity;
	tie(mesg,r)=Sender(mesg,parity);
//	mesg = "10101101110";
	Reciver(mesg,r,parity);
	return 0;
}
tuple<string,int> Sender(string mesg,char parity){
	string midmsg = "22";
	reverse(mesg.begin(),mesg.end());
	int base=2,r,i,j,m = mesg.length();
	for(r=0;r<31;++r){
		if(pow(2,r)>=m+r+1)
			break;
	}
	string redundant[r];
	string redunt[r];
	i=0;
	while(i<m){
		if((i+1+base)==pow(2,base)){
			midmsg+='2';
			++base;
		}
		else{
			midmsg+=mesg[i];
			++i;
		}
	}
	for(j=0;j<r;++j){
		int temp = pow(2,j);
		for(i=temp-1;i<m+r;i=i+temp){
			int k = temp+1;
			while(--k&&i<m+r){
				if(midmsg[i]!='2')
					redundant[j]+=midmsg[i];
				++i;
			}
		}
	}
	for(i=0;i<r;++i){
		redunt[i] = redundant[i];
		reverse(redunt[i].begin(),redunt[i].end());
	}
	if(parity=='e'){
		for(i=0;i<r;++i){
			base = redundant[i].length();
			int count=0;
			for(j=0;j<base;++j){
				if(redundant[i][j]=='1')
					++count;
			}
			if(count%2)
				redundant[i]='1';
			else
				redundant[i]='0';
		}
	}else {
		for(i=0;i<r;++i){
			base = redundant[i].length();
			int count=0;
			for(j=0;j<base;++j){
				if(redundant[i][j]=='1')
					++count;
			}
			if(count%2)
				redundant[i]='0';
			else
				redundant[i]='1';
		}
	}

	j=0;

	string hammesg="";
	for(i=0;i<m+r;++i){
		if(midmsg[i]=='2'){
			midmsg[i] = 'R';
			hammesg+=redundant[j];
			++j;
		}
		else{
			hammesg+=midmsg[i];
		}

	}
	reverse(midmsg.begin(),midmsg.end());
	reverse(hammesg.begin(),hammesg.end());
	cout<<"\n";
	cout<<"Bit calculation: "<<endl;
	cout<<midmsg<<endl;
	cout<<"\n";
	for(i=0;i<r;++i){
		cout<<"R"<<pow(2,i)<<" = "<<redunt[i]<<" = "<<redundant[i]<<endl;
	}
	cout<<"\n";
	cout<<"Hamming Code: "<<hammesg<<endl;
	cout<<"\n";
	return make_tuple(hammesg,r);
}
void Reciver(string mesg,int r,char parity){
	reverse(mesg.begin(),mesg.end());
	int l=mesg.length();
	int i=0,j,base=0;
	string decode="";
	string bits[r];
	for(j=0;j<r;++j){
		int temp = pow(2,j);
		for(i=temp-1;i<l;i=i+temp){
			int k = temp+1;
			while(--k&&i<l){
					bits[j]+=mesg[i];
				++i;
			}
		}
	}
	if(parity=='e'){
			for(i=0;i<r;++i){
				base = bits[i].length();
				int count=0;
				for(j=0;j<base;++j){
					if(bits[i][j]=='1')
						++count;
				}
				if(count%2)
					bits[i]='1';
				else
					bits[i]='0';
			}
		}else {
			for(i=0;i<r;++i){
				base = bits[i].length();
				int count=0;
				for(j=0;j<base;++j){
					if(bits[i][j]=='1')
						++count;
				}
				if(count%2)
					bits[i]='0';
				else
					bits[i]='1';
			}
		}
	for(int i=0;i<r;++i){
		decode+=bits[i];
	}
	reverse(decode.begin(),decode.end());
	cout<<"Reciver Side decoding: ";
	cout<<decode<<endl;
}
