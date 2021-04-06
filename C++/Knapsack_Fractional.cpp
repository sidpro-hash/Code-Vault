//============================================================================
// Name        : Knapsack_Fractional.cpp
// Author      : SidPro
// Version     : 1.0
// Description : Fractional Knapsack Problem
// https://www.geeksforgeeks.org/fractional-knapsack-problem/
//============================================================================

#include <iostream>
using namespace std;

double fractionalKnapsack(int W, int val[],int wt[], int n){
    int curWeight = 0;  // Current weight in knapsack
    double finalvalue = 0.0; // Result (value in Knapsack)
    // Looping through all Items
    for(int i = 0; i < n; i++){
        if(curWeight + wt[i] <= W){
            curWeight += wt[i];
            finalvalue += val[i];
        }
        else{
            int remain = W - curWeight;
            finalvalue += val[i] * ((double) remain / wt[i]);
            break;
        }
    }
    return finalvalue;
}

// driver program to test above function
int main()
{
    int W = 50;   //    Weight of knapsack
    int val[] = {60,80,10};
    int wt[] = {10,20,40};
    int temp=0,mid;
    bool swap;
    int n = sizeof(val) / sizeof(val[0]);
    for(int i=0;i<n-1;i++){
    	double d1 = (double)val[i]/wt[i];
    	swap=false;
    	for(int j=i+1;j<n;j++){
    		double d2 = (double)val[j]/wt[j];
    		if(d1<d2){
    			temp=j;
    			swap=true;
    		}
    	}
    	if(swap){
    		mid = val[i];
    		val[i] = val[temp];
    		val[temp] = mid;
    		mid = wt[i];
    		wt[i] = wt[temp];
    		wt[temp] = mid;
    	}
    }
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, val,wt, n);
    return 0;
}
