#include <bits/stdc++.h>
using namespace std;
/*
 Brute Force                               
Complexity Analysis:
Time Complexity: O(N^3). We will genrate all substring and check for Longest Substring Without Repeating Characters.
Space Compelxity: O(1), No extra space required.
*/
/*
bool areDistinct(string str,int i,int j)
{

	vector<bool>visited(26);

	for(int k=i;k<=j;k++)
	{
		if(visited[str[k]-'a']==true)
			return false;
		visited[str[k]-'a']=true;
	}
	return true;
}

int length(string str)
{
	int n=str.size();

	int res=0;

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(areDistinct(str,i,j))
			{
				res=max(res,j-i+1);
			}
		}
	}
	return res;
}
*/

/*                              
Complexity Analysis:
Time Complexity: O(2 N) 
Space Compelxity: O(N), No extra space required.
*/
/*
int length(string str)
{
	int n= str.length();
	unordered_set<char>m;
	int len=0;

	int l=0;
	int r=0;

	while(r<n)
	{
		if(m.find(str[r]) != m.end())
		{
			m.erase(str.at(l));
			l++;
			
		}
		else
		{
			m.insert(str[r]);
			len=max(len,r-l+1);
			r++;
			
		}
	}
	return len;
}
*/

  
/*
 Sliding Window Optimized(Single pass)                           verdict : Accepted
Complexity Analysis:
Time Complexity: O(N). In the worst case each character will be visited only once by the window.
Space complexity : constant space
*/
int length(string str)
{
	int n=str.size();
	int l=0;
	int r=0;
	int le=0;
	vector<int> c(256,-1);
	while(r<n)
	{
		if(c[str[r]] != -1)
			l= max(c[str[r]]+1,l);

		c[str[r]]=r;
		le= max(le,r-l+1);
		r++;

	}
	return le;
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

	int ans=length(str);

	cout<<ans;

	return 0;
}