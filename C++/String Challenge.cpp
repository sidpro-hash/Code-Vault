
// 'Ctrl +' to increase font size
// 'Ctrl -' to decrease font size
// 'Ctrl 0' to Reset Font size
// 'Ctrl Alt h' for more help


// Sample code to perform I/O:

#include <iostream>

using namespace std;

string StringChallenge(string s){
    int n = s.length();
	string ans = "";
	for(int i=1;i<n;++i){
	    if(s[i-1]=='0'){
	        ans+='0';
	    }else{
	        ans+=s[i-1];
	        bool p1 = (s[i-1]-'0')%2==0?true:false;
	        bool p2 = (s[i] - '0')%2==0?true:false;
	        if(p1 && p2){
	            ans+='*';
	        }
	        else if(!p1 && !p2){
	            ans+='-';
	        }
	    }
	}
	ans+=s[n-1];
	return ans;
}


int main() {
	string s = "";
	cin>>s;
	cout<<StringChallenge(s);
	return 0;
}


// Write your code here