/*
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dpm (l, vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        vector<vector<int>> zero;
        for(int i = 0; i < strs.size(); i++) {
            int zeros = 0;
            for(char c : strs[i]) 
                if(c == '0')    zeros++;
            
            int k = strs[i].size();
            zero.push_back({i, zeros, k});
        }
        return dp(zero, m, n, 0, dpm);
    }
    
    int dp(vector<vector<int>>& zeros, int m, int n, int p, vector<vector<vector<int>>>& dpm) {
        if(p >= zeros.size())   return 0;
        if(dpm[p][m][n] != -1)  return dpm[p][m][n];

        //include
        int include = -1;
        if(zeros[p][1] <= m && (zeros[p][2] - zeros[p][1]) <= n)
            include = dp(zeros, m - zeros[p][1], n - (zeros[p][2] - zeros[p][1]), p + 1, dpm);
        
        //exclue
        int exclude = dp(zeros, m, n, p + 1, dpm);
        return dpm[p][m][n] = max(include + 1, exclude);
    }
};
