#include <bits/stdc++.h>
using namespace std;

void findMissingAndDuplicate(int arr[],int n)
{

	int i=0;
	while(i<n)
	{
		if(arr[i] != arr[arr[i]-1])
		{
			swap(arr[i],arr[arr[i]-1]);
		}
		else 
		{
			i++;
		}
	}
	for (int k=0;k<n;k++)
	{
		if(arr[k] != k+1)
		{
			cout<<"Duplicate element is :"<<arr[k]<<endl;
			cout<<"Missing element is :"<<k+1<<endl;
		}
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
	findMissingAndDuplicate(arr,n);
	return 0;
}
