#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>nums,int target)
{
	vector<vector<int>>res;
	if(nums.empty())
		return res;

	int n=nums.size();

	sort(nums.begin(),nums.end());
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int target2 = target-nums[i]-nums[j];
			int front= j+1;
			int back= n-1;

			while(front < back)
			{
				int sum = nums[front] +nums[back];

				if(sum<target2)
					front++;
				
				else if(sum>target2)
					back--;

				else
				{
					vector<int>quad(4,0);
					quad[0]=nums[i];
					quad[1]=nums[j];
					quad[2]=nums[front];
					quad[3]=nums[back];

					res.push_back(quad);

					while(front<back && nums[front]==quad[2])
						front++;

					while(front<back && nums[back]==quad[2])
						back--;

				}
			}

			while(j+1<n && nums[j+1]==nums[j])
				j++;
		}
		while(i+1<n && nums[i+1]==nums[i])
			i++;
	}
	return res;
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
	int target,n;
	cin>>n>>target;

	vector<int>nums;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		nums.push_back(x);
	}


	vector<vector<int>> ans=fourSum(nums,target);

	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}