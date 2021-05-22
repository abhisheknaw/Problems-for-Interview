/*
TC: N*O(2^n) 2^N beacuse of 2^N recursion calls and N*O(2^N) beacause we are inserting our ans in a resultant vector here ans
SC: O(2^n)*O(k) 2^N length of our ans vector and k is the average length of each subset
*/
class Solution {
public:
    void func(int index,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(index==nums.size())
        {
            ans.push_back(ds);
        }
        else
        {
            ds.push_back(nums[index]);
            func(index+1,ds,ans,nums);
            ds.pop_back();
            func(index+1,ds,ans,nums);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        vector<int>ds;
        vector<vector<int>>ans;
        func(index,ds,ans,nums);
        return ans;
    }
};