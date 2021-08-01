//============================================================================
// Name        : Repeating and the missing.cpp
// Author      : SidPro
// Version     : 1.0
// Description :
//Find the repeating and the missing
/*
    Let x be the missing and y be the repeating element.
    Let N is the size of array.
    Get the sum of all numbers using formula S = N(N+1)/2
    Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
    Iterate through a loop from i=1….N
    S -= A[i]
    Sum_Sq -= (A[i]*A[i])
    It will give two equations 
    x-y = S – (1) 
    x^2 – y^2 = Sum_sq 
    x+ y = (Sum_sq/S) – (2) 
     

Time Complexity: O(n) 

*/
//============================================================================

#include <bits/stdc++.h>
 
using namespace std;

// return vector 
vector<int>repeatedNumber(const vector<int> &A) {
    long long int len = A.size();
    // Sum_N = 6*7/2 = 21, Sum_NSq = 91
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
    //foe example A = {4,3,6,2,1,1};
    for(int i=0;i<A.size(); i++){
       Sum_N -= (long long int)A[i];
       Sum_NSq -= (long long int)A[i]*(long long int)A[i];
    }
    // now Sum_N = 4, Sum_NSq = 24
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2; // 5
    repeating= missingNumber - Sum_N; // 1
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
     
}
 
 
int main(void){
        std::vector<int> v = {4, 3, 6, 2, 1, 6,7};
    vector<int> res = repeatedNumber(v);
    for(int x: res){
        cout<< x<<"  ";
    }
    cout<<endl;
}

// return array
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        long long int len = n;
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
    
    for(int i=0;i<n; i++){
       Sum_N -= (long long int)arr[i];
       Sum_NSq -= (long long int)arr[i]*(long long int)arr[i];
    }
    
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;
        
        int *ans = new int(2);
        ans[0] = repeating;
        ans[1] = missingNumber;
        return ans;
    }
};