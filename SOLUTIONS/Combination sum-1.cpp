/*
Method : Backtracking              Verdict : Accepted
Complexity Analysis:
Time Complexity: O(k * 2^N).
where k is the average length of each possible solution. Copying such a possible solution list takes O(k) time.
Space Complexity: O(2^N).
Since each element is used only once (use it or not), intuitively we would say the size of the solution space is at most 2^N. Also, it can be interpreted as the sum of C(n, k) (which is 2^N) where k = 0...n is the size of the solution list.
If we do not consider the result list, the space complexity is bounded by O(N) because of at most N-size recursion stack and N-size of when copying list.
*/
class Solution {
public:
    void subset(int index,vector<int>&ds,vector<vector<int>>&ans,vector<int>&candidates,int target)
    {
        if(index==candidates.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        
        if(candidates[index]<=target)
        {
            ds.push_back(candidates[index]);
            subset(index,ds,ans,candidates,target-candidates[index]);
            ds.pop_back();
        }
        subset(index+1,ds,ans,candidates,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        vector<int>ds;
        vector<vector<int>>ans;
        subset(index,ds,ans,candidates,target);
        return ans;
    }
};