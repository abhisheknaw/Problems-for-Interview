/*
TC: N*O(2^n) 2^N beacuse of 2^N recursion calls and N*O(2^N) beacause we are inserting our ans in a resultant vector here ans
SC: O(2^n)*O(k) 2^N length of our ans vector and k is the average length of each subset
*/
class Solution {
public:
    void func(int index,vector<int>&ds,set<vector<int>>&ans,vector<int>&nums)
    {
        if(index==nums.size())
            ans.insert(ds);
        else
        {
            ds.push_back(nums[index]);
            func(index+1,ds,ans,nums);
            ds.pop_back();
            func(index+1,ds,ans,nums);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int index=0;
        vector<int>ds;
        set<vector<int>>ans;
        vector<vector<int>>ans1;
        sort(nums.begin(),nums.end());
        func(index,ds,ans,nums);
        for(auto it:ans)
        {
            ans1.push_back(it);
        }
        return ans1;
    }
};