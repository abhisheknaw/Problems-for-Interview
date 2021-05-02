#include <bits/stdc++.h>
using namespace std;
//time complexity O(n*n) space O(n*n)
void printPascal(int n)
{

	int pascal[n][n];

	for(int line=0;line<n;line++)
	{
		for(int j=0;j<=line;j++)
		{
			if(line==j || j==0)
				pascal[line][j]=1;

			else
			{
				pascal[line][j]=pascal[line-1][j-1]+pascal[line-1][j];
			}

			cout<<pascal[line][j]<<" ";
		}
		cout<<endl;
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
	int n=5;
	
	printPascal(n);
	return 0;
}