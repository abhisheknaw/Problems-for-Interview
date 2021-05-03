#include <bits/stdc++.h>
using namespace std;
/*Brute force
Time Complexity: O(N*N), We will find the xor of all the subarray and count all subarray with xor equal to k.
Space Complexity: O(1), No extra space required.
*/
/*
int count(vector<int>&nums,int target)
{
	int count=0;

	int n=nums.size();
	for(int i=0;i<n;i++)
	{
		int xorsum=0;
		for(int j=i;j<n;j++)
		{
			xorsum=xorsum^nums[j];

			if(xorsum==target)
				count++;
		}
	}

	return count;
}
*/




/*
 Hashing and using equation                                    
Complexity Analysis:
Time Complexity: O(N), as use of good hashing function will allow insertion and retrieval operations in O(1) time.
Space Complexity: O(N), for the use of extra space to store the prefix array and hashmap.
*/


/*
Intution : - Here we will use a equal (Y = X ^ K).
https://www.youtube.com/watch?v=lO9R5CaGRPY&t=1s
*/

int count(vector<int> &nums,int target)
{
	int prefix_xor=0;
	int count=0;
	unordered_map<int,int>mpp;
	int n=nums.size();

	for(int i=0;i<n;i++)
	{
		prefix_xor=prefix_xor^nums[i];

		if(prefix_xor==target)
		{
			count++;
		}

		else
		{
			if(mpp.find(prefix_xor ^ target) != mpp.end())
			{
				count += mpp[prefix_xor^target];
			}
			else
			{
				mpp[prefix_xor] += 1;
			}
		}
	}
	return count;
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
	vector<int>nums;


	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		nums.push_back(x);

	}

	int ans=count(nums,target);
	cout<<ans;

	return 0;
}