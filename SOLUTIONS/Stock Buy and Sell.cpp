#include <bits/stdc++.h>
using namespace std;

//time complexity O(n^2) and space complexity O(1)
int maxProfit(int arr[],int n)
{
	int maxPro=0;
	int curr_min=INT_MAX;

	for(int i=0;i<n;i++)
	{
		curr_min=min(arr[i],curr_min);
		maxPro=max(maxPro,arr[i]-curr_min);
	}

	return maxPro;
}

//time complexity O(n^2) for multiple transactions
/*
int maxProfit(int arr[],int start,int end)
{
	int curr_profit=0;
	int profit=0;

	for(int i=start;i<end;i++)
	{
		for(int j=i+1;j<=end;j++)
		{
			curr_profit=arr[j]-arr[i]+maxProfit(arr,start,i-1)+maxProfit(arr,j+1,end);

			profit=max(profit,curr_profit);
		}
	}
	return profit;
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
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int ans=maxProfit(arr,n);
	cout<<ans;
	return 0;
}