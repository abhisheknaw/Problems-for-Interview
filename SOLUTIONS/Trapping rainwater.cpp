/*
Method 1 :- Two Pointers
Complexity Analysis :
Time complexity: O(n) Single iteration of O(n).
Space complexity: O(1) extra space.
*/
 int trap(vector<int>& height) {
        int leftmax=0;
        int rightmax=0;
        int res=0;
        int left=0;
        int right=height.size()-1;
        
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=leftmax)
                    leftmax=height[left];
                else
                    res=res+(leftmax-height[left]);
                left++;
            }
            else
            {
                if(height[right]>=rightmax)
                    rightmax=height[right];
                else
                    res=res+(rightmax-height[right]);
                right--;
            }
        }
        return res;
    }

/*
Method 2 :- DP(Pre Computation of left bar and right bar)    
Complexity analysis
Time complexity: O(n).
  We store the maximum heights upto a point using 2 iterations of O(n) each.
  We finally update ans using the stored values in O(n).
Space complexity: O(n+n) = O(n) extra Space.
  n extra space each for pre computing lmax and rmax.
*/

 int trap(vector<int>& height) {
        int n=height.size();
        if(n<3)
            return 0;
        int prefix[n];
        int suffix[n];
        int res=0;
        prefix[0]=height[0];
        suffix[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(height[i],suffix[i+1]);
        }
        
        for(int i=0;i<n;i++)
        {
            res=res+min(prefix[i],suffix[i])-height[i];
        }
        return res;
    }
};


/*
Method 3 :- Brute force
Complexity Analysis :                   Verdict : TLE
Time complexity: O(n^2). For each element of array, we iterate the left and right parts.
Space complexity: O(1) extra space.
*/

int trap(vector<int>& height) {
    int n = height.size();
    int Wtrap = 0;

    for (int i = 0; i < n; i++) {

        int lmax = 0, rmax = 0;

        for (int j = 0; j <= i; j++) {
            lmax = max(lmax, height[j]);
        }

        for (int j = i; j < n; j++) {
            rmax = max(rmax, height[j]);
        }

        int ltrap = min(lmax, rmax) - height[i];

        Wtrap += ltrap;

    }

    return Wtrap;
}