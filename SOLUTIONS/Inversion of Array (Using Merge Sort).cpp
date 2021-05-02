#include <bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int n,int left,int mid,int right)
{
	int inv=0;
	int i=left;
	int j=mid;
	int k=left;

	while(i<=mid-1 && j<=right)
	{
		if(arr[i]<=arr[j])
		{
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
			inv=inv+(mid-i);
		}
	}

	while(i<=mid-1)
	{
		temp[k++]=arr[i++];
	}

	while(j<=right)
	{
		temp[k++]=arr[j++];
	}

	return inv;

}

int mergeSort(int arr[],int temp[],int n,int left,int right)
{
	int inv=0;
	if(left<right)
	{
		int mid=(left+right)/2;
		inv +=mergeSort(arr,temp,n,left,mid);
		inv +=mergeSort(arr,temp,n,mid+1,right);
		inv +=merge(arr,temp,n,left,mid+1,right);
	}
	return inv;
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
	int temp[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int res=mergeSort(arr,temp,n,0,n-1);

	cout<<res;
	return 0;
}