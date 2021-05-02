#include <bits/stdc++.h>
using namespace std;
// time compleity O(nlogn) space complexity O(n)

/*void mergeSubIntervals(vector<pair<int,int> > &intervals,int n)
{

	sort(intervals.begin(),intervals.end());
	stack<pair<int,int>> s;
	

	s.push({intervals[0].first,intervals[0].second});

	for(int i=1;i<n;i++)
	{
		int start=s.top().first;
		int end=s.top().second;
		int start1=intervals[i].first;
		int end1=intervals[i].second;

		if(end<start1)
		{
			s.push({start1,end1});
		}

		else
		{
			s.pop();
			end=max(end,end1);
			s.push({start,end});
		}
	}

	while(!s.empty())
	{
		cout<<s.top().first<<" "<<s.top().second<<endl;
		s.pop();
	}
}
*/

// time compleity O(nlogn) space complexity O(1)
void mergeIntervals(vector<pair<int,int>>&intervals,int n)
{

	sort(intervals.begin(),intervals.end());

	int index=0;

	for(int i=1;i<n;i++)
	{
		if(intervals[index].second >= intervals[i].first)
		{
			intervals[index].second=max(intervals[index].second,intervals[i].second);
			intervals[index].first=intervals[index].first;
		}

		else
		{
			index++;
			intervals[index]=intervals[i];
		}
	}

	for(int i=0;i<=index;i++)
	{
		cout<<intervals[i].first<<" "<<intervals[i].second<<endl;
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
	int n;
	cin>>n;
	vector<pair<int,int>>intervals;

	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		intervals.push_back({x,y});
	}
	//mergeSubIntervals(intervals,n);
	mergeIntervals(intervals,n);
	return 0;
}
