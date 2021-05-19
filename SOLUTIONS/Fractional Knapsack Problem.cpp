  
/*
Complexity Analysis :
Time Complexity: O(n*log(n)) Time for sorting.
Space Complexity: O(n) Extra space for vector of structure.
*/
struct Item{
    int value;
    int weight;
};

bool comparator(Item a,Item b)
{
    double r1= (double)a.value/(double)a.weight;
    double r2= (double)b.value/(double)b.weight;
    return r1>r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comparator);
        
        double profit=0.0;
        int curr_wt=0;
        for(int i=0;i<n;i++)
        {
            if(curr_wt+arr[i].weight<=W)
            {
                curr_wt=curr_wt+arr[i].weight;
                profit=profit+arr[i].value;
            }
            else
            {
                int remain=W-curr_wt;
                profit+=(double)remain*((double)arr[i].value/(double)arr[i].weight);
                break;
            }
        }
        return profit;
    }
        
};