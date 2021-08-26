
// 'Ctrl +' to increase font size
// 'Ctrl -' to decrease font size
// 'Ctrl 0' to Reset Font size
// 'Ctrl q' for more help


// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	string bin1,bin2;
	cin>>bin1;
	cin>>bin2;
	int n = bin1.length();
	int hamming_distance=0;
	for(int i=0;i<n;++i)
	    if(bin1[i]!=bin2[i])
	        ++hamming_distance;
	
	cout<<"hamming_distance:"<<hamming_distance;
	return 0;
}


// Write your code here