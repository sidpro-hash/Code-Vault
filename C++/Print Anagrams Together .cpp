//============================================================================
// Name        : Print Anagrams Together.cpp
// Author      : SidPro
// Version     : 1.0
// Description :
/*
Print Anagrams Together

Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.
Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output: 
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
*/
//============================================================================

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

vector<vector<string> > Anagrams(vector<string>& list) 
{
    // Your Code Here
    int n = list.size();
    vector<vector<string>> v;
    string temp = "";
    map<string, int> m;
    int k =0;
    
    for(int i=0;i<n;++i){
        temp = list[i];
        sort(temp.begin(),temp.end());
        auto itr = m.find(temp);
        if(itr==m.end()){
            m.insert({temp,k});
            vector<string> v1;
            v1.push_back(list[i]);
            v.push_back(v1);
            ++k;
        }
        else{
            v[itr->second].push_back(list[i]);
        }
    }
    
    return v;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends