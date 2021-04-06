//============================================================================
// Name        : Coinchange.cpp
// Author      : SidPro
// Version     : 1.0
// Description : Coin change problem
/*

=> 	Given a value N, if we want to make change for N cents, and we have infinite 
	supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we 
	make the change? The order of coins doesn’t matter.

=>	https://www.geeksforgeeks.org/coin-change-dp-7/

=>	Given a value V, if we want to make change for V cents, and we have infinite
	supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum 
	number of coins to make the change?
	
=>	https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

*/
//============================================================================

/* input - output format
 *
       0   1   2   3   4   5   6   7
   1   0   1   2   3   4   5   6   7
   2   0   1   1   2   2   3   3   4
   4   0   1   1   2   1   2   2   3
Minimum number Of Coins required for change is 3

       0   1   2   3
   0   1   0   0   0
   1   1   1   1   1
   2   1   1   2   2
   4   1   1   2   2
Number Of Ways to Make Change is 2
 *
 *
 */

#include <iostream>
#include <iomanip>
using namespace std;

int min(int a, int b){
    return (a<b)?a:b;
}

int Minimum_number_Of_Coins(int coin[],int ncoin,int nchange){
	int Table[ncoin][nchange + 1];
	int i=ncoin,j=nchange;
	for(i=0;i<ncoin;++i)
		Table[i][0]=0;

	for(j=1;j<=nchange;++j)
		Table[0][j]=(j%coin[0]==0)?j/coin[0]:nchange;

	for(i=1;i<ncoin;++i){
		for(j=1;j<=nchange;++j){
			if(coin[i]>j)
				Table[i][j]=Table[i - 1][j];
			else{
				Table[i][j]= min(Table[i - 1][j],1 + Table[i][j - coin[i]]);
			}
		}
	}


	cout<<"    ";
	for(j=0;j<=nchange;++j){
		cout<<setw(4)<<j;
	}
	cout<<"\n";
	for(i=0;i<ncoin;++i){
		cout<<setw(4)<<coin[i];
		for(j=0;j<=nchange;++j){
			cout<<setw(4)<<Table[i][j];
		}
		cout<<"\n";
	}
	return Table[ncoin - 1][nchange];
}

int Number_Of_Ways_to_Make_Change(int coin[],int ncoin,int nchange){
	int Table[ncoin + 1][nchange + 1];
	int i=ncoin,j=nchange;

	for(i=0;i<=ncoin;++i)
		Table[i][0]=1;

	for(j=1;j<=nchange;++j)
		Table[0][j]=0;

	for(i=1;i<=ncoin;++i){
		for(j=1;j<=nchange;++j){
			if(coin[i - 1]>j)
				Table[i][j]=Table[i - 1][j];
			else{
				Table[i][j]= Table[i - 1][j] + Table[i][j - coin[i - 1]];
			}
		}
	}
	cout<<"    ";
	for(j=0;j<=nchange;++j){
		cout<<setw(4)<<j;
	}
	cout<<"\n";
	for(i=0;i<=ncoin;++i){
		if(i>0)cout<<setw(4)<<coin[i-1];
		else cout<<setw(4)<<i;
		for(j=0;j<=nchange;++j){
			cout<<setw(4)<<Table[i][j];
		}
		cout<<"\n";
	}

	return Table[ncoin][nchange];
}

int main(){
//    int arr[] = {1,5,6,9};
    int arr[]={1,2,4};
    int ncoin = sizeof(arr)/sizeof(arr[0]);
//    int nchange = 10;
    int nchange =7;

    cout<<"\n";
    nchange = Minimum_number_Of_Coins(arr,ncoin,nchange);
	cout<<"Minimum number Of Coins required for change is "<<nchange;
	cout<<"\n";
	nchange = Number_Of_Ways_to_Make_Change(arr,ncoin,nchange);
	cout<<"Number Of Ways to Make Change is "<<nchange;
    return 0;
}
