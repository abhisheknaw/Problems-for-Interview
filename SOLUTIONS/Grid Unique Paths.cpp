#include <bits/stdc++.h>
using namespace std;
//Combinatorics solution complexity O(max(A,B))

/*
Explaination
for 3*3 we will have something like "RRDD" we can see no 'R' and 'D' of
will always be fixed which can be arranged in as
[4!/(2!*2!)] ways where 'R' and 'D' are repeated twice
or
{[((A-1)+(B-1))!]/[(A-1)! * (B-1)!]} == (A+B-2)C(A-1)
*/
int comb(int N,int k)
{
	int res=1;
	if(k>N-k);
	{
		k=N-k;
	}

	for(int i=0;i<k;i++)
	{
		res= res*(N-i);
		res=res/(i+1);
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

	int N=r+c-2;
	int k=r-1;

	int ans=comb(N,k);
	cout<<ans;
	return 0;
}











// for simple recursion program we have exponential tc and sc but when we memoise it then it becomes row *col
/*int uniquePaths(int row,int col,int m,int n,vector<vector<int>> &dp)
{
	if(m>=row || n>=col)
		return 0;

	if(m==row-1 && n==col-1)
		return 1;

	if(dp[m][n] != -1)
		return dp[m][n];

	else 
		return dp[m][n]= uniquePaths(row,col,m,n+1,dp)+uniquePaths(row,col,m+1,n,dp);

	return 0;

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

	int row,col;
	int m=0,n=0;
	cin>>row>>col;

	vector<vector<int>> dp(row, vector <int> (col,-1));
	

	int a=uniquePaths(row,col,m,n,dp);

	cout<<a;
	return 0;
}*/