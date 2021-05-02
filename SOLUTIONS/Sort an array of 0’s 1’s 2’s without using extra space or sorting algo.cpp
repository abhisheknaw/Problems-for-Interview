#include <bits/stdc++.h>
using namespace std;

void soRt(int arr[], int n)
{
	int low=0,mid=0,high=n-1;

	while(mid<=high)
	{
		switch (arr[mid]) 
		{

		case 0:
		swap(arr[low++], arr[mid++]);
		break;

		case 1:
		mid++;
		break;

		case 2:
		swap(arr[mid], arr[high--]);
		break;

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
	cout<<"AFTER SORTING"<<endl;
	soRt(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
