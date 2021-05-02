#include <bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n)
{
	int res=INT_MIN,curr_res=0;

	for(int i=0;i<n;i++)
	{
		curr_res=curr_res+arr[i];

		if(res<curr_res)
		{
			res = curr_res;
		}

		if(curr_res<0)
		{
			curr_res=0;
		}
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
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int res=kadane(arr,n);

	cout<<res;
	return 0;
}

