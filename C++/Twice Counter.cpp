//============================================================================
// Name        : Twice Counter.cpp
// Author      : SidPro
// Version     : 1.0
// Description :
/*
Twice Counter
Given a list of N words. Count the number of words that appear exactly twice in the list.
*/
//============================================================================

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int countWords(string list[], int n)
        {
           //code here.
           unordered_map<string, int> m;
            for (int i = 0; i < n; i++)
                m[list[i]] += 1;
         
            int res = 0;
            for (auto it = m.begin(); it != m.end(); it++)
                if ((it->second == 2))
                    res++;
         
            return res;
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
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;    
        cout <<ob.countWords(list, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends