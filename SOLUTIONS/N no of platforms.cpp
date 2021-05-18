#include <bits/stdc++.h>
using namespace std;
struct ti{
	int start;
	int dep;
};
bool comparator(ti a,ti b)
{
	return (a.dep<b.dep);
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
	ti arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].start;
		cin>>arr[i].dep;
	}
	int plat=1;
	int cur_plat=1;

	sort(arr,arr+n,comparator);
	int j=0;
	for(int i=1;i<n;)
	{
		if(arr[j].dep>=arr[i].start)
		{
			cur_plat++;
			i++;
		}
		else
		{
			cur_plat--;
			j++;
		}
		if(plat<cur_plat)
			plat=cur_plat;

	}
	cout<<plat;
	return 0;
}