#include <bits/stdc++.h>
using namespace std;
int trailingzero(int n)
{
	int count=0;
	while(n>0)
	{
		count =count + (n/5);
		n= n/5;
	}
	return count;
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
	int a=trailingzero(n);
	cout<<a;
	return 0;
}