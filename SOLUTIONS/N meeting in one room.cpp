  
/*
Complexity Analysis :
Time Complexity:O(n)+O(nlogn)+O(n)==O(nlogn) 
Space Complexity: O(n)
*/
struct meeting{
        int first;
        int second;
        int pos;
    };
    bool comparator(struct meeting m1,meeting m2)
    {
        if(m1.second<m2.second)
        {
            return true;
        }
        else if(m1.second>m2.second)
        {
            return false;
        }
        else if(m1.pos<m2.pos)
        {
            return true;
        }
        return false;
    }

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.

    int maxMeetings(int start[], int end[], int n)
    {
        struct meeting meet[n];
        for(int i=0;i<n;i++)
        {
            meet[i].first=start[i];
            meet[i].second=end[i];
            meet[i].pos=i+1;
        }
        sort(meet,meet+n,comparator);
        vector<int>ans;
        int new_second=meet[0].second;
        ans.push_back(meet[0].pos);
        for(int i=1;i<n;i++)
        {
            if(meet[i].first>new_second)
            {
                ans.push_back(meet[i].pos);
                new_second=meet[i].second;
            }
        }
        return ans.size();
    }
};