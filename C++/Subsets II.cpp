/*
Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& S) {
     sort(S.begin(), S.end());
        vector<vector<int>> ret = {{}};
        int size = 0, startIndex = 0;
        for (int i = 0; i < S.size(); i++) {
            startIndex = i >= 1 && S[i] == S[i - 1] ? size : 0;
            size = ret.size();
            for (int j = startIndex; j < size; j++) {
                vector<int> temp = ret[j];
                temp.push_back(S[i]);
                ret.push_back(temp);
            }
        }
        return ret;   
    }
    
};