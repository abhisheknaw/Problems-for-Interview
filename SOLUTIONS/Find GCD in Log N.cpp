#include <bits/stdc++.h>
using namespace std;

// tc O(log n)
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

/*
int gcd(int a,int b)
{
	if(a==0)
		return b;

	if(b==0)
		return a;

	if(a==b)
		return a;

	if(a>b)
		return gcd(a-b,b);

	return gcd(a,b-a);
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

	int a,b;
	cin>>a>>b;
	int c= gcd(a,b);
	cout<<c;
	return 0;
}