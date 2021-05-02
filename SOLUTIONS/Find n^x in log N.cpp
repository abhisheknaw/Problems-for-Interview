#include <bits/stdc++.h>
using namespace std;
//tc O(log n) sc O(1)
float power(double x,int n)
{
	long long ll=n;
	float ans=1.0;
	float t=1.0;
	
	if(ll<0)
	{
		ll= -1*ll;
	}

	while(ll>0)
	{
		if(ll%2==0)
		{
			ll=ll/2;
			x=x*x;
		}
		else
		{
			ans=ans*x;
			ll=ll-1;
		}

	}

	if(n<0)
	{
		ans= t/ans;
	}

	return ans;

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

	double x;
	int n;
	cin>>x>>n;
	float c=power(x,n);
	cout<<c;
	return 0;
}
