#include <bits/stdc++.h>
using namespace std;

//time complexity O(m+n)  space complexity O(m+n)

/*
void merges(vector<int> &a,int m,vector<int> &b,int n)
{
	vector<int>sorted;

	int i=0,j=0;
	while(i != m && j != n)
	{
		if(a[i] <= b[j])
		{
			sorted.push_back(a[i]);
			i++;
		}
		else
		{
			sorted.push_back(b[j]);
			j++;
		}
	}

	while(i!=m)
	{
		sorted.push_back(a[i]);
		i++;
	}

	while(j!=n)
	{
		sorted.push_back(b[j]);
		j++;
	}
	a=sorted;
}
*/


//time complexity O(n*m) space complexity O(1)
void merg(int A[],int m,int B[],int n)
{
	for(int i=0;i<m;i++)
	{
		if(A[i]>B[0])
		{
			swap(A[i],B[0]);

			int j=0;

			while(j+1<n && B[j]>B[j+1])
			{
				swap(B[j],B[j+1]);
				j++;
			}
		}
	}

	for(int i=0;i<m;i++)
		cout<<A[i]<<" ";

	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<B[i]<<" ";
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

	int m,n;
	cin>>m>>n;
	int A[m],B[n];

	for(int i=0;i<m;i++)
		cin>>A[i];

	for(int i=0;i<n;i++)
		cin>>B[i];

	merg(A,m,B,n);

}


