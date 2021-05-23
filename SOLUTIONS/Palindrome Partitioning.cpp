  
/*
Method : Backtracking              Verdict : Accepted
Complexity Analysis:
Time Complexity: O(N * 2^N).
Total O(2^N) recursive calls.For every call we do:
1) check ifPalindrome O(N)
2) create substring O(N)
therefore total time complexity will be O(n * 2^n).
Space Complexity: O(N).
Memory would be O(N). Due to recursion tree (which depth is at most n).
*/
class Solution {
public:
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
public:
    void func(int index,vector<string>&ds,vector<vector<string>>&ans,string s)
    {
        if(index==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                ds.push_back(s.substr(index,i-index+1));
                func(i+1,ds,ans,s);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        int index=0;
        func(index,ds,ans,s);
        return ans;
        
    }
};