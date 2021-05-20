/*
TC:O(2^N+2^Nlog2^N) 2^N because for every single element we have 2 choices whether to take it or not 
and 2^Nlog2^N because of sorting we have to sort the array of 2^N elements
*/
class Solution
{
public:
    void func(int index,int sum,vector<int>&ans,vector<int>&arr,int N)
    {
        if(index==N)
        {
            ans.push_back(sum);
            return;
        }
            
        func(index+1,sum+arr[index],ans,arr,N);
            
        func(index+1,sum,ans,arr,N);
            
            
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum=0;
        int index=0;
        vector<int>ans;
        func(index,sum,ans,arr,N);
        sort(ans.begin(),ans.end());
        return ans;
    }
};