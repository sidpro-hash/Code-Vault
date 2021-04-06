//============================================================================
// Name        : Knapsack_01.cpp
// Author      : SidPro
// Version     : 1.0
// Description : 0-1 Knapsack Problem
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
//============================================================================

/*
 *
0 0 0 0 0 0 0 0 0
0 0 0 2 2 2 2 2 2
0 0 0 2 3 3 3 5 5
0 0 0 2 3 4 4 5 6
0 0 0 2 3 4 4 5 6

6 :max value of bag.
 *
 */

#include <iostream>
using namespace std;

int max(int a, int b){
    return (a>b)?a:b;
}
int knapSack(int W, int wt[], int val[], int n){
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(wt[i - 1] > w)
                K[i][w] = K[i - 1][w];
            else
                K[i][w] = max(val[i-1] + K[i - 1][w - wt[i-1]],K[i - 1][w]);

            cout<<K[i][w]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
    return K[n][W];
}

int main()
{
    int val[] = {2,3,1,4}; // {item1's value,item2's value,...}
    int wt[] = {3,4,6,5}; //  {item1's weight,item2's weight,..}
    int W = 8; // max weight that bag can carry
    // goal is to maximize value in bag
    int n = sizeof(val)/sizeof(val[0]);
    for(int i=0;i<n-1;i++){
    	if(wt[i]>wt[i+1]){

    		int temp = val[i];
    		val[i] = val[i+1];
    		val[i+1] = temp;

    		temp=wt[i];
    		wt[i]=wt[i+1];
    		wt[i+1] = temp;
    	}
    }

    cout<<knapSack(W, wt, val, n)<<" :max value of bag.";
    return 0;
}






