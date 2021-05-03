#include <bits/stdc++.h>
using namespace std;
/*
Complexity Analysis:
Time Complexity: O(N), as use of good hashing function will allow insertion and retrieval operations in O(1) time.
Space Complexity: O(N), for the use of extra space to store the prefix array and hashmap.
*/

/*
Key idea is suppose you got sum equal to 5 at any index suppose at 3 not again after adding some element you
again got sum equal to 5 suppose at index 10 then its mean between index 4 to 10 there exist a subarray whose
sum is zero.
And its size will be 10 -3 = 7
*/

int sub(vector<int> &nums)
{
	int sum=0;
	int maxi=INT_MIN;
	int n=nums.size();
	unordered_map<int,int> mpp;

	for(int i=0;i<n;i++)
	{
		sum=sum+nums[i];

		if(sum==0)
		{
			maxi=i+1;
		}

		else
		{
			if(mpp.find(sum) != mpp.end())
			{
				maxi = max(maxi,i-mpp[sum]);
			}

			else
			{
				mpp[sum]=i;
			}
		}
	}


	return maxi;
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

	int n;
	cin>>n;

	vector<int>nums;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		nums.push_back(x);
	}

	int c= sub(nums);

	if(c<0)
		cout<<"0";
	else
		cout<<c;
	return 0;
}
