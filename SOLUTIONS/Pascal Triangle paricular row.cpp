#include <bits/stdc++.h>
using namespace std;

void printRow(int n)
{
	int prev=1;

	cout<<prev;

	for(int i=1;i<=n;i++)
	{
		int curr=(prev*(n-i+1))/i;
		cout<<","<<curr;
		prev=curr;
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
	printRow(n);
	return 0;
}
