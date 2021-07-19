
// Sample code to perform I/O:

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;			// Reading input from STDIN
	//cout << "Input number is " << n << endl;	// Writing output to STDOUT
	//cout<<"\n";
	
	//int rows = n*2 - 1; // total rows
	int cols = n*4 - 3; // total columns
	int mid = cols/2 + 1; // mid is going to be always odd number
	set<int> s; // keep track of allowed columns
	
	//const bool is_in = container.find(element) != container.end();
	string arr="";
	for(int i=0;i<n;++i){
	    int a = n-1;
	    // allow index to print number
	    int left = mid - i*2 -1; 
	    int right = mid + i*2 -1;
	    s.insert(left);
	    s.insert(right);
	    int k =0;
	    int q = 0;
	    string temp = "";
	    for(int j=0;j<cols;++j){
	        
	        
	        char ch;
	        if(s.find(j)!=s.end()){
	            if(k<=i){
	                // just print exact character
	                ch = 'a'+a-k;
	                cout<<ch;
	                temp+=ch; // take backup for future
	                ++k;
	                q=k-1;
	            }
	            else{
	                 // just print exact character
	                --q;
	                ch = 'a'+a-q;
	                cout<<ch;
	                temp+=ch; // take backup for future
	            }
	        }
	        else{
	            cout<<"-";
	            temp+='-';
	        }
	    }
	    
	    if(i<n-1){
	       cout<<"\n";
	        arr+=temp+'\n';
	    }
	}
	reverse(arr.begin(), arr.end());
	cout<<arr;
	return 0;
}


// Write your code here