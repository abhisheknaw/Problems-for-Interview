#include <bits/stdc++.h>
using namespace std;
/*
void findDuplicate(int arr[],int n)
{
	sort(arr,arr+n);
	for (int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)                                  //n^2;
		{
			if(arr[i]==arr[j])
			{
				cout<<arr[i]<<" ";
			}
		}
	}
}
*/

void findDuplicate(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[abs(arr[i])] >= 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];                     //0(n)  0(!)
		else
			cout<<abs(arr[i])<<" ";
	}
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
	{
		cin>>arr[i];
	}
	findDuplicate(arr,n);
	return 0;
}
