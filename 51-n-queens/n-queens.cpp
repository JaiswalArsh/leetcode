class Solution {
public:
    void solve(int col, vector<string>& board, int n,
               vector<vector<string>>& ans, vector<int>& lrow,
               vector<int>& upperD, vector<int>& lowerD) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (lrow[row] == 0 && lowerD[col + row] == 0 &&
                upperD[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                lrow[row] = 1;
                lowerD[col + row] = 1;
                upperD[n - 1 + col - row] = 1;
                solve(col + 1, board, n, ans, lrow, upperD, lowerD);
                board[row][col] = '.';
                lrow[row] = 0;
                lowerD[col + row] = 0;
                upperD[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        vector<int> lrow(n, 0), upperD(2 * n - 1, 0), lowerD(2 * n - 1, 0);
        solve(0, board, n, ans, lrow, upperD, lowerD);
        return ans;
    }
};