// C++ program to generate binary numbers from 1 to n

#include<iostream>
#include<queue>
using namespace std;

// This function uses queue data structure to print binary
// numbers
void generateBinary(int n){
	// Create an empty queue of strings
	queue<string> q;
	// Enqueue the first binary number
	q.push("1");
	
	
	for(int i=0;i<n;++i){
		string s1 = q.front();
		q.pop();
		cout<<s1<<"\n";
		// Store s1 before changing it
		string s2 = s1;
		// Append "0" to s1 and enqueue it
		q.push(s1.append("0"));
		// Append "1" to s2 and enqueue it. Note that s2
        // contains the previous front
		q.push(s2.append("1"));
	}
}

// Driver program to test above function
int main(){
    int n = 10;
    generateBinary(n);
    return 0;
}