/* Search in Rotated Sorted Array 

Logic Explanation:

    Core Observation - As we are are given a sorted and rotated array, it is guranteed that either 1/2 of the array is going to be sorted (If you aren't getting this try taking different combinations of provided example array)
    Now our first job is to find that sorted half. To do this we can do a simple comparison of mid (mid = (low+high)/2) element with the starting element (low) of the array.
    Comparison (do this with pen and paper in hand)
        if(nums[mid] >= nums[low]) -> the left half of array is sorted.
        else -> the right half of array is sorted.
    Now if left half of array is sorted:
        check if provided target element lies in the range [low, mid).
        If it does then update high = mid-1 (hence skipping the part present on right of mid).
        else update low = mid+1 (hence skipping the part present on left of mid)
    else as the right array is sorted:
        check if provided target element lies in the range (mid, high].
        If it does then update low = mid+1 (hence skipping the part present on left of mid).
        else update high = mid-1 (hence skipping the part present on right of mid)
    If still not found then return -1 (duh!)


*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            
            if(nums[mid]>=nums[low]){
                //left half is sorted
                if(target>=nums[low] && target<nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else{
                //right half is sorted
                if(target>nums[mid] && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};
