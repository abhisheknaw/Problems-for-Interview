#include <bits/stdc++.h>
using namespace std;

/*Complexity Analysis:
Time complexity : O(N) We traverse the list containing N elements only once. Each look up in the table costs only O(1) time.
Space complexity : O(N) The extra space required depends on the number of items stored in the hash table, which stores at most N elements.
*/
vector<int> twoSum(vector<int> &v,int n,int target)
{
    vector<int>nums;
    unordered_map<int,int>mp;
    for(int i=0;i<v.size();i++)
    {
        if(mp.find(target-v[i])!= mp.end())
        {
            nums.push_back(mp[target-v[i]]);
            nums.push_back(i);
            return nums;
        }
        
        mp[v[i]]=i;
    }
    return nums;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n,target;
	cin>>n>>target;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
	    int x;
	    cin>>x;
		v.push_back(x);
	}

	
	vector<int>ans=twoSum(v,n,target);
	for(int i=0;i<ans.size();i++)
	{
	    cout<<ans[i]<<" ";
	}
	return 0;
}