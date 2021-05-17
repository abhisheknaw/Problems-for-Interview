/*
Method 1 :- 2 pointers 
Complexity Analysis :
Time complexity: O(n) Single iteration on n element array.
Space complexity: O(1) extra space.
*/
int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int maxi=0;
        if(n==0)
            return count;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                count=count+1;
                maxi=max(maxi,count);
            }
            else
            {
                count=0;
            }
        }
        return maxi;
        
    }