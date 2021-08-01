//============================================================================
// Name        : Maximum Production.cpp
// Author      : SidPro
// Version     : 1.0
// Description :
//============================================================================
#include<iostream>
#include<cmath>
using namespace std;

#define FAST ios_base::sync_with_stdio(false), cin.tie(0),cout.tie(0);
//endl flushes output and forces data being written to disk. And this can significantly slow your program if you are doing this a lot.
#define endl "\n"

int main(){
    FAST
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;++i){
		int d,x,y,z;
		cin>>d>>x>>y>>z;
		
		x = x*7;
		y = d*y+(7-d)*z;
		cout<<max(x,y)<<"\n";
	}

    return 0;
}