#include <bits/stdc++.h>
using namespace std;


//time complexity O(r*c) space complexity O(n+m)
/*void Setmatrix(int *v,int r,int c)                 //pointer of 2d arary to traverse the 2d array
{
	int row[r];
	int column[c];

	for(int i=0;i<r;i++)
	{
		row[i]=0;
	}
	for(int i=0;i<c;i++)
	{
		column[i]=0;
	}

	for(int i=0 ;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(*(v+i*c+j)==1)
			{
				row[i]=1;
				column[j]=1;
			}
		}
	}

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(row[i]==1 || column[j]==1)
			{
				*(v+i*c+j)=1;
			}
		}
	}

	for(int i=0 ;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{

			cout<<*(v+i*c+j)<<" ";
		}
		cout<<endl;
	}

}*/

//time complexity O(r*c) space complexity O(1)
void Onematrix(int *v,int r,int c)
{

	bool row_flag=false;
	bool col_flag=false;

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i==0 && *(v+i*c+j)==1)
				row_flag=true;

			if(j==0 && *(v+i*c+j)==1)
				col_flag=true;

			if(*(v+i*c+j)==1)
			{
				*(v+0*c+j)=1;
				*(v+i*c+0)=1;
			}
		}
	}

	for(int i=1;i<r;i++)
	{
		for(int j=1;j<c;j++)
		{
			if(*(v+0*c+j)==1 || *(v+i*c+0)==1)
				*(v+i*c+j)=1;
		}
	}

	if(row_flag==true)
	{
		for(int j=0;j<c;j++)
			*(v+0*c+j)=1;
	}

	if(col_flag==true)
	{
		for(int i=0;i<r;i++)
			*(v+i*c+0)=1;
	}


	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(v+i*c+j)<<" ";
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

	int r,c;
	cin>>r>>c;

	int v[r][c];

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>v[i][j];
		}
		
	}


	Zeromatrix((int*)v,r,c);                        //pass 2 d array using pointers


	return 0;
}