//Kadane's Algorithm 

//Expected Time Complexity: O(N)
//Expected Auxiliary Space: O(1)

int maxSubarraySum(int arr[], int n){
        
        int maxsum = 0,cur=0;
        for(int i=0;i<n;++i){
         cur += arr[i];
         if(maxsum<cur)maxsum=cur;
         if(cur<0)cur=0;
            
        }
        return maxsum;
    }
