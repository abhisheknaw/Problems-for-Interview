#include <bits/stdc++.h>
using namespace std;

void convertToNumeric(string str)
{

	int n=str.size();
	int ans=0;
	int j=n-1;
	for(int i=0;i<n;i++)
	{
		int x=str[i]-'A'+1;
		ans= ans+pow(26,j)*x;
		j--;
	}
	cout<<ans;
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

	string str;
	getline(cin,str);

	convertToNumeric(str);
	return 0;
}