/*
method 1:
TC : O(n!)* *O(n) for loop
SC : O(n)+O(n) first n for data structure to save current result and another n for freq array
*/
class Solution {
private:
    void permute(vector<int>&ds,vector<vector<int>>&ans,int freq[],vector<int>&nums)
    {
        if(ds.size()==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(freq[i]!=1)
            {
                ds.push_back(nums[i]);
                freq[i]=1;
                permute(ds,ans,freq,nums);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)freq[i]=0;
        permute(ds,ans,freq,nums);
        return ans;
        
    }
};

/*
method 2 : space efficient
TC : O(n!)* *O(n) for loop
SC : O(n) for depth of recursion
*/

class Solution {
private:
    void permute(int index,vector<vector<int>>&ans,vector<int>&nums)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            permute(index+1,ans,nums);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        permute(index,ans,nums);
        return ans;
        
    }
};