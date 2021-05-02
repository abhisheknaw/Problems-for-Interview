#include <bits/stdc++.h>
using namespace std;

void rotate(int *a,int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=c-1;j>=0;j--)
		{
			cout<<*(a+j*c+i)<<" ";
		}
		cout<<endl;
	}
}

//time compexity O(r*c) space O(r*c)
/*void rotate(int *a,int r,int c)
{

	int a1[r][c];

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			a1[j][r-1-i]= *(a+i*c+j);
		}
	}

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<a1[i][j]<<" ";
		}
		cout<<endl;
	}
}*/

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
	
	int r,c,x;
	cin>>r>>c;

	int a[r][c];

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}

	rotate((int *)a,r,c);
	//reverse((int*)a,r,c);
	return 0;
}