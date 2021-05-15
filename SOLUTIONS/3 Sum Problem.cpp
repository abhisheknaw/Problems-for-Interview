/*
METHOD 2 : 2 pointer and SET 
Complexity Analysis
Time Complexity: O(N*N*log(M)) where M is no of triplet
Space Complexity: O(M).
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>sol;
        set<vector<int>>s;
        int n=nums.size();
        if(n<3)
        {
            return sol;
        }
            
        
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n-2;i++)
        {
            int left=i+1;
            int right=n-1;
            sum=-nums[i];
            while(left<right)
            {
                if((nums[left]+nums[right])<sum)
                {
                    left++;
                }
                    
                else if((nums[left]+nums[right])>sum)
                {
                    right--;
                }
                    
                else
                {
                    s.insert({nums[i],nums[left++],nums[right--]});
                }
            }
        }
        for(auto it:s)
        {
            sol.push_back(it);
        }
            
        
        return sol;
    }
    
};

/*
METHOD 1 : 2 pointer and skipping duplicate 
Complexity Analysis
Time Complexity: O(n*n) Only one traversal of the loop and one traversal to find 2SUM is needed.
Space Complexity: O(1).
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>sol;
        if(nums.size()<3)
            return sol;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int sum=-nums[i];
                int left=i+1;
                int right=nums.size()-1;
                while(left<right)
                {
                    if(nums[left]+nums[right]==sum)
                    {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        sol.push_back(temp);
                        
                        while(left<right && nums[left]==nums[left+1])
                        {
                            left++;
                        }
                        
                        while(left<right && nums[right]==nums[right-1])
                        {
                            right--;
                        } 
                        left++;
                        right--;
                    }
                    else if(nums[left]+nums[right]>sum)
                    {
                        right--;
                    }
                    else
                        left++;
                }
            }
        }
        
        return sol;
    }
    
};