#include <bits/stdc++.h>
using namespace std;

/*
Complexity Analysis
Time complexity : O(N).
Although the time complexity appears to be quadratic due to the while loop nested within the for loop,
closer inspection reveals it to be linear. Because the while loop is reached only when 'num' marks the
beginning of a sequence (i.e. 'num'-1 is not present in nums), the while loop can only run for N iterations
throughout the entire runtime of the algorithm. This means that despite looking like O(N*N) complexity, the
nested loops actually run in O(N + N) = O(N) time. All other computations occur in constant time, so the overall
runtime is linear.
Space complexity : O(N).
In order to set up O(1) containment lookups, we allocate linear space for a hash table to store the O(N) numbers
in nums. Other than that, the space complexity is identical to that of the brute force solution.
*/

int longest(vector<int> &nums)
{
	int n=nums.size();

	unordered_set<int> hashset(nums.begin(),nums.end());
	int max=0;

	for(int num:hashset)
	{
		if(hashset.find(num-1) == hashset.end())
		{
			int curr_max=1;
			int temp=num;


			while(hashset.find(temp+1) != hashset.end())
			{
				curr_max += 1;
				temp += 1;
			}

			if(curr_max>max)
				max=curr_max;
		}

	}
	return max;
}



/*
Complexity Analysis
Time complexity : O(N*Log(N)).
The main for loop does constant work N times, so the algorithm's time complexity is dominated by the invocation
of sort, which will run in  O(N*Log(N)) time for any sensible implementation.
Space complexity : O(1) or O(N).
For the implementations provided here, the space complexity is constant because we sort the input array in place. 
If we are not allowed to modify the input array, we must spend linear space to store a sorted copy.
*/


/*int longest(vector<int> &nums)
{
	sort(nums.begin(),nums.end());
	int n=nums.size();

	int max=0,curr_max=1;

	for(int i=0;i<n-1;i++)
	{
		if(nums[i]+1==nums[i+1])
		{
			curr_max++;
		}

		if(nums[i]+1 != nums[i+1])
		{
			curr_max=1;
		}

		if(curr_max>max)
		{
			max=curr_max;
		}
	}
	return max;
}
*/
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

	vector<int> nums;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		nums.push_back(x);
	}

	int ans=longest(nums);
	cout<<ans;

	return 0;
}