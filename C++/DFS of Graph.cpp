/*
DFS of Graph
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    bool visited[V];
	    vector<int> res;
	    for(int i=0;i<V;++i)visited[i]=false;
	    dfsutil(adj,0,visited,res);
	    return res;
	}
	void dfsutil(vector<int> adj[],int S,bool visited[],vector<int> &res){
	    visited[S]=true;
	    res.push_back(S);
	    for(auto i=adj[S].begin();i!=adj[S].end();++i)
	        if(visited[*i]==false)
	            dfsutil(adj,*i,visited,res);
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
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends