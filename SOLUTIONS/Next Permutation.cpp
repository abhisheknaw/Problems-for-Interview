#include <bits/stdc++.h>
using namespace std;


//space complexity O(1) time O(n)
void nextPermute(vector<int> &v,int n)
{
	int index,k;

	for(index=n-2;index>=0;index--)
	{
		if(v[index]<v[index+1])
		{
			break;
		}
	}

	if(index<0)
	{
		reverse(v.begin(),v.end());
	}
	else 
	{
		for(k=n-1;k>index;k--)
		{
			if(v[index] < v[k])
			{
				break;
			}
		}

		swap(v[index],v[k]);

		reverse(v.begin()+index+1,v.end());
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

	vector<int> v;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}

	nextPermute(v,n);

	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}	
	return 0;
}
