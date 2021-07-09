//============================================================================
// Name        : Playfair Cipher.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 
/*

The Playfair algorithm is based on the use of a 5 * 5 matrix of letters constructed
using a keyword.


*/
//============================================================================

#include<iostream>
#include<cstring>
#include <cctype>
using namespace std;

// 5 * 5 matrix of letters constructed using a key
void assign_matrix(char matrix[][5],string key){
	int n = key.length(),j=0,i=0;

	bool arr[26] = {true};
	char ch[26];
	memset(arr,true,sizeof(arr));
	
	for(i=0;i<n;++i){
		ch[i]=key[i];
		int t = key[i] - 'a';
		arr[t]=false;
	}
	j=i;
	for(int i=0;i<26;++i){
		if(arr[i]){
			arr[i]=false;
			char temp='a'+i;
			if(temp=='j')continue;
			ch[j]=temp;
			++j;			
		}
	}
	int t=0;
	for(i=0;i<5;++i){
		for(j=0;j<5;++j){
			matrix[i][j]=ch[t];
			++t;
		}
	}
}
//in st ru me nt s ->length = 11;
//01 23 45 67 89 10 
string Playfair_Cipher_encryption(char matrix[][5],string message){
	string origin = message;
	int n = message.length();
	int k=0;
	string ency="";
	bool is_odd = false;
	
	// check odd?
	if(n%2!=0){
		is_odd=true;
	}

	
	while(true){
		//on the spot change 'j' to 'i'
		if(k<n && message[k]=='j'){
			message[k]='i';
			if(k+1<n && message[k+1]=='j')
				message[k+1]='i';
		}
		else if(k+1<n && message[k+1]=='j'){
			message[k+1]='i';
			if(k+2<n && message[k+2]=='j')
				message[k+2]='i';
		}
		// both character is same
		else if(message[k]==message[k+1]){
			string temp1 = message.substr(0,k+1);
			string temp2 = message.substr(k+1);
			if(message[k]!='x'){
				message = temp1 + 'x' + temp2;
				n= message.length();
				if(n%2!=0){
					is_odd=true;
				}else{is_odd=false;}
			}
			else{
				message = temp1 + 'z' + temp2;
				n= message.length();
				if(n%2!=0){
					is_odd=true;
				}else{is_odd=false;}
			}
		}
		// at last,if length is odd than add 'z' if it is not last character.
		else if(is_odd && k==n-1){
			if(message[n-1]!='z')message+='z';
			else message+='x';
			n=message.length();
		}
		else{
			int x1,y1,x2,y2;
			for(int i=0;i<5;++i){
				for(int j=0;j<5;++j){
					if(message[k]==matrix[i][j]){
						x1=i;
						y1=j;
					}
					if(message[k+1]==matrix[i][j]){
						x2=i;
						y2=j;
					}
				}
			}
			
			// both letter in same column
			if(y1==y2){
				ency+=matrix[((x1+1)%5)][y1];
				ency+=matrix[((x2+1)%5)][y1];
			}
			// both letter in same row
			else if(x1==x2){
				ency+=matrix[x1][((y1+1)%5)];
				ency+=matrix[x1][((y2+1)%5)];
			}
			// if above is not true
			else{
				ency+=matrix[x1][y2];
				ency+=matrix[x2][y1];
			}
			k+=2;
		}
		if(k>=n)break;
	}
	return ency;
}

string Playfair_Cipher_decryption(char matrix[][5],string message){
	int x1,y1,x2,y2,k=0;
	string ency="";
	int n = message.length();
	while(true){
		for(int i=0;i<5;++i){
			for(int j=0;j<5;++j){
				if(message[k]==matrix[i][j]){
					x1=i;
					y1=j;
				}
				if(message[k+1]==matrix[i][j]){
					x2=i;
					y2=j;
				}
			}
		}
		
		// both letter in same column
		if(y1==y2){
			ency+=matrix[((x1-1)<0?(x1-1+5):(x1-1))][y1];
			ency+=matrix[((x2-1)<0?(x2-1+5):(x2-1))][y1];
		}
		// both letter in same row
		else if(x1==x2){
			ency+=matrix[x1][((y1-1)<0?(y1-1+5):(y1-1))];
			ency+=matrix[x1][((y2-1)<0?(y2-1+5):(y2-1))];
		}
		// if above is not true
		else{
			ency+=matrix[x1][y2];
			ency+=matrix[x2][y1];
		}
		k+=2;
		if(k>=n)break;
	}
	return ency;
}

int main(){
	char matrix[5][5];
	string key = "monarchy";
	string s;
	cout<<"Enter Message: ";
	getline(cin,s);
	
	assign_matrix(matrix,key);
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
	string p = Playfair_Cipher_encryption(matrix,s);
	cout<<"Playfair_Cipher_encryption: "<<p<<"\n";
	cout<<"Playfair_Cipher_decryption: "<<Playfair_Cipher_decryption(matrix,p);
	return 0;
}