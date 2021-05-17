/*
METHOD : Sorting          Verdict : Accepted
Complexity Analysis :
Time Complexity: O(n + n*log(n)) = O(n*log(n)) Time taken by sort function.
Space Complexity: O(1).
*/
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        int platform=1;
        int cur_plat=1;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0;
    	for(int j=1;j<n;)
    	{
    	     if(dep[i]>=arr[j])
    	     {
    	         cur_plat++;
    	         j++;
    	         
    	     }
    	     else
    	     {
    	         cur_plat--;
    	         i++;
    	     }
    	     
    	     if(platform<cur_plat)
    	     {
    	         platform=cur_plat;
    	     }
    	}
    	return platform;
    }
};