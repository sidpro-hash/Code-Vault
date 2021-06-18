Largest Element in Array

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Given an array A[] of size n. The task is to find the largest element in it.

//User function Template for C++

// C function to find maximum in arr[] of size n
int largest(int arr[], int n) {
    int max = -1;
    for(int i=0;i<n;++i){
        if(max<arr[i])max=arr[i];
    }
    return max;
}