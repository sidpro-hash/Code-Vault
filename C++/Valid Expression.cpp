// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
    stack<char> st;
    int n = s.length();
    for(int i=0;i<n;++i){
        if(s[i]=='(')st.push('(');
        else if(s[i]=='[')st.push('[');
        else if(s[i]=='{')st.push('{');
        else{
            if(!st.empty() && s[i]==')' && st.top()=='(')st.pop();
            else if(!st.empty() && s[i]==']' && st.top()=='[')st.pop();
            else if(!st.empty() && s[i]=='}' && st.top()=='{')st.pop();
            else return false;
        }
    }
    return true;
}