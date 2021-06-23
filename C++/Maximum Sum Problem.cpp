/*

A number n can be broken into three parts n/2, n/3 and n/4 (consider only integer part). Each number obtained in this process can be divided further recursively. Find the maximum sum that can be obtained by summing up the divided parts together.
Note: The maximum sum may be obtained without dividing n also.

Input:
n = 12
Output: 13
Explanation: Break n = 12 in three parts
{12/2, 12/3, 12/4} = {6, 4, 3}, now current
sum is = (6 + 4 + 3) = 13. Further breaking 6,
4 and 3 into parts will produce sum less than
or equal to 6, 4 and 3 respectively.

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
            int dp[n+1];
 
            // base conditions
            dp[0] = 0, dp[1] = 1;
         
            // Fill in bottom-up manner using recursive
            // formula.
            for (int i=2; i<=n; i++)
               dp[i] = max(dp[i/2] + dp[i/3] + dp[i/4], i);
         
            return dp[n];
        }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
