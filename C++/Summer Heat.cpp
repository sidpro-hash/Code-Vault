#include<iostream>
#include<cmath>
using namespace std;

// Bella ciao O(n)
/*
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		long long int D,d,P,Q,q=0,result=0;
		cin>>D>>d>>P>>Q;
		if(D>d){
			for(int j=1;j<=D;++j){
				
				result+=q;
				if(j%d==0){
					q=q+Q;
					cout<<"P:"<<P<<" Q:"<<q<<" result:"<<result<<"\n";
				}
			}
			cout<<"P:"<<P<<" Q:"<<q<<" result:"<<result<<"\n";
			cout<<(result + D*P)<<"\n";
		}
		else{
			cout<<(D*P)<<"\n";
		}
	}
	return 0;
}
*/
// Bella ciao O(1)


int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		long long int D,d,P,Q;
		cin>>D>>d>>P>>Q;
		if(D>d){
		long long int result=0,n=0,m=0,k=0,l=0;
		n = floor( (D-d) / d );
		k = n*(n+1)/2;
		m = (D-d) - n*d;
		result = D*P + d*(k*Q);
		if(m!=0)l=m*(n+1)*Q;
		cout<<( result + l )<<"\n";
		}
		else{
			cout<<(D*P)<<"\n";
		}
	}
	return 0;
}



// Summer Heat

/*
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		int xa,xb,Xa,Xb;
		cin>>xa>>xb>>Xa>>Xb;
		cout<<(ceil(Xa/xa) + ceil(Xb/xb))<<"\n";
	}
	return 0;
}
*/