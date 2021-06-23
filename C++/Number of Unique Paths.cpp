/*
Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].


Input:
A = 2, B = 2
Output: 2
Explanation: There are only two unique
paths to reach the end of the matrix of
size two from the starting cell of the
matrix.

*/


// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++
/* Note the count can also be calculated using the 
formula (m-1 + n-1)!/(m-1)!(n-1)!.  */
class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int arr[a][b];
        
        for(int i=0;i<a;++i)
            arr[i][0]=1;
            
        for(int j=0;j<b;++j)
            arr[0][j]=1;
            
        for(int i=1;i<a;++i){
            for(int j=1;j<b;++j){
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        return arr[a-1][b-1];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends
