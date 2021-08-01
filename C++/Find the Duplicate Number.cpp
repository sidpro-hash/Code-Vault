//============================================================================
// Name        : Maximum Production.cpp
// Author      : SidPro
// Version     : 1.0
// Description :
/*
Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/
//============================================================================

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        fast = nums[0];
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};