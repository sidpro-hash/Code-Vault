//Kadane's Algorithm 

//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(1)

int maxSubarraySum(int arr[], int n){
    int mx = INT_MIN;
    int current=0;
    int k=0;
    int l=0;
    int m=0;
    for(int i=0;i<n;++i){
        current+=arr[i];
        if(current>mx){
            mx=current;
            k=m;
            l=i;
        }
        if(current<0){
            current=0;
            m=i+1;
        }
        
    }
    cout<<"start:"<<k<<" end:"<<l<<endl;
    return mx;
}


