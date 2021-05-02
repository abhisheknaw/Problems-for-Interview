#include <bits/stdc++.h>
using namespace std;
int valueAT(int r,int c)
{
	int res=1;
	if(c>r-c)
	{
		c=r-c;
	}
	for(int i=0;i<c;++i)
	{
		res *= (r-i);
		res /= (i+1);
	}
	return res;
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
	int r,c;
	cin>>r>>c;
	int ans= valueAT(r,c);
	cout<<ans;
	return 0;
}

