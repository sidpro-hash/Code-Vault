/*
Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.
*/
class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        if(n==0 || n==1)return;
        int i = n-2;
        while(i>=0 && nums[i]>=nums[i+1])--i;
        if(i>=0){
            int j =n-1;
            while(nums[j]<=nums[i])--j;
            swap(nums,i,j);
        }
        reverse(nums,i+1,n-1);
    }
    public void swap(int[] nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public void reverse(int[] nums,int i,int j){
        while(i<j)swap(nums,i++,j--);
    }
}