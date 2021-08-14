/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> res;
	    bool visited[V];
	    for(int i=0;i<V;++i)visited[i]=false;
	    queue<int> q;
	    int s = 0;
	    visited[s] = true;
	    q.push(s);
	    while(!q.empty()){
	         s = q.front();
	         res.push_back(s);
	         q.pop();
	         for(auto i=adj[s].begin();i!=adj[s].end();++i){
	             if(visited[*i]==false){
	                 visited[*i] = true;
	                 q.push(*i);
	             }
	         }
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends