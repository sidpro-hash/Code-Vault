//============================================================================
// Name        : Maximize Number of 1s.cpp
// Author      : SidPro
// Version     : 1.0
// Description :
/*
Maximize Number of 1's

Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.
*/
//============================================================================


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        // Left and right indexes of current window
        int wL = 0, wR = 0; 
        // Left index and size of the widest window 
        int bestL = 0, bestWindow = 0; 
        // Count of zeroes in current window
        int zeroCount = 0; 
        // While right boundary of current window doesn't cross 
        // right end
        while (wR < n){
            // If zero count of current window is less than m,
            // widen the window toward right
            if (zeroCount <= m){
                if (arr[wR] == 0)zeroCount++;
                wR++;
            }
            // If zero count of current window is more than m,
            // reduce the window from left
            if (zeroCount > m){
                if (arr[wL] == 0)zeroCount--;
                wL++;
            }
            // Updqate widest window if this window size is more
            if ((wR-wL > bestWindow) && (zeroCount<=m)){
                bestWindow = wR-wL;
                bestL = wL;
            }
        }
        return bestWindow;
    }  
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends