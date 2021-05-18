/*
METHOD : Sorting and placing at far         Verdict : Accepted
Complexity Analysis :
Time Complexity: O(n*n + n*log(n)) = O(n*n) checking for each job and linearly finding its position to place in far most position.
Space Complexity: O(1).
*/
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool comparator(Job a,Job b)
{
    return (a.profit>b.profit);
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comparator);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i].dead);
        }
        int slot[maxi+1];
        for(int i=0;i<=maxi;i++)
        {
            slot[i]=-1;
        }
        int count_job=0,job_profit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(slot[j]==-1)
                {
                    slot[j]=arr[i].id;
                    count_job++;
                    job_profit=job_profit+arr[i].profit;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(count_job);
        ans.push_back(job_profit);
        return ans;
    } 
};