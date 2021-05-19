#include <bits/stdc++.h>
using namespace std;

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

	int n,amount,count=0;
	cin>>n>>amount;

	vector<int>deno(n);

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		deno.push_back(x);
	}

	sort(deno.begin(),deno.end(),greater<int>());

	for(int i=0;i<n;i++)
	{
		count+= amount/deno[i];
		amount=amount%deno[i];
	}
	cout<<count;
	return 0;
}