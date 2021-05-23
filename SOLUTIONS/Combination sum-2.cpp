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
    void func(int index,vector<int>&ds,vector<vector<int>>&ans,int target,vector<int>&a)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<a.size();i++)
        {
            if(i>index && a[i]==a[i-1])continue;
            if(target<a[i])break;
            ds.push_back(a[i]);
            func(i+1,ds,ans,target-a[i],a);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        int index=0;
        sort(candidates.begin(),candidates.end());
        func(index,ds,ans,target,candidates);
        return ans;
        
    }
};