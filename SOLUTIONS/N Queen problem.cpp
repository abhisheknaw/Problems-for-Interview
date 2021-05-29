/*
using backracking
*/
class Solution {
public:
    bool isSafe(int r,int c,vector<string>&ds,int n)
    {
        int dupr=r;
        int dupc=c;
        while(r>=0 && c>=0)
        {
            if(ds[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        r=dupr;
        c=dupc;
        while(c>=0)
        {
            if(ds[r][c]=='Q')
                return false;
            c--;
        }
        r=dupr;
        c=dupc;
        while(r<n && c>=0)
        {
            if(ds[r][c]=='Q')
                return false;
            r++;
            c--;
        } 
        return true;
    }
public:
    void queen(vector<vector<string>>&ans,vector<string>&ds,int c,int n)
    {
        if(c==n)
        {
            ans.push_back(ds);
            return;
        }
        for(int r=0;r<n;r++)
        {
            if(isSafe(r,c,ds,n))
            {
                ds[r][c]='Q';
                queen(ans,ds,c+1,n);
                ds[r][c]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>ds(n);
        string s(n,'.');
        int c=0;
        for(int i=0;i<n;i++)
        {
            ds[i]=s;
        }
        queen(ans,ds,c,n);
        return ans;
    }
};
/*
backtracking
efficient approach using hashing
*/

class Solution {

public: 
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &leftRow, 
               vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
    
        
        for(int row = 0;row<n;row++) {
            if(leftRow[row]==0 && lowerDiagonal[row + col] == 0 
               && upperDiagonal[n-1 + col - row] == 0) {
                
                board[row][col] = 'Q'; 
                leftRow[row] = 1; 
                lowerDiagonal[row+col] = 1; 
                upperDiagonal[n-1 + col - row] = 1;
                solve(col+1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
                board[row][col] = '.'; 
                leftRow[row] = 0; 
                lowerDiagonal[row+col] = 0; 
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n, '.'); 
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
        solve(0,board, ans, leftRow, upperDiagonal, lowerDiagonal, n); 
        return ans; 
    }
    
};